class UndirectedEulerianCircuit
{
	std::vector<std::vector<std::pair<std::size_t, std::size_t>>> graph;
	std::vector<std::size_t> degrees;
	std::size_t m = 0;
	std::vector<bool> used;
	std::stack<std::pair<std::size_t, std::size_t>> circuit;
	bool isEulerian;

	void dfs(const std::size_t &parent, const std::size_t &i)
	{
		while(!graph[i].empty())
		{
			auto next = graph[i].back();
			graph[i].pop_back();
			if(!used[next.second])
			{
				used[next.second] = true;
				dfs(i, next.first);
			}
		}
		if(!circuit.empty() && circuit.top().first != i) isEulerian = false;
		circuit.emplace(parent, i);
	}

public:
	explicit UndirectedEulerianCircuit(const std::size_t &n)
	{
		graph.resize(n);
		degrees.assign(n, 0);
	}

	void addEdge(const std::size_t u, const std::size_t v)
	{
		graph[u].emplace_back(v, m);
		graph[v].emplace_back(u, m);
		++degrees[u];
		++degrees[v];
		++m;
	}

	[[nodiscard]] std::vector<std::size_t> explore(const std::size_t &root)
	{
		used.assign(m, false);
		isEulerian = true;
		for(const auto &degree : degrees)
			if(degree % 2)
				return {};
		dfs(root, root);
		if(circuit.size() != m + 1 || !isEulerian) return {};
		std::vector<std::size_t> path;
		while(!circuit.empty())
		{
			path.push_back(circuit.top().second);
			circuit.pop();
		}
		return path;
	}
};
