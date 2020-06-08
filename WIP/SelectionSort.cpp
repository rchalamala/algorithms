template<typename T>
void sort(std::vector<T> &elements)
{
	for (T i = 0; i < elements.size() - 1; ++i)
	{
		T minimum = i;
		for (T j = i + 1; j < elements.size(); ++j)
			if (elements[j] < elements[minimum])
				minimum = j;
		std::swap(elements[i], elements[minimum]);
	}
}
