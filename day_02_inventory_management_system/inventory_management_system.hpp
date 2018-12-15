#include <map>
#include <string>

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
