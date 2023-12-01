#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> mp = {
        {"one", "o1e"},
        {"two", "t2o"},
        {"three", "t3e"},
        {"four", "f4r"},
        {"five", "f5e"},
        {"six", "s6x"},
        {"seven", "s7n"},
        {"eight", "e8t"},
        {"nine", "n9e"}
};


int main(){
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    long result = 0;
    while(cin>>s){
        cout<<"before: "<<s<<"\t";
        vector<int> digits;
        // comment below line for 2 star
        for(auto i: mp){
            s = regex_replace(s, regex(i.first), i.second);
        }

//        for (auto& entry : mp) {
//            size_t pos = s.find(entry.first);
//            cout<<"\npos is -> "<<pos<<"\n";
//            while (pos != string::npos) {
//                s.replace(pos, entry.first.length(), entry.second);
//                pos = s.find(entry.first, pos + entry.second.length());
//            }
//        }

//        for (size_t i = 0; i < s.length(); ++i) {
//            for (const auto& entry : mp) {
//                const string& key = entry.first;
//                const string& value = entry.second;
//                if (s.compare(i, key.length(), key) == 0) {
//                    s.replace(i, key.length(), value);
//                    i += value.length() - 1;  // Move index to the end of the replacement
//                    break;  // Move to the next position in the outer loop
//                }
//            }
//        }
        cout<<"after: "<<s<<"\n";
        for(int i = 0; i< s.length(); i++) {
            if (isdigit(s[i])) {
                digits.push_back((s[i] - '0'));
            }
        }
        long number = 0;
        long siz = digits.size();
        number = siz >= 2 ? digits[0] * 10 + digits[siz-1] * 1 : digits[0] *
                10 + digits[0] * 1;
//        for(int i = 0; i < digits.size(); i++){
//            number = number * 10 + digits[i];
//        }
        cout<<number<<"\n";
        result += number;
    }
    cout<<result;
}

