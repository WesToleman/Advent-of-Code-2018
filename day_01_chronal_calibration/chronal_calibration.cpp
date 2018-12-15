#include "chronal_calibration.hpp"

#include "parser.hpp"

#include <iostream>
#include <sstream>
#include <vector>

int main()
{
	std::vector<int> puzzle;
	auto inserter = std::back_inserter(puzzle);
	aoc::parse_nlv(inserter, std::cin);

	std::cout << get_frequency(puzzle) << '\n';

	return 0;
}
