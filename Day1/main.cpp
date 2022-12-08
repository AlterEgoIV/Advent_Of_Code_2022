#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>

int main()
{
	std::ifstream stream("input.txt");

	if(!stream)
	{
		std::cerr << "File could not be loaded" << "\n";
		return -1;
	}

	std::vector<int32_t> totals;
	int32_t total = 0;

	while(stream)
	{
		std::string line;
		std::getline(stream, line);

		if(!line.empty())
		{
			int32_t calories = std::stoi(line);
			total += calories;
		}
		else
		{
			totals.push_back(total);
			total = 0;
		}
	}

	std::sort(totals.begin(), totals.end());

	int32_t size = totals.size();
	int32_t calories = totals[size - 1] + totals[size - 2] + totals[size - 3];

	std::cout << "The combined calories of the three Elves with the most calories is " << calories << "\n";

	return 0;
}