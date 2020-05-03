/*
Initialization: BinarySearch<datatype> b(N); // N == amount of vertices
qunion Operation: q.qunion(u, v); // u, v == edge vertices
qfind Operation: q.find(u, v); // u, v == edge vertices // returns true if u and v are connected else returns false
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
