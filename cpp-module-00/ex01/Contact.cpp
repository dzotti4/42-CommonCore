#include "Contact.hpp"

Contact::Contact()
{
    _firstName = "";
    _lastName = "";
    _nickname = "";
    _phoneNumber = "";
    _darkestSecret = "";
}

void Contact::setFirstName(const std::string &s)
{
    _firstName = s;
}

void Contact::setLastName(const std::string &s)
{
    _lastName = s;
}

void Contact::setNickname(const std::string &s)
{
    _nickname = s;
}

void Contact::setPhoneNumber(const std::string &s)
{
    _phoneNumber = s;
}

void Contact::setDarkestSecret(const std::string &s)
{
    _darkestSecret = s;
}

std::string Contact::getFirstName() const
{
    return _firstName;
}

std::string Contact::getLastName() const
{
    return _lastName;
}

std::string Contact::getNickname() const
{
    return _nickname;
}

std::string Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return _darkestSecret;
}
