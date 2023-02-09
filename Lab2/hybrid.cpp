#include <iostream>

using namespace std;



void swap(int *x, int *y, int *moves) {
    ++(*moves);

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
    ++(*compares);
    if (!comp)
        return x <= y;
    else
        return y <= x;
}
void quickSort(int *list, int start, int end, int *compares, int *moves, bool comp) {
    if (start < end) {
        int x = list[start];
        int p = start;

        for (int j = start + 1; j <= end; j++) {
            if (compare(list[j], x, comp, compares)) {
                swap(&list[++p], &list[j], moves);
            }
        }
        if (list[p] != list[start]) {
            swap(&list[p], &list[start], moves);
        }

        quickSort(list, start, p - 1, compares, moves, comp);
        quickSort(list, p + 1, end, compares, moves, comp);
    }
}


void hybridSort(int *A, int left, int right, int *compares, int *moves, bool comp) {
    if (right <= left) {
        return;
    }
    if (right-left>5) {
        if (compare(A[right], A[left], comp, compares)) {
            swap(&A[left], &A[right], moves);
        }
        int p = A[left];
        int q = A[right];
        int i = left + 1;
        int k = right - 1;
        int j = i;
        int d = 0;
        while (j <= k) {
            if (d >= 0) {
                if (compare(A[j], p, comp, compares)) {
                    swap(&A[i], &A[j], moves);
                    i++;
                    j++;
                    d++;
                } else {
                    if (compare(A[j], q, comp, compares)) {
                        j++;
                    } else {
                        swap(&A[j], &A[k], moves);
                        k--;
                        d--;
                    }
                }
            } else {
                if (!compare(A[k], q, comp, compares)) {
                    k--;
                    d--;
                } else {
                    if (compare(A[k], p, comp, compares)) {
                        int tmp = A[k];
                        A[k] = A[j];
                        A[j] = A[i];
                        A[i] = tmp;
                        i++;
                        d++;
                        ++(*moves);
                    } else {
                        swap(&A[j], &A[k], moves);
                    }
                    j++;
                }
            }
        }
        swap(&A[left], &A[i - 1], moves);
        swap(&A[right], &A[k + 1], moves);
        hybridSort(A, left, i - 1, compares, moves, comp);
        hybridSort(A, i, k, compares, moves, comp);
        hybridSort(A, k + 2, right, compares, moves, comp);
    } else{
        quickSort(A,left,right,compares,moves,comp);
    }
}

bool isSorted(int x[], int n, bool comp) {
    for (int i = 0; i + 1 < n; i++)
        if (!comparePom(x[i], x[i + 1], comp))
            return false;
    return true;
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
    hybridSort(args,0,n-1,&compares,&moves,comp);
    cout<<"Array after sorting: "<<endl;
    printArray(args,n);
    cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
     else{
             hybridSort(args,0,n-1,&compares,&moves,comp);
     cout<<"Moves: "<<moves<< " Compares: "<<compares<<endl;
     cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;
     }
    return 0;
}