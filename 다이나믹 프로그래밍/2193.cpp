/*
	2193 이친수

	0과 1로만 이루어진 수를 이친수라고 한다.
	다음 조건을 만족하면 이친수라고 한다.

	1. 이친수는 0으로 시작하지 않는다.
	2. 이친수에서는 1이 두 번 연속으로 나타나지 않는다.
	즉, 11을 부분 문자열로 갖지 않는다.
	N자리 이친수의 개수를 구하는 문제

	D[i][j] = i자리 이친수의 개수 중에서 j로 끝나는 것의 개수 (j=0, 1)

	0으로 시작하지 않는다.
	D[1][0] = 0
	D[1][1] = 1

	가능한 경우
	0으로 끝나는 경우
		앞에 0과 1이 올 수 있다.
		D[i-1][0] + D[i-1][1]
	1로 끝나는 경우
		앞에 1은 올 수 없다. 즉, 0만 올 수 있다.
		D[1-1][0]

	D[i][0] = D[i-1][0] + D[i-1][1]
	D[i][1] = D[i-1][0]

	다른 방법
	D[i] = i자리 이친수의 개수
	가능한 경우
	0으로 끝나는 경우
		앞에 0과 1 모두 올 수 있다.
		D[i-1]
	1로 끝나는 경우
		앞에 0만 올 수 있다.
		앞에 붙는 0을 세트로 생각해서 i-2자리에 01을 붙인다고 생각
		D[i-2]
	
	D[i] = D[i-1] + D[i-2]
*/

#include <iostream>
using namespace std;
long long d[91];
int main() {
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n] << '\n';
	return 0;
}