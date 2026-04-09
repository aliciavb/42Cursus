
#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "Normal commands:" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::cout << "Commands random:" << std::endl;
	harl.complain("I LOVE BACON");
	harl.complain("");
	harl.complain("WARNING ");
	harl.complain("error");

	return 0;
}
