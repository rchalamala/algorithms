template<class T>
class DFSwithComponents
{
	std::vector<std::vector<std::size_t>> graph;
	std::vector<std::size_t> components;
	std::stack<std::size_t> next;
public:
	explicit DFSwithComponents(const std::size_t size)
	{ graph.resize(size); }

	explicit DFSwithComponents(const std::vector<std::vector<std::size_t>> &graph)
			: graph{graph}
	{ components.assign(graph.size(), 1); }

	void addEdge(const std::size_t u, const std::size_t v, const bool bidirectional = false)
	{
		graph[u].push_back(v);
		if(bidirectional) graph[v].push_back(u);
	}

	void explore(const bool clear = false)
	{
		if(clear) components.assign(graph.size(), 0);
		std::size_t componentNumber = 1;
		for(std::size_t i = 0; i < graph.size(); ++i)
			if(!components[i])
			{
				components[i] = componentNumber;
				next.push(i);
				while(!next.empty())
				{
					auto top = next.top();
					next.pop();
					for(auto &neighbor : graph[top])
						if(!components[neighbor])
						{
							components[neighbor] = componentNumber;
							next.push(neighbor);
						}
				}
				++componentNumber;
			}
	}

	[[nodiscard]] std::vector<std::vector<std::size_t>> getGraph() const
	{ return graph; }

	[[nodiscard]] std::vector<std::size_t> getComponents() const
	{ return components; }

	[[nodiscard]] bool connected(const T u, const T v) const
	{ return components[u] == components[v]; }
};
