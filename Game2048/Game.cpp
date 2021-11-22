#include "Game.h"


#define VERTIKAL "\n\n\n\n\n\n"
#define HORIZONTAL "\t\t\t\t\t"
void PrintField(char Field[4][4][4])
{
	system("CLS");
	cout << VERTIKAL;
	for (size_t i = 0; i < 4; i++)
	{
		cout << HORIZONTAL << "  ---------------------------" << endl;
		cout << HORIZONTAL << " |      |      |      |      |" << endl;
		cout << HORIZONTAL;
		for (size_t j = 0; j < 4; j++)
		{			
			cout << " | ";
			for (size_t z = 0; z < 4; z++)
			{
				cout << Field[i][j][z];
			}
			
		}
		cout <<" | " << endl;
		cout << HORIZONTAL << " |      |      |      |      |" << endl;
	}
	cout << HORIZONTAL << "  ---------------------------" << endl;
}

int CharInt(char Field[4][4][4], const size_t RowValue, const size_t ColumValue)
{
	int value = 0;
	int n = 1;
	
	for (size_t z = 0; z < 4; z++)
	{
		if (Field[RowValue][ColumValue][z]!=' ')
		{
			for (size_t i = 0; i < 3-z; i++)n *= 10;
			value = value + ((int)(Field[RowValue][ColumValue][z] - 48)*n);
		}
		n = 1;
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

void IntChar(char Field[4][4][4], const size_t RowValue, const size_t ColumValue, const int value)
{
	int tmp = value;
	
	for (size_t z = 0; z < 4; z++)
	{
		if (!tmp)
		{
			Field[RowValue][ColumValue][4 - z - 1] = ' ';
		}
		else 
		{
			Field[RowValue][ColumValue][4-z-1] = tmp%10 + 48;
			tmp = tmp / 10;
		}		
	} 
	
}

void UpField(char Field[4][4][4], bool& flag)
{
	for (size_t j = 0; j < 4; j++)
	{
		for (size_t l = 0; l < 4; l++)
		{
			for (size_t i = 0; i < 4-1; i++)
			{
				if (CharInt(Field,i,j)==0)
				{
					if (CharInt(Field, i+1, j)!=0 && flag==1)
					{
						flag = 0;
					}
					for (size_t z = 0; z < 4; z++)
					{
						char tmp = Field[i][j][z];
						Field[i][j][z]= Field[i+1][j][z];
						Field[i + 1][j][z] = tmp;
						
					}		
					
				}
				else if (CharInt(Field, i, j)== CharInt(Field, i + 1, j) && (CharInt(Field, i, j)%2==0))
				{
					IntChar(Field, i, j, CharInt(Field, i, j) * 2 + 1);//+1 פכאד קעמ בûכא סףללא
					IntChar(Field, i + 1, j, 0);
					flag = 0;
				}
				
					
				
			}
		}
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				if (CharInt(Field, i, j) % 2 == 1)
				{
					Field[i][j][3] = Field[i][j][3] - 1;
				}
			}
		}
	}	
}

void DnField(char Field[4][4][4], bool& flag)
{
	for (size_t j = 0; j < 4; j++)
	{
		for (size_t l = 0; l < 4; l++)
		{
			for (size_t i = 0; i < 3 ; i++)
			{
				if (CharInt(Field, 3-i, j) == 0)
				{
					if (CharInt(Field, 2-i, j) != 0 && flag == 1)
					{
						flag = 0;
					}
					for (size_t z = 0; z < 4; z++)
					{
						char tmp = Field[3-i][j][z];
						Field[3-i][j][z] = Field[2-i][j][z];
						Field[2-i][j][z] = tmp;
					}
				}
				else if (CharInt(Field, 3-i, j) == CharInt(Field, 2-i, j) && (CharInt(Field, 3-i, j) % 2 == 0))
				{
					IntChar(Field, 3-i, j, CharInt(Field, 2-i, j) * 2 + 1);//+1 פכאד קעמ בûכא סףללא
					IntChar(Field, 2-i, j, 0);
					flag = 0;
				}
				
					
				
			}
		}
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				if (CharInt(Field, i, j) % 2 == 1)
				{
					Field[i][j][3] = Field[i][j][3] - 1;
				}
			}
		}
	}
}

void LeftField(char Field[4][4][4], bool& flag)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t l = 0; l < 4; l++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if (CharInt(Field, i, j) == 0)
				{
					if (CharInt(Field, i, j+1) != 0 && flag == 1)
					{
						flag = 0;
					}
					for (size_t z = 0; z < 4; z++)
					{
						char tmp = Field[i][j][z];
						Field[i][j][z] = Field[i][j+1][z];
						Field[i][j+1][z] = tmp;
					}
				}
				else if (CharInt(Field, i, j) == CharInt(Field, i, j + 1) && (CharInt(Field, i, j) % 2 == 0))
				{
					IntChar(Field, i, j, CharInt(Field, i, j) * 2 + 1);//+1 פכאד קעמ בûכא סףללא
					IntChar(Field, i, j+1, 0);
					flag = 0;
				}
				
					
				
			}
		}
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				if (CharInt(Field, i, j) % 2 == 1)
				{
					Field[i][j][3] = Field[i][j][3] - 1;
				}
			}
		}
	}
}

void RightField(char Field[4][4][4], bool& flag)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t l = 0; l < 4; l++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if (CharInt(Field, i, 3-j) == 0)
				{
					if (CharInt(Field, i, 2-j) != 0 && flag == 1)
					{
						flag = 0;
					}
					for (size_t z = 0; z < 4; z++)
					{
						char tmp = Field[i][3-j][z];
						Field[i][3-j][z] = Field[i][2-j][z];
						Field[i][2-j][z] = tmp;

					}
				}
				else if (CharInt(Field, i, 3-j) == CharInt(Field, i, 2-j) && (CharInt(Field, i, 3-j) % 2 == 0))
				{
					IntChar(Field, i, 3-j, CharInt(Field, i, 3-j) * 2 + 1);//+1 פכאד קעמ בûכא סףללא
					IntChar(Field, i, 2-j, 0);
					flag = 0;
				}
				
					
				
			}
		}
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				if (CharInt(Field, i, j) % 2 == 1)
				{
					Field[i][j][3] = Field[i][j][3] - 1;
				}
			}
		}
	}
}

void AddValue(char Field[4][4][4])
{
	int arr[16];
	int z = 0;
	int value;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (CharInt(Field, i, j)==0)
			{
				arr[z] = i * 10 + j;
				z++;
			}

		}
	}
	value = arr[rand() % (z)];
	IntChar(Field, value / 10, value % 10, 2);
}

int Victory(char Field[4][4][4])
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (CharInt(Field,i,j)==2048)
			{
				return 1;
			}
		}
	}
	return 0;
}

int GameOver(char Field[4][4][4])
{
	int g = 0;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (CharInt(Field, i, j)==0)
			{
				g++;
			}
		}
	}
	if (g>0)
	{
		return 0;
	}
	return 1;
}



