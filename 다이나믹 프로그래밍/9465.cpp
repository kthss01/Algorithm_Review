/*
	9465 스티커

	스티커 2n개가 2xn 모양으로 배치되어 있다.
	스티커 한장을 떼면 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없다
	점수의 합을 최대로 만드는 문제

	D[i][j] = 2 x i 에서 얻을 수 있는 최대 점수, i번 열에서 뜯는 스티커는 j
	j = 0 -> 뜯지 않음
	j = 1 -> 위쪽 스티커를 뜯음
	j = 2 -> 아래쪽 스티커를 뜯음

	뜯지 않음 (D[i][0])
		i-1 열에서 스티커를 어떻게 뜯었는지 상관이 없다
		max(D[i-1][0], D[i-1][1], D[i-1][2])
	위쪽 스티커를 뜯음 (D[i][1])
		i-1 열에서 위쪽 스티커를 뜯으면 안된다
		max(D[i-1][0], D[i-1][2]) + A[i][0]
	아래쪽 스티커를 뜯음 (D[i][2])
		i-1 열에서 아래쪽 스티커를 뜯으면 안된다
		max(D[i-1][0], D[i-1][1]) + A[i][1]
*/

#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
long long a[100001][2];
long long d[100001][3];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i][0]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i][1]);
		}
		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][1];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(max(ans, d[i][0]), max(d[i][1], d[i][2]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}