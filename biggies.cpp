/*
给定一个words，排序将重复的删除，并且打印出长度大于给定sz的char
*/

#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

//按照字典序重排去除重复的
void elimDups(vector<string> & words) {
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main() {
    vector<string> words = {"the quick red fox jumps over tne slow red turtle"};
    elimeDups(words);
    for (auto& str : words)
        cout << str << " ";
    cout << endl;
}

