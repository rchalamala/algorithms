/*
Call: gcd(number1, number2); // number1, number2 == numbers to find greatest common divisor of // returns greatest common divisor of number1 and number2
*/

template<typename T>
T euclidsGCD(T a, T b)
{ return (b ? gcd(b, a % b) : a); }

2 6 9
weird
template<typename T>
T steinsGCD(T a, T b)
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

template<typename T>
tuple<T, T, T> extendedEuclidsGCD(T a, T b)
{
	if (b)
	{
		T x, y, g;
		tie(x, y, g) = gcd(b, a % b);
		return {y, x - (a / b) * y, g};
	}
	else return {1, 0, a};
}

/*
Call: isPrime(N); N == number to check primality of // returns number is prime
*/

// needs testing for 2
template <typename T>
bool isPrime(T n)
{
    T count = 0;
    for(T i = 1; i * i <= n; i++)
        if(n % i == 0)
			i * i == n ? count++ : count += 2;
	return count == 2;
}

/*
// Sieve of Eratosthenes
Call: sieve(N) // N == number to return all primes less that or equal to // returns bitset with all primes marked as true and all composites marked as composites
*/

template <typename T>
vector<bool> sieve(T n)
{
	vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(T i = 2; i * i <= n; i++)
         if(isPrime[i])
             for(T j = i * i; j <= n; j += i)
                 isPrime[j] = false;
	return isPrime;
}

/*
// Sieve of Eratosthenes (COMPILE TIME CONSTANT REQUIRED - space-efficient)
Call: sieve<datatype> () // define #MAXN maximum nvalue or const <datatype> MAXN = maximum nvalue or constexpr <datatype> MAXN = maximum nvalue somewhere above the function // returns bitset with all primes marked as 1 and all composites marked as 0
*/

//needs testing
template <typename T>
bitset<MAXN> sieve()
{
	bitset<MAXN> isPrime;
	isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(T i = 2; i * i <= MAXN; i++)
         if(isPrime[i])
             for(T j = i * i; j <= MAXN; j += i)
                 isPrime[j] = false;
	return isPrime;
}

/*
// Sieve of Eratosthenes (kindof, but faster, generates prime factorization, and uses more space) (COMPILE TIME CONSTANT REQUIRED - space-efficient)
Call: sieve<datatype> () // define #MAXN maximum nvalue or const <datatype> MAXN = maximum nvalue or constexpr <datatype> MAXN = maximum nvalue // returns bitset with all primes marked as 1 and all composites marked as 0
*/


// Factors
template <typename T>
vector<pair<T, T>> primeFactors(T n)
{
	vector<pair<T, T>> factors;
	for(T i = 2; i * i <= n; i++)
		if(n % i == 0)
		{
			T count = 0;
			while(n % i == 0)
			{
				count++;
				n /= i;
			}
			factors.emplace_back(i, count);
		}
	if(n > 1) factors.emplace_back(n, 1);
	return factors;
}

// does no evens
template <typename T>
bitset<MAXN> sieve()
{
	bitset<MAXN> isPrime;
	isPrime.set();
    isPrime[0] = isPrime[1] = false;
	isPrime[2] = true;
    for(T i = 3; i * i <= MAXN; i += 2)
         if(isPrime[i])
             for(T j = i * i; j <= MAXN; j += i)
                 isPrime[j] = false;
	return isPrime;
}
