#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

void dfs(string& f, string& s, int col, int row, int** table, string seq, set<string>& seqs, int max) {
    if(seq.length()==max){
        seqs.insert(seq);
        return ; 
    }

    if(row == 0 || col==0) {
        if(row==0){
            seq.insert(seq.begin(), s[row]);
        }
        else if(col==0){
            seq.insert(seq.begin(), f[col]);
        }                
        seqs.insert(seq);
        return;
    }
  
    if(f[col] == s[row]) {                
        seq.insert(seq.begin(), f[col]);
        dfs(f, s, col-1, row-1, table, seq, seqs, max);
    }
    else {
        if(table[row-1][col] == table[row][col-1]) {
            dfs(f, s, col-1, row, table, seq, seqs, max);
            dfs(f, s, col, row-1, table, seq, seqs, max);            
        }
        else if(table[row-1][col] > table[row][col-1]) {
            dfs(f, s, col, row-1, table, seq, seqs, max);
        }
        else {
            dfs(f, s, col-1, row, table, seq, seqs, max);
        }
    }
}

int Howmanytimes(string LCS_temp, string First, string Second){
    int multiple_times = 1 ;
    int First_start = 0; 
    int Second_start = 0 ;    
    for(int j=0; j<LCS_temp.size()-1; j++){        
        char Now = LCS_temp[j] ;
        char Boundary = LCS_temp[j+1] ;                
        int First_choice = 0; 
        int Second_choice = 0; 

        for(int k=First_start; k<First.length(); k++){                
            if(First[k]==Boundary){
                if(First_choice!=0){
                    multiple_times*= (First_choice) ;                                                                                                                
                    break ;
                }
                else{
                    First_start += 1 ;                    
                    First_choice += 1 ;  
                    continue ;
                }                
            }
            else if(First[k]==Now){                
                First_choice += 1 ;                                                
                First_start +=1 ;

            }
            else{
                First_start += 1 ;
            }                                                                         
        }                
        for(int k=Second_start; k<Second.length(); k++){                          
            if(Second[k]==Boundary){
                if(Second_choice!=0){
                    multiple_times*= Second_choice ;                                    
                    break ;
                }
                else{
                    Second_start += 1 ;
                    Second_choice += 1 ;  
                    continue ;
                }                                
            }
            else if(Second[k]==Now){
                Second_choice += 1 ;                        
                Second_start += 1 ;
            }
            else{
                Second_start += 1 ;
            }            
        }
    }    
    return multiple_times ;
}


int main(){
    int number_case ; 
    scanf("%d\n", &number_case) ;
    for(int case_=0; case_<number_case; case_++){
        string First, Second ;
        getline(cin, First); 
        getline(cin, Second);
        cout << First << endl ;
        cout << Second << endl ;
        int Table[Second.length()][First.length()] ;
        int Table_direction[Second.length()][First.length()] ;

        memset(Table, 0, sizeof(int) * Second.length() * First.length());
        memset(Table_direction, 0, sizeof(int) * Second.length() * First.length());

        for(int i=0; i<First.length(); i++){
            if(First[i]==Second[0]){
                Table[0][i] = 1 ;
            }
            else if(Table[0][i-1]==1){
                Table[0][i] = 1 ;
            }            
        }
        for(int i=0; i<Second.length(); i++){
            if(Second[i]==First[0]){
                Table[i][0] = 1 ;
            }
            else if(Table[i-1][0]==1){
                Table[i][0] = 1 ;
            }
        }


        for(int i=1; i<Second.length(); i++){
            for(int j=1; j<First.length(); j++){
                if(First[j]==Second[i]){
                    Table[i][j] = Table[i-1][j-1] + 1 ;
                }
                else{
                    Table[i][j] = max(Table[i-1][j], Table[i][j-1]) ;
                }
            }
        }
        cout << "  " ;
        for(int i=0; i<First.length(); i++){
            cout << First[i] << " ";
        }
        cout << endl ;

        for(int i=0; i<Second.length(); i++){
            cout << Second[i] << " ";
            for(int j=0; j<First.length(); j++){
                cout << Table[i][j] << " " ;            
            }
            cout << endl ;
        }
                
        set<string> seqs ;
        string seq ;        
        int* ptr_table[Second.length()] ;
        for(int temp=0; temp<Second.length(); temp++){
            ptr_table[temp] = Table[temp] ;
        }
        int total_number = 0 ;
        int max_number = Table[Second.length()-1][First.length()-1] ;
        dfs(First, Second, First.length()-1, Second.length()-1, ptr_table, seq, seqs, max_number) ;        
        for(set<string>::iterator it=seqs.begin(); it!=seqs.end(); it++){
            cout << "===========" << endl ;                     
            string LCS_temp ;
            LCS_temp = *it ; 
            int multiple_times = 1 ;
            cout << LCS_temp << endl ;
            multiple_times = Howmanytimes(LCS_temp, First, Second) ;
            total_number += multiple_times ;
            cout << multiple_times << endl ;            
        }
        cout << total_number << endl ;
    }
}