//
//  main.cpp
//  Test
//
//  Created by 月文 陈  on 2021/3/1.
//

// This program demonstrates the use of the stoXXX()
// numeric conversion functions.
#include <string>
#include <iostream>
using namespace std;
bool cmp(string s1,string s2){
    return s1<s2;
}
int main()
{
    string s[2];
    s[0]="22";
    s[1]="11";
    sort(s,s+2,cmp);
    cout<<s[0]<<s[1];
    int currentScore=testee[0].score;
    int currentRank=1;
    cout<<testee.size()<<endl;
    for(int j=0;j<testee.size();j++){
        if(testee[j].score!=currentScore){
            currentScore=testee[j].score;
            currentRank=j+1;
            
        }
        cout<<testee[j].registration_number<<" "<<currentRank<<" "<<testee[j].location_number<<" "<<testee[j].local_rank<<endl;
    }
}
