#include <iostream>
#include <limits>

namespace aoc
{
	/**
	 * @brief      Parses comma separated values
	 *
	 * @param      output          The an OutputIterator for a container to hold
	 *                             the output output
	 * @param      input           An input stream containing the comma
	 *                             separated values
	 *
	 * @tparam     OutputIterator  An type that satisfies std `OutputIterator`
	 */
	template<class OutputIterator>
	void parse_csv(OutputIterator &output, std::istream &input)
	{
		using value_type = typename OutputIterator::container_type::value_type;

		value_type tmp;

		while (input >> tmp)
		{
			*output++ = tmp;
			input.ignore(std::numeric_limits<std::streamsize>::max(), ',');
		}
	}
}
