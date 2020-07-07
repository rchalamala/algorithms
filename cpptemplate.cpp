/*
ID: rchalam1
LANG: C++14
TASK:
*/
// For train.usaco.org, fill the template above.

// Competitive Coding Template

// GCC OPTIMIAZTION FLAGS
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

/*
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
*/
// All Includes for Competitive Coding Template

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = std::vector<int>;
using vll = std::vector<long long>;
using vull = std::vector<unsigned long long>;

#define FOR(i, a, b) for (auto i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (auto i = (a); i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)
#define ITR(a, x) for (auto& a: x)

#define FSRT(set) sort((set).begin(),(set).end())
#define RSRT(set) sort((set).rbegin(),(set).rend())
#define CSRT(set, function) sort((set).begin(),(set).end(), (function))
#define TRS(set) sort((set).begin(),(set).end(), greater<>())
#define REV(set) reverse((set).begin(),(set).end());

#define CNT(set, target) count((set).begin(),(set).end(),target)
#define FFND(set, target) find((set).begin(),(set).end(),target)
#define RFND(set, target) rfind((set).begin(),(set).end(),target)

#define WRAP(set) (set).begin(), (set).end()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

// For stdio, call setIO() or setIO("").
void setIO(std::ifstream &readFile, std::ofstream &writeFile, const std::string &name = "", bool stdIO = false)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	if (!name.empty() && !stdIO)
	{
		readFile.open(name + ".in");
		if (readFile.fail()) return;
		writeFile.open(name + ".out");
		std::cin.rdbuf(readFile.rdbuf());
		std::cout.rdbuf(writeFile.rdbuf());
	}
}

// To time program, create object Timer  to start timing, and call Timer.elapsed().
#include <chrono>

class Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> m_beg;
public:
	Timer() : m_beg(std::chrono::high_resolution_clock::now())
	{}

	void reset()
	{ m_beg = std::chrono::high_resolution_clock::now(); }

	[[nodiscard]] long double elapsed() const
	{ return std::chrono::duration_cast<std::chrono::duration<long double, std::ratio<1> >>(std::chrono::high_resolution_clock::now() - m_beg).count(); }
};

// Defines datatype
using dt = int;
// Defines MAXN value
constexpr dt MAXN = std::numeric_limits<dt>::max();
// Defines Modulus
constexpr dt MOD = 1e9 + 7;
// Defines Floating Point Correction
constexpr long double EPS = 1e-9;

//*****
//START CODE BELOW
//*****


int main(int argc, char *argv[])
{
	static std::ifstream read;
	static std::ofstream write;
	setIO(read, write, "");
	dt t;
	cin >> t;
	while (t--)
	{
		dt n;
		cin >> n;

	}
}
