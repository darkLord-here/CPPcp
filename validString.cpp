#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isValid(string str){
    stack<char> stck;
    for(int i=0; i<str.size(); i++){
        // cout<<str[i]<<endl;
        if (str[i]=='(' or str[i]=='[' or str[i]=='{') stck.push(str[i]);
        else{
            if(stck.empty()) return false;
            else if ((stck.top()=='(' && str[i]!=')') || (stck.top()=='[' && str[i]!=']') || (stck.top()=='{' && str[i]!='}') ){
                return false;
            }else stck.pop();
        }
    }
    return stck.empty();
}


int main(){
    string str = "{}[][[(())]][][{}]";
    cout<<isValid(str)<<endl;
    return 0;
}