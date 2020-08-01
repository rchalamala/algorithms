template<typename T>
void merge(std::vector<T> &elements, const std::size_t &left, const std::size_t &midpoint, const std::size_t &right)
{
	std::vector<T> leftElements, rightElements;
	for(std::size_t i = 0; i < midpoint - left + 1; ++i)
		leftElements.push_back(elements[left + i]);
	for(std::size_t i = 0; i < right - midpoint; ++i)
		rightElements.push_back(elements[midpoint + i + 1]);
	std::size_t i = 0, j = 0, k = left;
	while(i < leftElements.size() && j < rightElements.size())
		elements[k++] = leftElements[i] <= rightElements[j] ? leftElements[i++] : rightElements[j++];
	while(i < leftElements.size())
		elements[k++] = leftElements[i++];
	while(j < rightElements.size())
		elements[k++] = rightElements[j++];
}

template<typename T>
void sort(std::vector<T> &elements, const std::size_t left, const std::size_t right)
{
	if(left < right)
	{
		const std::size_t midpoint = left + (right - left) / 2;
		sort(elements, left, midpoint);
		sort(elements, midpoint + 1, right);
		merge(elements, left, midpoint, right);
	}
}

template<typename T>
void sort(std::vector<T> &elements)
{ sort(elements, 0, elements.size() - 1); }
