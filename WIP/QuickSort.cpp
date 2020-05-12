/*
Call: sort(elements, start, end // elements == referenced vector (create and sort before calling function), start == start of elements (0), end == end of elements (element.size() - 1) // sorts referenced vector
*/

template <typename T>
T partition (std::vector<T>& elements, T l, T r) {
    T i = l + 1;
    T pivot = elements[l] ;
    for(int j = l + 1; j <= r; j++)
	{
    	if (elements[j] < pivot)
		{
            std::swap(elements[i], elements[j]);
            i++;
        }
	}
	std::swap(elements[l], elements[i - 1]);
	return i - 1;
}

template <typename T>
void sort(std::vector<T>& elements, T l, T r)
{
	if (l < r)
    {
        T pivot = partition(elements, l, r);
        sort(elements, l, pivot - 1);
		sort(elements, pivot + 1, r);
    }
}
