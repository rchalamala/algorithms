/*
ID: rchalam1
LANG: C++11
TASK:
*/
// For train.usaco.org, fill the template above.

// Competitive Coding Template

// GCC OPTIMIAZTION FLAGS
#ifndef LOCAL
#pragma GCC optimize("fast-math,no-stack-protector,Ofast,omit-frame-pointer,unroll-loops,inline")
#pragma GCC option("arch=native,no-zero-upper,tune=native")
#pragma GCC target("abm,avx,avx2,bmi2,fma,mmx,popcnt,sse,sse2,sse3,sse4,ssse3")
#endif

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <thread>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#include <x86intrin.h>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<typename T> using ordered_set = __gnu_pbds::tree<T,
														  __gnu_pbds::null_type,
														  std::less<T>,
														  __gnu_pbds::rb_tree_tag,
														  __gnu_pbds::tree_order_statistics_node_update>;

using ui = unsigned int;
using ul = unsigned long long;
using ll = long long;
using ld = long double;
using cd = std::complex<long double>;

using pui = std::pair<unsigned int, unsigned int>;
using pii = std::pair<int, int>;
using pul = std::pair<unsigned long long, unsigned long long>;
using pll = std::pair<long long, long long>;
using pld = std::pair<long double, long double>;
using pcd = std::pair<std::complex<long double>, std::complex<long double>>;

using vui = std::vector<unsigned int>;
using vii = std::vector<int>;
using vul = std::vector<unsigned long long>;
using vll = std::vector<long long>;
using vld = std::vector<long double>;
using vcd = std::vector<std::complex<long double>>;

using vpui = std::vector<std::pair<unsigned int, unsigned int>>;
using vpii = std::vector<std::pair<int, int>>;
using vpul = std::vector<std::pair<unsigned long long, unsigned long long>>;
using vpll = std::vector<std::pair<long long, long long>>;
using vpld = std::vector<std::pair<long double, long double>>;
using vpcd = std::vector<std::pair<std::complex<long double>, std::complex<long double>>>;

#define FOR(i, a, b) for (auto (i) = (a); (i) < (b); ++(i))
#define F0R(i, a) FOR((i), 0, (a))
#define ROF(i, a, b) for (auto (i) = (a); (i) >= (b); --(i))
#define R0F(i, a) ROF((i), (a), 0)
#define ITR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define FSRT(set) std::sort((set).begin(),(set).end())
#define RSRT(set) std::sort((set).rbegin(),(set).rend())
#define CSRT(set, function) std::sort((set).begin(),(set).end(), (function))
#define UNIQUE(set) std::sort((set).begin(), (set).end()), (set).erase(std::unique((set).begin(), (set.end())), (a).end())

#define ALL(set) (set).begin(), (set).end()
#define RALL(set) (set).rbegin(), (set).rend()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

// https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/CppIO.h
namespace std
{

	std::string to_string(const char& element)
	{
		return std::string(1, element);
	}

	std::string to_string(const char* element)
	{
		return std::string(element);
	}

	std::string to_string(const std::string& element)
	{
		return element;
	}

	std::string to_string(const bool& element)
	{
#ifdef LOCAL
		return element ? "true" : "false";
#else
		return std::string{static_cast<char>('0'+element)};
#endif
	}

	template<typename T>
	std::string to_string(const std::complex<T>& element)
	{
		std::stringstream convert;
		convert << element;
		return convert.str();
	}

	std::string to_string(const std::vector<bool>& elements)
	{
		std::string convert = "{";
		for (const auto& element : elements) convert += static_cast<char>('0' + element);
		return convert + "}";
	}

	template<std::size_t Size>
	std::string to_string(const std::bitset<Size>& elements)
	{
		std::string convert;
		for (auto i = 0; i < Size; ++i) convert += static_cast<char>('0' + elements[i]);
		return convert;
	}

	template<typename T1, typename T2>
	std::string to_string(std::pair<T1, T2> element)
	{
#ifdef LOCAL
		return "(" + std::to_string(element.first) + ", " + std::to_string(element.second) + ")";
#else
		return std::to_string(element.ff) + " " + std::to_string(element.ss);
#endif
	}

	template<typename T>
	std::string to_string(const T& elements)
	{
		std::string convert;
		bool first = true;
#ifdef LOCAL
		convert += "{";
		for (const auto& element : elements)
		{
			if (!first) convert += ", ";
			first = false;
			convert += std::to_string(element);
		}
		convert += "}";
#else
		for (const auto& element : elements) {
			if (!first) convert += " ";
			first = false;
			convert += std::to_string(element);
		}
#endif
		return convert;
	}
}

// Modified version of bqi343's IO
namespace io
{

// INPUT

	template<typename Arg, typename... Args> void read(Arg& first, Args& ... rest);
	template<typename T1, typename T2> void read(std::pair<T1, T2>& element);
	template<typename T, std::size_t Size> void read(std::array<T, Size>& elements);
	template<typename T> void read(double& element);
	template<typename T> void read(long double& element);
	template<typename T> void read(std::complex<T>& element);
	template<typename T> void read(std::vector<T>& elements);
	template<typename T> void read(T& element);

