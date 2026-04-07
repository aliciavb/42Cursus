// Write a program that contains:
// • A string variable initialized to "HI THIS IS BRAIN".
// • stringPTR: a pointer to the string.
// • stringREF: a reference to the string.
// 
// Your program must print:
// • The memory address of the string variable.
// • The memory address held by stringPTR.
// • The memory address held by stringREF.
// 
// And then:
// • The value of the string variable.
// • The value pointed to by stringPTR.
// • The value pointed to by stringREF.
// 
// That’s all—no tricks. The goal of this exercise is to demystify references,
// which may seem completely new. Although there are some small differences, this
// is simply another syntax for something you already do: address manipulation.
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
