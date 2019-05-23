/*
	10799 쇠막대기

	레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 '()'으로 표현된다.
	또한, 모든 '()'는 반드시 레이저를 표현한다.
	쇠막대기의 왼쪽 끝은 여는 괄호 '('로, 
	오른쪽 끝은 닫힌 괄호 ')'로 표현된다.

	올바른 괄호 문자열과 비슷하게 풀 수 있다.
	()가 나올 때 마다 스택에 들어있는 (의 개수를 세어준다.
	그런데,)가 나왔을 때, 이것이 레이저인지 쇠막대기인지 구분을 해줘야 한다.
	레이저는 항상 ()와 같이 붙어진 상태로 나온다
	스택에 (의 인덱스를 넣어서 인덱스가 1차이나는지 확인해야 한다.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string a;
	cin >> a;
	int n = a.size();
	stack<int> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '(') {
			s.push(i);
		}
		else {
			if (s.top() + 1 == i) {
				s.pop();
				ans += s.size();
			}
			else {
				s.pop();
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}