/*
	2225 합분해

	0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수
	D[K][N] = 0부터 N가지의 정수 K개를 더해서
	그 합이 N이 되는 경우의 수

	? + ? + ? + ? + ... + ? + L = N
	위의 식이 나타내는 값: D[K][N]

	? + ? + ? + ? + ... + ? = N - L
	위의 식이 나타내는 값: D[K-1][N-L]

	D[K][N] += D[K-1][N-L] (0 <= L <= N)

	d[0][0] = 1LL;
	for (int i=1; i<=k; i++) {
		for (int j=0; j<=n; j++) {
			for (int l=0; l<=j; l++) { 
				d[i][j] += d[i-1][j-l];
				d[i][j] %= mod;
			}
		}
	}
*/

#include <iostream>
using namespace std;
long long d[201][201];
long long mod = 1000000000;
int main() {
	int n, k;
	cin >> n >> k;
	d[0][0] = 1LL;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= mod;
			}
		}
	}
	cout << d[k][n] << '\n';
	return 0;
}