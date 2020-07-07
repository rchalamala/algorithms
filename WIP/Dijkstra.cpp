template<class T>
class Dijkstra
{
	std::vector<std::vector<std::pair<T, T>>> adjacencyList;
	std::vector<T> costs, parents;
	std::vector<bool> visited;
	std::priority_queue<std::pair<T, T>, std::vector<std::pair<T, T>>, std::greater<std::pair<T, T>>> next;
public:
	explicit Dijkstra(const T size)
	{ adjacencyList.resize(size); }

	explicit Dijkstra(const std::vector<std::vector<std::pair<T, T>>> &userAdjacencyList)
	{ adjacencyList = userAdjacencyList; }

	void addEdge(const T u, const T v, const T w, bool bidirectional = false)
	{
		adjacencyList[u].emplace_back(v, w);
		if (bidirectional) adjacencyList[v].emplace_back(u, w);
	}

	void explore(T source)
	{
		visited.clear();
		visited.resize(adjacencyList.size(), false);
		costs.clear();
		costs.resize(adjacencyList.size(), std::numeric_limits<T>::max());
		parents.clear();
		parents.resize(adjacencyList.size(), std::numeric_limits<T>::max());
		costs[source] = 0;
		parents[source] = source;
		next.emplace(costs[source], source);
		while (!next.empty())
		{
			T top = next.top().second;
			next.pop();
			if (visited[top]) continue;
			visited[top] = true;
			for (auto &neighbor : adjacencyList[top])
				if (!visited[neighbor.first] && costs[neighbor.first] > costs[top] + neighbor.second)
				{
					costs[neighbor.first] = costs[top] + neighbor.second;
					parents[neighbor.first] = top;
					next.emplace(costs[neighbor.first], neighbor.first);
				}
		}
	}

	[[nodiscard]] std::vector<T> getNeighbors() const
	{ return adjacencyList; }

	[[nodiscard]] std::vector<T> getCosts() const
	{ return costs; }

	[[nodiscard]] std::vector<T> getParents() const
	{ return parents; }

	[[nodiscard]] std::vector<bool> getVisited() const
	{ return visited; }
};
