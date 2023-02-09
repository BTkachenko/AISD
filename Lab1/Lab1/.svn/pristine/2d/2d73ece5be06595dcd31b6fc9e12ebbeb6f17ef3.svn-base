#include <iostream>

using namespace std;
const int MAXINT = -2147483647;

class stack
{
  private:
    int n;      // rozmiar tablicy
    int sptr;   // wskaźnik stosu
    int * S;    // tablica dynamiczna

  public:
 // konstruktor
    stack ( int x )
{
  n = x;
  S = new int [ x ];
  sptr = 0;
}
 ~stack()
{
  delete [ ] S;
}
    bool empty ( ) {
    return !sptr;
    }
     int  top ( ){
        if( sptr ) return S [ sptr - 1 ];
        return -MAXINT;
    }
    void push ( int v ) {
        if( sptr < n ) S[ sptr++ ]= v;
    }
    void pop ( )
    {
    if( sptr ) sptr--;
    }
};



class Fifo
{

  private:
    int n;      // rozmiar tablicy
    int qptr;   // wskaźnik początku kolejki
    int qcnt;   // licznik elementów
    int * F;    // tablica dynamiczna

  public:




// Konstruktor - tworzy tablicę dla kolejki
//-----------------------------------------
Fifo ( int x )
{
  n = x;
  F = new int [ x ];
  qptr = qcnt = 0;
}

// Destruktor - zwalnia tablicę dynamiczną
//----------------------------------------
~Fifo( )
{
  delete [ ] F;
}

// Sprawdza, czy kolejka jest pusta
//---------------------------------
bool empty ()
{
  return !qcnt;
}

// Zwraca początek kolejki.
// Wartość specjalna to -MAXINT
//-----------------------------
int front ()
{
  if( qcnt ) return F [ qptr ];
  return -MAXINT;
}

// Zapisuje do kolejki
//--------------------
void push ( int v )
{
  int i;
  if( qcnt < n )
  {
    i = qptr + qcnt++;
    if( i >= n ) i -= n;
    F[ i ] = v;
  }
}

// Usuwa z kolejki
//----------------
void pop ( )
{
  if( qcnt )
  {
    qcnt--;
    qptr++;
    if( qptr == n ) qptr = 0;
  }
}
};




int main( )
{
    cout<<"Stos:"<<endl;
  stack S ( 10); // tworzymy stos na 10 elementów


  for(int i = 1; i <= 10; i++ ){ S.push(i);cout<<"Dodano do stosu: "<< S.top ()<<endl;}

  while( !S.empty( ) )
  {

    cout << "Wyjmuje ze stosu: "<<S.top( ) << endl;
    S.pop( );
  }

  cout<<"_________________________"<<endl;
  cout<<"Kolejka:"<<endl;
  Fifo F( 10 ); // tworzymy kolejkę na 10 elementów

  for( int i = 1; i <= 10; i++ ) 
  { F.push(i);
    cout<<"Dodano do kolejki: "<< i<<endl;
  }
  while( !F.empty( ))
  {
    cout <<"Wyjmuje z kolejki: "<< F.front( ) << endl;
    F.pop( );
  }
}
