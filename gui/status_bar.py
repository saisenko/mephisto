import tkinter as tk

class StatusBar(tk.Frame):
    def __init__(self, parent):
        super().__init__(parent)
        self.label = tk.Label(self, text="Ready", anchor="w")
        self.label.pack(fill="x")

    def update_status(self, text):
        self.label.config(text=text)
