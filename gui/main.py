from tkinter import Tk
from editor import CodeEditor

def main():
    root = Tk()
    root.title("My Python Code Editor")
    editor = CodeEditor(root)
    root.mainloop()

if __name__ == "__main__":
    main()
