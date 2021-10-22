#include <cstdio>
#include <iostream>

using namespace std ; 

int main(){
    int Length ;
    int Sum;
    int Case = 1 ;        


    int dp[27][27][352] ;

    for(int i=0; i<27; i++){
        for(int j=0; j<27; j++){
            for(int k=0; k<352; k++){
                dp[i][j][k] = 0 ;
            }
        }
    }

    for(int i=1; i<=26; i++) dp[i][1][i] = 1 ;
    for(int i=1; i<=26; i++){
        for(int j=1; j<=i; j++){
            for(int k=1; k<=351; k++){
                dp[i][j][k] += dp[i-1][j][k] ;
                if(k>=i){
                    dp[i][j][k] += dp[i-1][j-1][k-i] ;
                }
            }
        }
    }


    scanf("%d %d", &Length, &Sum) ;
    while(Length!=0 && Sum!=0){
        // cout << "=================" << endl ;
        // cout << Length << " " << Sum << endl ;
        if(Length <= 26 && Sum <= 351){
            int Number_Case = dp[26][Length][Sum] ;        
            cout << "Case " << Case << ": " << Number_Case << endl ;            
        }
        else{
            cout << "Case " << Case << ": " << "0" << endl ;
        }

        Case += 1 ;
        scanf("%d %d", &Length, &Sum) ;
    }
    
}