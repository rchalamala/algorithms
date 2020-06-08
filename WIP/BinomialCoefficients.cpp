template<typename T>
T choose(T n, T k)
{ return (k ? n * choose(n - 1, k - 1) / k : 1); }

template<typename T>
std::vector<std::vector<T>> pascalsTriangle()
{
	std::vector<std::vector<T>> triangle(MAXN, vector<T>(MAXN));
	triangle[0][0] = 1;
	for (T i = 1; i < MAXN; ++i)
	{
		triangle[i][0] = triangle[i][i] = 1;
		for (T j = 1; j < i + 1; ++j)
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
	}
	return triangle;
}
