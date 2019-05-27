/*
	11729 하노이 탑 이동 순서

	하노이 탑 문제
	규칙 1: 한 번에 한 개의 원판만 다른 탑으로 옮길 수 있다.
	규칙 2: 쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다. (중간 과정 포함)

	solve(n,x,y)
	1~n개의 원판을 x에서 y로 이동하는 함수
	1~n-1개의 원판을 x에서 z로 이동한다 (z는 x와 y가 아닌 원판)
	n번 원판을 x에서 y로 이동한다
	1~n-1개의 원판을 z에서 y로 이동한다.

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