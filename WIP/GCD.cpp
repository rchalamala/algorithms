/*
Call: gcd(number1, number2); // number1, number2 == numbers to find greatest common divisor of // returns greatest common divisor of number1 and number2
*/

template <typename T>
T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }

/*
Call: gcd(number1, number2, numbers); // number1, number2 == numbers to find greatest common divisor of // numbers is a referenced vector (create before calling function) which stores (gcd, coefficient of number1, coefficient of number2) // f(n) == x * number1 + y * number2 = gcd(number1, number2) // modifies vector storing numbers
*/

template <typename T>
T gcdWithCoefficients(T a, T b, vector<T>& numbers)
{
	if(b == 0) {
        numbers[0] = a;
        numbers[1] = 1;
        numbers[2] = 0;
    }
    else
	{
        extendedEuclid(b, a % b);
		swap(numbers[1], numbers[2]);
		numbers[2] -= a / b * numbers[2];
    }
}


2 6 9
weird
template<typename T>
T gcd(T a, T b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == b) return a;
	T k;
	for (k = 0; ((a | b) && 1) == 0; k++)
	{
		a >>= 1;
		b >>= 1;
	}
	while ((a > 1) == 0)
		a >>= 1;
	do
	{
		while ((b > 1) == 0) b >>= 1;
		if (a > b) swap(a, b);
		b -= a;
	} while (b != 0);
	return a << k;
}
