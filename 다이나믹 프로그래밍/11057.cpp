/*
	11057 ������ ��

	������ ���� ���� �ڸ��� ���������� �̷�� ���� ���Ѵ�
	������ ���� ���Ƶ� ������������ ģ��
	���� ���� N�� �־����� ��, ������ ���� ������ ���ϴ� ����
	���� 0���� ������ �� �ִ�.
	
	��: 1233345, 357, 88888888, 15559999

	D[i][j] = ���̰� i�̰� ������ ���ڰ� j�� ������ ���� ����
	D[1][i] = 1
	D[i][j] += D[i-1][k] (0 <= k <= j)

	for (int i=0; i<=9; i++) d[1][i] = 1;
	for (int i=2; i<=n; i++) {
		for (int j=0; j<=9; j++) {
			for (int k=0; k<=j; k++) {
				d[i][j] += d[i-1][k];
				d[i][j] %= mod;
			}
		}
	}
	long long ans = 0;
	for (int i=0; i<10; i++) ans += d[n][i];
	ans %= mod;
*/

#include <iostream>
using namespace std;
long long d[1001][10];
long long mod = 10007;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += d[n][i];
	}
	ans %= mod;
	cout << ans << '\n';
	return 0;
}