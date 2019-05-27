/*
	2263 Ʈ���� ��ȸ

	N���� ������ ���� ���� Ʈ���� ������ 1���� N���� ��ȣ�� �ߺ����� �Ű��� �ִ�.
	�� ���� Ʈ���� �ο����� ����Ʈ������ �־����� �� ���� ������ ���ϴ� ����
	
	��������: 1 2 4 5 7 3 6
	�ο���: 4 2 7 5 1 3 6
	����Ʈ����: 4 7 5 2 6 3 1

	����Ʈ������ ���� �������� ��Ʈ�̴�.
	-> �̸� �̿��ؼ� �ο������� ��Ʈ�� ã�� ���� �������� ����
*/

#include <stdio.h>
int inorder[100000];
int postorder[100000];
int position[100001];

void solve(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end) return;
	int root = postorder[post_end];
	printf("%d ", root);
	int p = position[root];

	// inorder: in_start p in in_end
	// postorder: post_start post_end
	// left p - in_start
	// right in_end - p
	int left = p - in_start;
	solve(in_start, p - 1, post_start, post_start + left - 1);
	solve(p + 1, in_end, post_start + left, post_end - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
	for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);
	for (int i = 0; i < n; i++) {
		position[inorder[i]] = i;
	}
	solve(0, n - 1, 0, n - 1);
	return 0;
}

