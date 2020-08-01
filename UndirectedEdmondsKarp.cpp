template<typename T>
class UndirectedEdmondsKarp
{
	std::vector<std::vector<std::size_t>> graph;
	std::vector<std::vector<T>> capacity;
	std::vector<T> parents;

	T bfs(const std::size_t source, const std::size_t destination)
	{
		parents.assign(graph.size(), -1);
		std::queue<std::pair<T, T>> next;
		parents[source] = source;
		next.emplace(source, std::numeric_limits<T>::max());
		while(!next.empty())
		{
			std::size_t front = next.front().first;
			T flow = next.front().second;
			next.pop();
			for(const auto &neighbor : graph[front])
				if(parents[neighbor] == -1 && capacity[front][neighbor])
				{
					parents[neighbor] = front;
					T newFlow = std::min(flow, capacity[front][neighbor]);
					if(neighbor == destination) return newFlow;
					next.emplace(neighbor, newFlow);
				}
		}
		return 0;
	}

public:
	explicit UndirectedEdmondsKarp(const std::size_t size)
	{
		graph.resize(size);
		capacity.resize(size, std::vector<T>(size, 0));
	}

	explicit UndirectedEdmondsKarp(const std::vector<std::vector<std::size_t>> &graph)
			: graph{graph}
	{
		capacity.resize(graph.size(), std::vector<std::size_t>(graph.size(), 0));
		for(std::size_t i = 0; i < graph.size(); ++i)
			for(const auto &neighbor : graph[i])
				++capacity[i][neighbor];
	}

	void addEdge(const std::size_t u, const std::size_t v, const bool bidirectional = false)
	{
		graph[u].push_back(v);
		++capacity[u][v];
		if(bidirectional)
		{
			graph[v].push_back(u);
			++capacity[v][u];
		}
	}

	T explore(const std::size_t source, const std::size_t destination)
	{
		T maxFlow = 0, flow;
		while((flow = bfs(source, destination)))
		{
			maxFlow += flow;
			T current = destination;
			while(current != parents[current])
			{
				capacity[parents[current]][current] -= flow;
				capacity[current][parents[current]] += flow;
				current = parents[current];
			}
		}
		return maxFlow;
	}
};
