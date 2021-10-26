/**
      Lab Task-1
    Khadiza Akther
                    */

#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int X[], int n, int Xm);

int main()
{
    int n,flag ;

    cout << "Enter the size of array = ";
    cin >> n;

    int X[n];

    cout << "\nEnter the sorted element of the array= ";
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d",&X[i]);
    }

    cout << "\nEnter searching element= ";
    int Z ;
    cin >> Z;

    flag = BinarySearch(X,n,Z);

    if(flag == 1)
    {
        cout << "FOUND\n";
    }
    else
    {
        cout << "NOT FOUND\n";
    }
    return 0;
}

int BinarySearch(int X[], int n, int Z)
{

    int l = 1;
    int h = n ;
    int flag = 0;
    while( l <= h && flag == 0)
    {
        int mid = (l+h)/2;
        int Xm = X[mid];

        if(Xm < Z)
        {
            l = mid + 1;
        }
        else if (Xm > Z)
        {
            h = mid - 1;
        }
        else
        {
            flag = 1;
        }
    }
    if(flag == 1)
    {
        return 1;
    }
    else
        return -1;
}
