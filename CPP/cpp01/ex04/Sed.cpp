#include "Sed.hpp"
#include <iostream>
#include <fstream>

Sed::Sed(std::string filename)
{
	_inFile = filename;
	_outFile = filename + ".replace";
}

Sed::~Sed()
{
}

void Sed::replace(std::string s1, std::string s2)
{
	if (s1.empty())
	{
		std::cerr << "Error: s1 is empty." << std::endl;
		return;
	}

	std::ifstream ifs(_inFile.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::ofstream ofs(_outFile.c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Error: could not create the replaced file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(ifs, line))
	{
		size_t pos = line.find(s1);

		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}

		ofs << line;
		if (!ifs.eof())
		{
			ofs << std::endl;
		}
	}
}
