#include <stdio.h>
#include <iostream>


using namespace std;
void swap(int *x, int *y, int *moves) {
    (*moves)++;
    int temp = *x;
    *x = *y;
    *y = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int n, int i,int * moves,int* compares) {

// Find largest among root, left child and right child

	// Initialize largest as root
int largest = i;

int left = 2 * i + 1;

int right = 2 * i + 2;

// If left child is larger than root
if (left < n && arr[left] > arr[largest])
{
	largest = left;
    (*moves)+=1;
    (*compares)+=2;
}
// If right child is larger than largest
if (right < n && arr[right] > arr[largest])
{
	largest = right;
    (*moves)+=1;
    (*compares)+=2;
}
// Swap and continue heapifying if root is not largest
// If largest is not root
if (largest != i) {

	swap(&arr[i], &arr[largest],moves);
	heapify(arr, n, largest,moves,compares);
    (*compares)++;
}

}

void heapSort(int arr[], int n,int *moves,int *compares) {

// Build max heap
for (int i = n / 2 - 1; i >= 0; i--)
{
	heapify(arr, n, i,moves,compares);
}
// Heap sort
for (int i = n - 1; i >= 0; i--) {

	swap(&arr[0], &arr[i],moves);

	// Heapify root element to get highest element at root again
	heapify(arr, i, 0,moves,compares);

}

}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
for (int i = 0; i < n; i++)
	printf("%d ", arr[i]);
printf("\n");

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
    heapSort(args,n,&moves,&compares);
    cout<<"Array after sorting: "<<endl;
    printArray(args,n);
     }
     cout<<" "<<moves<< " ; "<<compares<<endl;
    // cout<<"Array is sorted: "<<isSorted(args,n,comp)<<endl;

    return 0;
}


