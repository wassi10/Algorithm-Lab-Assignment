/**
      Lab Task-2
    Khadiza Akther
                    */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int coin, n, i, j;

    cout << "Coin Limit: ";
    cin >> n;

    cout << "Coin type: ";
    cin >> coin;

    int Coin[coin+1];
    cout << "Coins: ";
    for(i=1; i<=coin; i++)
    {
        cin >> Coin[i];
    }

    int T[coin+1][n+1]; ///Index

    for(i=0; i<=coin; i++)
        for(j=0; j<=n; j++)
        {
            if(j==0)
                T[i][j]=0;
            else if(i==0)
                T[i][j]= 100;
            else
            {
                if(j-Coin[i] >= 0)
                {
                    if(T[i-1][j] <= 1+ T[i][j-Coin[i]])
                        T[i][j]   =T[i-1][j];
                    else
                        T[i][j] = 1+ T[i][j-Coin[i]];
                }
                else
                    T[i][j]=T[i-1][j];
            }

        }

    i= coin;
    j=n;

    printf("DP need minimum %d coin: ", T[i][j]);

    while(T[i][j] != 0)
    {
        if(T[i-1][j] == T[i][j])
            i--;
        else
        {
            cout << " " << Coin[i];
            j=j-Coin[i];
        }
    }
    printf("\n");
    return 0;
}
