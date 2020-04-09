#include <iostream>
#include <string>
using namespace std;
char c[17][33];
bool first(int k)
{
	if(k == 1 || k == 5 || k == 9 || k == 13)
		return true;
	return false;
}
void init(int myRow, int myCol)
{
	for(int i = 0; i < myRow; i++)
	{
		for(int j = 0; j < myCol; j++)
		{
			if(i % 2 == 0)
			{
				for(int k = 0; k < myCol; k++)
				{
					if(k % 4 == 0)
						c[i][k] = '+';
					else 
						c[i][k] = '-';
				}
				break;
			}
			else
			{
				if(first(i)) //白黑 
				{
					for(int k = 0; k < myCol; k++)
					{
						if(k % 4 == 0)
							c[i][k] = '|';
						else
						{
							if(k % 8 < 4)
							{
								c[i][k] = '.';
							}
							else
							{
								c[i][k] = ':';
							}
						}
					}
					break;
				}
				else //黑白 
				{
					for(int k = 0; k < myCol; k++)
					{
						if(k % 4 == 0)
							c[i][k] = '|';
						else
						{
							if(k % 8 > 4)
							{
								c[i][k] = '.';
							}
							else
							{
								c[i][k] = ':';
							}
						}
					}
					break;
				}
			}
		}
	}
}
bool role(char cc)
{
	if(cc == 'K' || cc == 'Q' || cc == 'R' || cc == 'B' || cc == 'N')
		return true;
	return false;
}
void deal(int myRow, int myCol)
{
	string b;
	getline(cin, b); //白 
	string a;
	getline(cin, a); //黑 
	int k = 0;
	while(b[k++] != 'K');
	int m = k - 1;
	while(m < b.length())
	{
		if(role(b[m]))
		{
			int col = (b[m + 1] - 'a') * 4 + 2;
			int row = 15 - (int(b[m + 2] - '0') - 1 ) * 2; 
			switch(b[m])
			{		
			case 'K':	
				c[row][col] = 'K';
				break;
			case 'Q':
				c[row][col] = 'Q'; 
				break;
			case 'R':
				c[row][col] = 'R'; 
				break;
			case 'B':
				c[row][col] = 'B'; 
				break;
			case 'N':
				c[row][col] = 'N'; 
				break;
			}
			m += 4;
		}
		else
		{
			int col = col = (b[m] - 'a') * 4 + 2;
			int row = 15 - (int(b[m + 1] - '0') - 1 ) * 2; 
			c[row][col] = 'P';
			m += 3;	
		}
	}
	//	getline(cin, b);
	k = 0;
	while(a[k++] != 'K');
	m  = k - 1;
	while(m < a.length())
	{
		if(role(a[m]))
		{
			int col = (a[m + 1] - 'a') * 4 + 2;
			int row = 15 - (int(a[m + 2] - '0') - 1 ) * 2; 
			switch(a[m])
			{		
			case 'K':	
				c[row][col] = 'k';
				break;
			case 'Q':
				c[row][col] = 'q'; 
				break;
			case 'R':
				c[row][col] = 'r'; 
				break;
			case 'B':
				c[row][col] = 'b'; 
				break;
			case 'N':
				c[row][col] = 'n'; 
				break;
			}
			m += 4;
		}
		else
		{
			int col = col = (a[m] - 'a') * 4 + 2;
			int row = 15 - (int(a[m + 1] - '0') - 1 ) * 2; 
			c[row][col] = 'p';
			m += 3;	
		}
	}
}
void print(int myRow, int myCol)
{
	for(int i = 0; i < myRow; i++)
	{
		for(int j = 0; j < myCol; j++)
		{
			cout<<c[i][j];
		}
		cout<<endl;
	}		
}
int main()
{
	int myRow = 17;
	int myCol = 33;
	init(myRow, myCol);
	deal(myRow, myCol);
	print(myRow, myCol);
	return 0;	
}