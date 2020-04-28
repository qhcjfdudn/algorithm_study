/* https://www.acmicpc.net/problem/8958 */

/*
	간단한 구현 문제. 수를 더할 때 연속하는 것을 판단한 후 연속이 끝난 지점에서 덧셈 연산을 한 번에 수행하면
	속도가 좀 더 빠를까?
*/

#include <iostream>
#include <string>
using namespace std;

int T, pSum, serial;
string str;

int main() {
	cin >> T;
	while (T--) {
		cin >> str;
		pSum = serial = 0;

		for (int i = str.length() - 1; i >= 0; i--) {
			if (str[i] == 'O')
				pSum += ++serial;
			else
				serial = 0;
		}
		cout << pSum << '\n';
	}
}