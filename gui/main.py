"""
Main Python file responsible for Mephisto GUI
"""

import tkinter as tk
import tkinter.ttk as ttk


app_window = tk.Tk()

border_effects = {
    "flat": tk.FLAT,
    "sunken": tk.SUNKEN,
    "raised": tk.RAISED,
    "groove": tk.GROOVE,
    "ridge": tk.RIDGE,
}

for relief_name, relief in border_effects.items():
    frame = tk.Frame(master=app_window, relief=relief, borderwidth=5)
    frame.pack(side=tk.LEFT)
    label = tk.Label(master=frame, text=relief_name)
    label.pack()


if __name__ == "__main__":
    print("[... Here starts Mephisto ...]")
    app_window.mainloop()
