#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    Zombie *horde = zombieHorde(N, "HordeZombie");

    if (horde == NULL)
        return (1);

    int i = 0;
    while (i < N)
    {
        std::cout << i << ": ";
        horde[i].announce();
        i++;
    }

    delete[] horde;

    return (0);
}