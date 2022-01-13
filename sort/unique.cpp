//删除重复元素
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
void elimeDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    for (auto& str : words)
        cout << str << " ";
    cout << endl;
    words.erase(end_unique, words.end());
    for (auto& str : words)
        cout << str << " ";
    cout << endl;
}

int main() {
    vector<string> words = {the, quick, red, fox, jumps, over, the, slow, red, turtle};
    elimeDups(words);
}