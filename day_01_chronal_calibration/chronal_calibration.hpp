#include <numeric>

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
