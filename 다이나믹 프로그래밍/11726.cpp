/*
	11726 2xn Ÿ�ϸ�

	2xn ���簢���� 1x2, 2x1Ÿ�Ϸ� ä��� ����� ��
	D[i] = 2xi ���簢���� ä��� ����� ��
	D[i] = D[i-1] + D[i-2]
*/

#include <stdio.h>
int d[1001];
int main() {
	d[0] = 1;
	d[1] = 1;
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 10007;
	}
	printf("%d\n", d[n]);
	return 0;
}