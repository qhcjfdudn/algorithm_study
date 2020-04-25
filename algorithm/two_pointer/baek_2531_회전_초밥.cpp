/* https://www.acmicpc.net/problem/2531 */

/*
	난독증을 조심하자. 연속해서 먹는데, 다른 것들로만 연속해서 먹는 것이 아니다.
	이후에는 컨베이어 벨트를 어떻게 표현할지 생각하면 된다. 간단히 모듈러를 통해 구현하자.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, d, k, c, belt[30000];
int sushi[3001];

int solve() {
	int ret = 0, cnt = 0;

	for (int i = 0; i < k; i++)
		if (!sushi[belt[i]]++)
			cnt++;

	for (int i = 0; i < N; i++) {
		ret = max(ret, cnt + !sushi[c]);
		if (!--sushi[belt[i]]) cnt--;
		if (!sushi[belt[(i + k) % N]]++) cnt++;
	}

	return ret;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) cin >> belt[i];

	cout << solve() << '\n';
}
