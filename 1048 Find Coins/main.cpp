//
//  main.cpp
//  1048 Find Coins
//
//  Created by 月文 陈  on 2021/3/3.
//

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> coins;
    int N,M;
    cin>>N>>M;
    
    int hasTwo[501]={0};
    
    for(int i=0;i<N;i++)
    {
        int coin;
        cin>>coin;
        if(hasTwo[coin]>=2){        //对于重复的数，只保留两个
            continue;
        }
        coins.push_back(coin);
        hasTwo[coin]++;
    }
    
    sort(coins.begin(),coins.end());

    
    for(int i=0;i<coins.size();i++){
        if(coins[i]*2>M) goto END;              //第一个数只可能在小于M/2的数中取
        for(int j=i+1;j<coins.size();j++){
            int sum=coins[i]+coins[j];
            if(sum>M){
                break;
            }else if(sum==M){
                cout<<coins[i]<<" "<<coins[j]<<endl;
                return  0;
            }
        }
        
    }
    
    END:
    cout<<"No Solution"<<endl;

}
