#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

int main(){
    int N ; 
    N = 1 ;
    
    while(N!=0){
        scanf("%d", &N) ; 
        if(N==0){
            break ;
        }
        // cout << "=========" << endl ;
        // cout << N << endl ;
        bool flag ;
        for(int m=1; m<10*N; m++){
            // Initial array false 
            bool array[N] ;
            for(int i=0; i<N; i++){
                array[i] = false ;
            }

            // Start loop process
            // Start with index 0
            int idx ;
            idx = 0 ;
            while(idx!=12){
                if(array[idx]==false){
                    array[idx] = true ;
                    
                    int sum ;
                    sum = 0 ;
                    while(sum!=m){                      
                        idx += 1 ;
                        idx = idx% N ;
                        if(array[idx]==false){
                            sum += 1 ;
                        }
                    }                    
                }
            }

            // idx = 12 
            // Ensure only idx 12 is false            
            flag = true ;                    
            for(int k=0; k<N; k++){
                if(k==12){
                    continue ;
                }
                else if(array[k]==false){
                    flag = false ;
                    break ;
                }
            }
            if(flag==true){
                cout << m << endl ;
                break ;
            }
            else if(flag==false){
                continue ;
            }

        }
        if (flag==false){
            cout << endl ;
        }


    }
    return 0 ;
}