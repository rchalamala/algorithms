/*
Initialization: QuickUnion<datatype> q(N); // N == amount of vertices
Union Operation: q.qunion(u, v); // u, v == edge vertices
Find Operation: q.find(u, v); // u, v == edge vertices // returns true if u and v are connected else returns false
*/

template <class T>
class QuickUnion
{
	vector<T> parents, sizes;
	int root(T i)
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
		parents.resize(size, 0);
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
