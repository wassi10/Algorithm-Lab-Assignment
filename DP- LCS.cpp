/**
      Lab Task-2
    Khadiza Akther
                    */

#include<bits/stdc++.h>
using namespace std;

char X[100],Y[100],subseq[100];

int main()
{
    int m,n,i,j;

    printf("Enter first string: ");
    gets(X);
    m = strlen(X);

    printf("\nEnter second string: ");
    gets(Y);
    n = strlen(Y);

    int T[m+1][n+1];
    for(i=0; i<=m; i++)
        T[i][0]=0;
    for(j=0; j<=n; j++)
        T[0][j]=0;

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(X[i-1]==Y[j-1])
            {
                T[i][j]=T[i-1][j-1]+1;
            }
            else
            {
                if(T[i-1][j] >= T[i][j-1])
                    T[i][j] = T[i-1][j];
                else
                    T[i][j] = T[i][j-1];
            }

        }
    }
    printf("\nLCS Matrix: \n");
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
            printf("%4d ", T[i][j]);
        printf("\n");
    }

    int k=0;
    i=m;
    j=n;

    while(i>=1 || j>=1)
    {
        if(T[i][j] == T[i-1][j]) i--;
        else if(T[i][j] == T[i][j-1]) j--;
        else
        {
            subseq[k++] = X[i-1];
            i--;
            j--;
        }
    }
    printf("\nSubsequence String is: %s\n", strrev(subseq));

    return 0;
}

