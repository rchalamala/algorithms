/*
Call: editDistance<numeric datatype>(start, end) // start, end == strings to find edit distance of // returns edit distance of two strings
*/

template<typename T>
T editDistance(string start, string end)
{
	vector<vector<T>> dp(start.size() + 1, vector<T>(end.size() + 1, 0));
	for(T i = 0; i <= start.size(); i++)
		for(T j = 0; j <= end.size(); j++)
		{
			if(i == 0) dp[i][j] = j;
			else if(j == 0) dp[i][j] = i;
			else dp[i][j] = min(dp[i - 1][j - 1] + (start[i - 1] != end[j - 1]), min(dp[i - 1][j], dp[i][j - 1]) + 1);
		}
	return dp[start.size()][end.size()];
}
