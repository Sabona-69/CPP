#include <iostream>
#include <iomanip>

class Tic
{
	public:
		char	player;
		char	*table[4] = {
			"   ",
			"   ", 
			"   ",
			NULL
		};
		std::string level;
		// void create_table(){
		// 	for (int i = 0; i < 9; i++)
		// 	{
		// 		// table[i] = ;
		// 		for (int j = 0; j < 10; j++)
		// 			table[i][j] = ;
		// 	}
		// }
		void print_table()
		{
			// create_tabke();
			std::cout << "-------------\n";
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					std::cout << "|" << std::setw(2) << std::left;
					// if (table[i][j])
						std::cout << table[i][j];
					// else 
						std::cout << " ";
				}
					// std::cout << std::endl;
			std::cout << "|\n-------------\n";
			}
		}

};

int main()
{
	Tic game;
	game.print_table();
	std::string input;
	while (true)
	{
		std::cout << "Choose your character :" << std::endl;
		std::cout << "1 : for X" << std::endl;
		std::cout << "2 : for O" << std::endl;
		getline(std::cin, input);
		{
		while (input != "1" && input != "2")
			std::cout << "Wrong Choice :" << std::endl;
			getline(std::cin, input);
		}
		game.player = input[0];

		std::cout << input << std::endl;
	}
}