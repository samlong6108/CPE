#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

// 1 : up 0 -1
// 2 : up left -1 0
// 3 : left down -1 1
// 4 : down 0 1
// 5 : right down 1 0
// 6 : up right 1 -1

// pass_through : Accumulate !!

int main(){
    int input ;
    int level ;
    int level_max ;
    int level_move ;
    int diff ;
    int pass_x ;
    int pass_y ;
    map<int, int> pass_through_x= {{0, 0}, {1, 0}, {2, -1}, {3, -2}, {4, -2}, {5, -1}, {6, 0}};
    map<int, int> pass_through_y= {{0, 0}, {1, -1}, {2, -1}, {3, 0}, {4, 1}, {5, 1}, {6, 0}};
    map<int, int> moudle_x = {{0, 0}, {1, 0}, {2, -1}, {3, -1}, {4, 0}, {5, 1}, {6, 1}} ;
    map<int, int> moudle_y = {{0, 0}, {1, -1}, {2, 0}, {3, 1}, {4, 1}, {5, 0}, {6, -1}} ;
    while(scanf("%d ", &input)!=EOF){
        // printf("========\n");
        // printf("%d\n", input);
        if(input==1){
            printf("%d %d\n", 0, 0);
            continue ;
        }
        for(int i=1; i<9999; i++){
            level_max = 3 * (i*i - i) + 1 ;
            if(level_max>=input){
                level = i ;
                break ;
            }
        }
        // printf("Number %d is at the level %d . And the level max is %d\n", input, level, level_max);
        int x = level - 1 ;
        int y = 0 ; 
        level_move = level - 1 ;
        diff = level_max - input ;
        // printf("diff is %d\n", diff);
        // printf("level_move is %d\n", level_move);
        int pass_number = diff/level_move ;
        pass_x = pass_through_x[pass_number] ;
        pass_y = pass_through_y[pass_number] ;
        // printf("%d %d\n", pass_x, pass_y);
        x = pass_x * level_move + x ;
        y = pass_y * level_move + y ;
        int pass_number_moudle = pass_number + 1;
        x = x + moudle_x[pass_number_moudle] * (diff%level_move) ;
        y = y + moudle_y[pass_number_moudle] * (diff%level_move) ;
        printf("%d %d\n", x, y) ;

    }
    return 0 ;
}