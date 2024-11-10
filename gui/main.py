"""
Main Python file responsible for Mephisto GUI
"""

import tkinter as tk
from tkinter import messagebox
import subprocess


def process_input():
    """
    Get user input (ASM code) and process it
    using C++ backend
    """
    user_input = entry.get()

    res = subprocess.run(
        ["./build/Mephisto", user_input],
        capture_output=True,
        text=True
    )

    messagebox.showinfo("C++ Output", res.stdout)


app_window = tk.Tk()
app_window.title("Mephisto")

tk.Label(app_window, text="Enter code:").pack(pady=5)
entry = tk.Entry(app_window, width=50)
entry.pack(pady=5)

tk.Button(app_window, text="Run", command=process_input).pack(pady=20)


if __name__ == "__main__":
    app_window.mainloop()
