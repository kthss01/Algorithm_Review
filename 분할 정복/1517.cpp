/*
	1517 ���� ��Ʈ

	N���� �̷���� ���� A[1],A[2], ... , A[N]�� ���� ��
	Swap�� �� �� �� �߻��ϴ��� �˾Ƴ��� ����
	321 -> 231 -> 213 -> 123 (3��)

	�� ������ �������� inversion�� ������ ���� �����̴�.
	inversion: A[i] > A[j] (i < j)
	���� ��Ʈ�� �ϸ鼭 ������ Ǯ �� �ִ�.

	3 5 2 9�� inversion�� ������
	3 > 2, 5 > 2 �� 2���̴�.
	������ ������ �̵��� ��
	���� ���ݿ��� ���� �̵����� ���� ���� ������
	�� ���� inversion�� �����̴�.
	2�� ���� �̵��ϴµ�, �� �� ���� ���ݿ��� 3�� 5�� �ִ�.
	�̰��� 3 > 2, 5 > 2�� �ǹ��Ѵ�.

	1 5 2 3�� inversion�� ������
	5 > 2, 5 > 3���� 2����.
	������ ������ �̵��� ��
	���� ���ݿ��� ���� �̵����� ���� ���� ������
	�� ���� inversion�� �����̴�.
	2�� �̵��� ��, ���� ���ݿ��� 5�� �����ִ�. (inversion = 1)
	3�� �̵��� ���� ���� ���ݿ��� 5�� �����ִ�. (inversion = 1)

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