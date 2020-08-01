template<class T>
class HeavyLightDecomposition
{
	std::vector<std::size_t> sizes, parent, depths, head;
	std::vector<std::pair<std::size_t, std::size_t>> times;
	SegmentTree<T> *tree;
	std::size_t type;

	void update(T &answer, const T &value)
	{ answer = type ? type == 1 ? std::min(answer, value) : std::max(answer, value) : answer + value; }

	void dfs(std::vector<std::vector<std::size_t>> &graph, const std::size_t &i)
	{
		sizes[i] = 1;
		for(auto &child : graph[i])
			if(child != parent[i])
			{
				parent[child] = i;
				depths[child] = depths[i] + 1;
				dfs(graph, child);
				sizes[i] += sizes[child];
				if(graph[i][0] == parent[i] || sizes[child] > sizes[graph[i][0]]) std::swap(graph[i][0], child);
			}
	}

	T currentTime = -1;

	void decompose(std::vector<std::vector<std::size_t>> &graph, const std::size_t &i)
	{
		times[i].first = ++currentTime;
		for(const auto &child : graph[i])
			if(child != parent[i])
			{
				head[child] = (graph[i][0] == child ? head[i] : child);
				decompose(graph, child);
			}
		times[i].second = currentTime;
	}

	template<typename BinaryOperation>
	void path(T &u, T &v, BinaryOperation operation)
	{
		for(; head[u] != head[v]; v = parent[head[v]])
		{
			if(depths[head[u]] > depths[head[v]]) std::swap(u, v);
			operation(times[head[v]].first, times[v].first);
		}
		if(depths[u] > depths[v]) std::swap(u, v);
		operation(times[u].first, times[v].first);
	}

	void initialize(std::vector<std::vector<std::size_t>> &graph, const std::size_t &root)
	{
		sizes.resize(graph.size());
		parent.resize(graph.size());
		depths.resize(graph.size());
		head.resize(graph.size());
		parent[root] = root;
		depths[root] = 0;
		dfs(graph, root);
		times.resize(graph.size());
		head[root] = root;
		decompose(graph, root);
	}

public:
	explicit HeavyLightDecomposition(std::vector<std::vector<std::size_t>> &graph, const std::vector<T> elements, const std::size_t &type, const std::size_t &root = 0)
			: type{type}
	{
		initialize(graph, root);
		std::vector<T> positionedElements(graph.size());
		for(std::size_t i = 0; i < graph.size(); ++i) positionedElements[times[i].first] = elements[i];
		tree = new SegmentTree<T>(positionedElements, type);
	}

	explicit HeavyLightDecomposition(std::vector<std::vector<std::size_t>> &graph, const std::size_t &type, const std::size_t &root = 0)
			: type{type}
	{
		initialize(graph, root);
		tree = new SegmentTree<T>(graph.size(), type);
	}

	~HeavyLightDecomposition()
	{ delete[] tree; }

	void updateSubTree(T u, const T &value, const bool &set = false)
	{ tree->change(times[u].first, times[u].second, value, set); }

	void updatePath(T u, T v, const T &value, const bool &set = false)
	{
		path(u, v, [this, &value, &set](const T &low, const T &high)
		{ tree->change(low, high, value, set); });
	}

	T query(T u)
	{ return tree->range(times[u].first, times[u].second); }

	T query(T u, T v)
	{
		T answer = type ? type == 1 ? std::numeric_limits<T>::max() : std::numeric_limits<T>::min() : 0;
		path(u, v, [this, &answer](const T &low, const T &high)
		{ update(answer, tree->range(low, high)); });
		return answer;
	}
};
