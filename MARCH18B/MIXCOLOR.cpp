#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main () {
  int test , n , arr[100010] , count ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    count = 0 ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d" , &arr[i] ) ;
    sort ( arr , arr + n ) ;
    for ( int i = 1 ; i < n ; i ++ )
      if ( arr[i] == arr[i-1] )
	count ++ ;
    printf("%d\n" , count ) ;
  }
  return 0 ;
}
