#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

using namespace std ;

int main(){
    int N, R ;
    int C1, C2, P ;
    int S, D, T ;
    int number = 1 ;
    while(scanf("%d %d", &N, &R)){
        if(N==0 && R==0){
            break ;
        }
        // cout << "=========" << endl ;
        // cout << N << " " << R << endl ;

        int Table[N][N] ;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                Table[i][j] = 0 ;
            }
        }
        for(int i=0; i<R; i++){
            scanf("%d %d %d", &C1, &C2, &P);
            // cout << C1 << " " << C2 << " " << P  << endl ;            
            Table[C1-1][C2-1] = P ;
            Table[C2-1][C1-1] = P ;
        }        
        scanf("%d %d %d", &S, &D, &T);
        // cout << S <<" " << D << " " << T << endl ;
        cout << "Scenario #" << number << endl ;
        number += 1 ;        

        for(int k=0; k<N; k++){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    Table[i][j] = max(Table[i][j], min(Table[i][k], Table[k][j])) ;
                }
            }
        }                

        int max_capicity = Table[S-1][D-1] ;     
        max_capicity -= 1 ;           
        int times = T / max_capicity ;
        if(T%max_capicity!=0){
            times += 1 ;
        }
        cout << "Minimum Number of Trips = " << times << endl ;
        cout << endl ;
        
    }
}