/*
	1463 1로 만들기

	세준이는 어떤 정수 N에 다음과 같은 연산중 하나를 할 수 있다.

	1. N이 3으로 나누어 떨어지면, 3으로 나눈다.
	2. N이 2로 나누어 떨어지면, 2로 나눈다.
	3. 1을 뺀다.

	세준이는 어떤 정수 N에 위와 같은 연산을 선택해서 1을 만드려고 한다.
	연산을 사용하는 횟수의 최소값을 출력하시오.

	D[i] = i를 1로 만드는데 필요한 최소 연산 횟수
	i에게 가능한 경우를 생각해보자.
	
	1. i가 3으로 나누어 떨어졌을 때, 3으로 나누는 경우
		D[i/3] + 1
	2. i가 2로 나누어 떨어졌을 때, 2로 나누는 경우
		D[i/2] + 1
	3. i에서 1을 빼는 경우
		D[i-1] + 1
	
	세 값 중의 최소값이 들어가게 된다.

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