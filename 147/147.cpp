#include <bits/stdc++.h>
#include <iostream>

using namespace std ;


long long dp[30005] = {1} ;

int money[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5} ;

int main(){

    for(int i=10; i>=0; i--){
        for(int j=money[i]; j<=30000; j++){
            dp[j] = dp[j] + dp[j-money[i]] ;            
        }
    }

    int part1, part2;    
    while(scanf("%d.%d", &part1, &part2)!=EOF && !(part1==0 && part2==0)){        
        printf("%3d.%02d%17lld\n", part1, part2, dp[part1*100+part2]) ;
    }
}