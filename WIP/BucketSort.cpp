template <typename T>
void sort(std::vector<T>& elements)
{
	vector<vector<T>> buckets(elements.size());
	auto max = std::max_element(elements.begin(), elements.end());
	for(auto& element : elements)
		buckets[floor(elements.size() * element / max)].push_back(element);
	for(auto& bucket : buckets)
		std::sort(bucket.begin(), bucket.end());
	T index = 0;
	for(auto& bucket : buckets)
		for(auto& element : bucket)
			elements[index++] = element;
}
