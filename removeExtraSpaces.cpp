#include<string>
#include<iostream>

using namespace std;

void removeExtraSpaces(string& s);
int main() {
    string str = "  Bob loves    Alice ";
    for (const auto& ch : str)
        cout << ch;
    cout << endl;
    removeExtraSpaces(str);
    for (const auto& ch : str)
        cout << ch;
    cout << endl;
}

void removeExtraSpaces(string& s) {
    int len = s.size();
    int slow_index = 0, fast_index = 0;
    //去除句前空格
    while (len > 0 && s[fast_index] == ' ')
        ++fast_index;
    //去除句中空格
    for (; fast_index < len; ++fast_index) {
        if (fast_index > 1 && s[fast_index] == s[fast_index - 1] && s[fast_index] == ' ')
            continue;
        else
            s[slow_index++] = s[fast_index]; 
    }

    if (s[slow_index - 1] == ' ')
        s.resize(slow_index - 1);
    else       
        s.resize(slow_index);
}