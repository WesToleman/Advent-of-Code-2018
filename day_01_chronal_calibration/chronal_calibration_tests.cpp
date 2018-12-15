#include "chronal_calibration.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Get frequency")
{
	std::vector<int> test_case;

	test_case = { +1, -2, +3, +1 };
	REQUIRE(get_frequency(test_case) == 3);

	test_case = { +1, +1, +1 };
	REQUIRE(get_frequency(test_case) == 3);

	test_case = { +1, +1, -2 };
	REQUIRE(get_frequency(test_case) == 0);

	test_case = { -1, -2, -3 };
	REQUIRE(get_frequency(test_case) == -6);
}
