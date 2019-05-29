/*
	9095 1,2,3 더하기

	정수 n을 1,2,3의 조합으로 나타내는 방법의 수를 구하는 문제

	n = 4
	1+1+1+1
	1+1+2
	1+2+1
	2+1+1
	2+2
	1+3
	3+1

	D[i] = i를 1,2,3의 조합으로 나타내는 방법의 수
	D[i] = D[i-1] + D[i-2] + D[i-3]
*/

#include <stdio.h>
int d[11];
int main() {
	d[0] = 1;
	for (int i = 1; i <= 10; i++) {
		if (i - 1 >= 0) {
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0) {
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3];
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}
	return 0;
}