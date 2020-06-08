template <typename T>
vector<T> failureFunction(const string& pattern)
{
	vector<T> pi(pattern.size(), 0);
	for(T j = 1; j < pattern.size(); ++j)
	{
		T i = pi[j - 1];
		while(i && pattern[i] != pattern[j])
			i = pi[i - 1];
		pi[j] = pattern[i] == pattern[j] ? i + 1 : i;
	}
	return pi;
}

template<typename T>
vector<T> patternMatching(const string& text, const string& pattern)
{
	vector<T> indices, pi = failureFunction<T>(pattern);

	return indices;
}

template<typename T>
vector<T> patternMatching(const string& text, const string& pattern)
{
	vector<T> indices, pi = failureFunction<T>(pattern);
	T i = 0, j = 0;
	while(i < text.size())
	{
		if(text[i] == pattern[j]) i++, j++;
		if(j == pattern.size())
		{
			indices.push_back(i - j);
			j = pi[j - 1];
		}
		else if(i < text.size() && text[i] != pattern[j]) j ? j = pi[j - 1] : i++;
	}
	return indices;
}
