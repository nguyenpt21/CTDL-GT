

#include <iostream>
#include<string>
using namespace std;
int tongcs(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] - '0';
    return sum;
}
int main()
{
    string s; cin >> s;
    int sum = tongcs(s);
    int i = s.size();
    int vtgiam = -1;
    int vtdau = -1;
    while (i)
    {
        i--;
        if (vtdau == -1)
        {
            if ((s[i] - '0') < 9)
            {
                vtdau = i;
            }
        }
        else
        {
            if (vtgiam == -1 && (s[i] - '0') > 0)
                vtgiam = i;
        }
    }
    if (vtgiam == -1)
        cout << "0";
    else
    {
        s[vtgiam] = s[vtgiam] - 1;
        int j;
        for (j = 0; j <= vtgiam; j++)
        {
            sum -= s[j] - '0';
        }
        while(j < s.size())
        {
            if (sum >= 9)
            {
                s[j] = '9';
                sum -= 9;
            }
            else
            {
                s[j] = '0' + sum;
                sum = 0;
            }
            j++;
        }
        if (s[0] == '0')
            cout << "0";
        else
            cout << s;
    }

}
