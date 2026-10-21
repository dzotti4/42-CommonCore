#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Replace.hpp"

static int print_error(const std::string& msg)
{
    std::cout << msg << std::endl;
    return (1);
}

int main(int argc, char **argv)
{
    std::string filename;
    std::string s1;
    std::string s2;

    if (argc != 4)
        return (print_error("Usage: ./sedisforlosers <filename> <s1> <s2>"));

    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];

    if (s1.length() == 0)
        return (print_error("Error: s1 cannot be empty"));

    std::ifstream in(filename.c_str());
    if (!in.is_open())
        return (print_error("Error: cannot open input file"));

    std::ostringstream buffer;
    buffer << in.rdbuf();
    std::string content = buffer.str();
    in.close();

    std::string outname = filename + ".replace";
    std::ofstream out(outname.c_str());
    if (!out.is_open())
        return (print_error("Error: cannot create output file"));

    out << replace_all(content, s1, s2);
    out.close();

    return (0);
}
