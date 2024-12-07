import tkinter as tk
from tkinter import ttk
from tkinter import filedialog

from menu import MenuBar
from file_processor import process_file, get_register_states

class CodeEditor(tk.Tk):
    def __init__(self, root):
        super().__init__()
        self.root = root
        self.file_path = None

        # Set up text area
        self.editor = tk.Text(self, wrap="word", height=20, width=60)
        self.editor.grid(row=0, column=0, padx=10, pady=10, sticky="nsew")

        self.register_display = tk.Text(self, wrap="word", height=20, width=30)
        self.register_display.grid(row=0, column=1, padx=10, pady=10, sticky="nsew")

        # Button to refresh register states
        self.refresh_button = ttk.Button(
            self, text="Refresh Registers", command=self.update_register_display
        )
        self.refresh_button.grid(row=1, column=1, padx=10, pady=5, sticky="ew")

        self.grid_columnconfigure(0, weight=3)
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)

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
                self.editor.delete(1.0, tk.END)  # Clear previous content
                self.editor.insert(tk.END, content)



    def save_file(self):
        # Code for saving file
        pass

    def process_code(self):
        if self.file_path:
            process_file(self.file_path)  # Call the backend function

    def update_register_display(self):
        """Fetch and display register states from the backend."""
        # Example function to get the data from the backend
        register_states = get_register_states()  # Assuming this calls your backend
        self.register_display.delete(1.0, tk.END)  # Clear current content
        self.register_display.insert(tk.END, register_states)  # Add new content
