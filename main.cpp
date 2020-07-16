#include <iostream>
using namespace std;
int power(int x, unsigned int y, int p)
{
    int res = 1;	 // Initialize result
    if(x==0){
        return 0;
    }
    if(y==0){
        return 1;
    }
    if(y%2==0){
        res=power(x,y/2,p);
        return (res*res)%p;
    }

    res=(x%p)*(power(x,y-1,p)%p);
    return res;
}



int main()
{
    int x,y,p;
    cin>>x>>y>>p;
    cout << "Power is " << power(x, y, p);
    return 0;
}

// This code is contributed by shubhamsingh10
