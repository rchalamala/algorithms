template <typename T>
void sort(std::vector<T>& elements)
{
	for (T i = 0; i < elements.size(); ++i)
	{
		T key = elements[i];
		T j = i;
		while(j && key < elements[j - 1])
		{
			std::swap(elements[j], elements[j - 1]);
			--j;
		}
		elements[j] = key;
	}
}
