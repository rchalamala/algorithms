template<class T>
class DSU
{
	std::vector<T> parents, sizes;
public:

	explicit DSU(const T size)
	{
		parents.resize(size);
		iota(parents.begin(), parents.end(), 0);
		sizes.resize(size, 1);
	}

	T root(T i)
	{
		while (i != parents[i])
		{
			parents[i] = parents[parents[i]];
			i = parents[i];
		}
		return i;
	}

	void quickUnion(const T u, const T v)
	{
		T i = root(u);
		T j = root(v);
		if (i == j) return;
		if (sizes[i] >= sizes[j])
		{
			parents[j] = i;
			sizes[i] += sizes[j];
		}
		else
		{
			parents[i] = j;
			sizes[j] += sizes[i];
		}
	}
};
