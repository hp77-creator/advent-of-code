//
// Created by himanshu.pandey on 02/12/23.
//

#include <bits/stdc++.h>

using namespace std;

map<string, int> checkColor = {
        {"red", 12},
        {"green", 13},
        {"blue", 14}
};

void part1(string s, int &result, int &gameNum1){
    while(getline(cin, s)) {
        cout<<s<<"\n";
        istringstream ss(s);
        string token;
        string game;
        getline(ss, token, ':');
        istringstream token2(token);
        token2 >> game >> gameNum1;
        cout<<"game num: "<<gameNum1<<"\n";
        string color;
        int count;
        bool isOkay = true;
        while(getline(ss, token, ';')){
            istringstream token3(token);
            while(getline(token3, token, ',')){
                istringstream token4(token);
                token4 >> count >> color;
                cout<<"color: "<<color<<" count: "<<count<<"\n";
                if(checkColor[color] < count) {
                    isOkay = false;
                    break;
                }
            }
            if(!isOkay){
                break;
            }
        }
        cout<<"okay : "<<isOkay<<"\n";
        if(isOkay) {
            cout<<"befor: result: "<<result<<" gamenum: "<<gameNum1<<"\n";
            result += gameNum1;
        }
    }
    cout<<result<<"\n";
}

void part2(string s, int &gameNum1){
    unsigned long long res = 0;
    while(getline(cin, s)) {
        unsigned long long prod = 1;
        cout<<s<<"\n";
        istringstream ss(s);
        string token;
        string game;
        getline(ss, token, ':');
        istringstream token2(token);
        token2 >> game >> gameNum1;
        cout<<"game num: "<<gameNum1<<"\n";
        string color;
        int count;
        map<string, int> ownMap = {
                {"red", 0},
                {"blue", 0},
                {"green", 0}

        };
        while(getline(ss, token, ';')){
            istringstream token3(token);
            while(getline(token3, token, ',')){
                istringstream token4(token);
                token4 >> count >> color;
                ownMap[color] = max(count, ownMap[color]);
                cout<<"color: "<<color<<" count: "<<count<<"\n";
            }
        }
        prod = ownMap["red"] * ownMap["green"] * ownMap["blue"];
        res += prod;
    }
    cout<<res<<"\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    int result = 0;
    int gameNum1 = 0;
//    part1(s, result, gameNum1);
    part2(s, gameNum1);
}
