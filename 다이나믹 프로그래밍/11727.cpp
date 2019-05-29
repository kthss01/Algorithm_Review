/*
	11727 2xn 타일링 2
	
	2xn 직사각형을 1x2, 2x1, 2x2 타일로 채우는 방법의 수
	아래 그림은 2x5를 채우는 방법의 수
	D[i] = 2xi 직사각형을 채우는 방법의 수
	D[i] = 2*D[i-2] + D[i-1]
*/

#include <stdio.h>
int d[1001];
int main() {
	d[0] = 1;
	d[1] = 1;
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 2];
		d[i] %= 10007;
	}
	printf("%d\n", d[n]);
	return 0;
}