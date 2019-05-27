/*
	이분 탐색 Binary Search

	정렬되어 있는 리스트에서 어떤 값을 빠르게 찾는 알고리즘
	리스트의 크기를 N이라고 했을 대
	lgN의 시간이 걸린다
	시간 복잡도가 lgN인 이유는
	크기가 N인 리스트를 계속해서 절반으로 나누기 때문이다.
	2^k = N 일 때, k = lgN

	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			position = mid;
			break;
		}
		else if (a[mid] > x) {
			right = mid - 1;
		} 
		else {
			left = mid + 1;
		}
	}
*/
/*
	백준 문제
	10815 숫자 카드
	10816 숫자 카드 2
*/