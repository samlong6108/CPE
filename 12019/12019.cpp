#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std ;


// 2011 is non-leap year
// Monday : 1/10, 2/21, 4/4, 5/9, 6/6, 7/11, 8/8, 9/5, 10/10, 11/7, 12/12
int main(){
    int number_case;
    int month ;
    int date ;
    int map_date ;
    int diff_date ; 
    map<int, int> month_to_data = {{1, 10,}, {2, 21,}, {3, 7,}, {4, 4,}, {5, 9,}, {6, 6,}, {7, 11,}, {8, 8,}, {9, 5,}, {10, 10,}, {11, 7,}, {12, 12,}};
    map<int, string> diff_to_string = {{0, "Monday",}, {1, "Tuesday",}, {2, "Wednesday",}, {3, "Thursday",}, {4, "Friday",}, {5, "Saturday",}, {6, "Sunday"}};
    scanf("%d", &number_case);
    // printf("%d\n", number_case);
    while(scanf("%d %d", &month, &date)!=EOF){
        // printf("=====================\n");
        // printf("%d %d\n", month, date) ;
        map_date = month_to_data[month] ; 
        diff_date = date - map_date ;
        // printf("%d\n", map_date) ;
        // printf("%d\n", diff_date) ;
        if(diff_date>0){
            // printf("Enter >0 case \n");
            diff_date = diff_date%7 ;
            // printf("%d\n", diff_date) ;
        }
        else{
            // printf("Enter <0 case \n") ;
            diff_date = -1 * diff_date ;
            diff_date = (7 - diff_date%7)%7 ;
        }
        cout << diff_to_string[diff_date] << "\n" ;
    }
}