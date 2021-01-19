#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

unordered_map<char,int> storeFreq(string str){
    unordered_map<char,int> mp;
    for(int i=0; i<str.size(); i++){
        if(mp.count(str[i]))   mp[str[i]] += 1;
        else mp[str[i]] = 1;
    }
    return mp;
}

int main(){
    string str;
    getline(cin,str);
    // cin>> noskipws >>str;
    auto temp = storeFreq(str);
    for(int i = 0; i<str.size() ; i++){
        if(temp[str[i]]==1) {
            printf("%c",str[i]);
            break;
        }
    }
    return 0;
}