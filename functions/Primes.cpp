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
Call: sieve(N) // N == number to return all primes less that or equal to // returns bool vector of all numbers less that or equal to N stating if the afformentioned number is prime
*/

template <typename T>
vector<bool> sieve(T n)
{
	vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(T i = 2; i * i <= n; i++)
         if(isPrime[i])
             for(T j = i * i; j <= n; j += i)
                 isPrime[j] = false;
	return isPrime;
}
