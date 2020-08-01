template<typename T>
T partition(std::vector<T> &elements, const std::size_t &left, const std::size_t &right)
{
	std::size_t i;
	T pivot = elements[left];
	for(std::size_t j = (i = left + 1); j <= right; j++)
		if(elements[j] < pivot)
			std::swap(elements[i++], elements[j]);
	std::swap(elements[left], elements[i - 1]);
	return i - 1;
}

template<typename T>
void sort(std::vector<T> &elements, const std::size_t left, const std::size_t right)
{
	std::size_t pivot = partition(elements, left, right);
	if(left < pivot) sort(elements, left, pivot - 1);
	if(right > pivot) sort(elements, pivot + 1, right);
}

template<typename T>
void sort(std::vector<T> &elements)
{ sort<T>(elements, 0, elements.size() - 1); }
