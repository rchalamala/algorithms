template <typename T>
void sort(vector<T>& elements)
{
	priority_queue<T> pq;
	for(auto& element : elements) pq.push(-element);
	T i = 0;
	while(!pq.empty())
	{
		elements[i++] = -pq.top();
		pq.pop();
	}
}

// use with unsigned numbers
template<typename T>
void sort(vector<T> &elements)
{
	priority_queue<T, vector<T>, greater<T>> pq;
	for (auto &element : elements) pq.push(element);
	T i = 0;
	while (!pq.empty())
	{
		elements[i++] = pq.top();
		pq.pop();
	}
}
