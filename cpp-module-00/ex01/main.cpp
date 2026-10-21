#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            break;

        if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Ignored." << std::endl;
    }
    return 0;
}
