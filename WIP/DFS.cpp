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
	vector<vector<T>> adjList;
	vector<bool> visited;
public:
	DFS(const T size) { adjList.resize(size); }
	void addEdge(const T u, const T v) { adjList[u].push_back(v); }
	void explore(const T source)
	{
		visited.clear();
		visited.resize(adjList.size(), false);
		stack<T> s;
		visited[source] = true;
		s.push(source);
		while (!s.empty())
		{
			auto top = s.top();
			s.pop();
			for(auto& neighbor : adjList[top])
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
	vector<vector<T>> adjList;
	vector<T> components;
	vector<bool> visited;
public:
	DFSwithComponents(const T size) { adjList.resize(size); }
	void addEdge(const T u, const T v) { adjList[u].push_back(v); }
	void explore()
	{
		components.clear();
		components.resize(adjList.size(), 0);
		visited.clear();
		visited.resize(adjList.size(), false);
		T componentNumber = 0;
		for(T i = 0; i < adjList.size(); i++)
			if(!visited[i])
			{
				stack<T> s;
				components[i] = componentNumber;
				visited[i] = true;
				s.push(i);
				while (!s.empty())
				{
					auto top = s.top();
					s.pop();
					for(auto& neighbor : adjList[top])
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
	vector<T> getAdjList(const T index) { return adjList[index]; }
	vector<T> getAllComponents() { return components; }
	vector<bool> getVisited() { return visited; }
	bool connected(const T u, const T v) { return components[u] == components[v]; }
};
