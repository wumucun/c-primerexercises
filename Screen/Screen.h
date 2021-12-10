#include <iostream>
#include <string>
using namespace std;

class Screen
{
    public:
    Screen():cursor(0),height(0),width(0)
    {cout<<"constructer1 running!";}
    Screen(int ht,int wd,char c):height(ht),width(wd),contents(ht*wd,c)
    {cout<<"constructer2 running";}
    Screen(int ht, int wd):Screen(ht,wd,' ')
    {
        cout<<endl<<"调用者constructor3 running!";
    }


    private:
    int height = 0,width = 0;
    int cursor = 0;
    string contents;

};