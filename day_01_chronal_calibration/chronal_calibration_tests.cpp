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

TEST_CASE("Get first repeated frequency")
{
	std::vector<int> test_case;

	test_case = { 1, -2, 3, 1, 1, -2 };
	REQUIRE(first_repeated_frequency(test_case) == 2);

	test_case = { +1, -1 };
	REQUIRE(first_repeated_frequency(test_case) == 0);

	test_case = { +3, +3, +4, -2, -4 };
	REQUIRE(first_repeated_frequency(test_case) == 10);

	test_case = { -6, +3, +8, +5, -6 };
	REQUIRE(first_repeated_frequency(test_case) == 5);

	test_case = { +7, +7, -2, -7, -4 };
	REQUIRE(first_repeated_frequency(test_case) == 14);
}
