/*
Call: sort(elements, start, end // elements == referenced vector (create and sort before calling function), start == start of elements (0), end == end of elements (element.size() - 1) // sorts referenced vector
*/

template <typename T>
void merge(std::vector<T>& elements, T l, T m, T r)
{
	std::vector<T> left, right;
	for(T i = 0; i < m - l + 1; i++)
		left.push_back(elements[l + i]);
	for(T i = 0; i < r - m; i++)
		right.push_back(elements[m + i + 1]);
	T i = 0, j = 0, k = l;
	while(i < left.size() && j < right.size())
		elements[k++] = left[i] <= right[j] ? left[i++] : right[j++];
	while(i < left.size())
		elements[k++] = left[i++];
	while(j < right.size())
		elements[k++] = right[j++];
}

template <typename T>
void sort(std::vector<T>& elements, T l, T r)
{
	if (l < r)
    {
        T m = l + (r - l) / 2;
        sort(elements, l, m);
        sort(elements, m + 1, r);
        merge(elements, l, m, r);
    }
}