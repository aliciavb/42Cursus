#include <string>
#include <iostream>

int main(void)
{
	std::string stringVar = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVar;
	std::string &stringREF = stringVar;
	
	std::cout << &stringVar << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << stringVar << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

}
