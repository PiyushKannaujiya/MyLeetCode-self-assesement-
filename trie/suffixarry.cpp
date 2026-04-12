#include <bits/stdc++.h>
using namespace std;

vector<int> suff;

vector<int> suffix(string s){
    int n = s.size();
    vector<pair<string, int>> st;

    for(int i = 0; i < n; i++){
        st.push_back({s.substr(i), i});
    }

    sort(st.begin(), st.end());

    for(auto a : st){
        cout << a.first << " : " << a.second << endl;
        suff.push_back(a.second);
    }

    return suff;
}

bool search(string text, string pattern, vector<int>& sa){
    int n = text.size();
    int m = pattern.size();

    int l = 0, r = n - 1;

    while(l <= r){
        int mid = (l + r) / 2;
        int start = sa[mid];

        string temp = text.substr(start, m);

        if(temp == pattern)
            return true;
        else if(temp < pattern)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return false;
}

int main(){
    string s = "banana";
    string pattern = "ana";

    vector<int> a = suffix(s);

    cout << "Suffix Array: ";
    for(auto b : a){
        cout << b << " ";
    }
    cout << endl;

    if(search(s, pattern, a))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}