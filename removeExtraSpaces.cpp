#include<string>
#include<iostream>

using namespace std;

void removeExtraSpaces(strict& s) {
    int len = s.size();
    int slow_index = 0, fast_index = 0;
    //去除句前空格
    while (len > 0 && s[fast_index] != ' ')
        ++fast_index;
    //去除句中空格
    for (; fast_index < len; ++fast_index) {
        if (fast_index > 1 && s[])
    }
}
int main() {

}