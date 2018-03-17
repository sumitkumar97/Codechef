#include <iostream>
#include <cstdio>
using namespace std ;

int main (){
  int n , test , q ;
  double cp , d , loss , sp ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    loss = 0 ;
    for ( int i = 0 ; i < n ; i ++ ){
      scanf("%lf%d%lf" , &cp , &q , &d ) ;
      sp = ( cp + ((cp*d)/100.0) ) ;
      sp -= (sp*d)/100.0 ;
      loss += (cp-sp)*q ;
    }
    printf("%lf\n" , loss ) ;
  }
  return 0 ;
}
