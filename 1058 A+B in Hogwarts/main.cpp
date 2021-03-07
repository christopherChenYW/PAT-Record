//
//  main.cpp
//  1058 A+B in Hogwarts
//
//  Created by 月文 陈  on 2021/3/7.
//

#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string str,char token){
    size_t position;
    vector<string> result;
    while((position=str.find(token))!=string::npos){
        result.push_back(str.substr(0,position));
        str.erase(0,position+1);
    }
    result.push_back(str);
    return  result;
}
int main(int argc, const char * argv[]) {
    string A,B;
    cin>>A>>B;
    vector<string> splitA=split(A, '.');
    vector<string> splitB=split(B, '.');
    
    int Galleon,Sickle,Knut;
    
    int temp=0;
    Knut=(stoi(splitB[2])+stoi(splitA[2]))%29;
    temp=(stoi(splitB[2])+stoi(splitA[2]))/29;
    
    Sickle=(stoi(splitB[1])+stoi(splitA[1])+temp)%17;
    temp=(stoi(splitB[1])+stoi(splitA[1])+temp)/17;
    
    Galleon=(stoi(splitB[0])+stoi(splitA[0])+temp);
    cout<<Galleon<<"."<<Sickle<<"."<<Knut<<endl;
    
}
