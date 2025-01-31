#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
    Zombie *zombie;

	zombie = new Zombie();
	if (!zombie)
		return NULL;
    zombie->set_name(name);
    return (zombie);
}