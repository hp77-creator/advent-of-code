//
// Created by himanshu.pandey on 01/12/23.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    char c;
    while(c != 'y'){
        int high, low, mid;
        cin>>high;
        cin>>low;
        mid = low + (high - low)/2;
        cout<<"mid -> "<<mid;
        cin>>c;
        if(c=='h'){
            high = mid;
        }else if (c =='l'){
            low = mid;
        }
        else break;
    }

}
