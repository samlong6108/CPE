#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm> 
#include <bits/stdc++.h>

using namespace std ;

int main(){
    long number ; 
    long answer ;
    while(scanf("%ld", &number)!=EOF){
        if(number==0){
            break ;
        }
        // cout << "==========" << endl ;
        int total = number;
        int flag = 0 ;
        int p = 2 ;
        while(number >= p){
            while(number%p==0){
                // cout << p << endl ;
                if(flag==0){
                    total = total * (1.0-(1.0/p)) ;
                }
                flag = 1 ;
                number = number / p ;
            }
            flag = 0 ;
            p += 1 ;
        }

        cout << total << endl ;
                
    }
}