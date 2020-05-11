/*

*/

template <class T>
class Dijkstra
{
	vector<vector<pair<T, T>>> adjList;
	vector<bool> visited;
	priority_queue< pair<T, T>, vector <pair<T, T>> , greater<pair<T, T>> > pq;
	vector<T> cost, parents;
public:
	Dijkstra(const T size)
	{
		adjList.resize(size);
		cost.resize(size, numeric_limits<T>::max());
		parents.resize(size, numeric_limits<T>::max());
	}
	void addEdge(const T u, const T v, const T w) { adjList[u].emplace_back(v, w); }
	pair<T, T> explore(T source, T destination)
	{
		visited.clear();
		visited.resize(adjList.size(), false);
		cost.clear();
		cost.resize(adjList.size(), numeric_limits<T>::max());
		parents.clear();
		parents.resize(adjList.size(), numeric_limits<T>::max());
		cost[source] = 0;
		pq.push(make_pair(cost[source], source));
		parents[source] = 0;
		while (!pq.empty())
		{
			T top = pq.top().second;
			pq.pop();
			visited[top] = true;
			for(auto& neighbor : adjList[top])
				if (!visited[neighbor.first] && cost[neighbor.first] > cost[top] + neighbor.second)
				{
					cost[neighbor.first] = cost[top] + neighbor.second;
					pq.push(make_pair(cost[neighbor.first], neighbor.first));
					parents[neighbor.first] = top;
				}
		}
		return make_pair(parents[destination], cost[destination]);
	}
	vector<T> getAdjList(const T index) { return adjList[index]; }
	vector<T> getCost() { return cost; }
	vector<T> getParents() { return parents; }
	vector<bool> getVisited() { return visited; }
};
