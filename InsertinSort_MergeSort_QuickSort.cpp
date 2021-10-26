/**
      Lab Task-1
    Khadiza Akther
                    */

#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int a[], int n);
void MergeSort(int A[], int n);
void Merge(int L[], int nL, int R[], int nR, int A[]);
int Partition(int A[], int left, int right);
void QuickSort(int A[], int left, int right);
void Display();
void Checking();
void finish();

int main()
{
    finish();

}
void finish()
{
    Display();
    Checking();
}

void Display()
{
    cout << "\n\tPress-1.Insertion Sort\n";
    cout << "\tPress-2.Merge Sort\n";
    cout << "\tPress-3.Quick Sort\n";
    cout << "\tPress-4.Exit\n";
}

void Checking()
{
    int n,i, left = 0, right;

    cout << "\n\tEnter the size of array: ";
    cin >> n;

    int A[n];
    right = n-1;

    cout << "\n\tEnter the Element of array: ";
    for(i=0; i<n; i++)
    {
        cin >> A[i];
    }

    int choose;

    cout << "\n\tChoose your Option: ";
    for(i=1; scanf("%d", &choose)>0; i++)
    {
        switch(choose)
        {
        case 1:
        {
            InsertionSort(A,n);
            cout << "\n\tAccording to Insertion Sort, Sorted Data is: ";
            for(i=0; i<n; i++)
            {
                cout << " "<< A[i];
            }
            break;
        }
        case 2:
        {
            MergeSort(A, n);
            cout << "\n\tAccording to Merge Sort, Sorted Data is: ";
            for(i=0; i<n; i++)
            {
                cout << " "<< A[i];
            }
            break;
        }
        case 3:
        {
            QuickSort(A, left, right);
            cout << "\n\tAccording to Quick Sort, Sorted Data is: ";
            for(i=0; i<n; i++)
            {
                cout << " "<< A[i];
            }
            break;
        }
        case 4:
        {
            cout << "\n\tProgram Terminated.\n";
            exit(0);
            break;
        }
        default:
            cout << "\n\tInvalid Option.\n";
        }
        cout << "\n\n\tChoose your Option: ";
    }
}

void InsertionSort(int a[], int n)
{
    int i, pos,temp;
    for(i=1; i < n; i++)
    {
        temp = a[i];
        pos =i;

        while(pos > 0 && a[pos - 1] > temp)
        {
            a[pos] = a[pos -1];
            pos--;
        }
        a[pos] = temp;
    }
}

void MergeSort(int A[], int n)
{
    if(n<2) return;

    int mid = n/2;
    int left[mid], right[n-mid];

    for(int i=0; i<=mid-1; i++)
        left[i] = A[i];

    for(int i=mid; i<=n-1; i++)
        right[i-mid] = A[i];

    MergeSort(left, mid);
    MergeSort(right, n-mid);
    Merge(left,mid, right, n-mid, A);
}

void Merge(int L[], int nL, int R[], int nR, int A[])
{
    int i, j, k;
    i=j=k=0;

    while(i<nL && j<nR)
    {
        if(L[i]<=R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<nL)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<nR)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void QuickSort(int A[], int left, int right)
{
    int q;
    if(left < right)
    {
        q = Partition(A,left,right);
        QuickSort(A, left,q-1);
        QuickSort(A, q+1, right);
    }
}

int Partition(int A[], int left, int right)
{
    int i, j, temp;

    int pivot = A[left];
    i=left;
    j=right;

    while(i<j)
    {
        while(A[i] <= pivot && i<= right)
        {
            i++;
        }
        while(A[j] > pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[j];
    A[j] = A[left];
    A[left] =  temp;

    return j;
}
