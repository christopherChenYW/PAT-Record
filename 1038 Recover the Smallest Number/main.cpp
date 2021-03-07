//
//  main.cpp
//  1038 Recover the Smallest Number
//
//  Created by 月文 陈  on 2021/3/2.
//

#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
bool cmp(string s1,string s2){
    return ((s1+s2)<(s2+s1))>0?true:false;
}

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vector<string> numbers;
    for(int i=0;i<N;i++)
    {   string str;
        cin>>str;
        numbers.push_back(str);
    }
    sort(numbers.begin(), numbers.end(),cmp);
    string result="";
    for(int i=0;i<numbers.size();i++)
    result+=numbers[i];
    while(result[0]=='0'){
        result.erase(result.begin());
    }
    
    if(result.size()==0) cout<<0<<endl;
    else cout<<result<<endl;
    
}
