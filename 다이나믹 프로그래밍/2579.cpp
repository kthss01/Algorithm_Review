/*
	2579 계단 오르기

	계단 오르는 데는 다음과 같은 규칙이 있다.

	1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다.
	즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
	2. 연속된 세 개의 계단을 모두 밟아서는 안된다.
	단, 시작점은 계단에 포함되지 않는다.
	3. 마지막 도착 계단은 반드시 밟아야 한다.

	각 계단에 쓰여 있는 점수가 주어질 때 
	이 게임에서 얻을 수 있는 총 점수의 최대값을 구하는 프로그램 작성

	D[i][j] = i번째 계단에 올라갔을 때, 최대 점수.
	i번째 계단은 j개 연속해서 올라온 계단임

	D[i][0] = 0개 연속 -> i번째 계단에 올라가야 하기 때문에 불가능한 경우
	D[i][1] = 1개 연속 -> i-1번째 계단은 밟으면 안됨
		i-2번째 계단은 1개 연속이거나 2개 연속이거나 상관이 없음
		max(D[i-2][1], D[i-2][2]) + A[i]
	D[i][2] = 2개 연속 -> i번째 계단은 밟아야 하고,
	반드시 1개 연속해서 올라온 계단이어야 함
		i-1번째 계단은 반드시 1개 연속 계단이어야 함
		D[i-1][1] + A[i]

	정답은 D[n][1]과 D[n][2] 중의 최대값

	d[1][1] = a[1];
	for (int i=2; i<=n; i++) {
		d[i][2] = d[i-1][1] + a[i];
		d[i][1] = max(d[i-2][1], d[i-2][2]) + a[i];
*/

//#include <stdio.h>
//#define max(a,b) (((a)>(b))?(a):(b))
//int a[301];
//int d[301][3];
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &a[i]);
//	}
//	d[1][1] = a[1];
//	for (int i = 2; i <= n; i++) {
//		d[i][2] = d[i - 1][1] + a[i];
//		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + a[i];
//	}
//	printf("%d\n", max(d[n][1], d[n][2]));
//	return 0;
//}

/*
	다른 방법
	D[i] = i번째 계단에 올라갔을 때, 최대 점수
	
	1개 연속 -> i-1번째 계단은 밟으면 안됨
		i-2번째 계단은 반드시 밟았어야 함
		D[i-2] + A[i]
	2개 연속 -> i-1번째 계단을 밟고, i-2번째 계단은 밟으면 안됨
		i-3번째 계단은 반드시 밟았어야 함
		D[i-3] + A[i-1] + A[i]

	d[1] = a[1];
	d[2] = a[1] + a[2];
	for (int i=3; i<=n; i++) {
		d[i] = max(d[i-2] + a[i], d[i-3] + a[i] + a[i-1]);
	}
*/

#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
int a[301];
int d[301];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	d[1] = a[1];
	d[2] = a[1] + a[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 2] + a[i], d[i - 3] + a[i] + a[i - 1]);
	}
	printf("%d\n", d[n]);
	return 0;
}