/*
   UVA 670 The dog task
   AC by J_Dark
   ON 2013/4/20
   Time 0.016s
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int perNodeNum, dogNodeNum;
struct XY{
	int x, y;
	XY(int a=0, int b=0){ x=a, y=b;}
	double Distance(XY P){ return sqrt(((P.x-x)*(P.x-x)+ (P.y-y)*(P.y-y))*1.0);}
};
struct PER{   //人走的每段路
	XY u, v; //起点，终点
	double pathUV;  //路的长度
	PER(XY a, XY b){
	   u=a;
	   v=b;
	   pathUV = u.Distance(v);
	}
};
vector <XY> perSonNode, dog; //人，狗坐标
vector <PER> perSon; //人走的每段路程
 //邻接表，存储与狗的兴趣点邻接的人走的段路程，即存放狗在某兴趣点时，它可以去往的全部人的段路程
vector < vector<int> > reachedPer;
//存放匹配边
vector <int> pairDP;
//是否匹配标记
vector <bool> visited;
/////////////////////////////////////
void Initial(){
	perSon.clear();
	dog.clear();
	perSonNode.clear();
	reachedPer.clear();
	pairDP.clear();
	visited.clear();
}
void Input(){
	cin >> perNodeNum >> dogNodeNum;
	int x, y;
	for(int i=0; i<perNodeNum; i++){
		cin >> x >> y;
		perSonNode.push_back(XY(x,y));
	}
	for(int i=0; i<perSonNode.size()-1; i++){
		perSon.push_back( PER(perSonNode[i], perSonNode[i+1]) );
	}
	for(int i=0; i<dogNodeNum; i++){
		cin >> x >> y;
		dog.push_back(XY(x,y));
	}
	for(int i=0; i<perSon.size(); i++)
	   pairDP.push_back(-1);
}

void Solve(){
	const double eps = 1e-20; //1e-10wa, 1e-20AC, uva此题数据强大，汗颜……
	vector<int> personPath;
	//寻找每个兴趣点，狗可以匹配的所有人的段路程，建立{狗兴趣点——人段路程}二部图
	for(int d=0; d<dog.size(); d++){
		personPath.clear();
		for(int p=0; p<perSon.size(); p++){  //人的路程集合标号
			// 狗的速度最大可达到人速度2倍，满足2*人路程 > 狗的路程, 即可建立关系
			if(2*perSon[p].pathUV - (dog[d].Distance(perSon[p].u) + dog[d].Distance(perSon[p].v)) > eps)
			   personPath.push_back(p);
		}
		//将所有与d邻接的集合存入
		reachedPer.push_back(personPath);
	}
}
///////////////////////////////////////////////////////////////
//匈牙利算法求二分图最大匹配
bool findPath(int d){
	for(int i=0; i<reachedPer[d].size(); i++){
		int temp_p = reachedPer[d][i];
		if(!visited[temp_p]){
			visited[temp_p] = true;
			//若temp_p为未盖点 或者 从temp_p出发可以找到增广路
			if(pairDP[temp_p] == -1 || findPath(pairDP[temp_p])){
				pairDP[temp_p] = d;  //交换匹配边与非匹配边，使最大匹配数+1
				return true;
			}
		}
	}
	//从d出发未找到增广路
	return false;
}

void MaxMatch(){
	int maxMatch = 0;
	for(int d=0; d<dog.size(); d++){
		visited.clear();
		visited.resize(perSon.size());
		if(findPath(d))
		   maxMatch++;
	}
	cout << maxMatch+perNodeNum << endl;
	int cc=0;
	for(int i=0; i<perSon.size(); i++){
	    if(cc > 0) cout << " ";
	    cc++;
		cout << perSon[i].u.x << " " << perSon[i].u.y;
		if(pairDP[i] != -1){
		   cout << " " << dog[pairDP[i]].x << " " << dog[pairDP[i]].y;
		}
	}
	cout << " " << perSon[perSon.size()-1].v.x << " " << perSon[perSon.size()-1].v.y;
	cout << endl;
}
/////////////////////////////////////
int main(){
	int testCase;
	while(cin >> testCase)
	{
		getchar();
		getchar();
		for(int i=0; i<testCase; i++)
		{
		   if(i>0) cout << endl;
		   Initial();
		   Input();
		   Solve();
		   MaxMatch();
	    }
	}
	//system("pause");
	return 0;
}
