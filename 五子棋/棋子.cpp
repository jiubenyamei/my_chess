#include"棋子.h"
#include"管理.h"
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
		int x;//接收横坐标
		cout << "输入目标的x轴" << endl;
		cin >> x;
		if (x < 1 || x>19) {
			cout << "没有该坐标，请重新输入" << endl;
			system("pause");
			system("cls");
			Map(*this);
			continue;
		}
		int y;//接收纵坐标
		cout << "输入目标的y轴" << endl;
		cin >> y;
		if (y < 1 || y>19) {
			cout << "没有该坐标，请重新输入" << endl;
			system("pause");
			system("cls");
			Map(*this);
			continue;
		}
		x -= 1; y -= 1;
		if (this->ch[y][x] != 0) {
			cout << "不能重复下子，请重新下" << endl;
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
	//横着五个胜利
	for (int y = 0; y < 19; y++) {
		for (int x = 0; x < 15; x++) {
			if (this->ch[y][x]!=0 && this->ch[y][x] == this->ch[y][x + 1] && this->ch[y][x] == this->ch[y][x + 2]
				&& this->ch[y][x] == this->ch[y][x + 3] && this->ch[y][x] == this->ch[y][x + 4]) {
				if (round % 2 == 0) {
					system("cls"); Map(*this);
					cout << "黑方胜利" << endl; win = 1; break;
				}
				else {
					system("cls"); Map(*this);
					cout << "白方胜利" << endl; win = 1; break;
				}
			}
		}
	}
	//竖着五个胜利
	for (int x = 0; x < 19; x++) {
		for (int y = 0; y < 15; y++) {
			if (this->ch[y][x] != 0 && this->ch[y][x] == this->ch[y+1][x] && this->ch[y][x] == this->ch[y+2][x ]
				&& this->ch[y][x] == this->ch[y+3][x] && this->ch[y][x] == this->ch[y+4][x]) {
				if (round % 2 == 0) {
					system("cls"); Map(*this);
					cout << "黑方胜利" << endl; win = 1;   break;
				}
				else {
					system("cls"); Map(*this);
					cout << "白方胜利" << endl; win = 1; break;
				}
			}
		}
	}
	//左上到右下斜着5个胜利
	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 15; y++) {
			if (this->ch[y][x] != 0 && this->ch[y][x] == this->ch[y + 1][x+1] && this->ch[y][x] == this->ch[y + 2][x+2]
				&& this->ch[y][x] == this->ch[y + 3][x+3] && this->ch[y][x] == this->ch[y + 4][x+4]) {
				if (round % 2 == 0) {
					system("cls"); Map(*this);
					cout << "黑方胜利" << endl; win = 1;   break;
				}
				else {
					system("cls"); Map(*this);
					cout << "白方胜利" << endl; win = 1; break;
				}
			}
		}
	}
	//右上到左下斜着5个胜利
	for (int x = 18; x > 3; x--) {
		for (int y = 0; y < 15; y++) {
			if (this->ch[y][x] != 0 && this->ch[y][x] == this->ch[y + 1][x - 1] && this->ch[y][x] == this->ch[y + 2][x - 2]
				&& this->ch[y][x] == this->ch[y + 3][x - 3] && this->ch[y][x] == this->ch[y + 4][x - 4]) {
				if (round % 2 == 0) {
					system("cls"); Map(*this);
					cout << "黑方胜利" << endl; win = 1;   break;
				}
				else {
					system("cls"); Map(*this);
					cout << "白方胜利" << endl; win = 1; break;
				}
			}
		}
	}
}
void Chess::change(char ch) {
	if (ch == '1') {
		cout << "选择更改的黑子皮肤" << endl;
		cout << "1.X 2.O 3.1" << endl;
		int i = 1;
		cin >> i; 
		if (i == 1 || i == 2 || i == 3) {
			this->blackColor = i;
			cout << "更换成功" << endl;
		}
		else {
			cout << "更换失败" << endl;
			return;
		}
	}
	else {
		cout << "选择更改的白子皮肤" << endl;
		cout << "1.O 2.X 3.2" << endl;
		int i = 1;
		cin >> i;
		if (i == 1 || i == 2 || i == 3) {
			this->whiteColor = i;
			system("pause");
		}
		else {
			cout << "更换失败" << endl;
			return;
		}
	}
}
 Chess::Chess(int i) {
	 this->whiteColor = i;
	 this->blackColor = i;
}