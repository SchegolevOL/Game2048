#include "Game.h"


#define VERTIKAL "\n\n\n\n\n\n"
#define HORIZONTAL "\t\t\t\t\t"
void PlayField(char Field[4][4][4])
{
	for (size_t i = 0; i < 4; i++)
	{
		cout << "  ---------------------------" << endl;
		cout << " |      |      |      |      |" << endl;
		for (size_t j = 0; j < 4; j++)
		{			
			cout << " | ";
			for (size_t z = 0; z < 4; z++)
			{
				cout << Field[i][j][z];
			}
			
		}
		cout <<" | " << endl;
		cout << " |      |      |      |      |" << endl;
	}
	cout << "  ---------------------------" << endl;
}

int CharInt(char Field[4][4][4], const size_t row, const size_t colum)
{
	int value = 0;
	int n = 1;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t z = 0; z < 4; z++)
			{
				if (Field[i][j][z]!=' ')
				{
					for (size_t i = 0; i < 3-z; i++)n *= 10;
					value = value + ((int)(Field[i][j][z] - 48)*n);
				}
				n = 1;
			}
		}
	}
	return value;
}

void ComplitFild(char Field[4][4][4])
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t z = 0; z < 4; z++)
			{
				Field[i][j][z] = ' ';
			}

		}
	}
}
