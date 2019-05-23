/*
	1978 소수 찾기
	입력으로 주어지는 N개의 소수 주에서 소수가 몇 개 인지 구하는 문제
*/

#include <iostream>
using namespace std;

bool is_prime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (is_prime(num)) {
			cnt += 1;
		}
	}

	cout << cnt << '\n';
	return 0;
}