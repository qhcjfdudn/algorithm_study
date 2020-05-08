/* https://programmers.co.kr/learn/courses/30/lessons/62049 */

/*
	���. ���� ��ĥ �� ���� ����� ������ ���̸� ���� ��ġ�� ���ʰ� ������ �ϳ� ���̴�.
	�̸� �̿��Ͽ� ��������� ������ �ذ��� �� �ִ�.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> ret;

void rec(int index, int N, int v) {
	if (index == N) {
		ret.push_back(v);
	}
	else {
		rec(index + 1, N, 0);
		ret.push_back(v);
		rec(index + 1, N, 1);
	}
}

vector<int> solution(int n) {
	rec(1, n, 0);
	return ret;
}