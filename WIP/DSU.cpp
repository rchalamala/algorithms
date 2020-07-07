template<class T>
class DSU
{
	std::vector<T> sizes, parent;
public:

	explicit DSU(const T size)
	{
	sizes.resize(size, 1);
		parent.resize(size);
		iota(parent.begin(), parent.end(), 0);
	}

	T root(T i)
	{
		while(i != parent[i]) i = parent[i] = parent[parent[i]];
		return i;
	}

	bool connect(const T u, const T v)
	{
		T i = root(u), j = root(v);
		if (i == j) return false;
		if (sizes[i] >= sizes[j])
		{
			sizes[i] += sizes[j];
			parents[j] = i;
		}
		else
		{
			sizes[j] += sizes[i];
			parents[i] = j;
		}
		return true;
	}
};
