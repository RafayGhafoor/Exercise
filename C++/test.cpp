#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
void input2D ( int data[][5], int row, int col)
{
	for(int i =0;i<row; i++)
	{
		for(int j =0; j<col;j++)
		{
			cin>>data[i][j];
		}
	}
}
void output2D ( int data[][5], int row, int col)
{
	for(int i =0;i<row; i++)
	{
		for(int j =0; j<col;j++)
		{
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
}
void rotate(int data[][5])
{
	int x=0,y=0;
	int swp = data[x][y];

	for(int i=0;i<4;i++)
	{
		data[0][i]=data[0][i+1];
	}
	for(int i=0;i<4;i++)
	{
		data[i][4]=data[i+1][4];
	}
	for(int i=4;i>0;i--)
	{
		data[4][i]=data[4][i-1];
	}
	for(int i=4;i>0;i--)
	{
		data[i][0]=data[i-1][0];
	}
	data[x+1][y]=swp;
}
int main()
{
	int data[5][5]= {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	rotate(data);
	output2D ( data, 5, 5 );
	system("pause");
}
