#include <cstdio>
#include <iostream>

using namespace std ;

int M, N ;

int main(){
    int Test_cases_number ;
    int Q ;
    char letter ;
    int point_i, point_j ;
    scanf("%d", &Test_cases_number) ;
    for(int number=0; number<Test_cases_number; number++){
        scanf("%d %d %d", &M, &N, &Q) ;
        // printf("===================\n");
        printf("%d %d %d\n", M, N, Q) ;
        char array[M][N] ;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                cin >> array[i][j] ;
            }
        }
        // for(int i=0; i<M; i++){
        //     for(int j=0; j<N; j++){
        //         printf("%c", array[i][j]);
        //     }
        //     printf("\n");
        // }        
        for(int i=0; i<Q; i++){
            scanf("%d %d", &point_i, &point_j) ;
            // printf("==\n") ;
            
            if(point_i<0){
                if(point_j<0){
                    continue ;
                }
            }
            // printf("=============================\n");
            // printf("%d %d\n",M, N) ;
            // printf("%d %d\n", point_i, point_j) ;
            for(int range=0; range<100; range++){
                int radius = 2*range + 1;
                int flag = 0 ;
                for(int index_i=point_i-range; index_i<=point_i+range; index_i++){
                    for(int index_j=point_j-range; index_j<=point_j+range; index_j++){
                        if(index_i<0 || index_j<0 || index_i>M-1 || index_j>N-1){
                            flag = 1 ;
                            break ;
                        }                                                 
                        
                        if(array[index_i][index_j]!=array[point_i][point_j]){                            
                            flag = 1 ;
                            break ;
                        }
                    }
                    if(flag==1){
                        break ;
                    }
                }
                if(flag==1){                
                    printf("%d\n", 2*(range-1)+1) ;
                    break ;
                }
            }            

        }
    }
}