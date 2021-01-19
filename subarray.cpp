#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void prefixSum(vector<int> &arr){
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        arr[i] = sum + arr[i];
        sum = arr[i];
    }
}

int longestSubArrayWithSumK(int *arr, int n, int k){
    unordered_map<int,int> mp;
    int prefixSum = 0;
    int result = 0;
    for(int i=0;i<n;i++){
        prefixSum += arr[i];
        if(prefixSum==k){
            // subarray with sum k
            result = max(result, i+1);
        }
        if(mp.count(prefixSum-k)>0){
            result = max(result, i-mp[prefixSum-k]);
        }
        mp[prefixSum] = min(i, mp[prefixSum]);
    }
    return result;
}

int main(){
    // vector<int> arr = {1, 2, -2, 3, -1, 4};
    int arr[6] = {1, 2, -2, 3, -1, 4};
    int k = 3;
    cout<<longestSubArrayWithSumK(arr, 6, 3)<<endl;
    // for (int i: arr){
    //     cout<<i<<" ";
    // }
    // cout<<endl<<arr.size()<<endl;
    // prefixSum(arr);
    // for (int i: arr){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // ComputeLSA(arr,k);
    return 0;
}