#pragma once
#include<map>
#include"����.h"
#include<iostream>
using namespace std;
//�˵�
void menu();
//��Ϸ��ʼ��
void gameView(Chess&play);
//����
void Map(Chess& ch);
//��ʾƤ��
string Color(Chess& ch,int x, int y, int white, int black);
//����
void setting(Chess& ch);