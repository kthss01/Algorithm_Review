/*
	9012 괄호

	괄호 문자열이 주어졌을 때, 올바른 괄호 문자열인지 아닌지를 알아보는 문제
	괄호 문자열: (와 )로만 이루어진 문자열
	올바른 괄호 문자열: 괄호의 쌍이 올바른 문제

	스택을 사용해서 올바른 고라호 문자열인지 아닌지를 알 수 있다.
	(가 나오면 스택에 (를 넣고
	)가 나오면 스택에서 하나를 빼서 (인지 확인한다.
	또는 하나를 뺄 수 있는지를 확인한다.

	스택이 비어 있는데 )가 나타나면 올바른 괄호 문자열이 아님
	모든 과정이 끝나고 스택이 비어있으면 올바른 괄호 문자열
	끝났는데, 스택이 비어있지 않으면 올바른 괄호 문자열이 아님
*/

#include <iostream>
#include <string>
using namespace std;

string valid(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt += 1;
		}
		else {
			cnt -= 1;
		}
		if (cnt < 0) {
			return "NO";
		}
	}
	if (cnt == 0) {
		return "YES";
	}
	else {
		return "NO";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << valid(s) << '\n';
	}
	return 0;
}