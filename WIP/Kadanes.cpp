template<typename T>
T wrappingKadanes(const std::vector<T> &elements)
{
	T total = 0, positive = 0, positiveAnswer = 0, negative = 0, negativeAnswer = 0;
	for (const auto &element : elements)
	{
		total += element;
		positive = std::max(positive + element, element);
		negative = std::max(negative - element, -element);
		positiveAnswer = std::max(positiveAnswer, positive);
		negativeAnswer = std::max(negativeAnswer, negative);
	}
	return std::max(positiveAnswer, total + negativeAnswer);
}

template<typename T>
T kadanes(const std::vector<T> &elements)
{
	T current = 0, answer = 0;
	for (const auto &element : elements)
	{
		current = std::max(current + element, element);
		answer = std::max(answer, current);
	}
	return answer;
}
