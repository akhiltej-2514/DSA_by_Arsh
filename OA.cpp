//given an array of size n and interger K find largest positive number less than 1e9 such that at least K numbers from the array are divisible by it
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int ans=-1;
    for(int i=1;i<=1e9;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]%i==0) cnt++;
        }
        if(cnt>=k) ans=i;
    }
    cout<<ans<<endl;
    return 0;
}