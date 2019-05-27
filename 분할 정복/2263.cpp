/*
	2263 트리의 순회

	N개의 정점을 갖는 이진 트리의 정점에 1부터 N까지 번호가 중복없이 매겨져 있다.
	이 이진 트리의 인오더와 포스트오더가 주어졌을 때 프리 오더를 구하는 문제
	
	프리오더: 1 2 4 5 7 3 6
	인오더: 4 2 7 5 1 3 6
	포스트오더: 4 7 5 2 6 3 1

	포스트오더의 가장 마지막은 루트이다.
	-> 이를 이용해서 인오더에서 루트를 찾아 분할 정복으로 진행
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

