#include "inventory_management_system.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Count repeated characters")
{
	std::string test_case;

	test_case = "abcdef";
	REQUIRE_FALSE(contains_n_repeats(test_case, 2));
	REQUIRE_FALSE(contains_n_repeats(test_case, 3));

	test_case = "bababc";
	REQUIRE(contains_n_repeats(test_case, 2));
	REQUIRE(contains_n_repeats(test_case, 3));

	test_case = "abbcde";
	REQUIRE(contains_n_repeats(test_case, 2));
	REQUIRE_FALSE(contains_n_repeats(test_case, 3));

	test_case = "abcccd";
	REQUIRE_FALSE(contains_n_repeats(test_case, 2));
	REQUIRE(contains_n_repeats(test_case, 3));

	test_case = "aabcdd";
	REQUIRE(contains_n_repeats(test_case, 2));
	REQUIRE_FALSE(contains_n_repeats(test_case, 3));

	test_case = "abcdee";
	REQUIRE(contains_n_repeats(test_case, 2));
	REQUIRE_FALSE(contains_n_repeats(test_case, 3));

	test_case = "ababab";
	REQUIRE_FALSE(contains_n_repeats(test_case, 2));
	REQUIRE(contains_n_repeats(test_case, 3));
}

TEST_CASE("Count mismatches")
{
	REQUIRE(count_mismatches("abcde", "axcye") == 2);
	REQUIRE(count_mismatches("fghij", "fguij") == 1);
}
