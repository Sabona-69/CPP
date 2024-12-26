#include "Zombie.hpp"

int main(){
	Zombie *arr = zombieHorde(12, "1");
	for (int i = 0; i < 12; i++){
		std::cout << i << " = ";
		arr[i].announce();
	}
	delete [] arr;
}