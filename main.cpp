#include <iostream>

using namespace std;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n/=i;
            }
            result-=result/i;
        }
    }
    if(n>1){
        result-=result/n;
    }
    return result;
}


int main() {
    int test = 24;
    cin>>test;
    cout << phi(test);
    return 0;
}

// This code is contributed by shubhamsingh10
