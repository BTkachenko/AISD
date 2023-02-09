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


void dpsqc(int arr[], int left, int right, int *compares, int *moves, bool comp) {
    if (right <= left) {
        return;
    }
    if (compare(arr[right], arr[left], comp, compares)) {
        swap(&arr[left], &arr[right], moves);
    }
    int p = arr[left];
    int q = arr[right];
    int i = left + 1;
    int k = right - 1;
    int j = i;
    int d = 0;
    while (j <= k) {
        if (d >= 0) {
            if (compare(arr[j], p, comp, compares)) {
                swap(&arr[i], &arr[j], moves);
                i++;
                j++;
                d++;
            } else {
                if (compare(arr[j], q, comp, compares)) {
                    j++;
                } else {
                    swap(&arr[j], &arr[k], moves);
                    k--;
                    d--;
                }
            }
        } else {
            if (!compare(arr[k], q, comp, compares)) {
                k--;
                d--;
            } else {
                if (compare(arr[k], p, comp, compares)) {
                    int tmp = arr[k];
                    arr[k] = arr[j];
                    arr[j] = arr[i];
                    arr[i] = tmp;
                    i++;
                    d++;
                    moves+=2;
                } else {
                    swap(&arr[j], &arr[k], moves);
                }
                j++;
            }
        }
    }
    swap(&arr[left], &arr[i - 1], moves);
    swap(&arr[right], &arr[k + 1], moves);
    dpsqc(arr, left, i - 1, compares, moves, comp);
    dpsqc(arr, i, k, compares, moves, comp);
    dpsqc(arr, k + 2, right, compares, moves, comp);
    printArray(arr,right);
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
    dpsqc(args,0,n,&compares,&moves,comp);
    cout<<"Array after sorting: "<<endl;
    printArray(args,n);
    cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
     else{
             dpsqc(args,0,n-1,&compares,&moves,comp);

     cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
     

    return 0;
}