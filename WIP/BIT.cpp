template<class T>
class BIT
{
	std::vector<T> tree;
public:
	explicit BIT(const std::size_t size)
	{ tree.assign(size + 1, 0); }

	void update(std::size_t i, T delta)
	{
		for(++i; i < tree.size(); i += (i & (-i)))
			tree[i] += delta;
	}

	T sum(std::size_t i)
	{
		T sum = 0;
		for(++i; i; i -= (i & (-i)))
			sum += tree[i];
		return sum;
	}

	T range(std::size_t i, std::size_t j)
	{ return sum(j) - sum(i - 1); }
};
