#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=10, n = 100000000;
    vector<int> vct(n);
    for(int i=0;i<n;i++)
        cin>>vct[i];

    priority_queue<int, vector<int>, greater<int>> track;

    for(int i=0;i<k;i++)    
         track.push(vct[i]);

    for(int i=k;i<n;i++){
        if(vct[i]> track.top()){
            track.pop();
            track.push(vct[i]);
        }
    }

    while(!track.empty()){
        cout<<track.top();
        track.pop();
    }
    return 0;
}