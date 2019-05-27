/*
	2447 별찍기 - 10

	분할 정복으로 멋지게 별을 찍는 문제
	가운데는 빈칸이고, 나머지 3칸은 다시 재귀적인 구조를 가지게 된다.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const char BLANK = ' ';
const char STAR = '*';

void go(vector< vector<char> > &a, int x, int y, int n, char color) {
	if (color == BLANK) {
		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				a[i][j] = BLANK;
			}
		}
	}
	else {
		if (n == 1) {
			a[x][y] = STAR;
		}
		else {
			char newColor = STAR;
			int m = n / 3;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1) {
						newColor = BLANK;
					}
					else {
						newColor = STAR;
					}
					go(a, x + m * i, y + m * j, m, newColor);
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector< vector<char> > a(n, vector<char>(n, 0));
	go(a, 0, 0, n, STAR);
	for (int i = 0; i < n; i++) {
		cout << string(a[i].begin(), a[i].end()) << '\n';
	}
	return 0;
}