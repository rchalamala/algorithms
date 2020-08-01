template<typename T>
vector<vector<T>> multiply(vector<vector<T>> &m1, const vector<vector<T>> &m2)
{
	m1 =
			{
					{
							m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0],
							m1[0][0] * m2[1][0] + m1[0][1] * m2[1][1]
					},
					{
							m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0],
							m1[1][0] * m2[1][0] + m1[1][1] * m2[1][1]
					}
			};
}

template<typename T>
vector<vector<T>> multiply(vector<vector<T>> &m1, const vector<vector<T>> &m2, const T &modulus)
{
	m1 =
			{
					{
							(((m1[0][0] * m2[0][0]) % modulus) + (m1[0][1] * m2[1][0]) % modulus) % modulus,
							(((m1[0][0] * m2[1][0]) % modulus) + (m1[0][1] * m2[1][1]) % modulus) % modulus
					},
					{
							(((m1[1][0] * m2[0][0]) % modulus) + (m1[1][1] * m2[1][0]) % modulus) % modulus,
							(((m1[1][0] * m2[1][0]) % modulus) + (m1[1][1] * m2[1][1]) % modulus) % modulus
					}
			};
}

template<typename T>
void multiply(vector<vector<T>> &m1, const vector<vector<T>> &m2)
{
	vector<vector<T>> matrix(m1.size(), vector<T>(m2[0].size(), 0));
	for(std::size_t i = 0; i < m1.size(); ++i)
		for(std::size_t j = 0; j < m2[0].size(); ++j)
			for(std::size_t k = 0; k < m2.size(); ++k)
				matrix[i][j] += (m1[i][k] * m2[k][j];
	m1 = matrix;
}

template<typename T>
void multiply(vector<vector<T>> &m1, const vector<vector<T>> &m2, const T &modulus)
{
	vector<vector<T>> matrix(m1.size(), vector<T>(m2[0].size(), 0));
	for(std::size_t i = 0; i < m1.size(); ++i)
		for(std::size_t j = 0; j < m2[0].size(); ++j)
			for(std::size_t k = 0; k < m2.size(); ++k)
				(matrix[i][j] += (m1[i][k] * m2[k][j]) % modulus) %= modulus;
	m1 = matrix;
}
