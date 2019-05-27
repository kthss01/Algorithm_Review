/*
	1517 버블 소트

	N개로 이루어진 수열 A[1],A[2], ... , A[N]이 있을 때
	Swap이 총 몇 번 발생하는지 알아내느 문제
	321 -> 231 -> 213 -> 123 (3번)

	이 문제는 수열에서 inversion의 개수를 세는 문제이다.
	inversion: A[i] > A[j] (i < j)
	머지 소트를 하면서 문제를 풀 수 있다.

	3 5 2 9의 inversion의 개수는
	3 > 2, 5 > 2 로 2개이다.
	오른쪽 절반이 이동할 때
	왼쪽 절반에서 아직 이동하지 않은 것의 개수가
	그 때의 inversion의 개수이다.
	2가 먼저 이동하는데, 그 때 왼쪽 절반에는 3과 5가 있다.
	이것은 3 > 2, 5 > 2를 의미한다.

	1 5 2 3의 inversion의 개수는
	5 > 2, 5 > 3으로 2개다.
	오른쪽 절반이 이동할 때
	왼쪽 절반에서 아직 이동하지 않은 것의 개수가
	그 때의 inversion의 개수이다.
	2가 이동할 때, 왼쪽 절반에는 5가 남아있다. (inversion = 1)
	3이 이동할 때도 왼쪽 절반에는 5가 남아있다. (inversion = 1)

	long long solve(int start, int end) {
		if (start == end) {
			return 0;
		}
		int mid = (start+end)/2;
		long long ans = solve(start, mid) + solve(mid+1, end);
		int i = start;
		int j = mid+1;
		int k = 0;
		while (i <= mid || j <= end) {
			if (i <= mid && (j > end || a[i] <= a[j])) {
				b[k++] = a[i++];
			}
			else {
				ans += (logn long)(mid-i+1);
				b[k++] = a[j++];
			}
		}
		for (int i=start; i<=end; i++) {
			a[i] = b[i-start];
		}
		return ans;
	}
*/

#include <stdio.h>
int a[500000];
int b[500000];
long long solve(int start, int end) {
	if (start == end) {
		return 0;
	}
	int mid = (start + end) / 2;
	long long ans = solve(start, mid) + solve(mid + 1, end);
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || a[i] <= a[j])) {
			b[k++] = a[i++];
		}
		else {
			ans += (long long)(mid - i + 1);
			b[k++] = a[j++];
		}
	}
	for (int i = start; i <= end; i++) {
		a[i] = b[i - start];
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	long long ans = solve(0, n - 1);
	printf("%lld\n", ans);
	return 0;
}