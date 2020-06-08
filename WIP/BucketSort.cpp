template<typename T>
void sort(std::vector<T> &elements)
{
	std::vector<std::vector<T>> buckets(elements.size());
	const auto maximum = std::max_element(elements.begin(), elements.end());
	for (const auto &element : elements)
		buckets[floor(elements.size() * element / maximum)].push_back(element);
	for (auto &bucket : buckets)
		std::sort(bucket.begin(), bucket.end());
	T index = 0;
	for (const auto &bucket : buckets)
		for (const auto &element : bucket)
			elements[index++] = element;
}
