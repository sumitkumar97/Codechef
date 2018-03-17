#include <iostream>
#include <cstdio>
using namespace std ;

unsigned int seg[32][400010] , arr[100010] ;

int lquery , rquery ;

void seg_build ( int vertex , int lseg , int rseg , int bit ) {
  int x = 1<<bit ;
  if ( lseg == rseg ){
    seg[bit][vertex] = ( ( arr[lseg] & x ) == x ) ? 1 : -1 ;
    return ;
  }
  int lchild = vertex<<1 , mid = (lseg+rseg)>>1 ;
  seg_build ( lchild , lseg , mid , bit ) ;
  seg_build ( lchild + 1 , mid + 1 , rseg , bit ) ;
  seg[bit][vertex] = seg[bit][lchild] + seg[bit][lchild+1] ;
}

int query ( int vertex , int lseg , int rseg , int bit ){
  if ( lquery > rseg || rquery < lseg )
    return 0 ;
  if ( lseg >= lquery && rseg <= rquery )
    return seg[bit][vertex] ;
  int lchild = vertex<<1 , mid = ( lseg+rseg)>>1 ;
  return query ( lchild , lseg , mid , bit ) + query ( lchild + 1 , mid + 1 , rseg , bit ) ;
}
    

int main ( ) {
  unsigned int n , q ;
  scanf("%d%d" , &n , &q ) ;
  
  for ( int i = 1 ; i <= n ; i ++ )
    scanf("%d" , &arr[i] ) ;
  
  for ( int i = 0 ; i < 32 ; i ++ )
    seg_build ( 1 , 1 , n , i ) ;
  
  for ( int i = 0 ; i < q ; i ++ ){
    scanf("%d%d" , &lquery , &rquery ) ;

    unsigned int ans = 0 ;
    for ( int j = 0 ; j < 31 ; j ++ ){
      if ( query ( 1 , 1 , n , j ) < 0 )
	ans += 1<<j ;
    }
    printf("%u\n" , ans ) ;
  }
  return 0 ;
}
