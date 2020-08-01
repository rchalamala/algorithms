template<class T>
class CentroidDecomposition
{
	std::vector<T> parents;
	std::vector<std::size_t> sizes;
	T root = -1;

	T dfs(std::size_t i, T parent, const std::vector<std::vector<std::size_t>> &graph)
	{
		sizes[i] = 1;
		for(auto &neighbor : graph[i])
			if(neighbor != parent && parents[neighbor] == -1)
				sizes[i] += dfs(neighbor, i, graph);
		return sizes[i];
	}

	std::size_t centroid(std::size_t i, T parent, std::size_t size, const std::vector<std::vector<std::size_t>> &graph)
	{
		for(auto &neighbor : graph[i])
			if(neighbor != parent && parents[neighbor] == -1 && sizes[neighbor] > size / 2)
				return centroid(neighbor, i, size, graph);
		return i;
	}

	void decompose(const std::vector<std::vector<std::size_t>> &graph, std::size_t i = 0, T parent = -1)
	{
		i = centroid(i, parent, dfs(i, parent, graph), graph);
		if(root == -1) root = parent = i;
		parents[i] = parent;
		for(auto &neighbor : graph[i])
			if(neighbor != parent && parents[neighbor] == -1)
				decompose(graph, neighbor, i);
	}

public:
	explicit CentroidDecomposition(const std::vector<std::vector<std::size_t>> &graph)
	{
		parents.assign(graph.size(), -1);
		sizes.resize(graph.size());
		decompose(graph);
	}

	std::vector<T> getParents()
	{ return parents; }

	T getRoot()
	{ return root; }

};
