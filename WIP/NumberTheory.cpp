template<typename T>
T euclidsGCD(T a, T b)
{ return (b ? gcd(b, a % b) : a); }

template<typename T>
T euclidsGCD(T a, T b)
{
	while(b) tie(a, b) = std::make_tuple(b, a % b);
	return a;
}

template<typename T>
tuple<T, T, T> extendedEuclidsGCD(T a, T b)
{
	T x = 1, y = 0, x1 = 0, y1 = 1;
	while(b)
	{
		T quotient = a / b;
		tie(x, x1) = make_tuple(x1, x - quotient * x1);
		tie(y, y1) = make_tuple(y1, y - quotient * y1);
		tie(a, b) = make_tuple(b, a - quotient * b);
	}
	return {x, y, a};
}

template<typename T>
tuple<T, T, T> extendedEuclidsGCD(T a, T b)
{
	if(!a) return {0, 1, b};
	T x, y, gcd;
	tie(x, y, gcd) = extendedEuclidsGCD(b % a, a);
	return {y - b / a * x, x, gcd};
}

template<typename T>
T modularMultiplicativeInverse(T b, T modulus)
{
	T x, y, gcd;
	tie(x, y, gcd) = extendedEuclidsGCD(b, modulus);
	if(gcd != 1) return -1;
	return (x % modulus + modulus) % modulus;
}

template<typename T>
T modularDivision(T a, T b, T modulus)
{
	a %= modulus;
	T answer = modularMultiplicativeInverse<T>(b, modulus);
	return answer == -1 ? -1 : (answer * a) % modulus;
}

template <typename T>
bool isPrime(T n)
{
	if(n <= 1) return false;
	if(n <= 3) return true;
	if(n % 2 == 0 || n % 3 == 0) return false;
	for(std::size_t i = 5; i * i <= n; i += 6)
		if(n % i == 0)
			return false;
	return true;
}

template <typename T>
vector<bool> sieve(T n)
{
	vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
	for(std::size_t i = 4; i <= n; i += 2)
		isPrime[i] = false;
    for(std::size_t i = 2; i * i <= n; ++i)
         if(isPrime[i])
             for(std::size_t j = i * i; j <= n; j += i)
                 isPrime[j] = false;
	return isPrime;
}

template<typename T>
vector<pair<T, T>> primeFactors(T n)
{
	vector<pair<T, T>> factors;
	for(std::size_t i = 2; i * i <= n; ++i)
		if(n % i == 0)
		{
			T count = 0;
			while(n % i == 0)
			{
				++count;
				n /= i;
			}
			factors.emplace_back(i, count);
		}
	if(n > 1) factors.emplace_back(n, 1);
	return factors;
}