	template<typename Arg, typename... Args>
	void read(Arg& first, Args& ... rest)
	{
		read(first);
		read(rest...);
	}

	template<typename T1, typename T2>
	void read(std::pair<T1, T2>& element)
	{
		read(element.first, element.second);
	}

	template<typename T, std::size_t Size>
	void read(std::array<T, Size>& elements)
	{
		for (auto& element : elements) read(element);
	}

	void read(double& element)
	{
		std::string convert;
		read(convert);
		element = std::stod(convert);
	}

	void read(long double& element)
	{
		std::string convert;
		read(convert);
		element = std::stold(convert);
	}

	template<typename T>
	void read(std::complex<T>& element)
	{
		T first, second;
		read(first, second);
		element = std::complex<T>(first, second);
	}

	template<typename T>
	void read(std::vector<T>& elements)
	{
		for (auto& element : elements) read(element);
	}

	template<typename T>
	void read(T& element)
	{
		std::cin >> element;
	}

// OUTPUT

	template<typename Arg, typename... Args> void print(const Arg& first, const Args& ... rest);
	template<typename Arg, typename... Args> void prints(const Arg& first, const Args& ... rest);
	template<typename T> void print(const T& element);
	void prints();

	template<typename Arg, typename... Args>
	void print(const Arg& first, const Args& ... rest)
	{
		print(first);
		print(rest...);
	}

	template<typename Arg, typename... Args>
	void prints(const Arg& first, const Args& ... rest)
	{
		print(first);
		if (sizeof...(rest)) print(" ");
		prints(rest...);
	}

	template<typename T>
	void print(const T& element)
	{
		std::cout << std::to_string(element);
	}

	void prints()
	{
		print('\n');
	}

// fast/file IO

	void setIO(std::ifstream& readFile, std::ofstream& writeFile, const std::string& name = "", bool stdIO = false)
	{
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		std::cin.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
		if (!name.empty() && !stdIO)
		{
			readFile.open(name + ".in");
			if (readFile.fail()) return;
			writeFile.open(name + ".out");
			std::cin.rdbuf(readFile.rdbuf());
			std::cout.rdbuf(writeFile.rdbuf());
		}
	}
}
using namespace io;

// https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/CppIO.h
namespace debug
{
	template<typename Arg, typename... Args> void DBG(const Arg& first, const Args& ... rest);
	void DBG();

	template<typename Arg, typename... Args>
	void DBG(const Arg& first, const Args& ... rest)
	{
		std::cerr << std::to_string(first);
		if (sizeof...(rest)) std::cerr << ", ";
		DBG(rest...);
	}

	void DBG()
	{
		std::cerr << "]" << std::endl;
	}

#ifdef LOCAL
#define dbg(...) std::cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
}
using namespace debug;

// To time program, create object Timer to start timing, and call Timer.elapsed().
class Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
public:
	Timer()
			:m_start(std::chrono::high_resolution_clock::now())
	{
	}

	void reset()
	{
		m_start = std::chrono::high_resolution_clock::now();
	}

	long double elapsed() const
	{
		return std::chrono::duration_cast<std::chrono::duration<long double, std::ratio<1> >>(
				std::chrono::high_resolution_clock::now() - m_start).count();
	}
};

// https://codeforces.com/blog/entry/62393
struct chash
{
	static std::uint64_t splitmix64(std::uint64_t x)
	{
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30ULL)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27ULL)) * 0x94d049bb133111eb;
		return x ^ (x >> 31ULL);
	}

	size_t operator()(std::uint64_t x) const
	{
		static const std::uint64_t
				FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch()
				.count());
		return splitmix64(x + FIXED_RANDOM);
	}

	size_t operator()(std::pair<std::uint64_t, std::uint64_t> x) const
	{
		static const std::uint64_t
				FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch()
				.count());
		return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1ULL);
	}
};

namespace rng
{
	std::mt19937& getPRNG()
	{
		static std::mt19937
				PRNG(
				std::chrono::duration_cast<std::chrono::nanoseconds>(
						std::chrono::steady_clock::now().time_since_epoch())
						.count());
		return PRNG;
	}

	template<typename T>
	T getUID(const T& low, const T& high)
	{
		return std::uniform_int_distribution<T>(low, high)(getPRNG());
	}

	template<typename T>
	T getURD(const T& low, const T& high)
	{
		return std::uniform_real_distribution<T>(low, high)(getPRNG());
	}

}
using namespace rng;

// Defines MAXN value
constexpr long long MAXN __attribute__((unused)) = static_cast<long long>(2 * 1e5 + 1);
// Defines INFINITE Value
constexpr long long INF __attribute__((unused)) = static_cast<long long>(1e18 + 1);
// Defines Modulus
constexpr long long MOD __attribute__((unused)) = static_cast<long long>(1e9 + 7);
// Defines Floating Point Correction
constexpr long double EPS __attribute__((unused)) = static_cast<long double>(1e-7);

//*****
//START CODE BELOW
//*****

void solve()
{

}

int main(int argc __attribute__((unused)), char* argv[] __attribute__((unused)))
{
	static std::ifstream readFile;
	static std::ofstream writeFile;
	setIO(readFile, writeFile);
	int T = 1;
	std::cin >> T;
	while (T--) solve();
	return 0;
}
