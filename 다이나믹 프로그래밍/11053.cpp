/*
	11053 가장 긴 증가하는 부분 수열

	수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 문제
	예시
	수열 A = {10, 20, 30, 20, 50}
	가장 긴 증가하는 부분 수열 A = {10_, 20_, 10, 30_, 20, 50_}

	D[i] = A[1], ..., A[i]까지 수열이 있을 때,
	A[i]을 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이
	D[i]는 A[i]이 반드시 포함되어야 한다.
	가장 긴 부분 수열이 A[?], A[?], ..., A[j], A[i]라고 했을 때,
	겹치는 부분 문제를 찾아보자.

	A[?], A[?], ..., A[j]는 D[j]로 나타낼 수 있다.
	(A[j]을 마지막으로 하는 부분 수열이기 때문)
	그럼 A[j]와 A[i]간의 관계를 생각해보자.
	A[j] < A[i]가 되어야 한다. (증가하는 부분 수열이 되어야 하기 때문)

	for (int i=0; i<n; i++) {
		d[i] = 1;
		for (int j=0; j<i; j++) {
			if (a[j] < a[i] && d[i] < d[j]+1) {
				d[i] = d[j]+1;
			}
		}
	}

	정답은 D[1], ..., D[N]중의 최대값이 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}

	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}