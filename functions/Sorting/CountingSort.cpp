template <typename T>
void sort(std::vector<T>& elements)
{
	T max = 0;
	for(auto& elem : elements)
		max = std::max(max, elem);
	std::vector<T> auxilary(max + 1, 0);
	for(auto& elem : elements)
		auxilary[elem]++;
	T j = 0;
	for(T i = 0; i <= max; i++)
		while(auxilary[i]--)
			elements[j++] = i;
}
