#include "inventory_management_system.hpp"

#include <catch2/catch.hpp>

#include <vector>
#include <string>

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

TEST_CASE("Common characters")
{
	REQUIRE(common_characters("fghij", "fguij") == "fgij");
}

TEST_CASE("Mismatches of given size")
{
	std::vector<std::string> test_data =
	{
		"abcde",
		"fghij",
		"klmno",
		"pqrst",
		"fguij",
		"axcye",
		"wvxyz",
	};

	SECTION("Strings with two characters difference")
	{
		const std::set<std::pair<std::string, std::string>> expected =
		{
			{ "abcde", "axcye" },
		};

		REQUIRE(strings_with_mismatches(test_data, 2) == expected);
	}

	SECTION("Strings with one character difference")
	{
		const std::set<std::pair<std::string, std::string>> expected =
		{
			{ "fghij", "fguij" },
		};

		REQUIRE(strings_with_mismatches(test_data, 1) == expected);
	}
}
