#include<iostream>
#include<string>
using namespace std;
int main(void) {
	string s,t;
	cout << "�����ʼ�ַ���:" << endl;
	getline(cin, s);
	char x;
	cout << "����Ҫɾ�����ַ���"<<endl;
	cin >> x;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != x) {
			t += s[i];
		}
	}
	cout << t;
}