#include <iostream>
#include <string>

using namespace std;

#define STRINGSIZE 5000
int main( )
{

    int moves = 0;
    int compares = 0;

  char s1[STRINGSIZE];
   char s2[STRINGSIZE];
   string sLCS;
  int ** L, i, j, m, n;


  static const int iloscLiter = 'z' - 'a';
   
    string wyraz;
    string moja;
    srand( time( NULL ) );
   
    for( int i = 0; i < 1000; ++i )
    {
        s1[i] = rand() %( iloscLiter + 1 ) + 'a';
    }
    for( int i = 0; i < 1000; ++i )
    {
        s2[2] = rand() %( iloscLiter + 1 ) + 'a';
    }
  
  m  = STRINGSIZE;
  n  = STRINGSIZE;

// tworzymy dynamicznie tablicę L

  L = new int * [ m + 1 ];
  for( i = 0; i <= m; i++ )
  {
   L [ i ] = new int [ n + 1 ];
  }

// obliczamy tablicę L

  for( i = 0; i <= m; i++ ) 
   { 
    L [ i ][ 0 ] = 0;
   
   }
  for( j = 0; j <= n; j++ ) 
    {
        L [ 0 ][ j ] = 0;
       
    }
  for( i = 0; i < m; i++ )
  {
    for( j = 0; j < n; j++ )
    {
      if( s1 [ i ] == s2 [ j ] )
        {
            L [ i + 1 ][ j + 1 ] = 1 + L [ i ][ j ];
            moves++;
            compares++;
        }
      else
        {
            L [ i + 1 ][ j + 1 ] = max ( L [ i + 1 ][ j ], L [ i ][ j + 1 ] );
            moves++;
            compares++;
        }
    }
  }
// wyznaczamy LCS

  sLCS = ""; i = m - 1; j = n - 1;
  while( ( i >= 0 ) && ( j >= 0 ) )
    if( s1 [ i ] == s2 [ j ] )
    {
      sLCS = s1 [ i ] + sLCS;
      i--; j--;
      moves++;
            compares++;
    }
    else if( L [ i + 1 ][ j ] > L [ i ][ j + 1 ] ) 
    {
        j--;
        compares++;
        }
    else {
        i--;
        compares++;
        }
 // cout << sLCS << ": " << L [ m ][ n ] << endl;
  cout<<STRINGSIZE<<";"<<moves<<";"<<compares<<endl;
  return 0;
} 