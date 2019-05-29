/*
	2011 암호 코드

	어떤 암호가 주어졌을 때,
	그 암호의 해석이 몇 가지가 나올 수 있는지 구하는 문제

	A는 1, B는 2, ..., Z는 26
	BEAN -> 25114
	25114 -> "BEAAD", "YAAD", "YAN", "YKD", "BEKD", "BEAN"

	D[i] = i번째 문자까지 해석했을 때, 나올 수 있는 해석의 가짓수
	i번째 문자에게 가능한 경우
	1자리 암호
		0을 제외
	2자리 암호
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