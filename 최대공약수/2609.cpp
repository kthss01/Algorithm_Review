/*
	2609 최대공약수와 최소공배수
	두 수의 최대공약수와 최소공배수를 구하는 문제
*/

#include <iostream>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	int a, b;
	cin >> a >> b;
	int g = gcd(a, b);
	cout << g << '\n' << a * b / g << '\n';
	return 0;
}