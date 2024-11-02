#include <iostream>

struct Player{
	int x;
	int y;
	void print()
	{
		std::cout << "x = " << x << "\n";
		std::cout << "y = " << y << "\n";
	}
};

int main(){
	Player player1;
	player1.x = 1;
	player1.y = 1;
	player1.print();
}