#pragma once
#include<map>
#include"棋子.h"
#include<iostream>
using namespace std;
//菜单
void menu();
//游戏开始、
void gameView(Chess&play);
//棋盘
void Map(Chess& ch);
//显示皮肤
string Color(Chess& ch,int x, int y, int white, int black);
//设置
void setting(Chess& ch);