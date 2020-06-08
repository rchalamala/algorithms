template<typename T>
T wrappingKadanes(const std::vector<T> &elements)
{
	T total = 0, positive = 0, positiveMax = 0, negative = 0, negativeMax = 0;
	for (const auto &element : elements)
	{
		total += element;
		positive = std::max(positive + element, element);
		negative = std::max(negative - element, -element);
		positiveMax = std::max(positiveMax, positive);
		negativeMax = std::max(negativeMax, negative);
	}
	return std::max(positiveMax, total + negativeMax);
}

template<typename T>
T kadanes(const std::vector<T> &elements)
{
	T current = 0, currentMax = 0;
	for (const auto &element : elements)
	{
		current = std::max(current + element, element);
		currentMax = std::max(currentMax, current);
	}
	return currentMax;
}
