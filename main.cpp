#include <bits/stdc++.h>
using namespace std;
int vsize=8;
void MaxHeapify(vector<int>&vector, int n, int i) {

    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && vector[l]>vector[largest]){
        largest=l;
    }

    if(r<n && vector[r]>vector[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(vector[i],vector[largest]);

        MaxHeapify(vector,n,largest);
    }



}

void buildMaxHeap(vector<int>&number, int n) {

    for(int i=n/2;i>=0; i--){
         MaxHeapify(number,8,i);
    }

}
void printHeap(vector<int>&list,int size){
    for(int i=0;i<size;i++){
        cout<<list[i]<<" ";
    }
}

int main(){
    vector<int>number(8);
    number[0]=1;
    number[1]=3;
    number[2]=5;
    number[3]=4;
    number[4]=6;
    number[5]=13;
    number[6]=10;
    number[7]=9;

    buildMaxHeap(number,8);
    printHeap(number,8);
}