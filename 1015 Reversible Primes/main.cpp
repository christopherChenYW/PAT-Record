//
//  main.cpp
//  1015 Reversible Primes
//
//  Created by 月文 陈  on 2021/3/1.
//

#include <iostream>
using namespace std;

int baseToTen(string number,int base){
    int sum=0;
    int exponent=1;
    for(int i=number.size()-1;i>=0;i--){
        sum+=(number[i]-'0')*exponent;
        exponent*=base;
    }
    return sum;
}
void tenToBase(string &s,int tenBaseNumber,int base){
    while(tenBaseNumber!=0){
        s+=to_string(tenBaseNumber%base);
        tenBaseNumber/=base;
    }
}
bool isPrime(int number){
    if(number==1) return false;
    else{
        for(int i=2;i<number;i++){
            if(number%i==0)return false;
        }
        return  true;
    }
}
int main(int argc, const char * argv[]) {

    while (true) {
        int number,base;
        cin>>number;
        if(number<0) break;
        cin>>base;
        string s="";
        tenToBase(s, number, base);
        bool result=isPrime(baseToTen(s, base))&&isPrime(number);
        if(result) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
