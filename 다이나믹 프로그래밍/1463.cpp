/*
	1463 1�� �����

	�����̴� � ���� N�� ������ ���� ������ �ϳ��� �� �� �ִ�.

	1. N�� 3���� ������ ��������, 3���� ������.
	2. N�� 2�� ������ ��������, 2�� ������.
	3. 1�� ����.

	�����̴� � ���� N�� ���� ���� ������ �����ؼ� 1�� ������� �Ѵ�.
	������ ����ϴ� Ƚ���� �ּҰ��� ����Ͻÿ�.

	D[i] = i�� 1�� ����µ� �ʿ��� �ּ� ���� Ƚ��
	i���� ������ ��츦 �����غ���.
	
	1. i�� 3���� ������ �������� ��, 3���� ������ ���
		D[i/3] + 1
	2. i�� 2�� ������ �������� ��, 2�� ������ ���
		D[i/2] + 1
	3. i���� 1�� ���� ���
		D[i-1] + 1
	
	�� �� ���� �ּҰ��� ���� �ȴ�.

	int go(int n) {
		if (n == 1) return 0;
		if (d[n] > 0) return d[n];
		d[n] = go(n-1) + 1;
		if (n % 2 == 0) {
			int temp = go(n/2) + 1;
			if (d[n] > temp) d[n] = temp;
		}
		if (n % 3 == 0) {
			int temp = go(n/3) + 1;
			if (d[n] > temp) d[n] = temp;
		}
		return d[n];
	}

	d[1] = 0;
	for (int i=2; i<=n; i++) {
		d[i] = d[i-1] + 1;
		if (i % 2 == 0 && d[i] > d[i/2] + 1) {
			d[i] = d[i/2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i/3] + 1) {
			d[i] = d[i/3] + 1;
		}
	}
*/

// Top-down
//#include <iostream>
//using namespace std;
//
//int d[1000001];
//int go(int n) {
//	if (n == 1) {
//		return 0;
//	}
//	if (d[n] > 0) {
//		return d[n];
//	}
//	d[n] = go(n - 1) + 1;
//	if (n % 2 == 0) {
//		int temp = go(n / 2) + 1;
//		if (d[n] > temp) {
//			d[n] = temp;
//		}
//	}
//	if (n % 3 == 0) {
//		int temp = go(n / 3) + 1;
//		if (d[n] > temp) {
//			d[n] = temp;
//		}
//	}
//	return d[n];
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << go(n) << '\n';
//	return 0;
//}

// Bottom-up
#include <iostream>
using namespace std;
int d[1000001];
int main() {
	int n;
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
		}
	}
	cout << d[n] << '\n';
	return 0;
}