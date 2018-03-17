#include <iostream>
#include <cstdio>
using namespace std ;

int n , h , arr[100010] ;

bool poss ( int k ) {
  int hrcount = 0 ;
  for ( int i = 0 ; i < n ; i ++ ){
    hrcount += arr[i] / k ;
    if ( arr[i] % k )
      hrcount ++ ;
  }
  return ( hrcount <= h ) ;
}

int binary ( int l , int r ){
  //printf("%d %d\n" , l , r ) ;
  if ( l >= r )
    return l ;
  int mid = ( l + r )>>1 ;
  if ( poss ( mid ) )
    return binary ( l , mid ) ;
  return binary ( mid + 1 , r ) ;
}
  

int main () {
  int test ;
  scanf("%d", &test ) ;
  while ( test -- ){
    scanf("%d%d", &n , &h ) ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d" , &arr[i] ) ;
    printf("%d\n" , binary ( 0 , 1000000000 ) ) ;
  }
  return 0 ;
}
	   
    
