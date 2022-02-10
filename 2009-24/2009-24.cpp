#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>

using namespace std ;

int main(){
    int number ;
    scanf("%d", &number);
    for(int i=0; i<number; i++){
        int number_point ;
        scanf("%d", &number_point) ;
        vector<pair<float, float> > v ;
        for(int j=0; j<number_point; j++){
            float point1, point2; 
            scanf("%f %f", &point1, &point2);
            v.push_back(pair<float, float>(point1, point2));
        }
        // cout << "Vector content is" << endl ;
        // for(int j=0; j<number_point; j++){
            // cout << v[j].first <<" " << v[j].second << endl ;
        // }

        map<float, set<float> > mapping ; 
        map<float, set<float> >::iterator finding ;
        for(int j=0; j<number_point; j++){
            for(int k=j+1; k<number_point; k++){
                // cout << "==========" << endl ;
                
                float a = (v[k].second - v[j].second) / (v[k].first - v[j].first) ;
                float b = v[k].second - a*v[k].first ;
                // cout << "x = " << v[j].first << " y= " << v[j].second << endl;
                // cout << "x = " << v[k].first << " y= " << v[k].second << endl;
                // cout << "a = " << a << " b = " << b << endl ;
                if(isinf(a)!=0){
                    // a = INFINITY ;                    
                    b = v[k].first ;
                }
                finding = mapping.find(a) ;
                if(finding==mapping.end()){
                    float temp[] = {b} ;
                    set<float> second (temp, temp+1) ;
                    mapping.insert(pair<float, set<float> >(a,  second)) ;
                    continue ;
                }
                // cout << "x = " << v[j].first << " y= " << v[j].second << endl;
                // cout << "x = " << v[k].first << " y= " << v[k].second << endl;   
                // cout << "a = " << a << " b = " << b << endl ;             
                set<float> temp = finding->second ;
                // for(set<float>::iterator iter=temp.begin(); iter!=temp.end(); iter++) {
                //     cout << *iter << " ";
                // }                
                // cout << endl ;
                temp.insert(b);
                // for(set<float>::iterator iter=temp.begin(); iter!=temp.end(); iter++) {
                //     cout << *iter << " ";
                // }             
                // cout << endl ;
                mapping.erase(a) ;                       
                mapping.insert(pair<float, set<float> >(a,temp) );
                // cout << finding->first << endl ;
                // for(int m=0; m<finding->second.size(); m++){
                //     cout << finding->second[m] << endl ;
                // }


                
            }
        }
        int count = 0 ;
        for(map<float, set<float> >::iterator i=mapping.begin(); i!=mapping.end(); i++){
            cout << "========" << endl ;
            cout << i->first << endl ;
            cout << "---" << endl ;
            for(set<float>::iterator iter=i->second.begin(); iter!=i->second.end(); iter++) {
                cout << *iter << " ";
                count += 1 ;
            }
            cout << endl;
        }
        cout << endl ;
        cout << "Answer" << endl ;
        cout << count << endl ;
    }
}