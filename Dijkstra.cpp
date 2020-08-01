template<class T>
class Dijkstra
{
	std::vector<std::vector<std::pair<std::size_t, T>>> graph;
	std::vector<T> costs;
	std::vector<std::size_t> parents;
	std::vector<bool> visited;
	std::priority_queue<std::pair<T, std::size_t>, std::vector<std::pair<T, std::size_t>>, std::greater<std::pair<T, std::size_t>>> next;
public:
	explicit Dijkstra(const std::size_t size)
	{
		graph.resize(size);
		costs.assign(graph.size(), std::numeric_limits<T>::max());
		parents.assign(graph.size(), std::numeric_limits<T>::max());
		visited.assign(graph.size(), false);
	}

	explicit Dijkstra(const std::vector<std::vector<std::pair<std::size_t, T>>> &graph)
			: graph{graph}
	{
		costs.assign(graph.size(), std::numeric_limits<T>::max());
		parents.assign(graph.size(), std::numeric_limits<T>::max());
		visited.assign(graph.size(), false);
	}

	void addEdge(const std::size_t u, const std::size_t v, const T w, const bool bidirectional = false)
	{
		graph[u].emplace_back(v, w);
		if(bidirectional) graph[v].emplace_back(u, w);
	}

	void explore(std::size_t source, const bool clear = false)
	{
		if(clear)
		{
			costs.assign(graph.size(), std::numeric_limits<T>::max());
			parents.assign(graph.size(), std::numeric_limits<T>::max());
			visited.assign(graph.size(), false);
		}
		costs[source] = 0;
		parents[source] = source;
		next.emplace(costs[source], source);
		while(!next.empty())
		{
			T top = next.top().second;
			next.pop();
			if(visited[top]) continue;
			visited[top] = true;
			for(const auto &neighbor : graph[top])
				if(!visited[neighbor.first] && costs[neighbor.first] > costs[top] + neighbor.second)
				{
					costs[neighbor.first] = costs[top] + neighbor.second;
					parents[neighbor.first] = top;
					next.emplace(costs[neighbor.first], neighbor.first);
				}
		}
	}

	[[nodiscard]] std::vector<std::vector<std::pair<T, std::size_t>>> getGraph() const
	{ return graph; }

	[[nodiscard]] std::vector<T> getCosts() const
	{ return costs; }

	[[nodiscard]] std::vector<std::size_t> getParents() const
	{ return parents; }

	[[nodiscard]] std::vector<bool> getVisited() const
	{ return visited; }
};
