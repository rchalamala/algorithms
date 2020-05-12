// replaces BinaryExponentiation.cpp and ExponentialSquaring.cpp

template<typename T>
T exponentiation(T base, T exponent, T modulus = 0)
{
	T result = 1;
	while(exponent)
	{
		if(exponent & 1)
		{
			result *= base;
			if(modulus) result %= modulus;
		}
		base *= base;
		if(modulus) base %= modulus;
		exponent /= 2;
	}
	return result;
}
