/*
	2004 조합 0의 개수

	nCm의 0의 개수를 구하는 문제

	팩토리얼은 2의 개수가 5의 개수보다 항상 많기 때문에,
	5의 개수만 세어줬는데
	조합은 어떻게 될 지 모르기 때문에, 
	2의 개수와 5의 개수를 동시에 세어줘야 한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long two = 0, five = 0;
	long long n, m;
	cin >> n >> m;

	for (long long i = 2; i <= n; i *= 2) {
		two += n / i;
	}
	for (long long i = 2; i <= n - m; i *= 2) {
		two -= (n - m) / i;
	}
	for (long long i = 2; i <= m; i *= 2) {
		two -= m / i;
	}

	for (long long i = 5; i <= n; i *= 5) {
		five += n / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) {
		five -= (n - m) / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		five -= m / i;
	}

	cout << min(two, five) << '\n';
	return 0;
}