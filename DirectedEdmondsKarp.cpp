template<typename T>
class DirectedEdmondsKarp
{
	std::vector<std::vector<std::pair<std::size_t, T>>> graph;
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
				if(parents[neighbor.first] == -1 && capacity[front][neighbor.first])
				{
					parents[neighbor.first] = front;
					T newFlow = std::min(flow, capacity[front][neighbor.first]);
					if(neighbor.first == destination) return newFlow;
					next.emplace(neighbor.first, newFlow);
				}
		}
		return 0;
	}

public:
	explicit DirectedEdmondsKarp(const std::size_t size)
	{
		graph.resize(size);
		capacity.resize(size, std::vector<T>(size, 0));
	}

	explicit DirectedEdmondsKarp(const std::vector<std::vector<std::pair<std::size_t, T>>> &graph)
			: graph{graph}
	{
		capacity.resize(graph.size(), std::vector<std::size_t>(graph.size(), 0));
		for(std::size_t i = 0; i < graph.size(); ++i)
			for(const auto &neighbor : graph[i])
				capacity[i][neighbor.first] += neighbor.second;
	}

	void addEdge(const std::size_t u, const std::size_t v, const T w, const bool bidirectional = false)
	{
		graph[u].emplace_back(v, w);
		capacity[u][v] += w;
		if(bidirectional)
		{
			graph[v].emplace_back(u, w);
			capacity[v][u] += w;
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
