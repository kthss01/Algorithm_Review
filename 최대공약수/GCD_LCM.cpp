/*
	최대공약수 Greatest Common Divisor

	최대공약수는 줄여서 GCD라고 쓴다.
	두 수 A와 B의 최대공약수 G는 A와 B의 공통된 약수 중에서 가장 큰 정수이다.
	최대공약수를 구하는 가장 쉬운 방법은 2부터 min(A,B)까지 모든 정수로 나누어 보는 방법
	최대공약수가 1인 두 수를 서로소(Coprime)라고 한다.

	int g = 1;
	for (int i=2; i<=min(a,b); i++) {
		if (a % i == 0 && b % i == 0) {
			g = i;
		}
	}

	더 빠른 방법이 있다.
	유클리드 호제법(Euclidean algorithm)을 이용하는 방법이다.
	a를 b로 나눈 나머지를 r이라고 했을 대
	GCD(a,b) = GCD(b,r)과 같다.
	r = 0이면 그 때 b가 최대 공약수이다.
	GCD(24,16) = GCD(16,8) = GCD(8,0) = 8

	재귀함수를 사용해서 구현한 유클리드 호제법

	int gcd(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a%b);
		}
	}

	재귀함수를 사용하지 않고 구현한 유클리드 호제법

	int gcd(int a, int b) {
		while (b != 0) {
			int r = a%b;
			a = b;
			b = r;
		}
		return a;
	}

	세 수의 최대공약수는 다음과 같이 구할 수 있다.
	
	GCD(a, b, c) = GCD(GCD(a,b),c)
	네 수, N개의 숫자도 위와 같은 식으로 계속해서 구할 수 있다.
*/
/*
	백준 문제 
	2609 최대공약수와 최소공배수
*/

/*
	최소공배수 Least Common Multiple

	최소공배수는 줄여서 LCM이라고 한다.
	두 수의 최소공배수는 두 수의 공통된 배수 중에서 가장 작은 정수
	최소공배수는 GCD를 응용해서 구할 수 있다.
	두 수 a,b,의 최대공약수를 g라고 했을 때
	최소공배수 l = g * (a/g) * (b/g)이다.
*/
/*
	백준 문제
	1934 최소공배수
	9613 GCD 합
*/