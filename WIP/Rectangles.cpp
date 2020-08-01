template<typename T>
T area(const std::pair<std::pair<T, T>, std::pair<T, T>> &pair)
{ return std::abs(pair.second.first - pair.first.first) * std::abs(pair.second.second - pair.first.second); }

template<typename T>
std::pair<std::pair<T, T>, std::pair<T, T>> intersection(const std::pair<std::pair<T, T>, std::pair<T, T>> &p1, const std::pair<std::pair<T, T>, std::pair<T, T>> &p2)
{
	std::pair<std::pair<T, T>, std::pair<T, T>> answer;
	answer.first.first = std::max(p1.first.first, p2.first.first);
	answer.first.second = std::max(p1.first.second, p2.first.second);
	answer.second.first = std::min(p1.second.first, p2.second.first);
	answer.second.second = std::min(p1.second.second, p2.second.second);
	if(answer.first.first > answer.second.first || answer.first.second > answer.second.second) return std::make_pair(std::make_pair(0, 0), std::make_pair(0, 0));
	return answer;
}
