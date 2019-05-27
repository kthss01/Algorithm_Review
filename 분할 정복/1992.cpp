/*
	1992 쿼드트리

	쿼드트리로 압축하여 출력하는 문제
	분할 정복 + 프리오더
	색종이 나누기와 비슷한 과정을 거치면 된다.

	void solve(int x, int y, int n) {
		if (same(x,y,n)) {
			printf("%d", a[x][y]);
		} 
		else {
			printf("(");
			int m = n/2;
			for (int i=0; i<2; i++) {
				for (int j=0; j<2; j++) {
					solve(x+m*i, y+m*j, m);
				}
			}
			printf(")");
		}
	}
*/

#include <stdio.h>
int a[100][100];
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
		printf("%d", a[x][y]);
	}
	else {
		printf("(");
		int m = n / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(x + m * i, y + m * j, m);
			}
		}
		printf(")");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	solve(0, 0, n);
	printf("\n");
	return 0;
}