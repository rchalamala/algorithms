/*
Initialization: DFS<datatype> d(N); // N == amount of vertices
addEdge Operation: d.addEdge(u, v); // u, v == edge vertices
explore Operation: d.explore(source); // source == vertex to start DFS from
getAdjList Operation: d.getAdjList(i); // i == vertex of requested adjacency list // returns adjList[i] vector
getVisited Operation: d.getVisited(); // returns visited vector
*/

template <class T>
class DFS
{
	const T n;
	vector<T> adjList;
	vector<bool> visited;
public:
	DFS(const T size)
	: n{size}
	{
		adjList.resize(size);
	}
	void addEdge(const T u, const T v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void explore(const T source)
	{
		visited.clear();
		visited.resize(n, false);
		stack<T> s;
		visited[source] = true;
		s.push(source);
		while (!s.empty())
		{
			auto top = s.top();
			s.pop();
			for(auto neighbor = adjList[top].end(); neighbor != adjList[top].begin(); neighbor--)
				if(!visited[neighbor])
				{
					visited[neighbor] = true;
					s.push(neighbor);
				}
		}
	}
	vector<T> getAdjList(const T index) { return adjList[index]; }
	vector<bool> getVisited() { return visited; }
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
template <class T>
class DFSwithComponents
{
	const T n;
	vector<T> adjList, components;
	vector<bool> visited;
public:
	DFSwithComponents(const T size) : n{size} {	adjList.resize(size); }
	void addEdge(const T u, const T v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void explore()
	{
		components.clear();
		components.resize(n);
		visited.clear();
		visited.resize(n, false);
		T componentNumber = 0;
		for(auto& node : adjList)
		{
			if(!visited[node])
			{
				stack<T> s;
				components[node] = componentNumber;
				visited[node] = true;
				s.push(node);
				while (!s.empty())
				{
					auto top = s.top();
					s.pop();
					for(auto neighbor = adjList[top].end(); neighbor != adjList[top].begin(); neighbor--)
						if(!visited[neighbor])
						{
							components[neighbor] = componentNumber;
							visited[neighbor] = true;
							s.push(neighbor);
						}
				}
				componentNumber++;
			}
		}
	}
	vector<T> getAdjList(const T index) { return adjList[index]; }
	vector<T> getAllComponents() { return components; }
	vector<bool> getVisited() { return visited; }
	bool connected(const T u, const T v) { return components[u] == components[v]; }
};
