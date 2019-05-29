/*
	11052 카드 구매하기

	카드를 N개 가지고 있다.
	카드 i개를 팔아서 얻을 수 있는 수익이 P[i]일 때,
	모두 판매해서 얻을 수 있는 최대 수익 구하기

	D[i] = 카드 i개를 팔아서 얻을 수 있는 최대 수익
	가능한 경우 생각해보기
	카드 1개를 P[1]에 팔기 -> 남은 카드의 개수: i-1 -> P[1] + D[i-1]
	카드 2개를 P[2]에 팔기 -> 남은 카드의 개수: i-2 -> P[2] + D[i-2]
	...
	카드 i-1개를 P[i-1]에 팔기 -> 남은 카드의 개수: 1 -> P[i-1] + D[1]
	카드 i개를 P[i]에 팔기 -> 남은 카드의 개수: 0 -> P[i] + D[0]

	D[i] = max(P[j] + D[i-j]) (1 <= j <= i)

	for(int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			d[i] = max(d[i], d[i-j] + a[j]);
		}
	}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> d(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + a[j]);
		}
	}
	cout << d[n] << '\n';
	return 0;
}