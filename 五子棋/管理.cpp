#include<iostream>
using namespace std;
#include"����.h"
#include"����.h"
//��ʾ
void tip(int i) {
	if (i % 2 == 0) {
		cout << "�����ǵ�"<<i-1<<"��  �����Ǻڷ�����" << endl;
	}
	else {
		cout << "�����ǵ�" << i - 1 << "�� �����ǰ׷�����" << endl;
	}
}
//�˵�
void menu() {
		cout << "\t������������" << endl;
		cout << "\t�������ѡ��" << endl;
		cout << "\t1.��ʼ��Ϸ\n";
		cout << "\t2.����\n";
		cout << "\t0.�˳�" << endl;
	
}
//��Ϸ��ʼ
void gameView(Chess& play) {
	int round = 2;
	int win = 0;
	play.newChess();
	while (true) {
		system("cls");
		//���̺�������ʾ
		Map(play);
		//��ʾ
		tip(round);
		play.down(round);
		system("pause");
		play.Win(round, win);
		if (win == 1) { cout << "��л����" << endl; system("pause"); return; }
		round++;
	}
}
void Map(Chess &ch) {
	//ˮƽ������ʾ
	cout << "\t";
	for (int i = 0; i < 9; i++) {
		cout << i+1 << "  ";
	}
	for (int i = 9; i < 19; i++) {
		cout << i + 1<<" ";
	}
	cout << endl;
	//��ֱ������ʾ������
	for (int i = 0; i < 19; i++) {
		cout << i + 1<<"\t";
		for (int j = 0; j < 19; j++) {
		
			cout << Color(ch,i,j,ch.whiteColor,ch.blackColor) << "  ";
		}cout << endl;
	}
}
//Ƥ��
string Color(Chess &ch,int y, int x, int white, int black) {
	if (ch.ch[y][x] == 0) {
		string temp = " ";
		return temp;
	}
	//����
	else if (ch.ch[y][x] == 1) {
		string temp ;
		switch (ch.blackColor) {
		case 1:
			temp = "X";
			break;
		case 2:
			temp = "O";
			break;
		case 3:
			temp = "1";
			break;
		}
		return temp;
	}
	//����
	else if (ch.ch[y][x] == 2) {
		string temp = "O";
		switch (ch.whiteColor) {
		case 1:
			temp = "O";
			break;
		case 2:
			temp = "X";
			break;
		case 3:
			temp = "2";
			break;
		}
		return temp;
	}
}
//����
void setting(Chess& ch) {
	while (true) {
		system("cls");
		cout << "\t����������" << endl;
		cout << "\t�������ѡ��" << endl;
		cout << "\t1.���ĺ���Ƥ��" << endl;
		cout << "\t2.���İ���Ƥ��" << endl;
		cout << "\t0.�˳�" << endl;
		char select;
		cin >> select;
		switch (select) {
		case '1':
			ch.change(select);
			break;
		case '2':
			ch.change(select);
			break;
		default:
			cout << "�˳��ɹ�" << endl;
		}
		break;
	}
}
