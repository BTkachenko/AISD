#include <bits/stdc++.h>
using namespace std;
 
// Node
typedef struct node {
    int data;
 
    // Lower values indicate
    // higher priority
    int priority;
 
    struct node* next;
 
} Node;
 
// Function to create a new node
Node* newNode(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
 
    return temp;
}
 
// Return the value at head
int peek(Node** head) { return (*head)->data; }
 
// Removes the element with the
// highest priority form the list
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
 
void push(Node** head, int d, int p,long *compares, long *moves)
{
    Node* start = (*head);
 
    // Create new Node
    Node* temp = newNode(d, p);
 
    // Special Case: The head of list has
    // lesser priority than new node
    if ((*head)->priority > p) {
 
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;

        (*moves)++;
        (*compares)++;
    }
    else {
 
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL
               && start->next->priority < p) {
            start = start->next;
            (*moves)+=1;
             (*compares)+=2;
 
            
        }
        (*moves)+=1;
            (*compares)+=2;
 
        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        (*moves)+=1;
        start->next = temp;
        (*moves)+=1;
    }
}
 
// Function to check is list is empty
int isEmpty(Node** head) { return (*head) == NULL; }
 
// Driver code
int main()
{
 
    
 int p =0;
 int v = 0;
    for(int j = 1 ; j <= 500;j++)
  {
    Node* pq = newNode(1, 10);
    long compares = 0 ;
    long moves = 0 ;
  for(int i = 0 ; i < 100*j;i++)
    {
    v = rand( ) % 10000;
     p = rand( ) %  10;
     push (&pq, p, v, &compares, &moves );
     }

     for(int i = 0 ; i < 100*j;i++)
    {

     push (&pq, p, v, &compares, &moves );
     }
     cout<<moves<<";"<<compares<<";"<<j*100<<endl;
     free(pq);
  }
    return 0;
}