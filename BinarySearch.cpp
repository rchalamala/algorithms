template<typename T>
T binarySearch(const std::vector<T> &elements, const T &target, std::size_t low, std::size_t high)
{
	while (low <= high)
	{
		const std::size_t midpoint = low + (high - low) / 2;
		if (elements[midpoint] < target) low = midpoint + 1;
		else if (elements[midpoint] > target) high = midpoint - 1;
		else return midpoint;
	}
	return -1;
}
