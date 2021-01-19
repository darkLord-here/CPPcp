#include<iostream>
#include<string>
#include<vector>

using namespace std;

void subsequences(string inp, string out, vector<string> &v){
    if (inp.size()==0){
        v.push_back(out);
        return;
    }
    char ch = inp[0];
    string ros = inp.substr(1);
    subsequences(ros,out,v);
    subsequences(ros,out+ch,v);
}


int main(){
    vector<string> v;
    string str = "abcd";
    string output = "";
    subsequences(str,output,v);
    for(string s : v){
        cout<<s<<",";
    }
}