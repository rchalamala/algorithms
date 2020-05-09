/*
Initialization: UnionFind<datatype> uf(N); // N == amount of vertices
qunion Operation: uf.qunion(u, v); // u, v == edge vertices
qfind Operation: uf.qfind(u, v); // u, v == edge vertices // returns u and v are connected
*/

template <class T>
class UnionFind
{
	vector<T> parents, sizes;
	T root(T i)
	{
		while(i != parents[i])
		{
			parents[i] = parents[parents[i]];
			i = parents[i];
		}
		return i;
	}
public:
	QuickUnion(const T size)
	{
		parents.resize(size);
		iota(parents.begin(), parents.end(), 0);
		sizes.resize(size, 1);
	}
	void qunion(const T u, const T v)
	{
		T i = root(u);
		T j = root(v);
		if(i == j) return;
		if(sizes[i] >= sizes[j])
		{
			parents[j] = i;
			sizes[i] += sizes[j];
		}
		else
		{
			parents[i] = j;
			sizes[j] += sizes[i];
		}
	}
	T qfind(const T u, const T v) { return root(u) == root(v); }
};
