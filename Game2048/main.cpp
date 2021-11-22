#include<iostream>
#include<Windows.h>
#include<time.h>
#include <stdlib.h>
#include<conio.h>
#include"Game.h"

using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));




	bool flag = 0;
	char Field[4][4][4];
	ComplitFild(Field);
	
	AddValue(Field);
	
	do
	{
		if (flag==0)
		{
			AddValue(Field);
		}
		flag = 1;
		PrintField(Field);
		char key;
		key = _getch();
		

		switch (key)
		{
			case 'w':
			{
				UpField(Field, flag);
				PrintField(Field);
				break;
			}
			case 's':
			{
				DnField(Field, flag);
				PrintField(Field);
				break;
			}
			case 'a':
			{
				LeftField(Field, flag);
				PrintField(Field);
				break;
			}
			case 'd':
			{
				RightField(Field, flag);
				PrintField(Field);
				break;
			}

			default:
				flag = 1;
				break;
		}
		if (Victory(Field)==1)
		{
			cout << "Победа";
			break;
		}
		if (GameOver(Field)==1)
		{
			cout << "GameOver";
			break;
		}
		
	} 
	while (!0);
	ComplitFild(Field);
	




	return 0;
}