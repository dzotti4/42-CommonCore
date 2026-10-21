#include "Replace.hpp"

std::string replace_all(const std::string& content, const std::string& s1, const std::string& s2)
{
    std::string result;
    std::size_t pos = 0;
    std::size_t found;

    while (true)
    {
        found = content.find(s1, pos);
        if (found == std::string::npos)
        {
            result.append(content.substr(pos));
            break;
        }
        result.append(content.substr(pos, found - pos));
        result.append(s2);
        pos = found + s1.length();
    }
    return (result);
}
