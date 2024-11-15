import tkinter as tk


class MenuBar(tk.Menu):
    def __init__(self, editor):
        super().__init__(editor.root)
        self.editor = editor

        # File menu
        file_menu = tk.Menu(self, tearoff=0)
        self.add_cascade(label="File", menu=file_menu)
        file_menu.add_command(label="Open", command=self.editor.open_file)
        file_menu.add_command(label="Save", command=self.editor.save_file)
        file_menu.add_separator()
        file_menu.add_command(label="Exit", command=self.editor.root.quit)

        # Process menu
        process_menu = tk.Menu(self, tearoff=0)
        self.add_cascade(label="Process", menu=process_menu)
        process_menu.add_command(label="Process Code", command=self.editor.process_code)
