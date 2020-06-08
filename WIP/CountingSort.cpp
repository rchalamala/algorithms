template<typename T>
void sort(std::vector<T> &elements)
{
	const auto minmax = std::minmax_element(elements.begin(), elements.end());
	const T minimum = *minmax.first, maximum = *minmax.second;
	std::vector<T> auxilary(maximum - minimum + 1, 0);
	for (auto &elem : elements)
		++auxilary[elem - minimum];
	T index = 0;
	for (T value = 0; value <= maximum - minimum; ++value)
		while (auxilary[value]--)
			elements[index++] = value + minimum;
}
