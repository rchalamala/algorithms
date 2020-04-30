/*
Initialization: BFS<datatype> b(N); // N == amount of vertices
addEdge Operation: b.addEdge(u, v); // u, v == edge vertices
explore Operation: b.explore(source); // source == vertex to start BFS from
getAdjList Operation: b.getAdjList(i); // i == vertex of requested adjacency list // returns adjList[i]
getVisited Operation: b.getVisited(); // returns visited vector
*/

template <class T>
class BFS
{
	T n;
	vector<T> adjList;
	vector<bool> visited;
public:
	BFS(const T size) : n{size} { adjList.resize(size); }
	void addEdge(const T u, const T v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void explore(const T source)
	{
		visited.clear();
		visited.resize(n, false);
		queue<T> q;
		visited[source] = true;
		q.push_back(source);
		while(!q.empty())
		{
			auto front = q.front();
			q.pop_front();
			for(auto& neighbor : adjList[front])
				if(!visited[neighbor])
				{
					visited[neighbor] = true;
					q.push_back(neighbor);
				}
		}
	}
	vector<T> getAdjList(const T index) { return adjList[index]; }
	vector<bool> getVisited() { return visited; }
};

/*
Initialization: BFSwithDepth<datatype> b(N); // N == amount of vertices
addEdge Operation: b.addEdge(u, v); // u, v == edge vertices
explore Operation: b.explore(source); // source == vertex to start BFS from
getAdjList Operation: b.getAdjList(i); // i == vertex of requested adjacency list // returns adjList[i]
getLevels Operation: b.getLevels(); // returns levels of depth relative to the most recent b.explore() source vertex
getVisited Operation: b.getVisited(); // returns visited vector
*/

template <class T>
class BFSwithDepth
{
	T n;
	vector<T> adjList, levels;
	vector<bool> visited;
public:
	BFSwithDepth(const T size) : n{size} { adjList.resize(size); }
	void addEdge(const T u, const T v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void explore(const T source)
	{
		levels.clear();
		levels.resize(n);
		visited.clear();
		visited.resize(n, false);
		queue<T> q;
		levels[source] = 0;
		visited[source] = true;
		q.push_back(source);
		while(!q.empty())
		{
			auto front = q.front();
			q.pop_front();
			for(auto& neighbor : adjList[front])
				if(!visited[neighbor])
				{
					levels[neighbor] = levels[front] + 1;
					visited[neighbor] = true;
					q.push_back(neighbor);
				}
		}
	}
	vector<T> getAdjList(const T index) { return adjList[index]; }
	vector<T> getLevels() { return levels; }
	vector<bool> getVisited() { return visited; }
};
