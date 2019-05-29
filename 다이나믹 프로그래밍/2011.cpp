/*
	2011 ��ȣ �ڵ�

	� ��ȣ�� �־����� ��,
	�� ��ȣ�� �ؼ��� �� ������ ���� �� �ִ��� ���ϴ� ����

	A�� 1, B�� 2, ..., Z�� 26
	BEAN -> 25114
	25114 -> "BEAAD", "YAAD", "YAN", "YKD", "BEKD", "BEAN"

	D[i] = i��° ���ڱ��� �ؼ����� ��, ���� �� �ִ� �ؼ��� ������
	i��° ���ڿ��� ������ ���
	1�ڸ� ��ȣ
		0�� ����
	2�ڸ� ��ȣ
		10 <= x <= 26

	d[0] = 1;
	for (int i=1; i<=n; i++) {
		int x = s[i] - '0';
		if (1 <= x && x <= 9) {
			d[i] = (d[i] + d[i-1]) % mod;
		}
		if (i==1) continue;
		if (s[i-1] == '0') continue;
		x = (s[i-1]-'0')*10 + (s[i]-'0');
		if (10 <= x && x <= 26) {
			d[i] += (d[i] + d[i-2]) % mod;
		}
	}
*/

#include <iostream>
#include <string>
using namespace std;
int d[5001];
int mod = 1000000;
int main() {
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x = s[i] - '0';
		if (1 <= x && x <= 9) {
			d[i] += d[i - 1];
			d[i] %= mod;
		}
		if (i == 1) {
			continue;
		}
		if (s[i - 1] == '0') {
			continue;
		}
		x = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (10 <= x && x <= 26) {
			d[i] += d[i - 2];
			d[i] %= mod;
		}
	}
	cout << d[n] << '\n';
	return 0;
}