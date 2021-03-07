//
//  main.cpp
//  1011 World Cup Betting
//
//  Created by 月文 陈  on 2021/2/26.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    double*first=new double[3];
    double*two=new double[3];
    double* three=new double[3];
    
    for(int i=0;i<3;i++){
        cin>>first[i];
    }
    for(int i=0;i<3;i++){
        cin>>two[i];
    }
    for(int i=0;i<3;i++){
        cin>>three[i];
    }
    double *firstMax=max_element(first,first+3);
    double *secondMax=max_element(two, two+3);
    double *thirdMax=max_element(three, three+3);

    cout<<(first[0]==*firstMax?'W':(first[1]==*firstMax?'T':'L'))<<" ";
    cout<<(two[0]==*secondMax?'W':(two[1]==*secondMax?'T':'L'))<<" ";
    cout<<(three[0]==*thirdMax?'W':(three[1]==*thirdMax?'T':'L'))<<" ";
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<(*firstMax**secondMax**thirdMax*0.65-1)*2<<endl;
}
