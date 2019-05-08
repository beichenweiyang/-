#ifndef PARKH
#define PARKH

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAXSIZE = 15;
const int n = 10;
int j = 0;
class Park
{
public:
	Park(string *v,int n);
	~Park() {};
	void NextValue(int k, int *x);
	void Hamiltonian(int k, int *x,int *y);
	void Hamiltonian(int *x,int *y);
	void show();

private:
	string vertex[MAXSIZE];        //顶点值
	int arc[MAXSIZE][MAXSIZE];     //邻接矩阵
	int vertexnum;                 //顶点数
	int sum = 0;
	int road = 10000;
};

Park::Park(string *v,int n) 
{
	int i, j;
	ifstream fin;
	fin.open("Park.txt", ios::in);
	if (!fin)
	{
		cout << "无法打开文件！" << endl;
		return;
	}
	else 
	{
		vertexnum = n;
		for (i = 0; i < MAXSIZE; i++)
		{
			for (j = 0; j < MAXSIZE; j++)
			{
				arc[i][j] = 0;
			}
		}
		for (i = 0; i < vertexnum; i++)
		{
			vertex[i] = v[i];
		}
		for (i = 0; i < vertexnum; i++)
		{
			for (j = 0; j < vertexnum; j++)
			{
				fin >> arc[i][j];
			}
		}
	}

}


void Park::NextValue(int k, int *x)     //寻找与当前结点相连的下一个结点
{
	int j;
	do {
		x[k] = (x[k] + 1) % n;               //下一个结点编号   
		if (!x[k])
		{
			return;
		}
		if (arc[x[k - 1]][x[k]])             //(x[k-1],x[k])之间是否是图中一条边 
		{
			for (j = 0; j < k; j++)          //检查与前k个结点是否有相同的 
			{
				if (x[j] == x[k])            //结点x[k]与前k个结点有重复，则结束循环
				{
					break;
				}
			}
			if (j == k)                    //若与前k个结点都不相同，则x[k]结点是当前可取的结点编号
			{
				if ((k < n - 1) || ((k == n - 1) && arc[x[n - 1]][x[0]]))//若此结点不是最后一个结点或者
				{                                                         //此结点为最后一个结点且与首结点相连接
					return;
				}
			}
		}
	} while (1);
}
void Park::Hamiltonian(int k, int *x,int *y)        //寻找地图中的所有哈密顿环路，并输出最短距离的哈密顿环路
{

	do {
		NextValue(k, x);                   //寻找与当前结点相连的下一个结点   
		if (!x[k])
		{
			if (k == 1)                    //当递归函数依次向外推出至最外层时，则寻找出了图中所有环路，此时输出最短路径。
			{
				cout << "\t  最佳路径为 ：" << endl<<"\t\t";
				for (int m = 0; m < n; m++)
				{
					cout <<"(" << y[m] << ")" << vertex[y[m]] << "->";
					if (m == 7)
					{
						cout << endl << "\t  ";
					}
				}
				cout << "(0)公园正门" << endl << "\t\t这条路径需要您步行" << road << "公里." << endl;
			}	
			return;                       //x[k]=0，表示已经没有可取结点  
		}
		if (k == n - 1)            //寻找到一个哈密顿环，并计算该条路径的所要行走的长度 
		{
			
			j++;
			cout << "第" << j << "条路径:  ";
			for (int i = 0; i < n; i++)
			{
			cout <<"("<< x[i] <<")"<< vertex[x[i]]<<"->";
			}
			cout << "(0)公园正门" << endl;
			
			for (int h = 0; h < n; h++)
			{
				sum = sum + arc[x[h]][x[(h + 1) % n]];
			}
			cout << "\t    需要走" << sum << "公里." << endl << endl;
			if (road > sum)          //若此条路径的长度小于上一条路径的长度，则保存这条路径的长度以及结点遍历的先后顺序 
			{
				road = sum;
				for (int g = 0; g < n; g++)
				{
					y[g] = x[g];
				}
			}
			sum = 0;
		}
		else
		{
			Hamiltonian(k + 1, x, y);         //深度优先进入下一层  
		}
	} while (1);
}
void Park::Hamiltonian(int *x,int *y)
{
	Hamiltonian(1, x, y);
}


void Park::show()
{
	cout << "\t                                   欢迎使用公园导游系统                                       " << endl;
	cout << " \t --------------------------------------------------------------------------------------------" << endl;
	cout << " \t|\t                                                                                     |" << endl;
	cout << " \t|\t                                  公园地图                                           |"<< endl;
	cout << " \t|\t                                                                                     |" << endl;
	cout << " \t|\t    (8) 昙 华 林-------------------------------------------(9) 茶 园                 |"<< endl;
	cout << " \t|\t        | | | |                                               | | |                  |" << endl;
	cout << " \t|\t        | | |  ---                                            | | |                  |" << endl;
	cout << " \t|\t        | | |     |                                           | | |                  |" << endl;
	cout << " \t|\t        | | |      ==============(7) 观 景 台-----------------  | |                  |" << endl;
	cout << " \t|\t        | | |     |                   / | |                     | |                  |" << endl;
	cout << " \t|\t        | | |     |         ----------  |  ---------------    --  |                  |" << endl;
	cout << " \t|\t        | | |     |       /             |                 |  |    |                  |" << endl;
	cout << " \t|\t        | |  ----(|)-(6) 八 角 亭------(|)---------(5) 紫 竹 林   |                  |" << endl;
	cout << " \t|\t        | |       |      | | |________  |             /     |     |                  |" << endl;
	cout << " \t|\t        |  ------(|)----(| |)-------  | |  ----------       |     |                  |" << endl;
	cout << " \t|\t        |    ____(|)_____| |        | | | |                 |     |                  |" << endl;
	cout << " \t|\t        |   |     |        |        | | | |                 |     |                  |" << endl;
	cout << " \t|\t    (4)通幽小径--(|)------(|)---(3) 情 人 湖 --------------(|)----                   |" << endl;
	cout << " \t|\t          |       |        |   ______| | |                  |                        |" << endl;
	cout << " \t|\t          |       |______  |  |        | |                  |                        |" << endl;
	cout << " \t|\t          |              | |  |        | |                  |                        |" << endl;
	cout << " \t|\t           ----------(2) 倚 梅 园      |  ------------(1) 猴 山                      |" << endl;
	cout << " \t|\t                            |          |                    |                        |" << endl;
	cout << " \t|\t                            |          |                    |                        |" << endl;
	cout << " \t|\t                             ------(0)公园正门--------------                         |" << endl;
	cout << " \t|\t                                                                                     |" << endl;
	cout << " \t --------------------------------------------------------------------------------------------" << endl;


	cout << endl;

}
#endif // PARKH



