/*
	11052 ī�� �����ϱ�

	ī�带 N�� ������ �ִ�.
	ī�� i���� �ȾƼ� ���� �� �ִ� ������ P[i]�� ��,
	��� �Ǹ��ؼ� ���� �� �ִ� �ִ� ���� ���ϱ�

	D[i] = ī�� i���� �ȾƼ� ���� �� �ִ� �ִ� ����
	������ ��� �����غ���
	ī�� 1���� P[1]�� �ȱ� -> ���� ī���� ����: i-1 -> P[1] + D[i-1]
	ī�� 2���� P[2]�� �ȱ� -> ���� ī���� ����: i-2 -> P[2] + D[i-2]
	...
	ī�� i-1���� P[i-1]�� �ȱ� -> ���� ī���� ����: 1 -> P[i-1] + D[1]
	ī�� i���� P[i]�� �ȱ� -> ���� ī���� ����: 0 -> P[i] + D[0]

	D[i] = max(P[j] + D[i-j]) (1 <= j <= i)

	for(int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			d[i] = max(d[i], d[i-j] + a[j]);
		}
	}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> d(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + a[j]);
		}
	}
	cout << d[n] << '\n';
	return 0;
}