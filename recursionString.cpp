#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

void casePermutation(string inp, string out, vector<string> &v){
    if(inp.size()==0){
        v.push_back(out);
        return;
    }
    string ros = inp.substr(1);
    if(inp[0]>='a' and inp[0] <= 'z')
    {
        // smallcase letter 
        casePermutation(ros, out+inp[0], v);
        casePermutation(ros, out+(char)(inp[0]-32),v);
    }else if (inp[0]>='A' and inp[0]<='Z')
    {
        // uppercase letter
        casePermutation(ros, out+inp[0], v);
        casePermutation(ros, out+(char)(inp[0]+32),v);
    }else
    {
        // numeric
        casePermutation(ros, out+inp[0],v);
    }     
}

int main(){
    vector<string> v;
    string str = "1aB2";
    string output = "";
    casePermutation(str,output,v);
    for(string s : v){
        cout<<s<<" ";
    }
}