#include "Sudoku.h"

//int i,j;
int answer=0;
void Sudoku::giveQuestion()
{
	cout<<"0 9 0 0 0 5 6 1 3"<<endl;
	cout<<"0 0 0 0 7 0 0 0 2"<<endl;
	cout<<"5 0 0 0 0 1 0 4 8"<<endl;
	cout<<"0 0 0 5 0 6 0 2 0"<<endl;
	cout<<"0 0 0 0 1 0 0 0 0"<<endl;
	cout<<"0 1 0 2 0 3 0 0 0"<<endl;	
	cout<<"1 3 0 7 0 0 0 0 9"<<endl;
	cout<<"6 0 0 0 5 0 0 0 0"<<endl;
	cout<<"8 2 5 1 0 0 0 6 0"<<endl;
}

void Sudoku::readIn()
{
	int n=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>n;
			map[i][j]=n;
		}
	}
}

bool Sudoku::check(int num)
{
	if(answer>1)
		return true;
	if(num==81)
	{
		for(int i=0;i<9;++i) 
		{
			for(int j=0;j<9;++j) 
				temp[i][j] = map[i][j];		//存到暫存 
		}
//		return true;
		answer++;
	}
	else
	{
		
		int row = num / 9;	//i 個 
		int col = num % 9;	//j 排 
		
		if (map[row][col]==0)	//偵測到0 
		{
			for (int i=1;i<=9;++i)
			{
				map[row][col]=i;	//從1代進去比對 
				if(compare(num))	//比對同行同列沒有相同數字 
					check(num + 1);	//進行下一個數字比對 
	//			if(!compare(num))	//1-9全部失敗表示無解 
	//				return false;	
					map[row][col] = 0;
					
				
			}
		}
		
		else
			check(num+1);
	}
}

bool Sudoku::compare(int num)
{
	int row=num/9;	//i 個 
	int col=num%9;	//j 橫排 
	
	for (int j=0;j<9;++j)	//檢查同橫排 
	{
		if(map[row][j] == map[row][col] && j!=col)
			return false;
	}
	
	for(int i=0;i<9;++i)	//檢查同直排 
	{
		if (map[i][col] == map[row][col] && i!=row)
			return false;
	}
	
	int rowB = row / 3 * 3;
	int colB = col / 3 * 3;
	for(int i=rowB;i<rowB+3;++i)	//檢查九宮格 
	{
		for(int j=colB;j<colB+3;++j)
		{
			if (map[i][j] == map[row][col] && i!=row && j!=col)
				return false;
		}
	}
	return true;
} 

void Sudoku::solve()
{
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			if(compare(i*9+j)== false && map[i][j] != 0)
			{
				cout<<"0"<<endl;
				return;
			}
		}
	}
	check(0);
	if(answer!=0)
	{
		if(answer==1)
		{
			cout<<"1"<<endl;
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					cout<<temp[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		else
			cout<<"2"<<endl;
	}
	else
		cout<<"0"<<endl;
}
		
void Sudoku::changeNum(int a, int b)
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			trans[i][j] = map[i][j];
			
			if(trans[i][j]==a)
				map[i][j]=b;
			
			else if(trans[i][j]==b)
				map[i][j]=a;
		}
	}
}
		
void Sudoku::changeRow(int a, int b)
{
	if(a==0)
	{
		if(b==1)
		{
			for(int j=0;j<9;j++)
			{
				swap(map[3][j],map[0][j]);
				swap(map[4][j],map[1][j]);
				swap(map[5][j],map[2][j]);
			}
		}
		else if(b==2)
		{
			for(int j=0;j<9;j++)
			{
				swap(map[6][j],map[0][j]);
				swap(map[7][j],map[1][j]);
				swap(map[8][j],map[2][j]);
			}
		}
	}
	
	else if(a==1)
	{
		if(b==0)
		{
			for(int j=0;j<9;j++)
			{
				swap(map[3][j],map[0][j]);
				swap(map[4][j],map[1][j]);
				swap(map[5][j],map[2][j]);
			}
		}
		else if(b==2)
		{
					
			for(int j=0;j<9;j++)
			{
				swap(map[6][j],map[3][j]);
				swap(map[7][j],map[4][j]);
				swap(map[8][j],map[5][j]);
			}
		}
  	}
  	
	else if(a==2)
  	{
  		if(b==0)
  		{
  			for(int j=0;j<9;j++)
			{
				swap(map[6][j],map[0][j]);
				swap(map[7][j],map[1][j]);
				swap(map[8][j],map[2][j]);
			}
		}
  		
  		else if(b==1)
  		{
  			for(int j=0;j<9;j++)
			{
				swap(map[6][j],map[3][j]);
				swap(map[7][j],map[4][j]);
				swap(map[8][j],map[5][j]);
			}
		}
	}
}
		
