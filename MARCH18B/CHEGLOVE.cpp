#include <iostream>
#include <cstdio>
using namespace std ;

int main (){
  int test , n , f[100010] , g ;
  bool front , back ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d" , &f[i] ) ;
    front = back = true ;
    for ( int i = 0 ; i < n ; i ++ ){
      scanf("%d" , &g ) ;
      if ( f[i] > g )
	front = false ;
      if ( f[n-1-i] > g )
	back = false ;
    }
    if ( front && back )
      printf("both\n") ;
    else if ( front )
      printf("front\n") ;
    else if ( back )
      printf("back\n") ;
    else
      printf("none\n") ;
  }
  return 0 ;
}

    
