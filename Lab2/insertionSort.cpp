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

void insertionSort(int arr[], int n, int *compares, int *moves, bool comp) {
    int key;
    int i;

    for (int j = 1; j < n; j++) {
        key = arr[j];
        i = j - 1;
        while (i > -1 && compare( key,arr[i], comp, compares)) {
            arr[i + 1] = arr[i];
            (*moves)++;
            i--;
        }
        printArray(arr,n);
        arr[i + 1] = key;
        (*moves)++;
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
    insertionSort(args,n,&compares,&moves,comp);
    cout<<"Array after sorting: "<<endl;
    printArray(args,n);
    cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
     else{
             insertionSort(args,n,&compares,&moves,comp);

        cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
     

    return 0;
}