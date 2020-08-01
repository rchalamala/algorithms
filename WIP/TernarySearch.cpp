template <typename T>
T ternarySearch(vector<T>& elements, const T target, T low, T high)
{
	while(low <= high)
	{
		T lowMid = low + (high - low) / 3;
		T highMid = high - (high - low) / 3;
		if(elements[lowMid] == target)
			return lowMid;
		if(elements[highMid] == target)
			return highMid;
		if(elements[lowMid] > target)
			high = lowMid - 1;
		else if(elements[highMid] < target)
			low = highMid + 1;
		else
		{
			low = lowMid + 1;
			high = highMid - 1;
		}
	}
	return -1;
}
