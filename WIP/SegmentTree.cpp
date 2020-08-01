template<class T>
class SegmentTree
{
	struct Node
	{
		T value, set, delta = 0;
		std::size_t low, high;
		bool validSet = false;
	};
	std::vector<Node> tree;
	const T type;

	T update(const T &left, const T &right)
	{ return type ? type == 1 ? std::min(left, right) : std::max(left, right) : left + right; }

	void propogate(const std::size_t &i)
	{
		if(tree[i].validSet)
		{
			if(tree[i].low != tree[i].high)
			{
				tree[2 * i].set = tree[2 * i + 1].set = tree[i].set;
				tree[2 * i].delta = tree[2 * i + 1].delta = 0;
				tree[2 * i].validSet = tree[2 * i + 1].validSet = true;
			}
			tree[i].value = (type ? 1 : tree[i].high - tree[i].low + 1) * tree[i].set;
			tree[i].set = 0;
			tree[i].validSet = false;
		}
		if(tree[i].delta)
		{
			if(tree[i].low != tree[i].high)
			{
				tree[2 * i].delta += tree[i].delta;
				tree[2 * i + 1].delta += tree[i].delta;
			}
			tree[i].value += (type ? 1 : tree[i].high - tree[i].low + 1) * tree[i].delta;
			tree[i].delta = 0;
		}
	}

	void build(const std::size_t &i, const std::size_t &low, const std::size_t &high, const std::vector<T> &elements)
	{
		tree[i].low = low;
		tree[i].high = high;
		const std::size_t midpoint = low + (high - low) / 2;
		if(low == high)
		{
			tree[i].value = elements[midpoint];
			return;
		}
		build(2 * i, low, midpoint, elements);
		build(2 * i + 1, midpoint + 1, high, elements);
		tree[i].value = update(tree[2 * i].value, tree[2 * i + 1].value);
	}

public:
	explicit SegmentTree(const std::vector<T> &elements, const T &type)
			: type{type}
	{
		tree.resize(4 * elements.size());
		build(1, 0, elements.size() - 1, elements);
	}

	explicit SegmentTree(const std::size_t &size, const T &type)
			: type{type}
	{
		tree.resize(4 * size);
		build(1, 0, size - 1, std::vector<T>(size, 0));
	}

	void change(const std::size_t &low, const std::size_t &high, const T &delta, const bool &set = false, const std::size_t &i = 1)
	{
		propogate(i);
		if(low > tree[i].high || tree[i].low > high) return;
		if(low <= tree[i].low && tree[i].high <= high)
		{
			if(set)
			{
				tree[i].set = delta;
				tree[i].delta = 0;
				tree[i].validSet = true;
			}
			else tree[i].delta = delta;
			propogate(i);
			return;
		}
		change(low, high, delta, set, 2 * i);
		change(low, high, delta, set, 2 * i + 1);
		tree[i].value = update(tree[2 * i].value, tree[2 * i + 1].value);
	}

	T range(const std::size_t &low, const std::size_t &high, const std::size_t &i = 1)
	{
		propogate(i);
		if(low > tree[i].high || tree[i].low > high) return type ? type == 1 ? std::numeric_limits<T>::max() : std::numeric_limits<T>::min() : 0;
		if(low <= tree[i].low && tree[i].high <= high) return tree[i].value;
		return update(range(low, high, 2 * i), range(low, high, 2 * i + 1));
	}
};

template<class T>
class SegmentTree
{
	struct Node
	{
		T value, set, delta = 0;
		bool validSet = false;
	};
	std::vector<Node> tree;
	const std::size_t size, type;

	T update(const T &left, const T &right)
	{ return type ? type == 1 ? std::min(left, right) : std::max(left, right) : left + right; }

