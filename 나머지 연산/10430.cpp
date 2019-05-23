/*
	10430 나머지
	첫째 줄에 (A+B) % C
	둘째 줄에 (A%C + B%C)%C
	셋째 줄에 (AXB)%C
	넷째 줄에 (A%C X B%C)%C 출력
*/

#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	a %= c;
	b %= c;
	cout << (a + b) % c << '\n';
	cout << (a + b) % c << '\n';
	cout << (a * b) % c << '\n';
	cout << (a * b) % c << '\n';

	return 0;
}