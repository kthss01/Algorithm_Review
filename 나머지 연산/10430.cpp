/*
	10430 ������
	ù° �ٿ� (A+B) % C
	��° �ٿ� (A%C + B%C)%C
	��° �ٿ� (AXB)%C
	��° �ٿ� (A%C X B%C)%C ���
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