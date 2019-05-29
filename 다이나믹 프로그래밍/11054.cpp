/*
	11054 가장 긴 바이토닉 부분 수열

	가장 긴 증가하는 부분 수열(D)과 
	가장 긴 감소하는 부분 수열(D2)를 구한 다음

	D[i] + D2[i] - 1이 가장 큰 값을 찾으면 된다
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
	vector<int> d2(n);
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		d2[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j] && d2[j] + 1 > d2[i]) {
				d2[i] = d2[j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < d[i] + d2[i] - 1) {
			ans = d[i] + d2[i] - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}