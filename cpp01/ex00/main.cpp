#include "Zombie.hpp"

int main(){
	Zombie *zombie = newZombie("test1");
	zombie->announce();
    randomChump("test2");
	delete zombie;
}