#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> *mem;
        mem = new vector<string>[n + 1];

        mem[1].push_back("()");
        for (int i = 2; i <= n; i++)
        {
            set<string> tmp;
            for (int j = 0; j < mem[i - 1].size(); j++)
            {
                // 1.P(k)+="("+P(k-1)+")"
                tmp.insert("(" + mem[i - 1][j] + ")");
            }
            // 2.P(k)+=P(a)+P(b); k=a+b
            int b = i - 1;
            for (int a = 1; b > 0;)
            {
                for (int s = 0; s < mem[a].size(); s++)
                {
                    for (int t = 0; t < mem[b].size(); t++)
                    {
                        tmp.insert(mem[a][s] + mem[b][t]);
                    }
                }

                b = i - ++a;
            }
            mem[i].assign(tmp.begin(), tmp.end());
        }

        return mem[n];
    }
};

int main()
{
}