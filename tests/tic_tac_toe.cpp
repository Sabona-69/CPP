#include <iostream>
#include <iomanip>

class Tic
{
	public:
		char	player;
		char	**table;
		std::string level;
		void create_table(){
			table = (char **)malloc(sizeof(char *) * 4);
			int k = 1;
			for (int i = 0; i < 3; i++)
			{
				table[i] = (char *)malloc(4);
				for (int j = 0; j < 3; j++)
					table[i][j] = k++ + 48;
			}
		}
		void print_table()
		{
			create_table();
			std::cout << "----------\n";
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					std::cout << "|" << std::setw(2) << std::left << table[i][j];
				}
			std::cout << "|\n----------\n";
			}
		}
		bool	check_win(char c, int i, int j)
		{
			
		}
		int		you_won()
		{
			for (int i = 0; table[i]; i++){

				for (int j = 0; table[i][j]; j++){
					if (table[i][j] == 'X' || table[i][j] == 'O')
					{
						if (check_win(table[i][j], i, j));
					}
				}
			}

		}
};

int main()
{
	Tic game;
	std::string input;
	while (true)
	{
		std::cout << "Choose your character :" << std::endl;
		std::cout << "1 : for X" << std::endl;
		std::cout << "2 : for O" << std::endl;
		getline(std::cin, input);
		while (input != "1" && input != "2")
		{
			std::cout << "Wrong Choice :" << std::endl;
			getline(std::cin, input);
		}
		if (input == "1")
			game.player = 'X';
		else 
			game.player = 'O';
		std::cout << "You Choosed : " << game.player << std::endl;
		while (!game.you_won())
			game.print_table();
		
		std::cout << input << std::endl;
	}
}