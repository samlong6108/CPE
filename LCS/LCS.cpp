#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

void dfs(string& f, string& s, int col, int row, int** table, string seq, set<string>& seqs) {
    if(col == 0 || row == 0) {
        seq.insert(seq.begin(), f[col]);
        seqs.insert(seq);
        return;
    }

    if(f[col] == s[row]) {                
        seq.insert(seq.begin(), f[col]);
        dfs(f, s, col-1, row-1, table, seq, seqs);
    }
    else {
        if(table[row-1][col] == table[row][col-1]) {
            dfs(f, s, col-1, row, table, seq, seqs);
            dfs(f, s, col, row-1, table, seq, seqs);            
        }
        else if(table[row-1][col] > table[row][col-1]) {
            dfs(f, s, col, row-1, table, seq, seqs);
        }
        else {
            dfs(f, s, col-1, row, table, seq, seqs);
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
        int First_choice = 1; 
        int Second_choice = 1; 
        for(int k=First_start+1; k<First.length(); k++){                    
            if(First[k]==Boundary){
                multiple_times*= (First_choice) ;                                                                                                
                First_start +=1 ;
                break ;
            }
            else if(First[k]==Now){
                First_choice += 1 ;                                                
            }                                         
            First_start +=1 ;                    
        }
        for(int k=Second_start+1; k<Second.length(); k++){                                        
            if(Second[k]==Boundary){
                multiple_times*= Second_choice ;                    
                Second_start += 1 ;
                break ;
            }
            else if(Second[k]==Now){
                Second_choice += 1 ;                        
            }
            Second_start += 1 ;
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
                
        dfs(First, Second, First.length()-1, Second.length()-1, ptr_table, seq, seqs) ;        
        for(set<string>::iterator it=seqs.begin(); it!=seqs.end(); it++){
            cout << "===========" << endl ;                     
            string LCS_temp ;
            LCS_temp = *it ; 
            int multiple_times ;
            cout << LCS_temp << endl ;
            multiple_times = Howmanytimes(LCS_temp, First, Second) ;
            cout << multiple_times << endl ;            
        }
    }
}