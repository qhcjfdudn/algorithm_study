/* https://www.acmicpc.net/problem/1324 */

/*
	이전 값이 얼마이든 상관 없이, 첫째날의 길 위 어떤 지점a와
	둘째날의 길 위 어떤 지점 b의 값이 동일하다면, 이 이후의 연산은
	반복수행하지 않아도 결과가 항상 같다. 즉 DP를 쓸 수 있다.
	cache[첫째날 어느 지점][둘째날 어느 지점]으로 메모이제이션 가능하다.

	하지만 이렇게 풀 경우 소스가 많이 느리다. 다른 소스를 참고하여
	더 효율적으로 개선하자.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, first[1000], second[1000], cache[1000][1000];

int DP(int fi, int si, int beforeNum) {
	if (fi == N || si == N) return 0;

	int &ret = cache[fi][si];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = fi; i < N; i++) {
		if (beforeNum >= first[i]) continue;
		for (int j = si; j < N; j++)
			if (first[i] == second[j])
				ret = max(ret, DP(i + 1, j + 1, first[i]) + 1);
	}

	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> first[i];
	for (int i = 0; i < N; i++) cin >> second[i];

	memset(cache[0], -1, sizeof(cache));

	cout << DP(0, 0, -1) << '\n';
}