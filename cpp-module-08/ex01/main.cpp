#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Subject test:" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Error in subject test" << std::endl;
    }

    try
    {
        Span sp2(5);
        std::vector<int> values;

        values.push_back(100);
        values.push_back(101);
        values.push_back(102);

        sp2.addRange(values.begin(), values.end());
        sp2.addNumber(200);
        sp2.addNumber(300);

        std::cout << "\naddRange test:" << std::endl;
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Error in addRange test" << std::endl;
    }

    try
    {
        Span sp3(3);
        std::vector<int> values2;

        values2.push_back(1);
        values2.push_back(2);
        values2.push_back(3);
        values2.push_back(4);

        sp3.addRange(values2.begin(), values2.end());
    }
    catch (const std::exception&)
    {
        std::cout << "\naddRange overflow test: exception caught" << std::endl;
    }

    return (0);
}
