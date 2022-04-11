#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

int main(){
    int number ;
    scanf("%d", &number) ;
    for(int iter=0; iter<number; iter++){
        int number_point ;
        scanf("%d", &number_point) ;
        vector<pair<float, float> > v ;
        for(int pair_idx=0; pair_idx<number_point; pair_idx++){
            float position_x ;
            float position_y ;
            scanf("%f %f", &position_x, &position_y)  ;
            v.push_back(pair<float, float>(position_x, position_y)) ;
        }

        // for(int i=0; i<point.size() ; i++){
            // cout << "============" << endl ;
            // cout << point[i].first << " " << point[i].second << endl ;
        // }

        map<float, set<float> > mapping ;
        map<float, set<float> > ::iterator finding ;
        for(int j=0; j<v.size(); j++){
            for(int k=j+1; k<v.size(); k++){
                float a = (v[k].second - v[j].second) / (v[k].first - v[j].first) ;
                float b = v[k].second - a*v[k].first ;
                
                if(isinf(a)!=0){
                    b = v[k].first ;
                }

                finding = mapping.find(a) ;
                if(finding==mapping.end()){
                    float temp[] = {b} ; 
                    set<float> second(temp, temp+1) ;
                    mapping.insert(pair<float, set<float> >(a, second)) ;
                    continue ;
                }

                set<float> temp = finding->second ;
                temp.insert(b) ;
                mapping.erase(a) ;
                mapping.insert(pair<float, set<float> >(a, temp)) ;
            }
        }
        int count = 0 ;
        for(map<float, set<float> >::iterator it=mapping.begin(); it!=mapping.end(); ++it){
            for(set<float>::iterator iter=it->second.begin(); iter!=it->second.end(); ++iter){
                count += 1 ;
            }
        }
        cout << count << endl ;
        
    }
    return 0 ;
}