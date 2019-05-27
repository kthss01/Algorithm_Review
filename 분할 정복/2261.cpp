/*
	2261 가장 가까운 두 점

	2차원 평면 위의 N개의 점 중에서 가장 가까운 두 점을 찾는 문제
	2 <= N <= 100,000

	먼저 점을 x좌표가 증가하는 순서로 정렬한다.
	중간에 있는 점을 찾는다.
	중간에 있는 점을 기준으로 왼쪽과 오른쪽으로 나눈다.
	왼쪽: Pl
	오른쪽: Pr

	Pl에서 가장 가까운 두 점을 찾고
	Pr에서 가장 가까운 두 점을 찾는다.

	Pl에서 가장 가까운 두 점 Dl
	Pr에서 가장 가까운 두 점 Dr

	d = min(Dl, Dr)
	이라고 했을 때
	가운데 점으로부터
	가운데로부터 -d, +d 만큼
	떨어진 곳에서 가장 가까운 두 점을 찾아야 한다.

	한 점당
	살펴봐야 하는 점의 개수는 6개이다.
*/

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	bool operator < (const Point &v) const {
		if (x == v.x) {
			return y < v.y;
		}
		else {
			return x < v.x;
		}
	}
};

bool cmp(const Point &u, const Point &v) {
	return u.y < v.y;
}

int dist(Point p1, Point p2) {
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int brute_force(vector<Point> &a, int x, int y) {
	int ans = -1;
	for (int i = x; i <= y - 1; i++) {
		for (int j = i + 1; j <= y; j++) {
			int d = dist(a[i], a[j]);
			if (ans == -1 || ans > d) {
				ans = d;
			}
		}
	}
	return ans;
}

int closest(vector<Point> &a, int x, int y) {
	int n = y - x + 1;
	if (n <= 3) {
		return brute_force(a, x, y);
	}
	int mid = (x + y) / 2;
	int left = closest(a, x, mid);
	int right = closest(a, mid + 1, y);
	int ans = min(left, right);
	vector<Point> b;
	for (int i = x; i <= y; i++) {
		int d = a[i].x - a[mid].x;
		if (d*d < ans) {
			b.push_back(a[i]);
		}
	}
	sort(b.begin(), b.end(), cmp);
	int m = b.size();
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			int y = b[j].y - b[i].y;;
			if (y*y < ans) {
				int d = dist(b[i], b[j]);
				if (d < ans) {
					ans = d;
				}
			}
			else {
				break;
			}
		}
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a.begin(), a.end());
	printf("%d\n", closest(a, 0, n - 1));
	return 0;
}