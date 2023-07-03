#include<bits/stdc++.h>
using namespace std;

// Bubble Sort
void bubbleSort(vector<int>&arr, int n){
   for(int i=n-1; i>=0; i--){
       for(int j=0; j<i; j++){
           if(arr[j] > arr[j+1]){
               swap(arr[j], arr[j+1]);
           }
       }
   }
}

// intuition: we are comparing the adjacent elements and swapping them if they are not in order 
//eventually maximum element will be at the end of the array
//{8, 5, 7, 3, 2}
//{5, 7, 3, 2, 8}--step1
//{5, 3, 2, 7, 8}--step2
//{3, 2, 5, 7, 8}--step3
//{2, 3, 5, 7, 8}--step4

//max no of swaps = n(n-1)/2
//min no of swaps = 0
//min no of comparisons = n-1
//max no of comparisons = n(n-1)/2

//Best case: O(n)
//Worst case: O(n^2)
//Average case: O(n^2)
//Space complexity: O(1)

// Selection Sort

void selectionSort(vector<int>&arr, int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}


// intuition: we are selecting the minimum element in the array and swapping it with the first element of the array
//{8, 5, 7, 3, 2}
//{2,5,7,3,8}--step1
//{2,3,7,5,8}--step2
//{2,3,5,7,8}--step3
//max no of swaps = n-1
//min no of swaps = 0
//min no of comparisons = n-1
//max no of comparisons = n(n-1)/2

//Best case: O(n^2)
//Worst case: O(n^2)
//Average case: O(n^2)
//Space complexity: O(1)





// Insertion Sort

void insertionSort(vector<int>&arr, int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
// intuition: we are selecting the element and comparing it with the elements before it and placing it at the right position
//{8, 5, 7, 3, 2}
//{5,8,7,3,2}--step1
//{5,7,8,3,2}--step2
//{3,5,7,8,2}--step3
//{2,3,5,7,8}--step4
//max no of swaps = n(n-1)/2
//min no of swaps = 0
//min no of comparisons = n-1
//max no of comparisons = n(n-1)/2

//Best case: O(n)
//Worst case: O(n^2)
//Average case: O(n^2)

// Space complexity: O(1)


// quick Sort

int partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>&arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// Merge Sort

void merge(vector<int>&arr, int low, int mid, int high){
  int left=low;
  int right=mid+1;
  vector<int>tp;
  while(left<=mid && right<=high){
    if(arr[left]<=arr[right]){
        tp.push_back(arr[left]);
        left++;
    }
    else{
         tp.push_back(arr[right]);
         right++;
    }
  }
    while(left<=mid){
        tp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
         tp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=tp[i-low];
    }
  
}

void mergeSort(vector<int>&arr, int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

// Heap Sort

void heapify(vector<int>&arr, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>&arr, int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    vector<int>arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // quickSort(arr, 0, n-1);
     mergeSort(arr, 0, n-1);
     //  heapSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}