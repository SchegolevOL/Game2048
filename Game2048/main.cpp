#include<iostream>
#include<Windows.h>
#include<time.h>
#include <stdlib.h>
#include"Game.h"

using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	char Field[4][4][4];
	ComplitFild(Field);
	
	Field[0][0][0] = ' ';
	Field[0][0][1] = ' ';
	Field[0][0][2] = '2';
	Field[0][0][3] = '8';
	PrintField(Field);
	cout << CharInt(Field, 0, 0) << endl;
	IntChar(Field,1,3,2);
	
	PrintField(Field);
	return 0;
}