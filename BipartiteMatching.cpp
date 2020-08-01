template<class T>
class BipartiteMatching
{
	std::vector<std::vector<std::size_t>> graph;
	std::vector<T> match;
	std::vector<bool> mark;

	bool dfs(T i)
	{
		if(!mark[i])
		{
			mark[i] = true;
			for(auto &neighbor : graph[i])
				if(match[neighbor] == -1 || dfs(match[neighbor]))
					return match[i] = neighbor, match[neighbor] = i, true;
		}
		return false;
	}

public:
	explicit BipartiteMatching(const std::size_t size)
	{
		graph.resize(size);
		match.assign(size, -1);
	}

	explicit BipartiteMatching(const std::vector<std::vector<T>> &graph)
			: graph{graph}
	{ match.assign(graph.size(), -1); }

	void addEdge(const T u, const T v, const bool bidirectional = false)
	{
		graph[u].push_back(v);
		if(bidirectional) graph[v].push_back(u);
	}

	T matching(const bool clear = false)
	{
		if(clear) match.assign(graph.size(), -1);
		T matchings = 0;
		bool edited;
		do
		{
			edited = false;
			mark.assign(graph.size(), false);
			for(T i = 0; i < graph.size(); ++i)
				if(match[i] == -1 && !mark[i])
				{
					bool result = dfs(i);
					matchings += result;
					edited |= result;
				}
		} while(edited);
		return matchings;
	}
};
