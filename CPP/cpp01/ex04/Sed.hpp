#ifndef SED_HPP
#define SED_HPP

#include <string>

class Sed
{
private:
	std::string _inFile;
	std::string _outFile;

public:
	Sed(std::string filename);
	~Sed();
	void replace(std::string s1, std::string s2);
};

#endif
