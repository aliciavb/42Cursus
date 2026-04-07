#include "Zombie.hpp"

int main(void)
{
	int N = 8;
    Zombie *horde = zombieHorde(N, "zombie");

    if (horde == NULL)
        return (1);

    int i = 0;
    while (i < N)
    {
        horde[i].announce();
        i++;
    }

    delete[] horde;

    return (0);
}