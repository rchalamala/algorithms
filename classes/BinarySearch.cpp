/*
Initialization: BinarySearch<datatype> b(N); // N == amount of vertices
find Operation: b.find(target, low, high) // target == element to look for, low == lower bound of search, high = upper bound of search // returns target index if found otherwise N
*/

template <class T>
class BinarySearch
{
	const vector<T> elements;
public:
	BinarySearch(vector<T> list) : elements{list} {}
	T find(const T target, T low, T high)
	{
		const T max = high;
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
		return max;
	}
};
