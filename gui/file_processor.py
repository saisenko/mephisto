# from file_processor import call_cpp_translator

import ctypes

risc_backend = ctypes.CDLL('./build/lib/libtranslator.dll')
risc_backend.get_all_regs_data.restype = ctypes.c_char_p

def process_file(file_content):
    # result = call_cpp_translator(file_content)
    return file_content

def get_register_states():
    """
    Fetch regs from backend
    :return: regs content
    """
    regs_data = risc_backend.get_all_regs_data()
    return regs_data.decode("utf-8")