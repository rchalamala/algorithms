class KosarajusSCCs
{
	std::vector<std::vector<std::size_t>> transposed, SCCs;
	std::vector<bool> visited;
	std::stack<std::size_t> order;

	void dfs(const std::vector<std::vector<std::size_t>> &graph, const std::size_t &i)
	{
		visited[i] = true;
		for(const auto &neighbor : graph[i])
			if(!visited[neighbor])
				dfs(graph, neighbor);
		order.push(i);
	}

	void transposedDFS(const std::size_t &i, const std::size_t &index)
	{
		SCCs[index].push_back(i);
		visited[i] = false;
		for(const auto &neighbor : transposed[i])
			if(visited[neighbor])
				transposedDFS(neighbor, index);
	}

public:
	explicit KosarajusSCCs(const std::vector<std::vector<std::size_t>> &graph)
	{
		transposed.resize(graph.size());
		visited.assign(graph.size(), false);
		for(std::size_t i = 0; i < graph.size(); ++i)
		{
			if(!visited[i]) dfs(graph, i);
			for(const auto &neighbor : graph[i])
				transposed[neighbor].push_back(i);
		}
		while(!order.empty())
		{
			auto i = order.top();
			order.pop();
			if(visited[i])
			{
				SCCs.emplace_back();
				transposedDFS(i, SCCs.size() - 1);
			}
		}
	}

	[[nodiscard]] std::vector<std::vector<std::size_t>> getSCCs()
	{ return SCCs; }
};
