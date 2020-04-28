/* https://www.acmicpc.net/problem/8958 */

/*
	������ ���� ����. ���� ���� �� �����ϴ� ���� �Ǵ��� �� ������ ���� �������� ���� ������ �� ���� �����ϸ�
	�ӵ��� �� �� ������?
*/

#include <iostream>
#include <string>
using namespace std;

int T, pSum, serial;
string str;

int main() {
	cin >> T;
	while (T--) {
		cin >> str;
		pSum = serial = 0;

		for (int i = str.length() - 1; i >= 0; i--) {
			if (str[i] == 'O')
				pSum += ++serial;
			else
				serial = 0;
		}
		cout << pSum << '\n';
	}
}