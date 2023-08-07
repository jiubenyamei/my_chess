#include<iostream>
using namespace std;
#include"棋子.h"
#include"管理.h"
//提示
void tip(int i) {
	if (i % 2 == 0) {
		cout << "现在是第"<<i-1<<"子  现在是黑方下棋" << endl;
	}
	else {
		cout << "现在是第" << i - 1 << "子 现在是白方下棋" << endl;
	}
}
//菜单
void menu() {
		cout << "\t这里是五子棋" << endl;
		cout << "\t输入你的选择" << endl;
		cout << "\t1.开始游戏\n";
		cout << "\t2.设置\n";
		cout << "\t0.退出" << endl;
	
}
//游戏开始
void gameView(Chess& play) {
	int round = 2;
	int win = 0;
	play.newChess();
	while (true) {
		system("cls");
		//棋盘和棋子显示
		Map(play);
		//提示
		tip(round);
		play.down(round);
		system("pause");
		play.Win(round, win);
		if (win == 1) { cout << "感谢游玩" << endl; system("pause"); return; }
		round++;
	}
}
void Map(Chess &ch) {
	//水平距离提示
	cout << "\t";
	for (int i = 0; i < 9; i++) {
		cout << i+1 << "  ";
	}
	for (int i = 9; i < 19; i++) {
		cout << i + 1<<" ";
	}
	cout << endl;
	//竖直距离提示和棋子
	for (int i = 0; i < 19; i++) {
		cout << i + 1<<"\t";
		for (int j = 0; j < 19; j++) {
		
			cout << Color(ch,i,j,ch.whiteColor,ch.blackColor) << "  ";
		}cout << endl;
	}
}
//皮肤
string Color(Chess &ch,int y, int x, int white, int black) {
	if (ch.ch[y][x] == 0) {
		string temp = " ";
		return temp;
	}
	//黑棋
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
	//白棋
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
//设置
void setting(Chess& ch) {
	while (true) {
		system("cls");
		cout << "\t这里是设置" << endl;
		cout << "\t做出你的选择" << endl;
		cout << "\t1.更改黑子皮肤" << endl;
		cout << "\t2.更改白子皮肤" << endl;
		cout << "\t0.退出" << endl;
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
			cout << "退出成功" << endl;
		}
		break;
	}
}
