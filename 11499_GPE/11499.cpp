#include <cstdio>
#include <iostream>

using namespace std ;

int main(){
    int array_lenth ;
    scanf("%d", &array_lenth);
    int X[array_lenth] ;

    for(int i=0; i<array_lenth; i++){
        cin >> X[i] ;
    }
    // for(int i=0; i<array_lenth; i++){
    //     cout << X[i] << " " ; 
    // }
    // printf("\n") ;

    int DP[array_lenth] ;

    for(int i=0; i<array_lenth; i++){
        DP[i] = 1 ;
    }
    
    for(int i=0; i<array_lenth; i++){
        for(int j=0 ; j<i ;j++){
            if(X[j]<X[i]){
                if(DP[j]+1 > DP[i]){
                    DP[i] = DP[j] + 1 ;
                }
            }
        }
    }
    int max_length = 0 ;
    for(int i=0; i<array_lenth; i++){
        if (DP[i] > max_length){
            max_length = DP[i] ;
        }
    }    
    printf("%d\n", max_length);
}