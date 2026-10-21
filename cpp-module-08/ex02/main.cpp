#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int main(void)
{
    MutantStack<int> mstack;

    std::cout << "=== Subject test ===" << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << std::endl;
    std::cout << "=== Extra test: copy constructor ===" << std::endl;

    MutantStack<int> copy(mstack);

    MutantStack<int>::iterator it2 = copy.begin();
    MutantStack<int>::iterator ite2 = copy.end();

    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    std::cout << std::endl;
    std::cout << "=== Extra test: assignment operator ===" << std::endl;

    MutantStack<int> assign;
    assign = mstack;

    MutantStack<int>::iterator it3 = assign.begin();
    MutantStack<int>::iterator ite3 = assign.end();

    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }

    return (0);
}
