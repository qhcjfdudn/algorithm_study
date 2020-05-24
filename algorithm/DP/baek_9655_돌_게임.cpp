/* https://www.acmicpc.net/problem/9655 */

/*
	'완벽하게 게임을 한다'는 표현은 실수 없이 게임을 한다는 것. 이는 현재의 상태에서 
	내가 이길 수 있는 쪽으로만 다음 수를 선택한다는 의미이다.
	이는 현재 내가 돌을 어떤 식으로 선택해왔든 상관 없이 현재 N만큼의 돌이 있다면,
	내 승패는 결정 돼 있음을 말한다. 이에 DP를 적용할 수 있다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, cache[1001];

int DP(int cnt) {
	if (cnt <= 0) return cnt < 0 ? 1 : -1;
	if (cache[cnt]) return cache[cnt];

	return cache[cnt] = (-1) * min(DP(cnt - 1), DP(cnt - 3));
}

int main() {
	cin >> N;
	cout << (DP(N) == 1 ? "SK\n" : "CY\n");
}