#pragma once
#include<iostream>
using namespace std;
#include<map>
class Chess {
public:
	//�вι���
	Chess(int i);
	//��������
	map<int, map<int, int>>ch;
	//��ʼ������
	void newChess();
	//����
	void down(int i);
	//����Ƥ��
	int whiteColor;
	//����Ƥ��
	int blackColor;
	//�ж�ʤ��
	void Win(int i,int &win);
	//����Ƥ��
	void change(char ch);
};