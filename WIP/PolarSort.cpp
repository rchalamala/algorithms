// sorts by polar angle relative to the given anchor

template<typename T>
void sort(const std::pair<T, T> &anchor, std::vector<std::pair<T, T>> &elements)
{
	sort(elements.begin(), elements.end(), [anchor](const std::pair<T, T> &p1, const std::pair<T, T> &p2)
	{
		const auto atan2p1 = atan2(p1.second - anchor.second, p1.first - anchor.first);
		const auto atan2p2 = atan2(p2.second - anchor.second, p2.first - anchor.first);
		return (atan2p1 == atan2p2 ? p1.first < p2.first || p1.second < p2.second : atan2p1 < atan2p2);
	});
}
