from tkinter import Tk
from editor import CodeEditor

def main():
    root = Tk()
    root.title("Mephisto | RISC-V IDE")
    root.iconbitmap("assets/mephisto-logo-rounded.ico")
    editor = CodeEditor(root)
    root.mainloop()

if __name__ == "__main__":
    main()
