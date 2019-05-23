/*
	나머지 연산 Modular Arithmetic

	컴퓨터의 정수는 저장할 수 있는 범위가 저장되어 있기 때문에,
	답을 M으로 나눈 나머지를 출력하라는 문제가 등장한다.
	(A+B) mod M = ((A mod M) + (B mod M)) mod M
	(AXB) mod M = ((A mod M) X (B mod M)) mod M
	나누기의 경우에는 성립하지 않는다. (Modular Inverse를 구해야 함)
	뺄셈의 경우에는 먼저 mod 연산을 한 결과가 음수가 나올 수 있기 때문에
	다음과 같이 해야 한다.
	(A-B) mod M = ((A mod M) - (B mod M) + M) mod 
*/
/*
	백준 문제 
	10430 나머지
*/