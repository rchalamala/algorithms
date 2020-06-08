template<typename T>
void sort(std::vector<T> &elements)
{
	std::priority_queue<T, std::vector<T>, std::greater<T>> next;
	for (const auto &element : elements) next.push(element);
	T i = 0;
	while (!next.empty())
	{
		elements[i++] = next.top();
		next.pop();
	}
}
