// not sure if this exists already, couldn't find anything
// all code to test also

/*
ID:
LANG: C++14
TASK:
*/
// For train.usaco.org, fill the template above.

// Competitive Coding Template

// GCC OPTIMIAZTION FLAGS
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

// freopen generates warnings in Visual Studio
#define VISUALSTUDIO

using ll = long long;
using ull = unsigned long long;

using vi = std::vector<int>;
using vll = std::vector<long long>;
using vull = std::vector<unsigned long long>;

#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
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

#define mp make_pair
#define pb push_back
#define eb emplace_back

// For stdio, call setIO() or setIO("").
#ifdef VISUALSTUDIO

void setIO(const std::string &name = "")
{
	std::ifstream fin;
	std::ofstream fout;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	if (!name.empty())
	{
		fin.open(name + ".in");
		fout.open(name + ".out");
		std::cin.rdbuf(fin.rdbuf());
		std::cout.rdbuf(fout.rdbuf());
	}
}

#endif
#ifndef VISUALSTUDIO

void setIO(const std::string name = "")
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	if (!name.empty())
	{
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

#endif

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
typedef int dt;
// Defines MAXN value
constexpr dt MAXN = 1000000000;
// Defines Modulus
constexpr dt MOD = 1000000007;

//*****
//START CODE BELOW
//*****

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

template <typename T>
void csort(std::vector<T>& elements)
{
	auto minmax = std::minmax_element(elements.begin(), elements.end());
	T min = * minmax.first, max = *minmax.second;
	std::vector<T> auxilary(max - min + 1, 0);
	for(auto& elem : elements)
		auxilary[elem - min]++;
	T key = 0;
	for(T value = 0; value <= max - min; value++)
		while(auxilary[value]--)
			elements[key++] = value + min;
}


template <typename T>
T partition (std::vector<T>& elements, T l, T r) {
	T i = l + 1;
	T pivot = elements[l] ;
	for(int j = l + 1; j <= r; j++)
	{
		if (elements[j] < pivot)
		{
			std::swap(elements[i], elements[j]);
			i++;
		}
	}
	std::swap(elements[l], elements[i - 1]);
	return i - 1;
}

template <typename T>
void qsort(std::vector<T>& elements, T l, T r)
{
	if (l < r)
	{
		T pivot = partition(elements, l, r);
		qsort(elements, l, pivot - 1);
		qsort(elements, pivot + 1, r);
	}
}

/*
template <typename T>
void bsort(std::vector<T>& elements)
{
	T max = 1;
	for(auto& element : elements)
	{
		max = std::max(max, static_cast<T>(floor(log10(abs(element)))) + 1);
	}
	vector<vector<T>> buckets(max);
	for(auto& element : elements)
	{
		if(element) buckets[floor(log10(abs(element)))].push_back(element);
		else buckets[0].push_back(0);
	}
	for(auto& bucket : buckets)
		qsort<T>(bucket, 0, bucket.size() - 1); //std::sort(bucket.begin(), bucket.end());
	vector<T> newelements;
	/*for(auto& bucket : buckets)
	{
		T offset = 0;
		for (auto &element : bucket)
		{
			if (element >= 0) newelements.push_back(element);
			else newelements.insert(newelements.begin() + offset++, element);
		}
	}
	elements = newelements;
    * /
}
int main()
{
	//setIO();
	srand(time(nullptr));
	//vector<dt> as{10, 120, 1, 120, 3, 23, 25, 2, 3, 23, 23, 239, 8};
	dt t, n; cin >> t >> n;
	while(t--)
	{
		vector<dt> as(n);
		bool positive = true;
		for(auto& a : as)
		{
			a = rand() % n * (positive ? 1 : -1);
			positive = !positive;
		}
		auto as1 = as, as2 = as, as3 = as, as4 = as;
		//ITR(a, as) cout << a << ' ';
		cout << '\n';
		Timer time1;
		bsort<dt>(as1);
		cout << time1.elapsed() << " : sort() \n";
		Timer time2;
		qsort<dt>(as2, 0, as2.size() - 1);
		cout << time2.elapsed() << " : qsort() \n";
		Timer time3;
		std::sort(as3.begin(), as3.end());
		cout << time3.elapsed() << " : std::sort() \n";
		Timer time4;
		std::stable_sort(as4.begin(), as4.end());
		cout << time4.elapsed() << " : std::stable_sort()\n\n";
	}
	return 1;
}
 */

template <typename T>
void bsort(std::vector<T>& elements)
{
	auto minmax = std::minmax_element(elements.begin(), elements.end());
	T negative = *minmax.first < 0 ? static_cast<T>(floor(log10(abs(*minmax.first)))) + 1 : 0;
	T positive = *minmax.second > 0 ? static_cast<T>(floor(log10(*minmax.second))) + 1 : 0;
	T zeroCount = 0;
	vector<vector<T>> negatives(negative), positives(positive);
	for(auto& element : elements)
	{
		if(element > 0) positives[floor(log10(element))].push_back(element);
		else if(element < 0) negatives[floor(log10(abs(element)))].push_back(element);
		else zeroCount++;
	}
	for(auto& bucket : negatives)
		std::sort(bucket.begin(), bucket.end()); // csort(bucket); //qsort<T>(bucket, 0, bucket.size() - 1);
	for(auto& bucket : positives)
		std::sort(bucket.begin(), bucket.end()); // csort(bucket); //qsort<T>(bucket, 0, bucket.size() - 1);
	vector<T> newelements(zeroCount, 0);
	for(auto& bucket : negatives)
		newelements.insert(newelements.begin(), bucket.begin(), bucket.end());
	for(auto& bucket : positives)
		newelements.insert(newelements.end(), bucket.begin(), bucket.end());
	elements = newelements;
}

int main()
{
	//setIO();
	dt t, n; cin >> t >> n;
	std::uniform_int_distribution die{0, n};
	while(t--)
	{
		vector<dt> as(n);
		bool positive = true;
		for(auto& a : as)
		{
			a = die(mersenne);
			positive = !positive;
		}
		auto as1 = as, as2 = as, as3 = as, as4 = as, as5 = as;
		Timer time1;
		csort<dt>(as1);
		cout << time1.elapsed() << " : csort() \n";
		/*
		if(!is_sorted(as1.begin(), as1.end()))
		{
			ITR(a, as1) cout << a << ' ';
			return -1;
		}
		*/
		Timer time2;
		bsort<dt>(as2);
		cout << time2.elapsed() << " : sort() \n";
		Timer time3;
		qsort<dt>(as3, 0, as3.size() - 1);
		cout << time3.elapsed() << " : qsort() \n";
		Timer time4;
		std::sort(as4.begin(), as4.end());
		cout << time4.elapsed() << " : std::sort() \n";
		Timer time5;
		std::stable_sort(as5.begin(), as5.end());
		cout << time5.elapsed() << " : std::stable_sort()\n\n";
	}
}

/*
ID:
LANG: C++14
TASK:
*/
// For train.usaco.org, fill the template above.

// Competitive Coding Template

// GCC OPTIMIAZTION FLAGS
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

// freopen generates warnings in Visual Studio
#define VISUALSTUDIO

using ll = long long;
using ull = unsigned long long;

using vi = std::vector<int>;
using vll = std::vector<long long>;
using vull = std::vector<unsigned long long>;

#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
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

#define mp make_pair
#define pb push_back
#define eb emplace_back

// For stdio, call setIO() or setIO("").
#ifdef VISUALSTUDIO

void setIO(const std::string &name = "")
{
	std::ifstream fin;
	std::ofstream fout;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	if (!name.empty())
	{
		fin.open(name + ".in");
		fout.open(name + ".out");
		std::cin.rdbuf(fin.rdbuf());
		std::cout.rdbuf(fout.rdbuf());
	}
}

#endif
#ifndef VISUALSTUDIO

void setIO(const std::string name = "")
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	if (!name.empty())
	{
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

#endif

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
typedef int dt;
// Defines MAXN value
constexpr dt MAXN = 1000000000;
// Defines Modulus
constexpr dt MOD = 1000000007;

//*****
//START CODE BELOW
//*****

std::mt19937 mersenne{static_cast<std::mt19937::result_type>(chrono::high_resolution_clock::now().time_since_epoch().count())};

template <typename T>
void ssort(std::vector<T>& elements)
{
	T minimum;
	for (T i = 0; i < elements.size() - 1; i++)
	{
		minimum = i;
		for (T j = i + 1; j < elements.size(); j++)
			if (elements[j] < elements[minimum])
				minimum = j;
		std::swap(elements[i], elements[minimum]);
	}
}

template<typename T>
void csort(std::vector<T> &elements)
{
	auto minmax = std::minmax_element(elements.begin(), elements.end());
	T min = *minmax.first, max = *minmax.second;
	std::vector<T> auxilary(max - min + 1, 0);
	for (auto &elem : elements)
		auxilary[elem - min]++;
	T key = 0;
	for (T value = 0; value <= max - min; value++)
		while (auxilary[value]--)
			elements[key++] = value + min;
}


template<typename T>
T partition(std::vector<T> &elements, T l, T r)
{
	T i = l + 1;
	T pivot = elements[l];
	for (int j = l + 1; j <= r; j++)
	{
		if (elements[j] < pivot)
		{
			std::swap(elements[i], elements[j]);
			i++;
		}
	}
	std::swap(elements[l], elements[i - 1]);
	return i - 1;
}

template<typename T>
void qsort(std::vector<T> &elements, T l, T r)
{
	if (l < r)
	{
		T pivot = partition(elements, l, r);
		qsort(elements, l, pivot - 1);
		qsort(elements, pivot + 1, r);
	}
}

template<typename T>
void bsort(std::vector<T> &elements)
{
	auto minmax = std::minmax_element(elements.begin(), elements.end());
	T negative = *minmax.first < 0 ? static_cast<T>(floor(log10(abs(*minmax.first)))) + 1 : 0;
	T positive = *minmax.second > 0 ? static_cast<T>(floor(log10(*minmax.second))) + 1 : 0;
	T zeroCount = 0;
	vector<vector<T>> negatives(negative), positives(positive);
	for (auto &element : elements)
	{
		if (element > 0) positives[floor(log10(element))].push_back(element);
		else if (element < 0) negatives[floor(log10(abs(element)))].push_back(element);
		else zeroCount++;
	}
	for (auto &bucket : negatives)
		qsort<T>(bucket, 0, bucket.size() - 1);
	for (auto &bucket : positives)
		qsort<T>(bucket, 0, bucket.size() - 1);
	vector<T> newelements(zeroCount, 0);
	for (auto &bucket : negatives)
		newelements.insert(newelements.begin(), bucket.begin(), bucket.end());
	for (auto &bucket : positives)
		newelements.insert(newelements.end(), bucket.begin(), bucket.end());
	elements = newelements;
}
/*
int main()
{
	//setIO();
	dt t, n;
	cin >> t >> n;
	std::uniform_int_distribution die{0, n};
	while (t--)
	{
		vector<dt> as(n);
		bool positive = true;
		for (auto &a : as)
		{
			// a = die(mersenne);
			a = mersenne() % n;
			positive = !positive;
		}
		const auto asc = as;
		as = asc;
		Timer time1;
		csort<dt>(as);
		cout << time1.elapsed() << " : csort() \n";
		/*
		if(!is_sorted(as1.begin(), as1.end()))
		{
			ITR(a, as1) cout << a << ' ';
			return -1;
		}
		as = asc;
		Timer time2;
		bsort<dt>(as);
		cout << time2.elapsed() << " : sort() \n";
		as = asc;
		Timer time3;
		ssort<dt>(as);
		cout << time3.elapsed() << " : ssort() \n";
		as = asc;
		Timer time4;
		qsort<dt>(as, 0, as.size() - 1);
		cout << time4.elapsed() << " : qsort() \n";
		as = asc;
		Timer time5;
		std::sort(as.begin(), as.end());
		cout << time5.elapsed() << " : std::sort() \n";
		as = asc;
		Timer time6;
		std::stable_sort(as.begin(), as.end());
		cout << time6.elapsed() << " : std::stable_sort()\n\n";
	}
}
*/

int main(int argc, char* argv[])
{
	dt n; cin >> n;
	vector<dt> as(n);
	ITR(number, as) cin >> number;
	cout << '\n';
	const auto asc = as;
	as = asc;
	Timer time1;
	csort<dt>(as);
	cout << time1.elapsed() << " : csort() \n";
	as = asc;
	Timer time2;
	bsort<dt>(as);
	cout << time2.elapsed() << " : sort() \n";
	/*
	as = asc;
	Timer time3;
	ssort<dt>(as);
	cout << time3.elapsed() << " : ssort() \n";
	*/
	as = asc;
	Timer time4;
	qsort<dt>(as, 0, as.size() - 1);
	cout << time4.elapsed() << " : qsort() \n";
	as = asc;
	Timer time5;
	std::sort(as.begin(), as.end());
	cout << time5.elapsed() << " : std::sort() \n";
	as = asc;
	Timer time6;
	std::stable_sort(as.begin(), as.end());
	cout << time6.elapsed() << " : std::stable_sort()\n\n";
}
