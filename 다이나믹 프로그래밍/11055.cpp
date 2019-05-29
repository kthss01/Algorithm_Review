/*
	11055 가장 큰 증가하는 부분 수열

	수열 A가 주어졌을 때, 
	그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 문제

	D[i] = A[1], ..., A[i]까지 수열이 있을 때,
	A[i]을 마지막으로 하는 가장 큰 증가하는 부분 수열의 합

	for (int i=0; i<n; i++) {
		d[i] = a[i];
		for (int j=0; j<i; j++) {
			if (a[j] < a[i] && d[i] < d[j]+a[i]) {
				d[i] = d[j]+a[i];
			}
		}
	}
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
		d[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + a[i] > d[i]) {
				d[i] = d[j] + a[i];
			}
		}
	}
	int ans = *max_element(d.begin(), d.end());
	cout << ans << '\n';
	return 0;
}