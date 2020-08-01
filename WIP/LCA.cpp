template<typename T>
class LCA
{
	struct Node
	{ T value, low, high; };
	vector<Node> tree;
	vector<T> heights, euler, first;

	void dfs(T i, T parent, const vector<vector<T>>& children, T height = 0)
	{
		heights[i] = height;
		first[i] = euler.size();
		euler.push_back(i);
		for(auto& child : children[i])
			if(child != parent)
			{
				dfs(child, i, children, height + 1);
				euler.push_back(i);
			}
	}

	T index(T left, T right)
	{ return heights[left] < heights[right] ? left : right; }

	void build(T i, T low, T high)
	{
		tree[i].low = low;
		tree[i].high = high;
		T midpoint = low + (high - low) / 2;
		if(low == high)
		{
			tree[i].value = euler[midpoint];
			return;
		}
		build(2 * i, low, midpoint);
		build(2 * i + 1, midpoint + 1, high);
		tree[i].value = index(tree[2 * i].value, tree[2 * i + 1].value);
	}

	T query(T i, T low, T high)
	{
		if(low > tree[i].high || tree[i].low > high) return -1;
		if(low <= tree[i].low && tree[i].high <= high) return tree[i].value;
		T left = query(2 * i, low, high);
		T right = query(2 * i + 1, low, high);
		if(left == -1) return right;
		if(right == -1) return left;
		return index(left, right);
	}
public:
	explicit LCA(const vector<vector<T>>& children, T root = 0)
	{
		heights.resize(children.size()); euler.reserve(2 * children.size()); first.resize(children.size());
		dfs(root, root, children);
		tree.resize(4 * euler.size());
		build(1, 0, euler.size() - 1);
	}

	T lca(T u, T v)
	{
		T left = first[u];
		T right = first[v];
		return query(1, min(left, right), max(left, right));
	}

	T distance(T u, T v)
	{ return heights[u] + heights[v] - 2 * heights[lca(u, v)]; }

};
