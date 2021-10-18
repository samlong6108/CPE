#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std ;

int main(){
    string input_1, input_2 ;
    while(getline(cin, input_1)){
        getline(cin, input_2) ;
        // cout << input_1 << endl ;
        // cout << input_2 << endl ;
        int len_1 = input_1.size() ;
        int len_2 = input_2.size() ;        
        int DP[len_1+1][len_2+1] ; 
        for(int i=0; i<=len_1; i++){
            for(int j=0; j<=len_2; j++){
                DP[i][j]=0 ;
            }
        }
        for(int i=0; i<len_1; i++){
            for(int j=0; j<len_2; j++){
                if(input_1[i]==input_2[j]){
                    DP[i+1][j+1] = DP[i][j] + 1 ;
                }
                else{
                    DP[i+1][j+1] = max(DP[i][j+1], DP[i+1][j]) ;
                }
            }
        }
        cout << DP[len_1][len_2] << endl; 
    }
    return 0 ;
}