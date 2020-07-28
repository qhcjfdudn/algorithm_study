/* https://www.acmicpc.net/problem/17390 */

/*
	단순한 정렬과 부분합 문제!
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, Q, A[300001];

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) cin >> A[i];

	sort(A + 1, A + N + 1);

	for (int i = 2; i <= N; i++) A[i] += A[i - 1];

	for (int i = 0, L, R; i < Q; i++) {
		cin >> L >> R;
		cout << A[R] - A[L - 1] << '\n';
	}
}