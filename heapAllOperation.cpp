#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size;

    Heap() {
        size = 0;
        arr[0] = -1;
    } 
    void insert(int value) {

        size = size + 1;
        int index = size;
        arr[index] = value;
        
        while(index > 1) {
            int parent = index/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() { 
        for(int i = 1; i<=size; i++) {
            cout << arr[i] <<" ";
        }
        cout << endl;
    }

    void deletefromHeap() {
        if(size == 0) { 
            cout << "Deletion is not possible" << endl;
        }

        // step 1: swap root node with last node
        arr[1] = arr[size];

        // step 2: remove last node from heap
        size--;

        // step 3: propagate root node to its correct position
        int i = 1;
        while(i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if(leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            } else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }
};

int main() {
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();
   return 0;
}