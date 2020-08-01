template<class T>
class BFSwithDepth
{
	std::vector<std::vector<std::size_t>> graph;
	std::vector<T> depths;
	std::queue<std::size_t> next;
public:
	explicit BFSwithDepth(const std::size_t size)
	{
		graph.resize(size);
		depths.assign(size, -1);
	}

	explicit BFSwithDepth(const std::vector<std::vector<T>> &graph)
			: graph{graph}
	{ depths.assign(graph.size(), -1); }

	void addEdge(const std::size_t u, const std::size_t v, const bool bidirectional = false)
	{
		graph[u].push_back(v);
		if(bidirectional) graph[v].push_back(u);
	}

	void explore(const std::size_t source, const bool clear = false)
	{
		if(clear) depths.assign(graph.size(), -1);
		depths[source] = 0;
		next.push(source);
		while(!next.empty())
		{
			auto front = next.front();
			next.pop();
			for(const auto &neighbor : graph[front])
				if(depths[neighbor] == -1)
				{
					depths[neighbor] = depths[front] + 1;
					next.push(neighbor);
				}
		}
	}

	[[nodiscard]] std::vector<std::vector<std::size_t>> getGraph() const
	{ return graph; }

	[[nodiscard]] std::vector<T> getDepths() const
	{ return depths; }
};
