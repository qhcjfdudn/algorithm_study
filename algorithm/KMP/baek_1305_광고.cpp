/* https://www.acmicpc.net/problem/1305 */

/*
	전광판에 보이는 광고의 문구가 반복되는 부분이 최대일 경우는
	현재 보이는 문구의 접두사와 접미사가 가장 많이 같을 때이다.
*/

#include <iostream>
using namespace std;

int L, failure_function[1000000];
char src[1000001];

int solve() {
	int idx = 1, m = 0;

	while (idx + m < L) {
		if (src[m] == src[idx + m]) {
			failure_function[idx + m] = m + 1;
			m++;
		}
		else {
			if (m > 0) {
				idx += m - failure_function[m - 1];
				m = failure_function[m - 1];
			}
			else idx++;
		}
	}

	return L - failure_function[L - 1]; // 전체 길이에서 가장 마지막 실패함수의 값을 빼준다.
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> L >> src;

	cout << solve() << '\n';
}