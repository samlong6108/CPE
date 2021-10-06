#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main(){
    int number_list ;
    long long number ;
    int point_i, point_j, point_k ;
    long long a, b, c, d;
    while(true){
        scanf("%d", &number_list);
        int break_flag = 0 ;        
        vector<long long> list ;
        if(number_list==0) break ;        
        for(int i=0; i<number_list; i++){
            scanf("%lld", &number);            
            list.push_back(number);
        }
        sort(list.begin(), list.end());
        for(int i=list.size()-1; i>=0; i--){         
            d = list[i] ;            
            for(point_k=list.size()-1; point_k>=0; point_k--){
                for(point_j=point_k-1; point_j>=0; point_j--){
                    for(point_i=point_j-1; point_i>=0; point_i--){
                        if(i==point_i | i==point_j | i==point_k){
                            continue ;
                        }
                        a = list[point_i] ;
                        b = list[point_j] ;
                        c = list[point_k] ;
                        if((a+b+c)==d){
                            printf("%lld\n", d) ;
                            break_flag = 1 ;                            
                        }
                        if(break_flag==1) break;
                    }
                    if(break_flag==1) break;                    
                }
                if(break_flag==1) break;
            }                
            if(break_flag==1) break ;
        }
        if(break_flag==0){
            printf("no solution\n");
        }        
    }
}