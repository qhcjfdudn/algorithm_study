/* https://www.acmicpc.net/problem/2740 */

/*
	최종적으로 만들어질 행렬곱셈 모양으로 for문을 구현하자!
*/

#include <iostream>
using namespace std;

int N, M, K, A[100][100], B[100][100], C[100][100];

void init() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	cin >> M >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];
}

void solve() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < K; j++)
			for (int k = 0; k < M; k++)
				C[i][j] += A[i][k] * B[k][j];
}

void printAns() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << C[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	init();
	solve();
	printAns();
}