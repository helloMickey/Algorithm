/*
����2013����Ե����⣺
���������Թ���Ѱ������������֮��ľ��롱
*/
#include<vector>
#include<iostream>
#include <queue>
using namespace std;

const int lowB = 0;
const int highB = 99;
const int mazeEdgeSize = 100;//
const int mazeSize = 10000;//100*100
const int sX = 50;//����1 ����㣻
const int sY = 49;
struct{
	int increX;
	int increY;
}incre[mazeSize + 1];
struct Point{
	int x;
	int y;
};
vector<int> getPrimeNumber(){//��ȡ1-10000֮�����������
	vector<int> result;
	bool IisPrimeNum[ mazeSize + 1 ]={};
	for(int i = 0; i <= mazeSize; i++)
		IisPrimeNum[i] = true;
	IisPrimeNum[0]=false;
	IisPrimeNum[1]=false;
	for(int i = 2; i <= (mazeSize/2); i++)
	{
		int it = 2;
		while(i*it <= mazeSize){
			IisPrimeNum[i*it] = false;
			it++;
		}
	}
	for(int i = 2; i <= mazeSize; i++)
		if(IisPrimeNum[i])
			result.push_back(i);
	return result;
}
void constructMaze()
{

	//����ƫ��������
	//����1 ��λ�ã�50�� 49��//��������������ѭ������������Ϊ1��1��2��2��3��3��4��4��5��5������
	incre[0].increX = 0;incre[0].increY = 0; incre[1].increX = 0;incre[1].increY = 0;
	int delta = 0; int derict = 0;
	for(int i = 2; i <= mazeSize; i++){
		if(i%2 == 0) delta++;
		switch(derict%4){
		case 0:
			incre[i].increX = delta;
			incre[i].increY = 0;
		case 1:
			incre[i].increX = 0;
			incre[i].increY = (0 - delta);
		case 2:
			incre[i].increX = (0 - delta);
			incre[i].increY = 0;
		case 3:
			incre[i].increX = 0;
			incre[i].increY = delta;
		}
		derict++;
	}

	//�����Թ�
	vector<vector<int>> primeNumMaze(mazeEdgeSize, vector<int>(mazeEdgeSize));
	vector<int> primeNumList = getPrimeNumber();

	primeNumMaze[sX][sY] = 0;//��ֵ0��ʾ��������
	int count = 2;int curX = sX, curY = sY;
	for(int i = 0; i < primeNumList.size(); i++)
	{
		while (count != primeNumList[i])
		{//������ǰ��
			int x = curX + incre[count].increX,
				y = curY + incre[count].increY;
			primeNumMaze[x][y] = 0;
			count++;
		}
		primeNumMaze[curX][curY] = count; //��ǰcount������
	}

}
//������ȱ���
void BFS(vector<vector<int>> maze, int sX,int sY, int end)
{
	vector<vector<bool>> visit;//����Ƿ���ʹ�
	queue<Point> q;
	int curX = sX, curY = sY;
	Point start; 
	start.x = curX;start.y = curY;
	q.push(start);
	while( !q.empty()){
		//if()
	}

}
//int main()
//{
//	vector<int> primeNumList = getPrimeNumber();
//	for(int i = 0; i < primeNumList.size(); i++)
//	{
//		cout << primeNumList[i] << endl;
//	}
//}