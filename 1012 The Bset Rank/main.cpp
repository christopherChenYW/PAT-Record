//
//  main.cpp
//  1012 The Bset Rank
//
//  Created by 月文 陈  on 2021/2/26.
//

#include <iostream>
#include<map>
#include<list>
#include<algorithm>
using namespace std;
bool compare(int a,int b){
    return b<a;
}
int main(int argc, const char * argv[]) {
    
    int N,M;
    cin>>N>>M;
    int *cGrade=new int[N];
    int *mGrade=new int[N];
    int *eGrade=new int[N];
    double *avagGrade=new double[N];
    
    map<string,list<int>> studentMap;
    
    for(int i=0;i<N;i++){
        string name;
        cin>>name;
        int C,M,E;
        cin>>C>>M>>E;
        cGrade[i]=C;
        mGrade[i]=M;
        eGrade[i]=E;
        list<int> stuList;
        stuList.push_back(C);
        stuList.push_back(M);
        stuList.push_back(E);
        avagGrade[i]=(C+M+E)/3;
        studentMap.insert(pair<string,list<int>>(name,stuList));
    }
    sort(mGrade,mGrade+N,compare);
    sort(cGrade,cGrade+N,compare);
    sort(eGrade,eGrade+N,compare);
    sort(avagGrade,avagGrade+N,compare);
    
    string *name=new string[M];
    for(int i=0;i<M;i++){
        cin>>name[i];
        
    }
    for(int i=0;i<M;i++){
        map<string,list<int>>::iterator iter=  studentMap.find(name[i]);
        if(iter != studentMap.end()){
            list<int> scoreList=iter->second;
            list<int>::iterator listIter=scoreList.begin();
            int cScore=*listIter++;
            int mScore=*listIter++;
            int eScore=*listIter++;
            
            int bestRank=99999;
            char type='A';
            double aScore=(cScore+mScore+eScore)/3;
            for(int j=0;j<N;j++){
                if(avagGrade[j]==aScore){
                    if(j+1<bestRank){
                        bestRank=j+1;
                        break;
                    }
                }
            }
            for(int j=0;j<N;j++){
                if(cGrade[j]==cScore){
                    if(j+1<bestRank){
                        bestRank=j+1;
                        type='C';
                        break;
                    }
                }
            }
            for(int j=0;j<N;j++){
                if(mGrade[j]==mScore){
                    if(j+1<bestRank){
                        bestRank=j+1;
                        type='M';
                        break;
                    }
                }
            }
            for(int j=0;j<N;j++){
                if(eGrade[j]==eScore){
                    if(j+1<bestRank){
                        bestRank=j+1;
                        type='E';
                        break;
                    }
                }
            }
            cout<<bestRank<<" "<<type<<endl;
            continue;
        }
          cout<<"N/A"<<endl;
    }
    
    return 0;
}
