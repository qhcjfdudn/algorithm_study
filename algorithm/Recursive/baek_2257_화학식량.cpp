/* https://www.acmicpc.net/problem/2257 */

/*
	계산의 제약을 최소화 하기 위해 괄호를 포함한 원소 단위로 값을 처리한다.
*/

#include <cstdio>
#include <stack>

char str[101];
int len;

int atom2wei(const char atom) {
	switch (atom) {
	case 'H': return 1;
	case 'C': return 12;
	case 'O': return 16;
	default: return 0;
	}
}

int solve() {
	std::stack<int> subCnt;
	int ret = 0, cur = 0;

	while (cur != len) {
		if (str[cur] == '(') {
			subCnt.push(-1);
		}
		else if (str[cur] == ')') {
			int cnt = 0;
			while (subCnt.top() != -1) {
				cnt += subCnt.top();
				subCnt.pop();
			}
			subCnt.pop();
			subCnt.push(cnt);
		}
		else if (str[cur] <= '9') {
			int calcCnt = subCnt.top() * (str[cur] - '0');
			subCnt.pop();
			subCnt.push(calcCnt);
		}
		else subCnt.push(atom2wei(str[cur]));
		cur++;
	}
	while (!subCnt.empty()) {
		ret += subCnt.top();
		subCnt.pop();
	}
	return ret;
}

int main() {
	scanf("%s", str);
	while (str[len]) len++;

	printf("%d\n", solve());
}