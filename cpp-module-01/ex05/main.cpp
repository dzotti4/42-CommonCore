#include <iostream>
#include "Harl.hpp"

static void run_all(Harl &h)
{
    h.complain("DEBUG");
    h.complain("INFO");
    h.complain("WARNING");
    h.complain("ERROR");

	h.complain("DEBUG");
    h.complain("WARNING");
}

int main(int argc, char **argv)
{
    Harl h;

    if (argc == 1)
    {
        run_all(h);
        return (0);
    }
    if (argc == 2)
    {
        h.complain(argv[1]);
        return (0);
    }
    std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
    return (1);
}
