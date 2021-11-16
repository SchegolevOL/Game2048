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

	char Field[4][4][4];
	/*do
	{
		char key;
		key = _getch();
		switch (key)
		{
			case '8':
			{

			break;
			}
			case '2':
			{

				break;
			}
			case '4':
			{

				break;
			}
			case '6':
			{

				break;
			}

			default:
				break;
		}
	} 
	while (!0);*/
	ComplitFild(Field);
	

	cout << CharInt(Field, 0, 0) << endl;
	IntChar(Field,1,3,2);
	IntChar(Field, 0, 0, 2);
	IntChar(Field, 1, 2, 2);
	IntChar(Field, 0, 2, 2);
	IntChar(Field, 2, 2, 4);
	IntChar(Field, 3, 0, 4);
	IntChar(Field, 3, 2, 2);
	IntChar(Field, 2, 1, 4);
	IntChar(Field, 3, 1, 4);
	IntChar(Field, 0, 0, 4);
	PrintField(Field);
	UpField(Field);	
	PrintField(Field);
	DnField(Field);
	PrintField(Field);
	
	


	return 0;
}