	void propogate(const std::size_t &i, const std::size_t &treeLeft, const std::size_t &treeRight, const std::size_t &midpoint)
	{
		if(tree[i].validSet)
		{
			if(treeLeft != treeRight)
			{
				tree[i + 1].set = tree[i + 2 * (midpoint - treeLeft + 1)].set = tree[i].set;
				tree[i + 1].delta = tree[i + 2 * (midpoint - treeLeft + 1)].delta = 0;
				tree[i + 1].validSet = tree[i + 2 * (midpoint - treeLeft + 1)].validSet = true;
			}
			tree[i].value = (type ? 1 : treeRight - treeLeft + 1) * tree[i].set;
			tree[i].set = 0;
			tree[i].validSet = false;
		}
		if(tree[i].delta)
		{
			if(treeLeft != treeRight)
			{
				tree[i + 1].delta += tree[i].delta;
				tree[i + 2 * (midpoint - treeLeft + 1)].delta += tree[i].delta;
			}
			tree[i].value += (type ? 1 : treeRight - treeLeft + 1) * tree[i].delta;
			tree[i].delta = 0;
		}
	}

	void build(const std::size_t &i, const std::size_t &left, const std::size_t &right, const std::vector<T> &elements)
	{
		const std::size_t midpoint = left + (right - left) / 2;
		if(left == right)
		{
			tree[i].value = elements[midpoint];
			return;
		}
		build(i + 1, left, midpoint, elements);
		build(i + 2 * (midpoint - left + 1), midpoint + 1, right, elements);
		tree[i].value = update(tree[i + 1].value, tree[i + 2 * (midpoint - left + 1)].value);
	}

	void change(const std::size_t i, const std::size_t treeLeft, const std::size_t treeRight, const std::size_t &left, const std::size_t &right, const T &delta, const bool &set)
	{
		const std::size_t midpoint = treeLeft + (treeRight - treeLeft) / 2;
		propogate(i, treeLeft, treeRight, midpoint);
		if(left > treeRight || treeLeft > right) return;
		if(left <= treeLeft && treeRight <= right)
		{
			if(set)
			{
				tree[i].set = delta;
				tree[i].delta = 0;
				tree[i].validSet = true;
			}
			else tree[i].delta = delta;
			propogate(i, treeLeft, treeRight, midpoint);
			return;
		}
		change(i + 1, treeLeft, midpoint, left, right, delta, set);
		change(i + 2 * (midpoint - treeLeft + 1), midpoint + 1, treeRight, left, right, delta, set);
		tree[i].value = update(tree[i + 1].value, tree[i + 2 * (midpoint - left + 1)].value);
	}

	T range(const std::size_t i, const std::size_t treeLeft, const std::size_t treeRight, const std::size_t &left, const std::size_t &right)
	{
		const std::size_t midpoint = treeLeft + (treeRight - treeLeft) / 2;
		propogate(i, treeLeft, treeRight, midpoint);
		if(left > treeRight || treeLeft > right) return type ? type == 1 ? std::numeric_limits<T>::max() : std::numeric_limits<T>::min() : 0;
		if(left <= treeLeft && treeRight <= right) return tree[i].value;
		return update(range(i + 1, treeLeft, midpoint, left, right), range(i + 2 * (midpoint - treeLeft + 1), midpoint + 1, treeRight, left, right));
	}

public:
	explicit SegmentTree(const std::vector<T> &elements, const std::size_t &type)
			: size{elements.size()}, type{type}
	{
		tree.resize(2 * elements.size());
		build(1, 0, elements.size() - 1, elements);
	}

	explicit SegmentTree(const std::size_t &size, const std::size_t &type)
			: size{size}, type{type}
	{
		tree.resize(2 * size);
		build(1, 0, size - 1, std::vector<T>(size, 0));
	}

	void change(const std::size_t &left, const std::size_t &right, const T &delta, const bool &set = false)
	{ change(1, 0, size - 1, left, right, delta, set); }

	T range(const std::size_t &left, const std::size_t &right)
	{ return range(1, 0, size - 1, left, right); }

	T range(const std::size_t &index)
	{ return range(1, 0, size - 1, index, index); }
};
