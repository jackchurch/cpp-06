#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base*   genrate(void)
{
    int r = std::rand() % 3;
    switch (r)
    {
        case 0:
            std::cout << "Generate:\t\t\tA" << std::endl;
            return (new A());
        case 1:
            std::cout << "Generate:\t\t\tB" << std::endl;
            return (new B());
        case 2:
                std::cout << "Generate:\t\t\tC" << std::endl;
                return (new C());
        default:
            std::cerr << "Random number error" << std::endl;
            return (NULL);
    }
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identify base direct:\t\tA" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identify base direct:\t\tB" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identify base direct:\t\tC" << std::endl;
    else
        std::cerr << "Identify base direct: Unknown type" << std::endl;
}

void    identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "Identify base pointer:\t\tA" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "Identify base pointer:\t\tB" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "Identify base pointer:\t\tC" << std::endl;
    else
        std::cerr << "Identify base pointer: Unknown type" << std::endl;
}
//    std::cout << "float:\t" << static_cast<float>(i) << ".0f" << std::endl;

void    a(void) {
	system("leaks a.out");
}

int     main()
{
    // atexit(a);
    srand(time(NULL));
    int i = 0;
    while (i < 10)
    {
        std::cout << std::endl;
        Base *p = genrate();
        identify(p);
        identify(*p);
        delete p;
        i++;
    }

    std::cout << "Try a fail..." << std::endl;
    Base* unknown = new Base();
    identify(unknown);
    identify(*unknown);
    delete unknown;

    return (0);
}

