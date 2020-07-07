/*
Initialization: FenwickTree<datatype> q(N); // N == length of vector // run update operations on every element to initialize (f.update(i, elements[i]))
update Operation: f.update(i, delta) // i == index to update, delta == delta of new element value versus old element value
sum Operation: f.sum(i) // i == index to get sum up to // returns sum up to index i
query Operation: f.query(i, j) // i == start of sum, j == end of sum // returns sum from index i to index j
*/

template<class T>
class FenwickTree
{
	std::vector<T> tree;
public:
	explicit FenwickTree(const T size)
	{ tree.resize(size + 1, 0); }

	void update(T i, T delta)
	{
		for (++i; i < tree.size(); i += (i & (-i)))
			tree[i] += delta;
	}

	T sum(T i)
	{
		T sum = 0;
		for (++i; i > 0; i -= (i & (-i)))
			sum += tree[i];
		return sum;
	}

	T query(T i, T j) const
	{ return sum(j) - sum(--i); }
};
