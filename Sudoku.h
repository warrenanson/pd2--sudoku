#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include<algorithm>
using namespace std;

class Sudoku
{
	public:
		void giveQuestion(); 
		void readIn(); 
		void solve(); 
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		
	private:
		int map[9][9];
		int trans[9][9];
		int temp[9][9];
		void print();
		bool check(int num);
		bool compare(int num);

};

