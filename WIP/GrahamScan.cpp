template<class T>
class GrahamScan
{
	std::pair<T, T> anchor;
	std::stack<std::pair<T, T>> hull;

	void sort(std::vector<std::pair<T, T>> &elements)
	{
		std::sort(elements.begin(), elements.end(), [&](const std::pair<T, T> &p1, const std::pair<T, T> &p2)
		{
			const auto atan2p1 = atan2(p1.second - anchor.second, p1.first - anchor.first);
			const auto atan2p2 = atan2(p2.second - anchor.second, p2.first - anchor.first);
			return (atan2p1 == atan2p2 ? p1.first < p2.first || p1.second < p2.second : atan2p1 < atan2p2);
		});
	}

	T orientation(const std::pair<T, T> &p1, const std::pair<T, T> &p2, const std::pair<T, T> &p3)
	{ return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first); }

	std::pair<T, T> secondInStack()
	{
		auto currentTop = hull.top();
		hull.pop();
		auto secondTop = hull.top();
		hull.push(currentTop);
		return secondTop;
	}

public:
	std::stack<std::pair<T, T>> find(std::vector<std::pair<T, T>> coordinates)
	{
		std::map<std::pair<T, T>, bool> inHull;
		T minimum = 0;
		inHull[coordinates[0]] = true;
		for(T i = 1; i < coordinates.size(); ++i)
		{
			if(inHull[coordinates[i]])
			{
				coordinates.erase(coordinates.begin() + i--);
				continue;
			}
			inHull[coordinates[i]] = true;
			if(coordinates[i].second < coordinates[minimum].second || coordinates[i].second == coordinates[minimum].second && coordinates[i].first < coordinates[minimum].first)
				minimum = i;
		}
		if(coordinates.size() < 3) return hull;
		anchor = coordinates[minimum];
		coordinates.erase(coordinates.begin() + minimum);
		sort(coordinates);
		hull.push(anchor);
		hull.push(coordinates[0]);
		for(T i = 1; i < coordinates.size(); ++i)
		{
			while(hull.size() > 1 && orientation(secondInStack(), hull.top(), coordinates[i]) <= 0)
				hull.pop();
			hull.push(coordinates[i]);
		}
		return hull;
	}
};
