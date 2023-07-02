#include<bits/stdc++.h>
using namespace std;

// Given an array of n integers where each value represents number of chocolates in a packet.
// Each packet can have variable number of chocolates. There are m students, the task is to
// distribute chocolate packets such that:
// 1. Each student gets one packet.
// 2. The difference between the number of chocolates in packet with maximum chocolates and
// packet with minimum chocolates given to the students is minimum.

// Input : arr[] = {7, 3, 2, 4, 9, 12, 56}
// m = 3
// Output: Minimum Difference is 2
// We have seven packets of chocolates and
// we need to pick three packets for 3 students
// If we pick 2, 3 and 4, we get the minimum
// difference between maximum and minimum packet
// sizes.

// sol  : sort the array and then find the min diff between the first and last element of the
// window of size m
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,diff=INT_MAX;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>m;
        sort(arr,arr+n);
        for(int i=0;i+m-1<n;i++){
            diff=min(diff,arr[i+m-1]-arr[i]);
        }
        cout<<diff<<endl;
    }
    return 0;
}