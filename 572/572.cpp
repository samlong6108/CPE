#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void search(vector<vector<char> > &map, vector<vector<int> > &idx_table, int row, int col, int id){
    if( (row<0) || (row>=map.size())) return ;
    if( (col<0) || (col>=map[0].size())) return ;
    if( (map[row][col] !='@') || (idx_table[row][col]!=0)) return ;
    idx_table[row][col] = id ; 
    search(map, idx_table, row-1, col, id) ;
    search(map, idx_table, row-1, col+1, id) ;
    search(map, idx_table, row-1, col-1, id) ;
    search(map, idx_table, row+1, col, id) ;
    search(map, idx_table, row+1, col+1, id) ;
    search(map, idx_table, row+1, col-1, id) ;
    search(map, idx_table, row, col+1, id) ;
    search(map, idx_table, row, col-1, id) ;
}


int main(){
    int row=-1 ; 
    int col=-1 ;    
    bool Check_map = false ;
    while((row!=0) && (col!=0)){
        // Read Input 
        string row_col ;        
        getline(cin, row_col) ;
        stringstream ss(row_col) ;
        ss >> row >> col ;
        if((row==0) && (col==0)){
            break ;
        }
        // cout << "=======" << endl ;
        // cout << row << " " << col << endl ;

        // Constrcut map
        vector<vector<char> > map(row, vector<char> (col)) ;
        vector<vector<int> > idx_table(row, vector<int> (col, 0)) ;
        for(int i=0; i<row; i++){
            string one_line ;         
            getline(cin, one_line) ;            
            for(int j=0; j<col; j++){
                map[i][j] = one_line[j] ;             
            }
        }

        // Check map
        if(Check_map){
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    cout << map[i][j] ;
                }
                cout << endl ;
            }
        }

        // Ready to find max number of oil
        int id = 1 ;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if( (map[i][j]=='@') && (idx_table[i][j]==0)){
                    search(map, idx_table, i, j, id) ;
                    id++ ;
                }
            }
        }
        id -- ;
        // cout << "The answer is" << endl ;
        cout << id << endl ; 
        
    }
}