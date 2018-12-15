#include "inventory_management_system.hpp"

#include "parser.hpp"

#include <string>

int main()
{
	std::vector<std::string> puzzle;
	auto inserter = std::back_inserter(puzzle);
	aoc::parse_nlv(inserter, std::cin);

	std::vector<unsigned> counts = { 2, 3 };

	std::cout << "Checksum: " << checksum(puzzle, counts) << '\n';

	return 0;
}
