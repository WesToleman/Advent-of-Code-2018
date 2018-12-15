#include "parser.hpp"

#include <catch2/catch.hpp>

#include <sstream>

TEST_CASE("CSV Input parser parses comma delimited `int`s")
{
	const auto fill_stream = [](std::iostream& stream, const std::vector<int>& values)
	{
		for (const auto& val : values)
		{
			stream << val << ", ";
		}
	};

	const auto parse_values = [](std::iostream& stream)
	{
		std::vector<int> ret;
		auto inserter = std::back_inserter(ret);

		aoc::parse_csv(inserter, stream);

		return ret;
	};

	std::stringstream ss;

	SECTION("Parser handles positive numbers")
	{
		const std::vector<int> expected = { 0, 1, 2, 3, 4, 5 };
		fill_stream(ss, expected);

		REQUIRE(parse_values(ss) == expected);
	}

	SECTION("Parser handles negative numbers")
	{
		const std::vector<int> expected = { -1, -2, -3, -4, -5 };
		fill_stream(ss, expected);

		REQUIRE(parse_values(ss) == expected);
	}

	SECTION("Parser handles mixed positive and negative numbers")
	{
		const std::vector<int> expected = { 0, -1, 2, -3, -4, 5 };
		fill_stream(ss, expected);

		REQUIRE(parse_values(ss) == expected);
	}
}

TEST_CASE("New line separated input parser parses new line separated `int`s")
{
	const auto fill_stream = [](std::iostream& stream, const std::vector<int>& values)
	{
		for (const auto& val : values)
		{
			stream << val << '\n';
		}
	};

	const auto parse_values = [](std::iostream& stream)
	{
		std::vector<int> ret;
		auto inserter = std::back_inserter(ret);

		aoc::parse_nlv(inserter, stream);

		return ret;
	};

	std::stringstream ss;

	SECTION("Parser handles positive numbers")
	{
		const std::vector<int> expected = { 0, 1, 2, 3, 4, 5 };
		fill_stream(ss, expected);

		REQUIRE(parse_values(ss) == expected);
	}

	SECTION("Parser handles negative numbers")
	{
		const std::vector<int> expected = { -1, -2, -3, -4, -5 };
		fill_stream(ss, expected);

		REQUIRE(parse_values(ss) == expected);
	}

	SECTION("Parser handles mixed positive and negative numbers")
	{
		const std::vector<int> expected = { 0, -1, 2, -3, -4, 5 };
		fill_stream(ss, expected);

		REQUIRE(parse_values(ss) == expected);
	}
}
