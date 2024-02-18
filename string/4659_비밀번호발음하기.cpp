//4659 ��й�ȣ �����ϱ�
#include <iostream>
#include <string>
using namespace std;

//���� üũ
bool isMoeum(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	string s;
	while (1) {
		// input & break condition
		cin >> s;
		if (s == "end") break;

		// init variables
		bool isExist = false; //1�� ����
		bool isTriple = false; //2�� ����
		bool isDouble = false; //3�� ����
		int jaeum = 0, moeum = 0;

		int len = s.size();
		for (int i = 0; i < len; i++) {
			//1�� ���� �� 2�� ���
			if (isMoeum(s[i])) {
				isExist = true;
				moeum++;
				jaeum = 0;
			} else {
				jaeum++;
				moeum = 0;
			}
			//2�� ����
			if (jaeum >= 3 || moeum >= 3) {
				isTriple = true;
				break;
			}
			//3�� ����
			if (i > 0 && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') {
				isDouble = true;
				break;
			}
		}

		//output
		if (isExist && !isTriple && !isDouble) {
			cout << "<" << s << "> is acceptable.\n";
		} else {
			cout << "<" << s << "> is not acceptable.\n";
		}
	}

	return 0;
}