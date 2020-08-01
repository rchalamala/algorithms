template<class T>
class SegmentIntersection
{
	bool inside(const T &a, const T &b, const T &c)
	{ return a <= b && b <= c; }

	T orientation(const std::pair<T, T> &p1, const std::pair<T, T> &p2, const std::pair<T, T> &p3)
	{ return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first); }

	bool onSegment(const pair<T, T> &p1, const pair<T, T> &p2, const pair<T, T> &p3)
	{ return inside(std::min(p1.ff, p2.ff), p3.ff, std::max(p1.ff, p2.ff)) && inside(std::min(p1.ss, p2.ss), p3.ss, std::max(p1.ss, p2.ss)); }

public:
	bool intersects(const pair<pair<T, T>, pair<T, T>> &p1, const pair<pair<T, T>, pair<T, T>> &p2)
	{
		vector<T> orientations{orientation(p2.ff, p2.ss, p1.ff, orientation(p2.ff, p2.ss, p1.ss), orientation(p1.ff, p1.ss, p2.ff), orientation(p1.ff, p1.ss, p2.ss)};
		return (orientations[0] > 0 && orientations[1] < 0 || orientations[0] < 0 && orientations[1] > 0) && (orientations[2] > 0 && orientations[3] < 0 || orientations[2] < 0 && orientations[3] > 0) || !orientations[0] && onSegment(p2.ff, p2.ss, p1.ff) || !orientations[1] && onSegment(p2.ff, p2.ss, p1.ss) || !orientations[2] && onSegment(p1.ff, p1.ss, p2.ff) || !orientations[3] && onSegment(p1.ff, p1.ss, p2.ss);
	}
};
