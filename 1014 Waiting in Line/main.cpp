
#include<iostream>
#include<queue>

using namespace std;
int main(){
    queue<int> windows[21];
    int N,M,K,Q;
    cin>>N>>M>>K>>Q;
    queue<int > waitingQueue;
    if(K>N*M){
        for(int i=1;i<=N*M;i++){
            int pos=i%N;
            windows[pos==0?N:pos].push(i);
        }
        for(int i=N*M+1;i<K;i++)
        waitingQueue.push(i);
    }else{
        for(int i=1;i<=K;i++){
            int pos=i%N;
            windows[pos==0?N:pos].push(i);
        }
    }
    int timeToServer[1001];
    int timeNeed[1001];
    int timeToLeave[1001];
    for(int i=1;i<=K;i++){
        cin>>timeToServer[i];
        timeNeed[i]=timeToServer[i];
        timeToLeave[i]=0;
    }
    int T=0;
    while(true){
        int minTime=9999;
     
        for(int i=1;i<=N;i++){
            if(!windows[i].empty()){
                minTime=min(minTime,timeNeed[windows[i].front()]);
            
            }
        }
   
        T+=minTime;
        for(int i=1;i<=N;i++){
            if(!windows[i].empty()){
                timeNeed[windows[i].front()]-=minTime;
                if(timeNeed[windows[i].front()]==0){
                    timeToLeave[windows[i].front()]=T;
                    windows[i].pop();
                    if(!waitingQueue.empty()){
                        windows[i].push(waitingQueue.front());
                        waitingQueue.pop();
                    }
                }
            }
        }
        
        if(T>=540){
            for(int i=1;i<=N;i++){
                if(!windows[i].empty()&&timeNeed[windows[i].front()]!=timeToServer[windows[i].front()]){
                    
                    timeToLeave[windows[i].front()]=T+timeNeed[windows[i].front()];
                }
            }
            break;;
        }
    }
    for(int i=0;i<Q;i++){
        int queryOne;
        cin>>queryOne;
        if(timeToLeave[queryOne]==0){
            cout<<"Sorry"<<endl;
        }else{
            int hour=timeToLeave[queryOne]/60+8;
            int minutes=timeToLeave[queryOne]%60;
            if(hour<10){
                cout<<"0";
            }
            cout<<hour<<":";
            if(minutes<10){
                cout<<"0";
            }
            cout<<minutes<<endl;
        }
    }
    
}
