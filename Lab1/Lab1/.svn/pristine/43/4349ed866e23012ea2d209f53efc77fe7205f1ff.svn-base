#include <iostream>
#include <time.h>
#include <stdlib.h>     /* srand, rand */

using namespace std;

struct listEl
{
    listEl * next;
    int data;
};


class list
{
  public:
    listEl * head;
    int length;
    list( );  // konstruktor
    ~list( ); // destruktor
    unsigned size( );
    void printl( );
    void push_front ( int v );
    void push_back ( int v );
    void insert_before ( listEl * e, int v );
    void insert_after ( listEl * e, int v );
    void pop_front( );
    void pop_back( );
    void remove ( listEl * e );
    int get_data(int n)
    {
        return get_el(n)->data;
    }
    listEl * get_el(int n)
    {
        listEl * p = head;
        for(int i = 0 ; i <n;i++)
        {

            p = p->next;
        }
        return p;
    }
};

// Konstruktor listy
//------------------
list::list( )
{

  head = NULL;
}

// Destruktor listy
//-----------------
list::~list( )
{
  while( head ) pop_front( );
}

// Funkcja oblicza liczbę elementów listy
//---------------------------------------
unsigned list::size( )
{
  unsigned c = 0;
  listEl * p = head;
  while( p )
  {
    c++;
    p = p->next;
  }
  return c-1;
}

// Procedura wyświetla zawartość elementów listy
//----------------------------------------------
void list::printl( )
{
  unsigned i;
  listEl * p = head;

  cout << "Number of elements : " << size( ) +1<< endl;
  for( i = 1; p; p = p->next ) cout << "Element #" << i++ << "  data = " << p->data << endl;
  cout << endl;
}

// Procedura dołączania na początek listy
//---------------------------------------
void list::push_front ( int v )
{
  listEl * p;

  p = new listEl;
  p->next = head;
  p->data = v;
  head = p;
}

// Procedura dołączania na koniec listy
//---------------------------------------
void list::push_back ( int v )
{
  listEl * p, * e;

  e = new listEl;  // tworzymy nowy element
  e->next = NULL;   // inicjujemy element
  e->data = v;
  p = head;
  if( p )
  {
     while( p->next ) p = p->next;
     p->next = e;
  }
  else head = e;
}

// Procedura dołączania przed elementem e
//---------------------------------------
void list::insert_before ( listEl * e, int v )
{
  listEl * p = head;

  if( p == e ) push_front ( v );
  else
  {
    while( p->next != e ) p = p->next;
    p->next = new listEl;
    p->next->next = e;
    p->next->data = v;
  }
}

// Procedura dołączania za elementem e
//------------------------------------
void list::insert_after ( listEl * e, int v )
{
  listEl * p = new listEl;

  p->next = e->next;
  p->data = v;
  e->next = p;
}

// Procedura usuwa pierwszy element
//---------------------------------
void list::pop_front( )
{
  listEl * p = head; // zapamiętujemy początek

  if( p )
  {
    head = p->next;   // nowy początek
    delete p;         // usuń element z pamięci
  }
}

// Procedura usuwa ostatni element
//---------------------------------
void list::pop_back( )
{
  listEl * p = head; // zapamiętujemy początek

  if( p )
  {
    if( p->next )
    {
      while( p->next->next ) p = p->next;
      delete p->next;
      p->next = NULL;
    }
    else
    {
      delete p;
      head = NULL;
    }
  }
}

// Procedura usuwa wybrany element
//--------------------------------
void list::remove ( listEl * e )
{
  listEl * p;

  if( head == e ) pop_front( );
  else
  {
    p = head;
    while( p->next != e ) p = p->next;
    p->next = e->next;
    delete e;
  }
}

void merge(list * l1,list *l2)
{
    listEl * h1 = (l1->get_el(l1->size()));
    listEl * t1 = (l2->get_el(0));
    h1->next = t1;

}

int main()
{
    cout << "Merge example:" << endl;
    cout<<"List 1:"<<endl;
    list *l1 = new list();
    l1->push_back(2);
    l1->push_back(5);
    l1->push_back(10);
    l1->printl();
    cout<<l1->get_data(1)<<endl;
    cout<<l1->get_data(0)<<endl;
    cout<<l1->get_data(2)<<endl;
     cout<<"List 1:"<<endl;
    list *l2 = new list();
    l2->push_back(1);
    l2->push_back(3);
    l2->push_back(17);
    l2->printl();


    cout<<"Merge(List1,List2)"<<endl;
    merge(l1,l2);
    l1->printl();
        delete l1;
    cout<<"________________________________"<<endl;
    list * l = new list();



    srand(time(nullptr));

    for(int i = 0 ; i <1000;i++)
    {
        int randvalue = rand()%4444;
        l->push_back(randvalue);
    }

    cout<<"Czas wymagany na 10000000 wywołań 50 elementu:"<<endl;
    // Start measuring time
    time_t begin, end;
    time(&begin);

    for(int i = 0 ; i < 10000000;i++)
    {

        l->get_data(50);
    }
    time(&end);
    time_t elapsed = end - begin;
    printf("Time measured: %ld seconds.\n", elapsed);








    cout<<"Czas wymagany na 10000000 wywołań 500 elementu:"<<endl;
    // Start measuring time
    time_t begin2, end2;
    time(&begin2);

    for(int i = 0 ; i < 10000000;i++)
    {

        l->get_data(500);
    }
    time(&end2);
    time_t elapsed2 = end2 - begin2;
    cout<< elapsed2<<endl;



    cout<<"Czas wymagany na 10000000 wywołań 999 elementu:"<<endl;
    // Start measuring time
    time_t begin1, end1;
    time(&begin1);

    for(int i = 0 ; i < 10000000;i++)
    {
        l->get_data(999);
    }
    time(&end1);
    time_t elapsed1 = end1 - begin1;
    cout<<elapsed1<<endl;

    delete l;
    return 0;
}