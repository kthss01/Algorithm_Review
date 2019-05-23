/*
	11653 소인수분해
	정수 N을 소인수분해해서 출력하는 문제
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			printf("%d\n", i);
			n /= i;
		}
	}
	if (n > 1) {
		printf("%d\n", n);
	}

	return 0;
}