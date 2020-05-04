/*
ID:
LANG: C++14
TASK:
*/
//For train.usaco.org, fill the template above.

//Competitive Coding Template

#include <bits/stdc++.h>
using namespace std;

//freopen generates warnings in Visual Studio
#define VISUALSTUDIO

using ll = long long;
using ull = unsigned long long;

using vi = std::vector<int>;
using vll = std::vector<long long>;
using vull = std::vector<unsigned long long>;

#define FOR(i,a,b) for (auto i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (auto i = (b); i > (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define SRT(set) sort((set).begin(),(set).end())
#define SRTF(set,function) sort((set).begin(),(set).end(),function)
#define TRS(set) sort((set).begin(),(set).end(),greater<>())
#define REV(set) reverse((set).begin(),(set).end());

#define CNT(set, target) count((set).begin(),(set).end(),target)
#define FND(set,target) find((set).begin(),(set).end(),target)
#define RFND(set,target) rfind((set).begin(),(set).end(),target)

#define pb push_back
#define eb emplace_back

//For stdio, call setIO() or setIO("").
#ifdef VISUALSTUDIO
void setIO(const std::string name = "")
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	if (!name.empty())
	{
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
#else
std::ifstream fin;
std::ofstream fout;
void setIO(const std::string name = "")
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	if (!name.empty())
	{
		fin.open(name + ".in");
		fout.open(name + ".out");
		std::cin.rdbuf(fin.rdbuf());
		std::cout.rdbuf(fout.rdbuf());
	}
}
#endif

//To time program, create object Timer  to start timing, and call Timer.elapsed().
#include <chrono>
class Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> m_beg;
public:
	Timer() : m_beg(std::chrono::high_resolution_clock::now()) {}
	void reset() { m_beg = std::chrono::high_resolution_clock::now(); }
	[[nodiscard]] double elapsed() const { return std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1> >>(std::chrono::high_resolution_clock::now() - m_beg).count(); }
};

//*****
//START CODE BELOW
//*****

int main(int argc, char argv[])
{
	setIO();
}
