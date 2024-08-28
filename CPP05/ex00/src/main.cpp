#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat John("John", 1);
		Bureaucrat Jane("Jane", 150);
        Jane.Demote();
        std::cout << Jane;
        std::cout << John;
		John.Promote();
        std::cout << "SHOULD NOT BE PRINTED" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "---------------------" << std::endl;
	try
	{
		Bureaucrat John("John", 1);
		Bureaucrat Jane("Jane", 150);
		John.Promote();
        std::cout << John;
        std::cout << Jane;
		Jane.Demote();
        std::cout << "SHOULD NOT BE PRINTED" << std::endl;
	}
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl;
	try
	{
		Bureaucrat Jack("Jack", 151);
		std::cout << "SHOULD NOT BE PRINTED" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "---------------------" << std::endl;
	try
	{
        Bureaucrat Jack("Jack", 0);
        std::cout << "SHOULD NOT BE PRINTED" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
	}
    std::cout << "---------------------" << std::endl;
    try
    {
        Bureaucrat Linda("Linda", 100);
        for(int i = 0; i < 100; i++)
        {
            Linda.Promote();
            std::cout << Linda;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    try
    {
        Bureaucrat Linda("Linda", 100);
        Linda.Demote();
        Linda.Promote();
        
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}