#pragma once
#include"stdafx.h"

void PrintField(char Field[4][4][4]);//����� ���� �� �����
int CharInt(char Field[4][4][4], const size_t row, const size_t colum);//������� ������� char �� 3� ������� � ����� int
void ComplitFild(char Field[4][4][4]);//��������� 3� ������� ���������
void IntChar(char Field[4][4][4], const size_t row, const size_t colum, const int value);//������� ����� int � ������� char � ������� � 3� �������
void UpField(char Field[4][4][4]);
void DnField(char Field[4][4][4]);
void LeftField(char Field[4][4][4]);
void RightField(char Field[4][4][4]);

