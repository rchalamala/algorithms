/*
Call: checkprime(N); N == number to check primality of // returns number is prime
*/

template <typename T>
bool checkprime(T n)
{
    T count = 0;
    for(T i = 1; i * i <= n; i++)
        if(n % i == 0)
			i * i == n ? count++ : count += 2;
	return count == 2 ? true : false;
}

/*
// Sieve of Eratosthenes
Call: sieve(N) // N == number to return all primes less that or equal to // returns bitset with all primes marked as true and all composites marked as composites
*/

template <typename T>
vector<bool> sieve()
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
