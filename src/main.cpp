#include <iostream>
#include <string>

#include "Color.h"

int main() {
    std::cout << "Hello and welcome to \033[34mGBATools\033[0m!" << std::endl;
    std::cout << " What can I do for you today? " << std::endl;
    
    while(1) {
        uint8_t choice = 0;
        std::string str;
        while(!choice) {
            std::cout << "1) Convert 8-bit \033[31mc\033[32mo\033[33ml\033[34m\033[35mo\033[36mr\033[0m to 5-bit" << std::endl;
            std::cout << "2) Exit" << std::endl;

            std::cin >> str;

            if (*str.c_str() == 0) {
                std::cout << "Pleas input a number" << std::endl;
            } else if (*str.c_str() < '1' || *str.c_str() > '2') {
                std::cout << "I'm affraid I can't help you with that" << std::endl;
            } else {
                choice = *str.c_str() - '0';
            }
        }

        switch (choice) {
        case 1: {
            std::cout << " \033[31mC\033[32mo\033[33ml\033[34m\033[35mo\033[36mr\033[0m convertion has been selected" << std::endl;
            
            while(1) {
                std::cout << "Please input a \033[31mc\033[32mo\033[33ml\033[34m\033[35mo\033[36mr\033[0m to be converted \033[31mrr\033[32mgg\033[34mbb\033[0m(-1 if you want to exit): ";

                std::string color;
                std::cin >> color;

                unsigned int col = Color::hexTo8Col(color);

                if (col == (unsigned int) -1) break;

                printf("The conversion returns: %X \n", Color::convert8to5(col));
            }
            
            break;
        }
        case 2:
            std::cout << "Have a nice day!";
            return 0;
        
        default:
            std::cout << "Something went wrong! Safety termination is required" << std::endl;
            return 1;
        }

        std::cout << "What can I do for you?" << std::endl;
    }

    return 0;
}