#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Invalid input. Expected 2 args." << std::endl;
    }

    std::string user_input = argv[1];

    std::cout << user_input << std::endl;
    
    return 0;
}
