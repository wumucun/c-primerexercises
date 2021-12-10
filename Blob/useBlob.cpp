#include "Strblob.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

vector<int> *test1()
{
    return new vector<int>();
}

vector<int> test2()
{
    vector<int> *temp = test1();
    int in;
    while (cin >> in)
    {
        if (in != '\n')
            temp->push_back(in);
        else
            break;
    }
    vector<int> res = *temp;
    delete temp;
    return res;
}
void test3(const vector<int> &res)
{
    for (auto v : res)
        cout << v << " ";
    cout << endl;
}

int min_elem_index(vector<int> &res)
{
    unordered_map<int, int> tem;
    int min_e = INT_MAX;
    int i = 0;
    for (int v : res)
    {
        min_e = min(v, min_e);
        tem[v] = i;
        ++i;
    }
    return tem[min_e];
}

int res_index(vector<int> &res, int tem)
{
    unordered_map<int, int> temp;
    for (int i = 0; i < res.size(); i++)
        temp[res[i]] = i;
    return temp[tem];
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int len = matrix.size();
    int c_len = matrix[0].size();
    vector<int> min_indexs(len, 0);
    min_indexs[0] = min_elem_index(matrix[0]);
    int min_sum = 0;
    min_sum += matrix[0][min_indexs[0]];
    for (int i = 1; i < len; i++)
    {
        int last_index = min_indexs[i - 1];
        int min_tem = 0;
        if (last_index == 0)
            min_tem = min(matrix[i][last_index], matrix[i][last_index + 1]);
        else if (last_index == c_len - 1)
            min_tem = min(matrix[i][last_index], matrix[i][last_index - 1]);
        else
        {
            min_tem = min(min(matrix[i][last_index + 1], matrix[i][last_index-1]),
                          matrix[i][last_index]);
        }
        min_sum += min_tem;
        min_indexs[i] = res_index(matrix[i], min_tem);
    }
    return min_sum;
}

int main()
{
    vector<vector<int>> matrix =
        {
            {-19,57},
            {-40,-5}
        };
    cout << minFallingPathSum(matrix);
}