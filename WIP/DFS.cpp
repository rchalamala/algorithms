/*
Initialization: DFS<datatype> d(N); // N == amount of vertices
addEdge Operation: d.addEdge(u, v); // u, v == edge vertices
explore Operation: d.explore(source); // source == vertex to start DFS from
getAdjList Operation: d.getAdjList(i); // i == vertex of requested adjacency list // returns adjList[i] vector
getVisited Operation: d.getVisited(); // returns visited vector
*/

template<class T>
class DFS
{
	std::vector<std::vector<T>> adjacencyList;
	std::vector<bool> visited;
public:
	explicit DFS(const T size)
	{ adjacencyList.resize(size); }

	explicit DFS(const std::vector<std::vector<T>> &userAdjacencyList)
	{ adjacencyList = userAdjacencyList; }

	void addEdge(const T u, const T v, bool bidirectional = false)
	{
		adjacencyList[u].push_back(v);
		if (bidirectional) adjacencyList[v].push_back(u);
	}

	void explore(const T source)
	{
		visited.clear();
		visited.resize(adjacencyList.size(), false);
		std::stack<T> s;
		visited[source] = true;
		s.push(source);
		while (!s.empty())
		{
			auto top = s.top();
			s.pop();
			for (auto &neighbor : adjacencyList[top])
				if (!visited[neighbor])
				{
					visited[neighbor] = true;
					s.push(neighbor);
				}
		}
	}

	[[nodiscard]] std::vector<T> getNeighbors() const
	{ return adjacencyList; }

	[[nodiscard]] std::vector<bool> getVisited() const
	{ return visited; }
};

/*
Initialization: DFSwithComponents<datatype> d(N); // N == amount of vertices
addEdge Operation: d.addEdge(u, v); // u, v == edge vertices
explore Operation: d.explore(source); // source == vertex to start DFS from
getAdjList Operation: d.getAdjList(i); // i == vertex of requested adjacency list // returns adjList[i]
getAllComponents Operation: d.getAllComponents(); // returns all components relative to edges added before the most d.explore() // returns components vector
getVisited Operation: d.getVisited(); // returns visited vector
connected Operation: d.connected(u, v) // u, v == edge vertices // returns true if u and v are connected else returns false
*/

template<class T>
class DFSwithComponents
{
	std::vector<std::vector<T>> adjacencyList;
	std::vector<T> components;
	std::vector<bool> visited;
public:
	explicit DFSwithComponents(const T size)
	{ adjacencyList.resize(size); }

	explicit DFSwithComponents(const std::vector<std::vector<T>> &userAdjacencyList)
	{ adjacencyList = userAdjacencyList; }

	void addEdge(const T u, const T v, bool bidirectional = false)
	{
		adjacencyList[u].push_back(v);
		if (bidirectional) adjacencyList[v].push_back(u);
	}

	void explore()
	{
		components.clear();
		components.resize(adjacencyList.size(), 0);
		visited.clear();
		visited.resize(adjacencyList.size(), false);
		T componentNumber = 0;
		for (T i = 0; i < adjacencyList.size(); i++)
			if (!visited[i])
			{
				std::stack<T> s;
				components[i] = componentNumber;
				visited[i] = true;
				s.push(i);
				while (!s.empty())
				{
					auto top = s.top();
					s.pop();
					for (auto &neighbor : adjacencyList[top])
						if (!visited[neighbor])
						{
							components[neighbor] = componentNumber;
							visited[neighbor] = true;
							s.push(neighbor);
						}
				}
				componentNumber++;
			}
	}

	[[nodiscard]] std::vector<T> getNeighbors() const
	{ return adjacencyList; }

	[[nodiscard]] std::vector<T> getComponents() const
	{ return components; }

	[[nodiscard]] std::vector<bool> getVisited() const
	{ return visited; }

	[[nodiscard]] bool connected(const T u, const T v) const
	{ return components[u] == components[v]; }
};
