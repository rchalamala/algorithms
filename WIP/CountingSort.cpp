template <typename T>
void sort(std::vector<T>& elements)
{
	auto minmax = std::minmax_element(elements.begin(), elements.end());
	T min = * minmax.first, max = *minmax.second;
	std::vector<T> auxilary(max - min + 1, 0);
	for(auto& elem : elements)
		auxilary[elem - min]++;
	T key = 0;
	for(T value = 0; value <= max - min; value++)
		while(auxilary[value]--)
			elements[key++] = value + min;
}
