template<typename T>
T binary_exp(T base, T exp)
{
	T res = 1;
	while(exp)
	{
		if(exp & 1)
		{
			res *= base;
			exp--;
		}
		else
		{
			base *= base;
			exp /= 2;
		}
	}
	return res;
}
