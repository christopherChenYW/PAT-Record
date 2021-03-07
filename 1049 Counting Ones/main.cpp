//
//  main.cpp
//  1049 Counting Ones
//
//  Created by 月文 陈  on 2021/3/4.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int count=0;
   
    int indexLeftNum,indexRightNUm,index;
    int i=1;//代表数位
    while(N/i!=0){
        index=(N/i)%10;
        indexLeftNum=(N/i)/10;
        indexRightNUm=N-(N/i)*i;
        
        if(index==1)     count+=i*indexLeftNum+indexRightNUm+1;
        else if(index>1) count+=i*(indexLeftNum+1);
        else             count+=i*indexLeftNum;
        
        i*=10;
    }
    cout<<count<<endl;

}
