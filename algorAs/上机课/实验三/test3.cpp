#include <iostream>
#include <queue>
#define min(x, y) (x < y ? x : y)
using namespace std;
int freight[3][4] = {{3, 11, 3, 10}, {1, 9, 2, 8}, {7, 4, 10, 5}};
int sales[4] = {3, 6, 5, 6};
int production[3] = {7, 4, 9};
int mincost = 999;
int key[5][3] = {{1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 2, 1}, {3, 1, 2}};
struct NodeType
{
    int r[4];
    int lb;
    int pro[3][4] = {{0}};
    bool operator<(const NodeType &s) const
    {
        return lb > s.lb;
    }
};

void ret()
{
    sales[0] = 3, sales[1] = 6, sales[2] = 5, sales[3] = 6;
    production[0] = 7, production[1] = 4, production[2] = 9;
}
void bound(NodeType &e)
{
    int sum = 0, j;
    for (int m = 0; m < 4; m++)
    {
        j = e.r[m];
        int temp, i = 0;
        int min = 100, max = 0, x[3] = {0};
        for (int k = 0; k < 3; k++)
        {
            if (min > freight[k][j])
            {
                x[0] = k;
                min = freight[k][j];
            }
        }
        for (int k = 0; k < 3; k++)
        {
            if (max < freight[k][j])
            {
                x[2] = k;
                max = freight[k][j];
            }
        }
        x[1] = 3 - x[0] - x[2];
        while (sales[j] > 0)
        {
            temp = sales[j];

            e.pro[x[i]][j] = min(sales[j], production[x[i]]);

            sales[j] -= production[x[i]];
            if (sales[j] > 0)
            {
                sum = sum + production[x[i]] * freight[x[i]][j];
                production[x[i]] = 0;
                i++;
            }
            else
            {
                sales[j] = 0;
                sum = sum + freight[x[i]][j] * temp;
                production[x[i]] -= temp;
            }
        }
    }

    e.lb = sum;
}

void bfs()
{
    priority_queue<NodeType> qu;
    NodeType e, e1;
    e.r[4] = {0};
    for (int m = 0; m < 4; m++)
        e.r[m] = m;
    bound(e);
    ret();
    qu.push(e);
    int j = 0;
    while (!qu.empty())
    {
        e = qu.top();
        qu.pop();
        if (mincost > e.lb)
        {
            mincost = e.lb;
        }
        e1.r[0] = e.r[0];
        for (int k = 1; k < 4; k++)
        {
            e1.r[k] = key[j][k - 1];
        }
        j++;
        bound(e1);
        ret();
        if (e1.lb <= mincost)
            qu.push(e1);
    }
    cout << "总运费最小的方案为：" << endl;
    cout << "\tB1\tB2\tB3\tB4" << endl;
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "A" << i + 1 << "\t";
        for (int j = 0; j < 4; j++)
        {
            cout << e.pro[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int j = 0;
    int min = 100;
    bfs();
    cout << "运输最小费用为:";
    cout << mincost << endl;
    return 0;
}
