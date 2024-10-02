#include <iostream>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int j = 1; av[j]; j++)
		{	
			std::string args = av[j];
			for (int i = 0; args[i]; i++)
				std::cout << (char)toupper(args[i]);
		}
	}
	else
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std:: cout << std:: endl;
}
