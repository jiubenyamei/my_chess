#include<iostream>
#include"����.h"
using namespace std;
int main() {
	Chess play(1);
	while (true) {
		system("cls");
		menu();
		char select;
		cin >> select;
		switch (select) {
		case '1':
			gameView(play);
			break;
		case'2':
			setting(play);
			system("pause");
			break;
		case'0':
			cout << "�˳��ɹ�" << endl;
			system("pause");
			return 0;
		default:
			cout << "�Ұ��Զ��˳�" << endl;
			system("pause");
			return 0;
		}
	}
}