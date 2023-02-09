#include <iostream>

using namespace std;

void printArray(int arr[], int n);
void swap(int *x, int *y, int *moves) {
    (*moves)++;
    int temp = *x;
    *x = *y;
    *y = temp;
}

bool comparePom(int x, int y, bool comp) {
    if (!comp)
        return x <= y;
    else
        return y <= x;
}

bool compare(int x, int y, bool comp, int *compares) {
    (*compares)++;
    if (!comp)
        return x <= y;
    else
        return y <= x;
}

bool isSorted(int arr[], int n, bool comp) {
    for (int i = 0; i + 1 < n; i++)
        if (!comparePom(arr[i], arr[i + 1], comp))
            return false;
    return true;
}


void merge(int arr[], int l, int m, int r, int *compares, int *moves, bool comp) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j], comp, compares)) {
            arr[k] = L[i];
            i++;
        } else {
            ++(*moves);
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int *compares, int *moves, bool comp) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, compares, moves, comp);
        mergeSort(arr, m + 1, r, compares, moves, comp);
        merge(arr, l, m, r, compares, moves, comp);
        printArray(arr,r);
    }
}

void printArray(int arr[], int n)
{
    if(n<=50){
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    }
}



int main()
{
    int n;
    scanf("%d",&n);
    int args[n];
    for(int i =0; i < n ;i++)
            {
                scanf("%d",&args[i]);
            }
    bool comp = false;
    int compares = 0;
    int moves = 0;
     if(n<=50)
     {
     cout<<"Array before sorting: "<<endl;
    printArray(args,n);
    cout<<"____________________"<<endl;
    mergeSort(args,0,n-1,&compares,&moves,comp);
    cout<<"Array after sorting: "<<endl;
    printArray(args,n);
     cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
     else{
             mergeSort(args,0,n-1,&compares,&moves,comp);

     cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
    return 0;
}