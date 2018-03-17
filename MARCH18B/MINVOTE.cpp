#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

typedef long long ll ;

int seg[400010] , lazy[400010] ;

int query ( int vertex , int lseg , int rseg , int lquery , int rquery ){
  if ( lquery > rseg || rquery < lseg )
    return 0 ;
  if ( lazy[vertex] > 0 ){
    seg[vertex] += lazy[vertex] ;
    if ( lseg != rseg ){
      lazy[vertex<<1] += lazy[vertex] ;
      lazy[(vertex<<1)+1] += lazy[vertex] ;
    }
    lazy[vertex] = 0 ;
  }
  if ( lseg >= lquery && rseg <= rquery )
    return seg[vertex] ;
  int lchild = vertex<<1 , mid = (lseg+rseg)>>1 ;
  return query ( lchild , lseg , mid , lquery , rquery ) + query ( lchild + 1 , mid + 1 , rseg , lquery , rquery);
}

void update ( int vertex , int lseg , int rseg , int lquery , int rquery ){
  //  printf("lseg = %d rseg = %d\n" , lseg , rseg ) ;
  if ( lquery > rseg || rquery < lseg )
    return ;
  
  if ( lseg >= lquery && rseg <= rquery ) {
    if ( lseg == rseg )
      seg[vertex] ++ ;
    else {
      lazy[vertex<<1] ++ ;
      lazy[(vertex<<1)+1] ++ ;
    }
    return ;
  }
    
  int lchild = vertex<<1 , mid = (lseg+rseg)>>1 ;
  update ( lchild , lseg , mid , lquery , rquery ) ;
  update ( lchild + 1 , mid + 1 , rseg , lquery , rquery ) ;
}

int main ( ) {
  int test , n , up , down ;
  ll sum[100010] , arr[100010] ; 
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;

    for ( int i = 0 ; i < (n<<2) ; i ++ ) {
      seg[i] = 0 ;
      lazy[i] = 0 ;
    }
    
    scanf("%lld" , &arr[0] ) ;
    sum[0] = arr[0] ;
    for ( int i = 1 ; i < n ; i ++ ) {
      scanf("%lld" , &arr[i] ) ;
      sum[i] = arr[i] + sum[i-1] ;
    }

    for ( int i = 0 ; i < n ; i ++ ){
      up = upper_bound ( sum , sum + n , sum[i] + arr[i] ) - sum ;

      if ( up >= n )
	up = n -1 ;
      if ( i + 1 <= up )
	update ( 1 , 0 , n -1 , i + 1 , up ) ;
      
      down = lower_bound ( sum , sum + n , sum[i] - arr[i] - arr[i] ) - sum ;
      
      if ( down < 0 )
	down = 0 ;

      if ( i - 1 >= down )
	update ( 1 , 0 , n - 1 , down , i - 1 ) ;


      /*      printf("%d Minion is voting\n" , i ) ;
      for ( int j = 0 ; j < n ; j ++ ) 
	printf("%d " , query ( 1 , 0 , n - 1 , j , j ) ) ;
	printf("\n") ; */



    }
    
    for ( int i = 0 ; i < n ; i ++ )
      printf("%d " , query ( 1 , 0 , n - 1 , i , i ) ) ;
    printf("\n") ;
  }
  return 0 ;
}
