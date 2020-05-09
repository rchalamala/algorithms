/*
Call: binarySearch(elements, target, low, high) // elements == referenced vector (create and sort before calling function), target == element to look for, low == lower bound of search, high = upper bound of search // returns target index if found otherwise -1
*/

template <typename T>
T multiply(vector<T>& elements, const T target, T low, T high)
{
	while(low <= high)
	{
		T midpoint = low + (high - low) / 2;
		if(elements[midpoint] < target)
			low = midpoint + 1;
		else if(elements[midpoint] > target)
			high = midpoint - 1;
		else
			return midpoint;
	}
	return -1;
}
