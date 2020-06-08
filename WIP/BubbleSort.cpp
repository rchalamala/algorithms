template<typename T>
void sort(std::vector<T> &elements)
{
	for (T i = 0; i < elements.size() - 1; ++i)
		for (T j = 0; j < elements.size() - i - 1; ++j)
			if (elements[j] > elements[j + 1])
				std::swap(elements[j], elements[j + 1]);
}
