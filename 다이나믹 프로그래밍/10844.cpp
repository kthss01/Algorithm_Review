/*
	10844 쉬운 계단 수

	인접한 자리의 차이가 1이 나는 수를 계단 수라고 한다.
	예: 45656
	길이가 N인 계단의 수를 구하는 문제

	D[i][j] = 길이가 i이고 마지막 숫자가 j인 계단 수의 개수
	D[i][j] = D[i-1][j-1] + D[i-1][j+1]

	for (int i=1; i<=9; i++) d[1][i] = 1;
	for (int i=2; i<=n; i++) {
		for (int j=0; j<=9; j++) {
			d[i][j] = 0;
			if (j-1 >= 0) d[i][j] += d[i-1][j-1];
			if (j+1 <= 9) d[i][j] += d[i-1][j+1];
			d[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int i=0; i<=9; i++) ans += d[n][i];
	ans %= mod;
*/

#include <iostream>
using namespace std;
long long d[101][10];
long long mod = 1000000000;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j - 1 >= 0) {
				d[i][j] += d[i - 1][j - 1];
			}
			if (j + 1 <= 9) {
				d[i][j] += d[i - 1][j + 1];
			}
			d[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
	}
	ans %= mod;
	cout << ans << '\n';
	return 0;
}