#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int arr1[], int p, int r) {
    int pivot = arr1[r];
    int i = p-1;
    for(int j = p; j < r; j++) {
        if(arr1[j] <= pivot) {
            i++;
            swap(arr1[i],arr1[j]);
        }
    }
    swap(arr1[i+1],arr1[r]);
    return (i+1);
}

void quickSort(int arr1[], int p, int r) {
    if(p<r) {
        // division
        int q = partition(arr1, p, r);
        quickSort(arr1,p,q-1);
        quickSort(arr1,q+1,r);
    }
}

int main() {
    int m;
    cin >> m;

    int arr[m];
    for(int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    quickSort(arr,0,m-1); 

    cout <<"The sorted array is : "<< endl;
    for(int i = 0; i < m; i++) {
        cout << arr[i] <<" ";
    }

    return 0;
}