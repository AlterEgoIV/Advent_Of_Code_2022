#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>

int32_t round(char a, char b)
{
	if(a == 'A' && b == 'X') return 4;
	if(a == 'A' && b == 'Y') return 8;
	if(a == 'A' && b == 'Z') return 3;
	if(a == 'B' && b == 'X') return 1;
	if(a == 'B' && b == 'Y') return 5;
	if(a == 'B' && b == 'Z') return 9;
	if(a == 'C' && b == 'X') return 7;
	if(a == 'C' && b == 'Y') return 2;
	if(a == 'C' && b == 'Z') return 6;

	return 0;
}

int main()
{
	std::ifstream stream("input.txt");

	if(!stream)
	{
		std::cerr << "File could not be loaded" << "\n";
		return -1;
	}

	int32_t score = 0;
	while(stream)
	{
		std::string line;
		std::getline(stream, line);
		line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
		if(!line.empty()) score += round(line[0], line[1]);
	}

	std::cout << "Your total score is " << score << "\n";

	return 0;
}