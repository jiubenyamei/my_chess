#pragma once
#include<iostream>
using namespace std;
#include<map>
class Chess {
public:
	//有参构造
	Chess(int i);
	//棋子容器
	map<int, map<int, int>>ch;
	//初始化棋子
	void newChess();
	//下棋
	void down(int i);
	//白棋皮肤
	int whiteColor;
	//黑棋皮肤
	int blackColor;
	//判断胜利
	void Win(int i,int &win);
	//更改皮肤
	void change(char ch);
};