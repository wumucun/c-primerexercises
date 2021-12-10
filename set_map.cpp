#include <set>
#include <map>
#include <iostream>
using namespace std;

int main()
{
    map<string,size_t> word_counter;
    set<string> exclude = {"the","hello","and","or"
                            "The","Cs","Ps","huawei"};
    string word;
    while (cin>>word)
    {
        if (exclude.find(word)==exclude.end())
            ++word_counter[word];
        
    }
    for (const auto& word:word_counter)
        cout<<word.first<<" "<<word.second<<endl;
}