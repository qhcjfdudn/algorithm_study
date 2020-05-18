/* https://www.acmicpc.net/problem/17609 */

/*
	ȸ������ �ƴ��� �Ǵ��ϴ� ���� �����ϴ�. ���� ȸ������ �ƴ��� �Ǵ��ϴ� ���� ���⿡ ����
	ȸ���� ã�� �������� ���� �ٸ� ���ڰ� ��Ÿ���� ��, ���ʰ� ������ �� � ���� ������ ��������
	ȸ���̾�� ���� �ǹ��Ѵ�. �׷��Ƿ� �� ���ھ� ����� �������� ȸ������ �Ǵ��ϸ� �ȴ�.
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