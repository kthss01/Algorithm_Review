/*
	11729 �ϳ��� ž �̵� ����

	�ϳ��� ž ����
	��Ģ 1: �� ���� �� ���� ���Ǹ� �ٸ� ž���� �ű� �� �ִ�.
	��Ģ 2: �׾� ���� ������ �׻� ���� ���� �Ʒ��� �ͺ��� �۾ƾ� �Ѵ�. (�߰� ���� ����)

	solve(n,x,y)
	1~n���� ������ x���� y�� �̵��ϴ� �Լ�
	1~n-1���� ������ x���� z�� �̵��Ѵ� (z�� x�� y�� �ƴ� ����)
	n�� ������ x���� y�� �̵��Ѵ�
	1~n-1���� ������ z���� y�� �̵��Ѵ�.

	void solve(int n, int x, int y) {
		if (n == 0) return;
		solve(n-1, x, 6-x-y);
		printf("%d %d\n", x, y);
		solve(n-1, 6-x-y, y);
	}
*/

#include <stdio.h>
void solve(int n, int x, int y) {
	if (n == 0) return;
	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	solve(n, 1, 3);
	return 0;
}