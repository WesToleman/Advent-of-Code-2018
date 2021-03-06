#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <type_traits>
#include <vector>

/**
 * @brief      Determines if a string contains any characters that are repeated
 *             exactly `n` times
 *
 * @param[in]  val   The string to count characters in
 * @param[in]  n     The number of repeats to find
 *
 * @return     True if contains `n` repeats, False otherwise.
 */
bool contains_n_repeats(const std::string& val, unsigned n)
{
	std::map<char, unsigned> letter_counts;

	for (const char& c : val)
	{
		if (letter_counts.count(c) == 1)
		{
			letter_counts.at(c) += 1;
		}
		else
		{
			letter_counts.emplace(c, 1);
		}
	}

	for (const auto& kv : letter_counts)
	{
		if (kv.second == n) { return true; }
	}

	return false;
}

/**
 * @brief      Counts the number of items with characters that are repeated
 *             exactly `n` times.
 *
 * @param[in]  Container        The container
 * @param[in]  n                The number of repeats to find
 * @param[in]  box_ids  The box identifiers
 *
 * @tparam     StringContainer  A container type containing `std::string`s
 *
 * @return     Number of identifiers with characters repeated `n` times
 */
template <class StringContainer>
unsigned count_repeats(const StringContainer& box_ids, unsigned n)
{
	using value_type = typename StringContainer::value_type;
	static_assert(std::is_same<std::string, value_type>::value,
	              "String Container must hold `std::string`");

	return std::count_if(box_ids.begin(), box_ids.end(), [&](const value_type& val)
	{
		return contains_n_repeats(val, n);
	});
}

/**
 * @brief      Counts the number of items with characters that are repeated
 *             exactly `n` times.
 *
 * @param[in]  Container        The container
 * @param[in]  n                The number of repeats to find
 * @param[in]  box_ids  The box identifiers
 *
 * @tparam     StringContainer  A container type containing `std::string`s
 *
 * @return     Number of identifiers with characters repeated `n` times
 */
template <class StringContainer, class CountsContainer>
unsigned checksum(const StringContainer& box_ids, const CountsContainer& counts)
{
	using value_type = typename StringContainer::value_type;
	static_assert(std::is_same<std::string, value_type>::value,
	              "String Container must hold `std::string`");

	using counts_type = typename CountsContainer::value_type;
	static_assert(std::is_same<unsigned, counts_type>::value,
	              "Counts Container must hold `unsigned int`");

	std::vector<counts_type> totals;

	for (const auto& n : counts)
	{
		totals.emplace_back(count_repeats(box_ids, n));
	}

	return std::accumulate(totals.begin(), totals.end(), 1, std::multiplies<counts_type>());
}

/**
 * @brief      Counts the number of differing characters between two strings
 *
 * @param[in]  left   The first string to compare
 * @param[in]  right  The second string to compare
 *
 * @return     Number of mismatches between the two strings
 */
unsigned count_mismatches(const std::string& left, const std::string& right)
{
	unsigned count = 0;
	auto itr = std::mismatch(left.begin(), left.end(), right.begin());

	while(itr.first != left.end())
	{
		++count;
		itr = std::mismatch(++itr.first, left.end(), ++itr.second);
	}

	return count;
}

/**
 * @brief      Get a string that is the intersection of two strings
 *
 * @param[in]  left   The first string
 * @param[in]  right  The second string
 *
 * @return     A string consisting of the common characters between two strings
 */
std::string common_characters(std::string left, const std::string& right)
{
	auto itr = right.begin();
	left.erase(std::remove_if(left.begin(), left.end(), [&](char c)
	{
		return c != *itr++;
	}));

	return left;
}

/**
 * @brief      Find all pairs of strings with a given number of differing
 *             characters
 *
 * @param[in]  strings          The strings
 * @param[in]  n                The number of mismatches between the two strings
 *
 * @tparam     StringContainer  A container type containing `std::string`s
 *
 * @return     A set of pairs of strings with a given amount of difference
 */
template <class StringContainer>
std::set<std::pair<std::string, std::string>> strings_with_mismatches(const StringContainer& strings, unsigned n)
{
	using value_type = typename StringContainer::value_type;
	static_assert(std::is_same<std::string, value_type>::value,
	              "String Container must hold `std::string`");

	std::set<std::pair<std::string, std::string>> results;

	for (auto itr = strings.begin(), end = strings.end(); itr != end; ++itr)
	{
		for (auto jtr = itr + 1; jtr != end; ++jtr)
		{
			if (count_mismatches(*itr, *jtr) == n)
			{
				results.emplace(*itr, *jtr);
			}
		}
	}

	return results;
}
