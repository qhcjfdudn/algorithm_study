/* https://www.acmicpc.net/problem/1525 */

/*
	퍼즐을 맞춤으로 만들어지는 모양이 불가능한 경우가 있는데,
	우선 이 녀석이 안 만들어진다는 걸 어떻게 파악해야 할지..
	map을 쓰면 애매하지만, 가장 구현이 간단한 map으로 우선 구현해보았다.
	1초 내에 풀이는 되었지만, 분명 더 빨리 풀 방법이 있다.
	ex) 휴리스틱을 적용? 해쉬? 트라이?
	다 도전해봐야겠다.
*/

#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

struct Pos {
	int y, x;
	Pos(int _y, int _x) : y(_y), x(_x) {}
};

string nums = "";
int zeroY, zeroX;
map<string, int> strMap;

void init() {
	for (int i = 0, num; i < 9; i++) {
		cin >> num;
		nums += '0' + num;
		if (num == 0) {
			zeroY = i / 3;
			zeroX = i % 3;
		}
	}
}

bool canMove(int i, Pos cp) {
	switch (i) {
	case 0: return cp.y > 0;
	case 1: return cp.y < 2;
	case 2: return cp.x > 0;
	case 3: return cp.x < 2;
	}
}

int solve() {
	if (nums == "123456780") return 0;
	queue<string> strQ;
	queue<Pos> posQ;
	strQ.push(nums);
	posQ.push({ zeroY, zeroX });
	strMap[nums] = 1;

	while (!strQ.empty()) {
		string curStr = strQ.front(); strQ.pop();
		Pos curPos = posQ.front(); posQ.pop();

		for (int i = 0; i < 4; i++) {
			if (!canMove(i, curPos)) continue;
			string nextStr = curStr;
			swap(nextStr[curPos.y * 3 + curPos.x], nextStr[(curPos.y + dy[i]) * 3 + curPos.x + dx[i]]);
			if (nextStr == "123456780") return strMap[curStr];

			if (strMap[nextStr] == 0) {
				strMap[nextStr] = strMap[curStr] + 1;
				strQ.push(nextStr);
				posQ.push({ curPos.y + dy[i], curPos.x + dx[i] });
			}
		}
	}
	return -1;
}

int main() {
	init();

	cout << solve() << '\n';
}