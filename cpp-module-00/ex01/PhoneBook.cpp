#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : _count(0), _next(0)
{
}

std::string PhoneBook::readNonEmptyLine(const std::string &prompt) const
{
    std::string line;

    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, line))
            return "";

        if (line.length() > 0)
            return line;

        std::cout << "Field cannot be empty. Try again." << std::endl;
    }
}

void PhoneBook::add()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "--- ADD CONTACT ---" << std::endl;

    firstName = readNonEmptyLine("First name: ");
    if (firstName == "")
    {
        std::cout << "Input ended (EOF). ADD canceled." << std::endl;
        return;
    }

    lastName = readNonEmptyLine("Last name: ");
    if (lastName == "")
    {
        std::cout << "Input ended (EOF). ADD canceled." << std::endl;
        return;
    }

    nickname = readNonEmptyLine("Nickname: ");
    if (nickname == "")
    {
        std::cout << "Input ended (EOF). ADD canceled." << std::endl;
        return;
    }

    phoneNumber = readNonEmptyLine("Phone number: ");
    if (phoneNumber == "")
    {
        std::cout << "Input ended (EOF). ADD canceled." << std::endl;
        return;
    }

    darkestSecret = readNonEmptyLine("Darkest secret: ");
    if (darkestSecret == "")
    {
        std::cout << "Input ended (EOF). ADD canceled." << std::endl;
        return;
    }

    _contacts[_next].setFirstName(firstName);
    _contacts[_next].setLastName(lastName);
    _contacts[_next].setNickname(nickname);
    _contacts[_next].setPhoneNumber(phoneNumber);
    _contacts[_next].setDarkestSecret(darkestSecret);

    if (_count < 8)
        _count++;

    _next++;
    if (_next == 8)
        _next = 0;

    std::cout << "Contact saved. Total contacts: " << _count << std::endl;
}

static std::string format_col(const std::string &s)
{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

static int parse_index(const std::string &s)
{
    size_t i;
    int    n;

    if (s.length() == 0)
        return -1;

    i = 0;
    n = 0;
    while (i < s.length())
    {
        if (s[i] < '0' || s[i] > '9')
            return -1;
        n = n * 10 + (s[i] - '0');
        i++;
    }
    return n;
}

void PhoneBook::search() const
{
    int         i;
    std::string input;
    int         idx;

    if (_count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    i = 0;
    while (i < _count)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << format_col(_contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << format_col(_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << format_col(_contacts[i].getNickname()) << std::endl;
        i++;
    }

    std::cout << "Enter index to display: ";
    if (!std::getline(std::cin, input))
        return;

    idx = parse_index(input);
    if (idx < 0 || idx >= _count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::cout << "First name: " << _contacts[idx].getFirstName() << std::endl;
    std::cout << "Last name: " << _contacts[idx].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[idx].getNickname() << std::endl;
    std::cout << "Phone number: " << _contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << _contacts[idx].getDarkestSecret() << std::endl;
}
