/*
	2133 타일 채우기

	3xN을 1x2,2x1로 채우는 방법의 수
	D[i] = 3xi를 채우는 방법의 수
	마지막에 올 수 있는 가능한 경우의 수

	D[i] = 3 * D[i-2] (아니다)
	가능한 경우가 더 있다

	D[i] = 3 * D[i-2] + 2*D[i-4] + 2*D[i-6] + ...
*/

#include <iostream>
using namespace std;
long long d[31];
int main() {
	int n;
	cin >> n;
	d[0] = 1;
	for (int i = 2; i <= n; i += 2) {
		d[i] = d[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += d[j] * 2;
		}
	}
	cout << d[n] << '\n';
	return 0;
}