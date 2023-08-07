#include"����.h"
#include"����.h"
#include<iostream>
using namespace std;
void Chess::newChess() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			map<int, int>temp;
			temp.insert(make_pair(j, 0));
			this->ch.insert(make_pair(i,temp));
		}
	}
}
void Chess::down(int i) {
	while (true) {
		int x;//���պ�����
		cout << "����Ŀ���x��" << endl;
		cin >> x;
		if (x < 1 || x>19) {
			cout << "û�и����꣬����������" << endl;
			system("pause");
			system("cls");
			Map(*this);
			continue;
		}
		int y;//����������
		cout << "����Ŀ���y��" << endl;
		cin >> y;
		if (y < 1 || y>19) {
			cout << "û�и����꣬����������" << endl;
			system("pause");
			system("cls");
			Map(*this);
			continue;
		}
		x -= 1; y -= 1;
		if (this->ch[y][x] != 0) {
			cout << "�����ظ����ӣ���������" << endl;
			system("pause");
			system("cls");
			Map(*this);
			continue;
		}
		if (i % 2 == 0) {
			this->ch[y][x] = 1;
			break;
		}
		else {
			this->ch[y][x] = 2;
			break;
		}
	}
}
void Chess::Win(int round,int &win) {
	//�������ʤ��
	for (int y = 0; y < 19; y++) {
		for (int x = 0; x < 15; x++) {
			if (this->ch[y][x]!=0 && this->ch[y][x] == this->ch[y][x + 1] && this->ch[y][x] == this->ch[y][x + 2]
				&& this->ch[y][x] == this->ch[y][x + 3] && this->ch[y][x] == this->ch[y][x + 4]) {
				if (round % 2 == 0) {
					system("cls"); Map(*this);
					cout << "�ڷ�ʤ��" << endl; win = 1; break;
				}
				else {
					system("cls"); Map(*this);
					cout << "�׷�ʤ��" << endl; win = 1; break;
				}
			}
		}
	}
	//�������ʤ��
	for (int x = 0; x < 19; x++) {
		for (int y = 0; y < 15; y++) {
			if (this->ch[y][x] != 0 && this->ch[y][x] == this->ch[y+1][x] && this->ch[y][x] == this->ch[y+2][x ]
				&& this->ch[y][x] == this->ch[y+3][x] && this->ch[y][x] == this->ch[y+4][x]) {
				if (round % 2 == 0) {
					system("cls"); Map(*this);
					cout << "�ڷ�ʤ��" << endl; win = 1;   break;
				}
				else {
					system("cls"); Map(*this);
					cout << "�׷�ʤ��" << endl; win = 1; break;
				}
			}
		}
	}
	//���ϵ�����б��5��ʤ��
	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 15; y++) {
			if (this->ch[y][x] != 0 && this->ch[y][x] == this->ch[y + 1][x+1] && this->ch[y][x] == this->ch[y + 2][x+2]
				&& this->ch[y][x] == this->ch[y + 3][x+3] && this->ch[y][x] == this->ch[y + 4][x+4]) {
				if (round % 2 == 0) {
					system("cls"); Map(*this);
					cout << "�ڷ�ʤ��" << endl; win = 1;   break;
				}
				else {
					system("cls"); Map(*this);
					cout << "�׷�ʤ��" << endl; win = 1; break;
				}
			}
		}
	}
	//���ϵ�����б��5��ʤ��
	for (int x = 18; x > 3; x--) {
		for (int y = 0; y < 15; y++) {
			if (this->ch[y][x] != 0 && this->ch[y][x] == this->ch[y + 1][x - 1] && this->ch[y][x] == this->ch[y + 2][x - 2]
				&& this->ch[y][x] == this->ch[y + 3][x - 3] && this->ch[y][x] == this->ch[y + 4][x - 4]) {
				if (round % 2 == 0) {
					system("cls"); Map(*this);
					cout << "�ڷ�ʤ��" << endl; win = 1;   break;
				}
				else {
					system("cls"); Map(*this);
					cout << "�׷�ʤ��" << endl; win = 1; break;
				}
			}
		}
	}
}
void Chess::change(char ch) {
	if (ch == '1') {
		cout << "ѡ����ĵĺ���Ƥ��" << endl;
		cout << "1.X 2.O 3.1" << endl;
		int i = 1;
		cin >> i; 
		if (i == 1 || i == 2 || i == 3) {
			this->blackColor = i;
			cout << "�����ɹ�" << endl;
		}
		else {
			cout << "����ʧ��" << endl;
			return;
		}
	}
	else {
		cout << "ѡ����ĵİ���Ƥ��" << endl;
		cout << "1.O 2.X 3.2" << endl;
		int i = 1;
		cin >> i;
		if (i == 1 || i == 2 || i == 3) {
			this->whiteColor = i;
			system("pause");
		}
		else {
			cout << "����ʧ��" << endl;
			return;
		}
	}
}
 Chess::Chess(int i) {
	 this->whiteColor = i;
	 this->blackColor = i;
}