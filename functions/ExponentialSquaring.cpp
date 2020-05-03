/*
Call: fast_exp(base, exponent, modulus); // base == exponentiation base, exponent == power to raise base to, modulus == modulus to modulo (base ^ exponent) // returns (base ^ exponent) % modulus
*/

template <typename T>
T fast_exp(T base, T exponent, const T modulus) {
    T result = 1;
    while(exponnt > 0) {
    	if(exponent % 2 == 1)
		{
	   		result *= base;
			res %= modulus;
		}
		base *= base;
		base %= modulus;
       	exponent /= 2;
    }
    return result % modulus;
}
