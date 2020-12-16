#include<bits/stdc++.h>
using namespace std;

bool isUnique(int n){
    int r, b[1000], p=0, flag = 0;
    while(n != 0){
        r = n%10;
        b[p] = r;
        n = n/10;
        p++;
    }
    for(int x=0; x<p; x++){
        //cout << b[x] << " ";
    }
    //cout << endl;
    for(int i=0; i<p; i++){
    
        for(int j=i+1; j<p; j++){
            //cout << "b[i] = " << b[i] << " ";
            //cout << "b[j] = " << b[j] << " ";
            if(b[i] == b[j]){
                //cout << "SAME ";
                return false;
            }
            else{
                //cout << "UNIQUE ";
            }
        }
    }
    //cout << endl;
    return true;
}

int main(){
    int t, l, r, a[1000];
    cin >> t; 
    for(int i=0; i<t; i++){
        cin >> l;
        cin >> r;
        for(int i=l; i<=r; i++){
            a[i] = i;
        }
        for(int i=l; i<=r; i++){
            if(isUnique(a[i])){
                cout << a[i] << " ";
            }
        }
    }


    return 0;
}