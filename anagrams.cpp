#include<iostream>
#include<string>
#include<string.h>
#include<unordered_map>

using namespace std;

unordered_map<char,int> frequencies(string str){
    unordered_map<char,int> mp;
    for(int i=0; i<str.length(); i++){
        if(mp.count(tolower(str[i]))==0){
            mp[tolower(str[i])] = 1;
        }else{
            mp[tolower(str[i])] += 1;
        }
    }
    // cout<<mp['a']<<endl;
    return mp;
}


int main(){
    string str1 = "Anagram";
    string str2 = "nagarm";
    if(frequencies(str1)==frequencies(str2)){
        cout<<true<<endl;
    }else{
        cout<<false<<endl;
    }
    return 0;
}