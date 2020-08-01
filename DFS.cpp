class DFS
{
	std::vector<std::vector<std::size_t>> graph;
	std::vector<bool> visited;
	std::stack<std::size_t> next;
public:
	explicit DFS(const std::size_t size)
	{ graph.resize(size); }

	explicit DFS(const std::vector<std::vector<std::size_t>> &graph)
			: graph{graph}
	{ visited.assign(graph.size(), false); }

	void addEdge(const std::size_t u, const std::size_t v, const bool bidirectional = false)
	{
		graph[u].push_back(v);
		if(bidirectional) graph[v].push_back(u);
	}

	void explore(const std::size_t source, const bool clear = false)
	{
		if(clear) visited.assign(graph.size(), false);
		visited[source] = true;
		next.push(source);
		while(!next.empty())
		{
			auto top = next.top();
			next.pop();
			for(const auto &neighbor : graph[top])
				if(!visited[neighbor])
				{
					visited[neighbor] = true;
					next.push(neighbor);
				}
		}
	}

	[[nodiscard]] std::vector<std::vector<std::size_t>> getGraph() const
	{ return graph; }

	[[nodiscard]] std::vector<bool> getVisited() const
	{ return visited; }
};
