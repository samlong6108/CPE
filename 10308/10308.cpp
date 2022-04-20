#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

const int maxn = 10001 ;
vector<pair<int, int> > toPoint[maxn] ; 
int answer=0 ;


int dfs(int to, int from){
    int Aroad=0 ;
    int temp=0 ;
    
    for(int i=0; i<toPoint[to].size(); i++){
        int go = toPoint[to][i].first ;
        int dist = toPoint[to][i].second ;      
        if(go != from){
            temp = dfs(go, to) + dist ;            
            answer = max(answer, temp+Aroad) ;             
            Aroad = max(temp, Aroad) ;
        }        
    }
    return Aroad ; 
}

int main(){
    string input ;    
    int v_a;
    int v_b;
    int distance;
    

    while(getline(cin, input)){               
        if(input.length()==0){
            dfs(1, 0) ;
            cout << answer << endl ;
            answer = 0 ;
            for(int i=0; i<maxn; i++){
                toPoint[i].clear() ;
            }
        }
        stringstream ss(input);
        ss >> v_a >> v_b >> distance ;            
        toPoint[v_a].push_back(make_pair(v_b, distance)) ;
        toPoint[v_b].push_back(make_pair(v_a, distance)) ;
    }
    dfs(1, 0) ;
    cout << answer << endl ;
    return 0 ;
}