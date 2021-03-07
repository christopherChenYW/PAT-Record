//
//  main.cpp
//  1025 PAT Ranking
//
//  Created by 月文 陈  on 2021/3/5.
//

#include <iostream>
#include <vector>
#include"model.h"

bool cmp(Testee t1,Testee t2){
    return t1.score>t2.score?true:(t1.score==t2.score?t1.registration_number<t2.registration_number:false);
}

void registerLocalRank(vector<Testee> &testee){
    int currentScore=testee[0].score;
    int currentRank=1;
    for(int j=0;j<testee.size();j++){
        if(testee[j].score!=currentScore){
            currentScore=testee[j].score;
            currentRank=j+1;
            
        }
        testee[j].local_rank=currentRank;
    }
}

void registerfinalRank(vector<Testee> testee){
    int currentScore=testee[0].score;
    int currentRank=1;
    for(int j=0;j<testee.size();j++){
        if(testee[j].score!=currentScore){
            currentScore=testee[j].score;
            currentRank=j+1;
            
        }
        cout<<testee[j].registration_number<<" "<<currentRank<<" "<<testee[j].location_number<<" "<<testee[j].local_rank<<endl;
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vector<Testee> testees;
    for(int i=1;i<=N;i++){
        int K;
        cin>>K;
        vector<Testee> localTestees;
        for(int j=0;j<K;j++)
        {
            Testee testee;
            cin>>testee.registration_number;
            cin>>testee.score;
            testee.location_number=i;
            localTestees.push_back(testee);
        }
        sort(localTestees.begin(), localTestees.end(), cmp);
        registerLocalRank(localTestees);
        for(int j=0;j<K;j++)
            testees.push_back(localTestees[j]);
    }
    
    sort(testees.begin(), testees.end(), cmp);
    cout<<testees.size()<<endl;
    registerfinalRank(testees);

}
