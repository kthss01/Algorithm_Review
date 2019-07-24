/*
	트리 순회

	이진 트리의 프리오더, 인오더, 포스트오더 순서를 출력하는 문제
*/

#include <iostream>
using namespace std;

int a[50][2];

void preorder(int x) {
	if (x == -1) return;
	cout << (char)(x + 'A');
	preorder(a[x][0]);
	preorder(a[x][1]);
}

void inorder(int x) {
	if (x == -1) return;
	inorder(a[x][0]);
	cout << (char)(x + 'A');
	inorder(a[x][1]);
}

void postorder(int x) {
	if (x == -1) return;
	postorder(a[x][0]);
	postorder(a[x][1]);
	cout << (char)(x + 'A');
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A';
		if (y == '.') {
			a[x][0] = -1;
		}
		else {
			a[x][0] = y - 'A';
		}
		if (z == '.') {
			a[x][1] = -1;
		}
		else {
			a[x][1] = z - 'A';
		}
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';

	return 0;
}