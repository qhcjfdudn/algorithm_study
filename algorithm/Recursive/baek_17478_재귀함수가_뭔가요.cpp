/* https://www.acmicpc.net/problem/17478 */

/*
문자열을 재귀함수를 사용해 출력하는 문제.
재귀가 되는 부분들, base case, 재귀의 시작지점 등의 관계에 대해 파악하기 좋은 문제.
*/

#include <iostream>
using namespace std;

const char recursiveAns[3][200] = {
	"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n"
	, "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n"
	, "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n"
};

int N;

void solve(int index) {
	for (int i = N - index; i < N; i++) cout << "____";
	cout << "\"재귀함수가 뭔가요?\"\n";
	if (index == N) {
		for (int i = N - index; i < N; i++) cout << "____";
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = N - index; j < N; j++) cout << "____";
			cout << recursiveAns[i];
		}
		solve(index + 1);
	}
	for (int i = N - index; i < N; i++) cout << "____";
	cout << "라고 답변하였지.\n";
}

int main() {
	cin >> N;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	solve(0);
}