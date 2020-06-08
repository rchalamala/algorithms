/*
Call: sort(elements, start, end // elements == referenced vector (create and sort before calling function), start == start of elements (0), end == end of elements (element.size() - 1) // sorts referenced vector
*/

template<typename T>
T partition(std::vector<T> &elements, const T left, const T right)
{
	T i = left + 1;
	T pivot = elements[left];
	for (int j = left + 1; j <= right; ++j)
		if (elements[j] < pivot)
		{
			std::swap(elements[i], elements[j]);
			++i;
		}
	std::swap(elements[left], elements[i - 1]);
	return i - 1;
}

template<typename T>
void sort(std::vector<T> &elements, const T left, const T right)
{
	if (left < right)
	{
		T pivot = partition(elements, left, right);
		sort(elements, left, pivot - 1);
		sort(elements, pivot + 1, right);
	}
}
