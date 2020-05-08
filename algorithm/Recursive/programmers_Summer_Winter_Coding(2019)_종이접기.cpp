/* https://programmers.co.kr/learn/courses/30/lessons/62049 */

/*
	재귀. 접고 펼칠 때 줄이 생기는 기준은 종이를 접은 위치의 왼쪽과 오른쪽 하나 씩이다.
	이를 이용하여 재귀적으로 문제를 해결할 수 있다.
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