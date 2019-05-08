#include <iostream>
#include "Parkh.h"
using namespace std;



int main()
{
	const int numv = 10;
	int op = 1;
	/*
	int border[numv][numv] = { {0,1,2,2,0,0,0,0,0,0},
	{1,0,0,2,0,5,0,0,0,0},
	{2,0,0,3,3,0,4,9,0,0},
	{2,2,3,0,4,3,2,3,5,4},
	{0,0,3,4,0,0,1,0,2,0},
	{0,5,0,3,0,0,5,2,0,3},
	{0,0,4,2,1,5,0,4,2,0},
	{0,0,5,3,0,2,4,0,2,1},
	{0,0,0,0,2,0,2,2,0,6},
	{0,0,0,4,0,3,0,1,6,0}, };
	*/
	string vname[numv] = { "公园正门","猴山","倚梅园","情人湖", "通幽小径",
		                   "紫竹林","八角亭","观景台","昙华林","茶园", };
	//int *p;
	string *q;
	int *x = new int[100];
	int *y = new int[100];
	for (int i = 0; i < n; i++)
	{
		x[i] = 0;
		y[i] = 0;
	}
	//p = &border[0][0];
	q = vname;
	Park pa(q, numv);
	pa.show();
	pa.Hamiltonian(x,y);
	return 0;
}
