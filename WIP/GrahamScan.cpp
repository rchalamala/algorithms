template <class T>
class GrahamScan
{
	pair<T, T> anchor;
	T minimum = 0;
	map<pair<T, T>, bool> used;
	void polarSort(vector<pair<T, T>>& elements)
	{
		sort(elements.begin(), elements.end(), [&] (const pair<T, T>& p1, const pair<T, T>& p2)
		{
			auto atan2p1 = atan2(p1.second - anchor.second, p1.first - anchor.first);
			auto atan2p2 = atan2(p2.second - anchor.second, p2.first - anchor.first);
			return (atan2p1 == atan2p2 ? p1.first < p2.first || p1.second < p2.second : atan2p1 < atan2p2);
		});
	}
	T orientation(const pair<T, T>& p1, const pair<T, T>& p2, const pair<T, T>& p3)
	{
		return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
	}
	pair<T, T> secondInStack(stack<pair<T, T>>& hull)
	{
		auto currentTop = hull.top();
		hull.pop();
		auto secondTop = hull.top();
		hull.push(currentTop);
		return secondTop;
	}
public:
	stack<pair<T, T>> findConvexHull(vector<pair<T, T>> coordinates)
	{
		stack<pair<T, T>> hull;
		used[coordinates[0]] = true;
		for(T i = 1; i < coordinates.size(); i++)
		{
			if(used[coordinates[i]])
			{
				coordinates.erase(coordinates.begin() + i--);
				continue;
			}
			used[coordinates[i]] = true;
			if (coordinates[i].second < coordinates[minimum].second || coordinates[i].second == coordinates[minimum].second && coordinates[i].first < coordinates[minimum].first)
				minimum = i;
		}
		if(coordinates.size() < 3) return hull;
		anchor = coordinates[minimum];
		coordinates.erase(coordinates.begin() + minimum);
		polarSort(coordinates);
		hull.push(anchor); hull.push(coordinates[0]);
		for(T i = 1; i < coordinates.size(); i++)
		{
			while(hull.size() > 1 && orientation(secondInStack(hull), hull.top(), coordinates[i]) <= 0)
				hull.pop();
			hull.push(coordinates[i]);
		}
		return hull;
	}
};
