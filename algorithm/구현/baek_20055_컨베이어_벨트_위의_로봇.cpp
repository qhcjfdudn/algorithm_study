/* https://www.acmicpc.net/problem/20055 */

/*
	B형 대비 느낌으로 자료구조도 구현하고~
	문제도 최적화하는 느낌으로다가 풀었다~
	그런데 최적화하지 않은 적당히 푼 소스보다 느리다. 왜지? 검증..
*/

#include <stdio.h>
using namespace std;

const int Q_SIZE = 150;

struct Q {
	int arr[Q_SIZE] = {}, f, r;
	Q() { f = 0; r = 0; }
	void push_back(int v) {
		arr[r] = v;
		r = (r + 1) % Q_SIZE;
	}
	void pop_front() {
		f = (f + 1) % Q_SIZE;
	}
	int front() {
		return arr[f];
	}
};

int N, K, A[200], cntZeroDura;

void init() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < 2 * N; i++) scanf("%d", A + i);
}
void rotateBelt(int* u) {
	*u = (*u + (2 * N - 1)) % (2 * N);
}
void mvRobot(Q* robots, int up) {
	int downPos = (up + N - 1) % (2 * N);
	for (int i = robots->f; i != robots->r; i = (i + 1) % Q_SIZE) {
		if (robots->arr[i] == downPos) {
			robots->pop_front();
		}
		else {
			int next = (robots->arr[i] + 1) % (2 * N);
			if (A[next] == 0 || (i != robots->f && robots->arr[(i + Q_SIZE - 1) % Q_SIZE] == next)) continue;
			if (--A[next] == 0) cntZeroDura++;
			robots->arr[i] = next;
			if (robots->arr[i] == downPos) {
				robots->pop_front();
			}
		}
	}
}
void putRobot(Q* robots, int u) {
	if (A[u] == 0) return;
	if (--A[u] == 0) cntZeroDura++;
	robots->push_back(u);
}
int solve() {
	Q robots;
	int upPos = 0, t = 0;
	while (++t) {
		rotateBelt(&upPos);
		mvRobot(&robots, upPos);
		putRobot(&robots, upPos);
		if (cntZeroDura >= K) break;
	}
	return t;
}

int main() {
	init();
	printf("%d\n", solve());
}