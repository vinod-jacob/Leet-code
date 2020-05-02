#include <iostream>
#include <stdio.h>
using namespace std;

unsigned long long tripleStep_dp(int n, unsigned long long* a)
{
    if (a[n] != 0)
        return a[n];
    else
    {
        a[n] = tripleStep_dp(n-1, a) + tripleStep_dp(n-2, a) + tripleStep_dp(n-3, a);
        // cout << "n = " << n << "    a[n] = " << a[n] <<endl;
        return a[n];
    }
    
}

unsigned long long triplestep_naive(int n)
{
    if (n <=0)
        return 0;
    else if(n == 1)
        return 1;
    else if (n== 2)
        return 2;
    else if(n == 3)
        return 4;
    else
    {
        // cout << "n = "<< n << endl;
        return triplestep_naive(n-1) + triplestep_naive(n-2) + triplestep_naive(n-3);
    }
    
}

int main()
{
    int n = 37 ;
    unsigned long long *a = new unsigned long long[n+1];
    a[0] = 0; a[1] = 1; a[2] = 2; a[3] = 4; 
    cout << "answer dp  = " << tripleStep_dp(n, a) << endl;
    cout <<"ans naive = " << triplestep_naive(n) << endl;
}



