/*
	11005 진법 변환 2
	10진법 수 N을 B진법으로 바꿔 출력하는 문제
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, b;
	cin >> n >> b;
	string ans = "";
	while (n > 0) {
		int r = n % b;
		if (r < 10) {
			ans += (char)(r + '0');
		}
		else {
			ans += (char)(r - 10 + 'A');
		}
		n /= b;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}