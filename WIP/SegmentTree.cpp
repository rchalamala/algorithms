template<class T>
class SegmentTree
{
	struct Node
	{ T value, delta = 0, low, high; };
	std::vector<Node> tree;
	const T type, infinity;
public:
	SegmentTree(const std::vector<T>& elements, const T& userType)
	: type{userType}, infinity{std::numeric_limits<T>::max()}
	{
		tree.resize(4 * elements.size());
		build(1, 0, elements.size() - 1, elements);
	}

	void sum(const T& i)
	{ tree[i].value = tree[2 * i].value + tree[2 * i].delta + tree[2 * i + 1].value + tree[2 * i + 1].delta; }

	void minimum(const T& i)
	{ tree[i].value = std::min(tree[2 * i].value + tree[2 * i].delta, tree[2 * i + 1].value + tree[2 * i + 1].delta); }

	void maximum(const T& i)
	{ tree[i].value = std::max(tree[2 * i].value + tree[2 * i].delta, tree[2 * i + 1].value) + tree[2 * i + 1].delta; }

	void update(const T& i)
	{ type ? type == 1 ? minimum(i) : maximum(i) : sum(i); }

	void propogate(const T& i)
	{
		tree[2 * i].delta += tree[i].delta;
		tree[2 * i + 1].delta += tree[i].delta;
		tree[i].delta = 0;
	}

	void build(const T& i, const T& low, const T& high, const std::vector<T>& elements)
	{
		tree[i].low = low;
		tree[i].high = high;
		const T midpoint = low + (high - low) / 2;
		if(low == high)
		{
			tree[i].value = elements[midpoint];
			return;
		}
		build(2 * i, low, midpoint, elements);
		build(2 * i + 1, midpoint + 1, high, elements);
		update(i);
	}

	void change(const T& i, const T& low, const T& high, const T& value)
	{
		if(low > tree[i].high || tree[i].low > high) return;
		if(low <= tree[i].low && tree[i].high <= high)
		{
			tree[i].delta += value;
			return;
		}
		propogate(i);
		change(2 * i, low, high, value);
		change(2 * i + 1, low, high, value);
		update(i);
	}

	[[nodiscard]] T range(const T& i, const T& low, const T& high)
	{
		if(low > tree[i].high || tree[i].low > high) return type ? type == 1 ? infinity : -infinity : 0;
		if(low <= tree[i].low && tree[i].high <= high) return tree[i].value + tree[i].delta * (tree[i].high - tree[i].low + 1);
		propogate(i);
		const T left = range(2 * i, low, high), right = range(2 * i + 1, low, high);
		update(i);
		return type ? type == 1 ? std::min(left, right) : std::max(left, right) : left + right;
	}
};
