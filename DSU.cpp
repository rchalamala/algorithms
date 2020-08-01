class DSU
{
	std::vector<std::size_t> parent, sizes;
public:

	explicit DSU(const std::size_t size)
	{
		parent.resize(size);
		std::iota(parent.begin(), parent.end(), 0);
		sizes.assign(size, 1);
	}

	std::size_t root(std::size_t i)
	{
		while(i != parent[i]) i = parent[i] = parent[parent[i]];
		return i;
	}

	bool connect(std::size_t i, std::size_t j)
	{
		if((i = root(i)) == (j = root(j))) return false;
		if(sizes[i] >= sizes[j])
		{
			sizes[i] += sizes[j];
			parent[j] = i;
		}
		else
		{
			sizes[j] += sizes[i];
			parent[i] = j;
		}
		return true;
	}
};
