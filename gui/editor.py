import tkinter as tk
from tkinter import filedialog

from menu import MenuBar
from file_processor import process_file

class CodeEditor:
    def __init__(self, root):
        self.root = root
        self.file_path = None

        # Set up text area
        self.text_area = tk.Text(self.root, wrap="word", undo=True)
        self.text_area.pack(fill="both", expand=True)

        # Add menu bar
        self.menu = MenuBar(self)
        self.root.config(menu=self.menu)

    def open_file(self):
        file_path = filedialog.askopenfilename(
            title="Select a File",
            filetypes=[("RISC-V Code Files", "*.rsv")]
        )
        
        if file_path:
            with open(file_path, 'r') as file:
                content = file.read()
                self.text_area.delete(1.0, tk.END)  # Clear previous content
                self.text_area.insert(tk.END, content)



    def save_file(self):
        # Code for saving file
        pass

    def process_code(self):
        if self.file_path:
            process_file(self.file_path)  # Call the backend function
