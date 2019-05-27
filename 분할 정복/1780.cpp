/*
	1780 ������ ����

	solve(0, 0, n)
	(0, 0)���� ���η� n��, ���η� n���� ���� ������ Ȯ�� �ϴ� �Լ�

	solve(x,y,n)
	(x,y)���� ���η� n��, ���η� n���� ���� ������ Ȯ���ϴ� �Լ�
	���� �κ� ������ �� 9��
	m = n/3�̶�� ���� ��
	�κ� ������ ��������

	solve(x,y,n)
		0: solve(x,y,m)
		1: solve(x,y+m,m)
		2: solve(x,y+2*m,m)
		3: solve(x+m,y,m)
		4: solve(x+m,y+m,m)
		5: solve(x+m,y+2*m,m)
		6: solve(x+2*m,y,m)
		7: solve(x+2*m,y+m,m)
		8: solve(x+2*m,y+2*m,m)

	�κ� ������ ȣ���ϱ� ����
	���� ���� �Ǿ� �ִ����� Ȯ���ؾ� �Ѵ�
	�װ� �ƴϸ� �κ� ������ ȣ��

	void solve(int x, int y, int n) {
		if (same(x, y, n)) {
			cnt[a[x][y]+1] += 1;
			return;
		}
		int m = n / 3;
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				solve(x+i*m, y+j*m, m);
			}
		}
	}

	bool same(int x, int y, int n) {
		for (int i=x; i<x+n; i++) {
			for (int j=y; j<y+n; j++) {
				if (a[x][y] != a[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
*/

#include <stdio.h>
int a[3000][3000];
int cnt[3];

bool same(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (a[x][y] != a[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int x, int y, int n) {
	if (same(x, y, n)) {
		cnt[a[x][y] + 1] += 1;
		return;
	}
	int m = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + i * m, y + j * m, m);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	solve(0, 0, n);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}