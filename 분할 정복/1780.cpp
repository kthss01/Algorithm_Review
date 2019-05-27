/*
	1780 종이의 개수

	solve(0, 0, n)
	(0, 0)부터 가로로 n개, 세로로 n개의 종이 개수를 확인 하는 함수

	solve(x,y,n)
	(x,y)부터 가로로 n개, 세로로 n개의 종이 개수를 확인하는 함수
	작은 부분 문제는 총 9개
	m = n/3이라고 했을 때
	부분 문제를 나눠보면

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

	부분 문제를 호출하기 전에
	같은 수로 되어 있는지를 확인해야 한다
	그게 아니면 부분 문제를 호출

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