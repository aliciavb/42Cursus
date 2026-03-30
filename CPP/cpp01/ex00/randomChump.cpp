// • void randomChump( std::string name );
// This function creates a zombie, names it, and makes it announce itself.

#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}
