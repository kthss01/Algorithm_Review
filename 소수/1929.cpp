/*
	1929 소수 구하기
	M이상 N이하 소수를 모두 출력하는 문제
*/

#include <iostream>
using namespace std;
const int MAX = 1000000;
bool check[MAX + 1]; // true 지워짐, false 지워지지 않음
int main() {
	check[0] = check[1] = true;
	for (int i = 2; i*i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}

	return 0;
}