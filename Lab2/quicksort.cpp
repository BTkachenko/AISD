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


void quickSort(int arr[], int start, int end, int *compares, int *moves, bool comp) {
    if (start < end) {
        int x = arr[start];
        int p = start;

        for (int j = start + 1; j <= end; j++) {
            if (compare(arr[j], x, comp, compares)) {
                swap(&arr[++p], &arr[j], moves);
            }
        }
        if (arr[p] != arr[start]) {
            swap(&arr[p], &arr[start], moves);
        }

        quickSort(arr, start, p - 1, compares, moves, comp);
        quickSort(arr, p + 1, end, compares, moves, comp);
        printArray(arr,end);
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
    quickSort(args,0,n-1,&compares,&moves,comp);
    cout<<"Array after sorting: "<<endl;
    printArray(args,n);
    cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
     else{
             quickSort(args,0,n-1,&compares,&moves,comp);

         cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
     

    return 0;
}