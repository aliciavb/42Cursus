#include "Zombie.hpp"

int main(void)
{
    // Creando un zombie en el heap usando newZombie
    // Esto nos devuelve un puntero porque el objeto vive fuera de la función
    Zombie *heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    // Creando un zombie en el stack usando randomChump
    // Este zombie se crea, se anuncia y muere al terminar la función randomChump
    randomChump("StackZombie");

    // IMPORTANTE: Como heapZombie se creó con 'new', tenemos que borrarlo manualmente
    // con 'delete'. Si no lo hacemos, tendríamos un memory leak.
    delete heapZombie;

    return (0);
}