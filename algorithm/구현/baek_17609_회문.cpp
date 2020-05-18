/* https://www.acmicpc.net/problem/17609 */

/*
	회문인지 아닌지 판단하는 것은 간단하다. 유사 회문인지 아닌지 판단하는 것은 여기에 단지
	회문을 찾는 과정에서 서로 다른 문자가 나타났을 때, 왼쪽과 오른쪽 중 어떤 것을 제거한 나머지는
	회문이어야 함을 의미한다. 그러므로 한 문자씩 지우고 나머지가 회문인지 판단하면 된다.
*/

#include <iostream>
#include <string>
using namespace std;

int N;
string str;

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	while (N--) {
		int ans = 0;
		bool isFirstSimilar = true;
		cin >> str;
		int s = 0, e = str.size() - 1, ts, te;
		while (s <= e) {
			if (str[s] != str[e]) {
				if (ans == 0) {
					ans++;
					ts = s++;
					te = e - 1;
				}
				else if (ans == 1) {
					if (isFirstSimilar) {
						isFirstSimilar = false;
						s = ts;
						e = te;
					}
					else {
						ans++;
						break;
					}
				}
			}
			else s++, e--;
		}
		cout << ans << '\n';
	}
}