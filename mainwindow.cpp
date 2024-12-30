#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>


#include "include/risc/memory/Registers.h"
#include "include/risc/memory/Memory.h"
#include "include/risc/instructions/Instruction.h"
#include "include/risc/InstructionFactory.h"

QStringList PSEUDOS = {
    "li", "la", "mv", "not", "neg",
    "bgt", "ble", "bgtu", "bleu", "beqz",
    "bnez", "bgez", "blez", "bgtz",
    "j", "call", "ret", "nop"
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openFileBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "", "RV32 Files (*.rsv);;All Files (*)");

    if (!filename.isEmpty()) {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "Could not open file");
            return;
        }

        QTextStream in(&file);
        QString file_content = in.readAll();
        file.close();

        ui->codeEditor->setText(file_content);
        current_file = filename;
    }
}


void MainWindow::on_saveFileBtn_clicked()
{
    QString filename;

    if (!current_file.isEmpty()) {
        filename = current_file;
    } else {
        filename = QFileDialog::getSaveFileName(this, "Save File", "", "RV32 Files (*.rsv);;All Files (*)");
    }

    if (!filename.isEmpty()) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "Could not save file");
            return;
        }
        QTextStream out(&file);
        out << ui->codeEditor->toPlainText();
        file.close();

        current_file = filename;

        QMessageBox::information(this, "File Saved", "File saved successfully.");
    }
}


QStringList process_pseudo(QStringList pseudo_instruction) {
    QStringList processed_pseudo;

    if (pseudo_instruction[0] == "li") {
        processed_pseudo << "addi" << pseudo_instruction[1] << "x0" << pseudo_instruction[2];
    } else if (pseudo_instruction[0] == "mv") {
        processed_pseudo << "addi" << pseudo_instruction[1] << pseudo_instruction[2] << "0";
    } else if (pseudo_instruction[0] == "nop") {
        processed_pseudo << "addi" << "x0" << "x0" << "0";
    } else {
        qDebug() << "Unknown pseudo-instruction: " << pseudo_instruction[0];
    }

    return processed_pseudo;
}

QStringList process_codeline(QStringList codeline) {
    QStringList processed_line;

    if (PSEUDOS.contains(codeline[0])) {
        processed_line = process_pseudo(codeline);
    } else {
        processed_line = codeline;
    }

    return processed_line;
}

QStringList process_operands(const QStringList operands) {
    size_t num_opers = operands.size();

    QStringList updated_operands;
    updated_operands << operands[0];

    for (size_t i = 1; i < num_opers; i++) {
        QString el = operands[i];
        if (el.startsWith('x')) {
            el.remove("x");
            updated_operands << el;
        } else if (el.contains("(")) {
            el.remove(")");
            QStringList split_el = el.split("(");
            split_el[1].remove("x");
            updated_operands << split_el[0];
            updated_operands << split_el[1];
        } else {
            updated_operands << el;
        }
    }
    updated_operands.removeFirst();

    return updated_operands;
}

QStringList execute_instructions(const QList<QStringList>& instructions, Registers& regs) {
    QStringList binaries;
    for (const QStringList& components : instructions) {
        QString name = components[0];
        QStringList operands = process_operands(components);

        Instruction* instruction = InstructionFactory::createInstruction(name, operands);
        instruction->execute(regs);

        QString binary = instruction->encode_to_binary();
        QString part1 = binary.mid(0, 8);
        QString part2 = binary.mid(8, 8);
        QString part3 = binary.mid(16, 8);
        QString part4 = binary.mid(24, 8);

        binaries << part1;
        binaries << part2;
        binaries << part3;
        binaries << part4;
    }
    return binaries;
}

void MainWindow::on_runBtn_clicked()
{
    QString usercode = ui->codeEditor->toPlainText();
    QStringList codelines = usercode.split("\n", Qt::SkipEmptyParts);

    QList<QStringList> updated_line_components;

    for (QString& line : codelines) {
        // Trim, remove commas, and split into components
        QStringList components = line.trimmed().remove(",").split(" ", Qt::SkipEmptyParts);

        // Process pseudo-instructions if applicable
        if (PSEUDOS.contains(components[0])) {
            updated_line_components.append(process_pseudo(components));
        } else {
            updated_line_components.append(components);
        }
    }

    // For debugging, print the processed instructions
    for (const QStringList& instruction : updated_line_components) {
        qDebug() << instruction.join(" ");
    }

    Memory mem;
    Registers regs;
    QStringList bins = execute_instructions(updated_line_components, regs);

    QList<int> regs_data = regs.get_all_regs_data();
    for (int i = 0; i < 32; i++) {
        int row_index = i % 8;  // Determine the row within the table

        QTableWidget* current_table = nullptr;

        // Select the appropriate table based on the index
        if (i >= 0 && i < 8) {
            current_table = ui->regsData1;
        } else if (i >= 8 && i < 16) {
            current_table = ui->regsData2;
        } else if (i >= 16 && i < 24) {
            current_table = ui->regsData3;
        } else if (i >= 24 && i < 32) {
            current_table = ui->regsData4;
        }

        // Set the data in the table
        if (current_table) {
            current_table->setItem(row_index, 0, new QTableWidgetItem(QString::number(regs_data[i])));
        }

        uint16_t address = 0x0000;
        for (QString& el : bins) {
            QString addressStr = QString("%1").arg(address, 4, 16, QChar('0')).toUpper();

            // Concatenate the address and binary data
            QString displayText = addressStr + ": " + el;

            // Add the item to the widget
            ui->memData->addItem(displayText);

            // Increment the address by 8 (each part is 8 bits)
            address += 0x0008;
        }

        ui->textOutput->document()->setPlainText("Program executed successfully");
    }
}
