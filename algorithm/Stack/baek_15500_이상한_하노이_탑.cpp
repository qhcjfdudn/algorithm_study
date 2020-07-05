/* https://www.acmicpc.net/problem/15500 */

/*
	무거운 순서대로 쌓을 필요가 없다면, 세번째 칸은 옮기는 칸이 아닌
	바로 무거운 순서대로 쌓이도록, 첫 번째와 두 번째 칸에서만 옮겨준다.
*/

#include <cstdio>
#include <stack>

int N, pos[124], cnt, printFirst[12345], printSecond[12345];
std::stack<int> first, second;

void solve() {
	while (N) {
		if (pos[N] == 1) {
			while (first.top() != N) {
				second.push(first.top());
				pos[first.top()] = 2;
				first.pop();
				printFirst[cnt] = 1;
				printSecond[cnt] = 2;
				cnt++;
			}
			pos[first.top()] = 3;
			first.pop();
			printFirst[cnt] = 1;
			printSecond[cnt] = 3;
			cnt++;
		}
		else {
			while (second.top() != N) {
				first.push(second.top());
				pos[second.top()] = 1;
				second.pop();
				printFirst[cnt] = 2;
				printSecond[cnt] = 1;
				cnt++;
			}
			pos[second.top()] = 3;
			second.pop();
			printFirst[cnt] = 2;
			printSecond[cnt] = 3;
			cnt++;
		}
		N--;
	}

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d %d\n", printFirst[i], printSecond[i]);
}

int main() {
	scanf("%d", &N);
	for (int i = 0, a; i < N; i++) {
		scanf("%d", &a);
		pos[a] = 1;
		first.push(a);
	}

	solve();
}