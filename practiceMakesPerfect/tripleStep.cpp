#include <iostream>
using namespace std;

int tripleStep_dp(int n, int* a)
{
    if (a[n] != 0)
        return a[n];
    else
    {
        a[n] = tripleStep_dp(n-1, a) + tripleStep_dp(n-2, a) + tripleStep_dp(n-3, a);
        cout << "n = " << n << "    a[n] = " << a[n] <<endl;
        return a[n];
    }
    
}

int triplestep_naive(int n)
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
        cout << "n = "<< n << endl;
        return triplestep_naive(n-1) + triplestep_naive(n-2) + triplestep_naive(n-3);
    }
    
}

int main()
{
    int n = 7 ;
    int *a = new int[n+1];
    a[0] = 0; a[1] = 1; a[2] = 2; a[3] = 4; 
    cout << "answer dp  = \n-----------------\n" << tripleStep_dp(n, a) << endl;

    cout <<"ans naive = \n--------------------\n" << triplestep_naive(n) << endl;
}



