//Print all possible combinations of r elements in a given array of size n in O(n^2) time and O(r) space
#include<bits/stdc++.h>
using namespace std;


void printCombination(int arr[],int n,int r,int index,int data[],int i){
    if(index==r){
        for(int i=0;i<r;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(i>=n)return;
    data[index]=arr[i];
    printCombination(arr,n,r,index+1,data,i+1);
    printCombination(arr,n,r,index,data,i+1);
}


int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int r=3;
    int data[r];
    printCombination(arr,n,r,0,data,0);
    return 0;
}





