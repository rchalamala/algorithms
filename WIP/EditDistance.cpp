/*
Call: editDistance<numeric datatype>(start, end) // start, end == strings to find edit distance of // returns edit distance of two strings
*/

template<typename T>
T editDistance(const std::string &start, const std::string &end)
{
	std::vector<std::vector<T>> editDistanceTable(start.size() + 1, std::vector<T>(end.size() + 1, 0));
	for (T i = 0; i <= start.size(); i++)
		for (T j = 0; j <= end.size(); j++)
		{
			if (!i) editDistanceTable[i][j] = j;
			else if (!j) editDistanceTable[i][j] = i;
			else editDistanceTable[i][j] = min(editDistanceTable[i - 1][j - 1] + (start[i - 1] != end[j - 1]), min(editDistanceTable[i - 1][j], dp[i][j - 1]) + 1);
		}
	return editDistanceTable[start.size()][end.size()];
}
