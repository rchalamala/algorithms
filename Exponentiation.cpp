template<typename T>
T power(T base, T exponent, T modulus = 0)
{
	if(exponent < 0) return (base == 1 ? 1 : 0);
	if(modulus) base %= modulus;
	T result = 1;
	while(exponent)
	{
		if(exponent % 2)
		{
			result *= base;
			if(modulus) result %= modulus;
		}
		base *= base;
		if(modulus) base %= modulus;
		exponent /= 2;
	}
	return (modulus ? result % modulus : result);
}
