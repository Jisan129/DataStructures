#include <bits/stdc++.h>


//implementing Disjoint set Union


int parent[100];

void make_set(int i) {
    parent[i] = i;
}

int find_set(int i) {
    if (parent[i] == i)return i;
    else {
        find_set(parent[i]);
    }
}

void union_sets(int a, int b) {

    int ra=find_set(a);
    int rb=find_set(b);
    if(ra!=rb){
        parent[rb]=ra;
    }

}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    make_set(1);
    make_set(4);
    make_set(2);
    make_set(3);
    union_sets(1,2);
    union_sets(3,4);
    union_sets(1,3);
    make_set(5);
    make_set(7);
    make_set(20);

    union_sets(5,20);

    std::cout<<find_set(20);

    return 0;
}
