/* https://www.acmicpc.net/problem/17478 */

/*
���ڿ��� ����Լ��� ����� ����ϴ� ����.
��Ͱ� �Ǵ� �κе�, base case, ����� �������� ���� ���迡 ���� �ľ��ϱ� ���� ����.
*/

#include <iostream>
using namespace std;

const char recursiveAns[3][200] = {
	"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n"
	, "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n"
	, "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n"
};

int N;

void solve(int index) {
	for (int i = N - index; i < N; i++) cout << "____";
	cout << "\"����Լ��� ������?\"\n";
	if (index == N) {
		for (int i = N - index; i < N; i++) cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = N - index; j < N; j++) cout << "____";
			cout << recursiveAns[i];
		}
		solve(index + 1);
	}
	for (int i = N - index; i < N; i++) cout << "____";
	cout << "��� �亯�Ͽ���.\n";
}

int main() {
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	solve(0);
}