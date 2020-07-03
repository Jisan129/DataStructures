#include <bits/stdc++.h>
#include <math.h>


//implementing Disjoint set Union


int parent[100];
int size[100];

void make_set(int i) {
    parent[i] = i;
    size[i]=1;
}

int find_set(int i) {
    if (parent[i] == i)return i;

    return parent[i] = find_set(parent[i]);     //stack implement ,every parent will be reassigned as the representative

}

void union_sets(int a, int b) {

    a = find_set(a);
    b = find_set(b);
    if (a != b) {

        if(size[b]>size[a]){
            int temp;
            temp=a;
            a=b;
            b=temp;
        }
        parent[b] = a;
        size[a]+=size[b];

    }

}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    make_set(1);
    make_set(4);
    make_set(2);
    make_set(3);
    union_sets(1, 2);
    union_sets(3, 4);
    union_sets(1, 3);
    make_set(5);
    make_set(7);
    make_set(20);

    union_sets(5, 20);

    std::cout << find_set(20);

    return 0;
}
