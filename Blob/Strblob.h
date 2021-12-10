#ifndef STRBLOB_H
#define STRBLOB_H
#include <string>
#include <memory>
#include <vector>
using namespace std;
class Strblob{
public:
    typedef vector<string>::size_type size_type;
    Strblob();
    Strblob(initializer_list<string> il);
    size_type size() const{return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const string &t){data->push_back(t);}

    void pop_back();
    string& front();
    string& back();
    const void pop_back() const;
    const string& front() const;
    const string& back() const;
private:
    shared_ptr<vector<string>> data;
    void check(size_type i,const string& msg) const;
};

Strblob::Strblob():data(make_shared<vector<string>>()){}
Strblob::Strblob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}

void Strblob::check(size_type i,const string& msg) const
{
    if(i >=data->size())
        throw out_of_range(msg);
}

string& Strblob::front()
{
    check(0,"front on empty Strblob");
    return data->front();
}

const string& Strblob::front() const
{
    check(0,"front on empty Strblob");
    return data->front();
}

string& Strblob::back()
{
    check(0,"back on empty Strblob");
    return data->back();
}

const string& Strblob::back() const
{
    check(0,"back on empty Strblob");
    return data->back();
}

void Strblob::pop_back()
{
    check(0,"pop_back on empty Strblob");
    data->pop_back();
}

const void Strblob::pop_back() const
{
    check(0,"pop_back on empty Strblob");
    data->pop_back();
}
#endif // !STRBLOB_H#define STRBLOB_H