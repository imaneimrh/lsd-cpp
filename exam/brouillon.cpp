#include<iostream>
#include<string>
using namespace std;

string truncate(string s){
    int i;
    string display= "          ";
    for(i=0;i<9;i++){
        display[i]=s[i];
    }
    if(s.length()>11)
        display[i]='.';
    return display;
}

int main(){
    string s = "sfhk";
    cout<<truncate(s);
}