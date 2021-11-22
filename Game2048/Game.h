#pragma once
#include"stdafx.h"

void PrintField(char Field[4][4][4]);//Вывод поля на экран
int CharInt(char Field[4][4][4], const size_t row, const size_t colum);//Перевод массива char из 3д матрицы в число int
void ComplitFild(char Field[4][4][4]);//заполняет 3д матрицу пробелами
void IntChar(char Field[4][4][4], const size_t row, const size_t colum, const int value);//Перевод числа int в массива char с записью в 3д матрицу
void UpField(char Field[4][4][4], bool& flag);
void DnField(char Field[4][4][4], bool& flag);
void LeftField(char Field[4][4][4], bool& flag);
void RightField(char Field[4][4][4], bool& flag);
void AddValue(char Field[4][4][4]);
int Victory(char Field[4][4][4]);
int GameOver(char Field[4][4][4]);
