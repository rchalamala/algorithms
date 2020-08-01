std::size_t editDistance(const std::string &start, const std::string &end)
{
	std::vector<std::vector<std::size_t>> table(start.size() + 1, std::vector<std::size_t>(end.size() + 1, 0));
	for(std::size_t i = 0; i <= start.size(); ++i) table[i][0] = i;
	for(std::size_t i = 0; i <= end.size(); ++i) table[0][i] = i;
	for(std::size_t i = 1; i <= start.size(); ++i)
		for(std::size_t j = 1; j <= end.size(); ++j)
			table[i][j] = std::min(table[i - 1][j - 1] + (start[i - 1] != end[j - 1]), std::min(table[i - 1][j], table[i][j - 1]) + 1);
	return table[start.size()][end.size()];
}
