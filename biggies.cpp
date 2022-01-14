/*
给定一个words，排序将重复的删除，并且打印出长度大于给定sz的char
*/

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//按照字典序重排去除重复的
void elimDups(vector<string> & words) {
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), 
                [](const string & a, const string& b)
                { return a.size() < b.size();});
    auto wc = find_if(words.begin(), words.end(), [sz](const string& a)
                                                  {return a.size() >= sz;});
    for (auto it = wc; it != words.end(); ++it)
        cout << *it << " ";
    cout << endl;
}



int main() {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "tne", "slow", "red", "turtle"};
    // elimDups(words);
    // cout << "字典序排序去重" << endl;
    // for (auto& str : words)
    //     cout << str << " ";
    // cout << endl;
    // cout << "按照长度排序" << endl;
    // stable_sort(words.begin(), words.end(), 
    //             [](const string & a, const string& b)
    //             { return a.size() < b.size();});
    // for (auto &str : words)
    //     cout << str << " ";
    // cout << endl;
    biggies(words, 5);
}

