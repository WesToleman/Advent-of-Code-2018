#include <numeric>
#include <set>

/**
 * @brief      Gets the frequency after a set of calibration instructions
 *
 * @param[in]  calibration_instructions  A set of calibration instructions
 *
 * @tparam     Container                 A container type
 *
 * @return     The resulting frequency
 */
template <class Container>
typename Container::value_type get_frequency(const Container& calibration_instructions)
{
	return std::accumulate(calibration_instructions.begin(),
	                       calibration_instructions.end(),
	                       0);
}

/**
 * @brief      Gets the first repeated frequency in a set of calibration
 *             instructions
 *
 *             The calibration instructions will be cycled until a repeated
 *             value is found.
 *
 * @param[in]  calibration_instructions  A set of calibration instructions
 *
 * @tparam     Container                 A container type
 *
 * @return     The first repeated frequency
 */
template <class Container>
typename Container::value_type first_repeated_frequency(const Container& calibration_instructions)
{
	using value_type = typename Container::value_type;
	value_type frequency{};

	std::set<value_type> frequencies = { 0 };

	do
	{
		for (const auto& instruction : calibration_instructions)
		{
			frequency += instruction;

			if (frequencies.count(frequency) == 1) { return frequency; }

			frequencies.insert(frequency);
		}
	} while (true);
}