void Sudoku::changeCol(int a,int b)
{
	if(a==0)
	{
		if(b==1)
		{
			for(int i=0;i<9;i++)
			{
				swap(map[i][3],map[i][0]);
				swap(map[i][4],map[i][1]);
				swap(map[i][5],map[i][2]);
			}
		}
		else if(b==2)
		{
			for(int i=0;i<9;i++)
			{
				swap(map[i][6],map[i][0]);
				swap(map[i][7],map[i][1]);
				swap(map[i][8],map[i][2]);
			}
		}
	}
			
	else if(a==1)
	{
		if(b==0)
		{
			for(int i=0;i<9;i++)
			{
				swap(map[i][3],map[i][0]);
				swap(map[i][4],map[i][1]);
				swap(map[i][5],map[i][2]);
			}
		}
		
		else if(b==2)
		{
			for(int i=0;i<9;i++)
			{
				swap(map[i][6],map[i][3]);
				swap(map[i][7],map[i][4]);
				swap(map[i][8],map[i][5]);
			}
		}
 	}
 	
 	else if(a==2)
 	{
 		if(b==0)
 		{
 			for(int i=0;i<9;i++)
			{
				swap(map[i][6],map[i][0]);
				swap(map[i][7],map[i][1]);
				swap(map[i][8],map[i][2]);
			}
		}
 		else if(b==1)
 		{
 			for(int i=0;i<9;i++)
			{
				swap(map[i][6],map[i][3]);
				swap(map[i][7],map[i][4]);
				swap(map[i][8],map[i][5]);
			}
		}
	}
}		

void Sudoku::rotate(int n)
{
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			trans[i][j] = map[i][j];
		}
	}
	if(n%4==0)			//旋轉0 
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				trans[i][j] = map[i][j];
			}
		}
	}
	else if(n%4==1)		//旋轉90 
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				trans[i][j] = map[8-j][i];
			}
		}
	}
			
	else if(n%4==2)		//選轉180 
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				trans[i][j] = map[8-i][8-j];
			}
		}
	}
			
	else if(n%4==3)		//旋轉270 
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				trans[i][j] = map[j][8-i];
			}
		}
	}
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			map[i][j] = trans[i][j];
		}
	}
}	

void Sudoku::flip(int n)
{
	if(n==0)
	{
		for(int i=0;i<9;i++)
		{
			swap(map[i][0],map[i][8]);
			swap(map[i][1],map[i][7]);
			swap(map[i][2],map[i][6]);
			swap(map[i][3],map[i][5]);
		}
	}
	else if(n==1)
	{
		for(int j=0;j<9;j++)
		{
			swap(map[0][j],map[8][j]);
			swap(map[1][j],map[7][j]);
			swap(map[2][j],map[6][j]);
			swap(map[3][j],map[5][j]);
		}
	}
}

void Sudoku::print()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}
		
void Sudoku::transform()
{
//	readIn();
	srand(time(NULL));
	changeNum(rand() % 10, rand() % 10);
	changeRow(rand() % 3, rand() % 3);
	changeCol(rand() % 3, rand() % 3);
	rotate(rand() % 101);
	flip(rand() % 2);
	print();
}		
/*
int main()
{
	Sudoku ss;
	ss.readIn();
//	ss.transform();
	ss.solve();
	return 0;
}
*/
