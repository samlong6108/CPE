#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

int main(){
    int number=1 ;
    int size = 100000 ; 
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(0) ;
    double *dp ;
    dp = new double[size] ;
    // int dp[65536] ; 
    dp[0] = 0 ;
    dp[1] = 1 ;
    dp[2] = 2 ;
    for(int i=3; i<size; i++){
        dp[i] = dp[i-1] + dp[i-2] ;
    }
    while(scanf("%d\n", &number)){
        if(number==0){
            break ;
        }
        cout << dp[number] << endl ;
    }
    
}