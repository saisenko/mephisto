import os

from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.gridlayout import GridLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.label import Label

from kivy.uix.filechooser import FileChooserListView
from kivy.uix.popup import Popup


class MainScreen(BoxLayout):
    def __init__(self, **kwargs):
        super().__init__(orientation="vertical", **kwargs)

        # toolbar setup
        toolbar = BoxLayout(orientation="horizontal", size_hint=(1, 0.1), spacing=10)
        
        # Open File button
        open_btn = Button(text="Open File")
        open_btn.bind(on_release=self.open_file)
        toolbar.add_widget(open_btn)

        # Save File button
        save_btn = Button(text="Save File")
        save_btn.bind(on_release=self.save_file)
        toolbar.add_widget(save_btn)
        
        # Change ISA button
        change_isa_btn = Button(text="Change ISA")
        change_isa_btn.bind(on_release=self.change_isa)
        toolbar.add_widget(change_isa_btn)

        # Debug button
        debug_btn = Button(text="Debug")
        debug_btn.bind(on_release=self.debug_user_code)
        toolbar.add_widget(debug_btn)

        # Run button
        run_btn = Button(text="Run")
        run_btn.bind(on_release=self.run_user_code)
        toolbar.add_widget(run_btn)

        self.add_widget(toolbar)

        main_layout = BoxLayout(orientation="horizontal")

        # code editor field setup
        self.code_editor = TextInput(
            multiline=True,
            size_hint=(0.6, 1),
            background_color=(0.9,0.9,1,1),
            foreground_color=(0,0,0,1),
            hint_text="Your ASM code here..."
        )
        main_layout.add_widget(self.code_editor)

        # memory/regs data fields setup
        side_panel = GridLayout(cols=1, size_hint=(0.4,1), spacing=10, padding=10)
        
        self.regs_area = Label(text="Regs data", size_hint=(1,0.5), valign="middle", halign="center")
        self.regs_area.bind(size=self.regs_area.setter("text_size"))

        self.mem_area = Label(text="Memory data", size_hint=(1,0.5), valign="middle", halign="center")
        self.mem_area.bind(size=self.mem_area.setter("text_size"))

        side_panel.add_widget(self.regs_area)
        side_panel.add_widget(self.mem_area)
        main_layout.add_widget(side_panel)

        self.add_widget(main_layout)

    def open_file(self, instance):
        """
        Open file from user and replace TextArea with its content
        """
        # File Open Popup
        content = BoxLayout(orientation="vertical")
        filechooser = FileChooserListView(path=".", size_hint=(1, 0.9))
        content.add_widget(filechooser)
        
        def select_file(*_):
            selected = filechooser.selection
            if selected:
                with open(selected[0], "r") as f:
                    self.code_editor.text = f.read()
            popup.dismiss()
        
        open_btn = Button(text="Open", size_hint_y=0.1)
        open_btn.bind(on_release=select_file)
        content.add_widget(open_btn)
        
        popup = Popup(title="Open File", content=content, size_hint=(0.9, 0.9))
        popup.open()

    def save_file(self, instance):
        """
        Open file from user and replace TextArea with its content
        """
        # File Open Popup
        content = BoxLayout(orientation="vertical")
        filechooser = FileChooser()
        content.add_widget(filechooser)
        
        def select_file(*_):
            selected = filechooser.selection
            if selected:
                with open(selected[0], "r") as f:
                    self.code_editor.text = f.read()
            popup.dismiss()
        
        open_btn = Button(text="Open", size_hint_y=0.1)
        open_btn.bind(on_release=select_file)
        content.add_widget(open_btn)
        
        popup = Popup(title="Open File", content=content, size_hint=(0.9, 0.9))
        popup.open()
    
    def save_file(self, instance):
        # Save File Functionality
        file_path = "output.rsv"  # Default filename
        with open(file_path, "w") as f:
            f.write(self.code_editor.text)
        popup = Popup(
            title="File Saved",
            content=Label(text=f"File saved as {file_path}"),
            size_hint=(0.6, 0.4)
        )
        popup.open()

    def run_user_code(self, instance):
        # Run the assembly code (call C++ code here)
        code = self.code_editor.text
        # Pass `code` to your C++ program and get the result (mocked here)
        result = f"Running Assembly Code:\n{code}"
        popup = Popup(
            title="Run Code",
            content=Label(text=result),
            size_hint=(0.9, 0.9)
        )
        popup.open()
    
    def change_isa(self, instance):
        """
        Change ISA to CISC, RISC or VLIW
        """
        pass

    def debug_user_code(self, instance):
        pass


class MainApp(App):
    def build(self):
        return MainScreen()


if __name__ == "__main__":
    MainApp().run()
