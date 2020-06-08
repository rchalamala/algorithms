/*
Initialization: BFS<datatype> b(N); // N == amount of vertices
addEdge Operation: b.addEdge(u, v); // u, v == edge vertices
explore Operation: b.explore(source); // source == vertex to start BFS from
getAdjList Operation: b.getAdjList(i); // i == vertex of requested adjacency list // returns adjList[i] vector
getVisited Operation: b.getVisited(); // returns visited vector
*/

template<class T>
class BFS
{
	std::vector<std::vector<T>> adjacencyList;
	std::vector<bool> visited;
	std::queue<T> next;
public:
	explicit BFS(const T size)
	{ adjacencyList.resize(size); }

	explicit BFS(const std::vector<std::vector<T>> &userAdjacencyList)
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
		visited[source] = true;
		next.push(source);
		while (!next.empty())
		{
			auto front = next.front();
			next.pop();
			for (const auto &neighbor : adjacencyList[front])
				if (!visited[neighbor])
				{
					visited[neighbor] = true;
					next.push(neighbor);
				}
		}
	}

	[[nodiscard]] std::vector<T> getAdjacencyList() const
	{ return adjacencyList; }

	[[nodiscard]] std::vector<bool> getVisited() const
	{ return visited; }
};

/*
Initialization: BFSwithDepth<datatype> b(N); // N == amount of vertices
addEdge Operation: b.addEdge(u, v); // u, v == edge vertices
explore Operation: b.explore(source); // source == vertex to start BFS from
getAdjList Operation: b.getAdjList(i); // i == vertex of requested adjacency list // returns adjList[i] vector
getAllLevels Operation: b.getAllLevels(); // returns all levels of depth relative to the most recent b.explore() source vertex // returns levels vector
getVisited Operation: b.getVisited(); // returns visited vector
depth Operation: b.depth(u); // u == vertex of requested level // returns levels[u]
*/

template<class T>
class BFSwithDepth
{
	std::vector<std::vector<T>> adjacencyList;
	std::vector<bool> visited;
	std::vector<T> depths;
	std::queue<T> next;
public:
	explicit BFSwithDepth(const T size)
	{ adjacencyList.resize(size); }

	explicit BFSwithDepth(const std::vector<std::vector<T>> &userAdjacencyList)
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
		depths.clear();
		depths.resize(adjacencyList.size());
		visited[source] = true;
		depths[source] = 0;
		next.push(source);
		while (!next.empty())
		{
			auto front = next.front();
			next.pop();
			for (const auto &neighbor : adjacencyList[front])
				if (!visited[neighbor])
				{
					visited[neighbor] = true;
					depths[neighbor] = depths[front] + 1;
					next.push(neighbor);
				}
		}
	}

	[[nodiscard]] std::vector<T> getAdjacencyList() const
	{ return adjacencyList; }

	[[nodiscard]] std::vector<bool> getVisited() const
	{ return visited; }

	[[nodiscard]] std::vector<T> getDepths() const
	{ return depths; }
};
