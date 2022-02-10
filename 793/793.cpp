#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std ;

int main(){
    int Case_total_number ; 
    scanf("%d", &Case_total_number) ;
    // cout << "Has " << Case_total_number << " case" << endl ;

    string input ;    
    getline(cin, input) ;
    // cout << input << endl ; 
    
    for(int casenumber=0; casenumber<Case_total_number; casenumber++){
        if (casenumber > 0) cout << "" << endl ;

        int Computer_number ; 
        scanf("%d", &Computer_number) ;
        // cout << Computer_number << endl ;      
        cin.ignore() ;   
        int correct = 0 ;
        int incorrect = 0 ;
        int Connected[Computer_number][Computer_number] ;
        for(int index_i=0; index_i<Computer_number; index_i++){
            for(int index_j=0; index_j<Computer_number; index_j++){
                if (index_i==index_j){
                    Connected[index_i][index_j] = 1 ;    
                }
                else{
                    Connected[index_i][index_j] = 0 ;
                }
                
            }
        }
        while(getline(cin, input) && input!=""){     
            cout << "=========" << endl ;
            cout << input << endl ;                    
            stringstream ss(input);
            char input_question ; 
            int input_1, input_2 ;
            ss >> input_question >> input_1 >> input_2 ;   
            // cout << input_1 << endl ;
            // cout << input_2 << endl ;
            if(input[0]=='c'){                
                Connected[input_1-1][input_2-1] = 1 ;
                Connected[input_2-1][input_1-1] = 1 ;
            }
            else{
                for(int i=0; i<Computer_number; i++){
                    for(int j=0; j<Computer_number; j++){
                        for(int k=0; k<Computer_number; k++){
                            if(Connected[i][j]==Connected[j][k]){
                                if(Connected[i][j]==1){
                                    Connected[i][k] = 1 ;
                                    Connected[k][i] = 1 ;
                                }
                            }
                        }
                    }
                }
            
                if(Connected[input_1-1][input_2-1]==1){
                    correct += 1 ;
                }
                else{
                    incorrect += 1 ;
                }
            }            
        }
        cout << correct << "," << incorrect <<endl ;
    }
}