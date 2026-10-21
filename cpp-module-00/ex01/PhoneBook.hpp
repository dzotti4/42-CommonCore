#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact     _contacts[8];
    int         _count;
    int         _next;

    std::string readNonEmptyLine(const std::string &prompt) const;
	
public:
    PhoneBook();

    void        add();
    void        search() const;
};

#endif
