//DAA Assignment Q-9
//Trapping rain water problem
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int * a= (int*) malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int,int>> Buckets;
    int mark1 = 0;
    int mark2 = 0;
    for(int i = 1;i<n-1;i++){
        if(a[i-1] < a[i] && a[i+1] < a[i] && mark1 ==  0){
            mark1 = i;
        }
        else if(a[i-1]< a[i] && a[i+1] < a[i] && mark1 != 0){
            mark2 = i;
            Buckets.push_back(make_pair(mark1,mark2));
            mark1 = 0;
            mark2 = 0;
            i--;
        }
    }
    int water = 0;
    for(auto it: Buckets){
        for(int i = it.first;i<it.second;i++){
            if(min(a[it.first],a[it.second])-a[i] > 0) {
                water += min(a[it.first], a[it.second])-a[i];
            }
        }
        cout<<it.first<<" "<<it.second<<endl;
        cout<<water<<endl;
    }
    cout<<water<<endl;
}