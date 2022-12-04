#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

std::pair<int32_t, int32_t> find_elf(std::ifstream& stream)
{
	std::pair<int32_t, int32_t> elf;
	int32_t index = 0, total = 0;

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
			if(total > elf.second)
			{
				elf.first = index;
				elf.second = total;
			}

			++index;
			total = 0;
		}
	}

	return elf;
}

int main()
{
	std::ifstream stream("input.txt");

	if(!stream)
	{
		std::cerr << "File could not be loaded" << "\n";
		return -1;
	}

	std::pair<int32_t, int32_t> elf = find_elf(stream);

	std::cout << "The Elf with the most calories is Elf " << elf.first << "\n";
	std::cout << "Elf " << elf.first << " has " << elf.second << " calories\n";

	return 0;
}