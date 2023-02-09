#include <iostream>

using namespace std;

struct dlistEl
{
  dlistEl * next;   // następnik
  dlistEl * prev;   // poprzednik
  int data;
};


class dlist
{
  public:
    dlistEl * head;  // początek listy
    dlistEl * tail;  // koniec listy
    unsigned count;  // licznik elementów

    dlist( );         // konstruktor
    ~dlist( );        // destruktor
    void printl( );
    void push_front ( int v );
    void push_back ( int v );
    void insert_before ( dlistEl * e, int v );
    void insert_after ( dlistEl * e, int v );
    void remove ( dlistEl * e );
    void pop_front( );
    void pop_back( );



    int get_data(int n)
    {
        return get_el(n)->data;
    }
    dlistEl * get_el(int n)
    {
        int kroki = 0;
        if(n<=count/2)
        {
            dlistEl * p = head;
            for(int i = 0 ; i <n;i++)
            {

            p = p->next;

            }
            return p;
        }
        else
            {
                dlistEl * p = tail;
            for(int i = 0 ; i <count-n;i++)
            {

                p = p->prev;
            }
            return p;
            }
    }

};




//------------------------------------
// Metody obiektu listy dwukierunkowej
//------------------------------------

// Inicjuje pola zmiennej listy
//-----------------------------
dlist::dlist( )
{
  head  = tail  = NULL;
  count = 0;
}

// Usuwa listę z pamięci
//----------------------
dlist::~dlist( )
{
  while( count ) pop_front( );
}


void dlist::printl( )
{
  unsigned i;
  dlistEl * p = head;

  cout << "Number of elements : " << count<< endl;
  for( i = 0; i<count; i++ )
  {
      if(p)
  {cout << "Element #" << i << "  data = " << p->data << endl; p = p->next;}
  }
  cout << endl;
}

// Dodaje nowy element na początek listy
//------------------------------------------------
void dlist::push_front ( int v )
{
  dlistEl * p;

  p = new dlistEl;
  p->data = v;
  p->prev = NULL;
  p->next = head;
  head  = p;
  count++;
  if( p->next ) p->next->prev = p;
  else tail = p;
}

// Dodaje nowy element na koniec listy
//----------------------------------------------
void dlist::push_back ( int v )
{
  dlistEl * p;

  p = new dlistEl;
  p->data = v;
  p->next = NULL;
  p->prev = tail;
  tail  = p;
  count++;
  if( p->prev ) p->prev->next = p;
  else head = p;
}

// Dodaje nowy element przed wybranym
//-----------------------------------
void dlist::insert_before ( dlistEl * e, int v )
{
  dlistEl * p;

  if( e == head ) push_front ( v );
  else
  {
    p = new dlistEl;
    p->data = v;
    p->next = e;
    p->prev = e->prev;
    count++;
    e->prev->next = p;
    e->prev = p;
  }
}

// Dodaje nowy element za wybranym
//--------------------------------
void dlist::insert_after ( dlistEl * e, int v )
{
  dlistEl * p;

  if( e == tail ) push_back ( v );
  else
  {
    p = new dlistEl;
    p->data = v;
    p->next = e->next;
    p->prev = e;
    count++;
    e->next->prev = p;
    e->next = p;
  }
}

// Usuwa wybrany element z listy
//------------------------------
void dlist::remove ( dlistEl * e )
{
  count--;
  if( e->prev ) e->prev->next = e->next;
  else        head = e->next;
  if( e->next ) e->next->prev = e->prev;
  else        tail = e->prev;
  delete e;
}

// Usuwa element z początku listy
//-------------------------------
void dlist::pop_front( )
{
  if( count ) remove ( head );
}

// Usuwa element z końca listy
//----------------------------
void dlist::pop_back( )
{
  if( count ) remove ( tail );
}




void merge(dlist * l1,dlist *l2)
{
    dlistEl * t1 = (l1->get_el(l1->count));
    dlistEl * h1 = (l1->get_el(0));
    dlistEl * t2 = (l2->get_el(l2->count));
    dlistEl *h2 = (l2->get_el(0));
    t1->next = h2;
    h2->prev = t1;

    t2->next = h1;
    h1->prev = t2;

    l1->count = l1->count + l2->count;

}







int main()
{


    cout << "Merge example:" << endl;
    cout<<"List 1:"<<endl;
    dlist *l1 = new dlist();
    l1->push_back(2);
    l1->push_back(5);
    l1->push_back(10);
    l1->printl();
    cout<<"TAIL: "<<l1->get_data(l1->count)<<endl;
    cout<<"Head: "<<l1->get_data(0)<<endl;
     cout<<"List 2:"<<endl;
    dlist *l2 = new dlist();
    l2->push_back(1);
    l2->push_back(3);
    l2->push_back(17);
    l2->printl();
    cout<<"TAIL: "<<l2->get_data(l1->count)<<endl;
    cout<<"Head: "<<l2->get_data(0)<<endl;


    cout<<"Merge(List1,List2)"<<endl;
    merge(l1,l2);
    l1->printl();
        //delete l1;
    cout<<"________________________________"<<endl;


















    dlist * l = new dlist();



    srand(time(nullptr));

    for(int i = 0 ; i <1000;i++)
    {
        int randvalue = rand()%100;
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
    cout<<elapsed2<<endl;
    delete l;
    return 0;

}
