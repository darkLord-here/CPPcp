#include<iostream>



using namespace std;

int f(int x){
    int ans=0;
    while(x>0)
        ans+=x , x/=10;   
    return ans;     
}

int inverse(int x){
    int beg = 1, end = x;
    while(beg<=end){
        int mid = (beg+end)/2;
        int f_val = f(mid);
        if(f_val==x) return mid;
        else if(f_val>x) end = mid-1;
        else beg=mid+1; 
    }
    return -1;
}

int main(){
    int num=1370;
    cout<<inverse(num)<<endl;
    return 0;
}