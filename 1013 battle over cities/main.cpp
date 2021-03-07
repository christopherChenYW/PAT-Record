//
//  main.cpp
//  1013 battle over cities
//
//  Created by 月文 陈  on 2021/2/26.
//
#include <iostream>
#include <list>
#include <string>
using namespace std;
int BFS(int chooseCity,int **graph1,int cityNum){
    int **graph=new int*[cityNum];
    for(int i=0;i<cityNum;i++){
        graph[i]=new int[cityNum];
    }
    
    for(int i=0;i<cityNum;i++)
        for(int j=0;j<cityNum;j++)
            graph[i][j]=graph1[i][j];
    
    
    for(int i=0;i<cityNum;i++){
        graph[chooseCity-1][i]=graph[i][chooseCity-1]=-1;
    }
    list<int> queue;
    bool visit[cityNum];
    for(int i=0;i<cityNum;i++)
    visit[i]=false;
    list<list<int>> setList;
    for(int j=0;j<cityNum;j++){
        if(visit[j]==true) continue;
        queue.push_back(j);
        list<int> set;
        while(!queue.empty()){
            int currentCity=queue.front();
            set.push_back(currentCity);
            for(int i=0;i<cityNum;i++)
            if(visit[i]==false&&graph[i][currentCity]==1){
                visit[i]=true;
                queue.push_back(i);
            }
            queue.pop_front();
        }
        setList.push_back(set);
    }
    return  setList.size()-2;
}
int main()
{
    
    int cityNum=0,roadNum,testNum;
    cin>>cityNum>>roadNum>>testNum;
     int **graph=new int*[cityNum];
    for(int i=0;i<cityNum;i++){
        graph[i]=new int[cityNum];
        for(int j=0;j<cityNum;j++){
            graph[i][j]=-1;
        }
    }
    
    for(int i=0;i<roadNum;i++){
        int cityOne;
        int cityTwo;
        cin>>cityOne>>cityTwo;
        graph[cityOne-1][cityTwo-1]=graph[cityTwo-1][cityOne-1]=1;
    }
    
    int *testCity=new int[testNum];
    for(int i=0;i<testNum;i++)
        cin>>testCity[i];
    
    for(int i=0;i<testNum;i++)
        cout<<BFS(testCity[i],graph,cityNum)<<endl;
}

