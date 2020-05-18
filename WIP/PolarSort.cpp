// sorts by polar angle relative to the given anchor

template <typename T>
void polarSort(pair<T, T> anchor, vector<pair<T, T>>& elements)
{
	sort(elements.begin(), elements.end(), [&] (const pair<T, T>& p1, const pair<T, T>& p2)
	{
		auto atan2p1 = atan2(p1.second - anchor.second, p1.first - anchor.first);
		auto atan2p2 = atan2(p2.second - anchor.second, p2.first - anchor.first);
		return (atan2p1 == atan2p2 ? p1.first < p2.first || p1.second < p2.second : atan2p1 < atan2p2);
	});
}
