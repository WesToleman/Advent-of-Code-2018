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

	auto common_strings = *(strings_with_mismatches(puzzle, 1).begin());

	std::cout << "Common Characters: " << common_characters(common_strings.first, common_strings.second) << '\n';

	return 0;
}
