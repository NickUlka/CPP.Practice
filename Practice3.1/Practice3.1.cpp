
//Проверка номера СНИЛС

#include <string>
//#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

bool CheckInn(string s) {
    bool flag = true;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ' || s[i] != '-' || !isdigit(s[i]))
        {
            flag = false;
            break;
        }

   /* char str[] = "100 ab 123 1010";
    char* end;*/
    string newS;
    if (flag)
        /*   unsigned long long num = strtoull(str, &end, 10);*/
        for (int i = 0; i < s.length(); i++)
            if (isdigit(s[i]))
                newS += s[i];
            else
                cout << "FALSE";
}

int main()
{

    string inn;
    cout << "Input INN: ";
    getline(cin, inn);



   /* string s;
    getline(cin, s);

    if (s[s.length() - 1] != '.')
        s += '.';*/

    //string tmp;
    //vector <string> vs;
    //for (int i = 0; i < s.length(); i++)
    //{
    //    if (s[i] == ' ' || s[i] == '.')
    //    {
    //        vs.push_back(tmp);
    //        tmp.clear();
    //    }
    //    else
    //        tmp += s[i];
    //}

    //int n = stoi(vs[0]);
    //int m = stoi(vs[1]);
    //int k = stoi(vs[2]);

    //cout << n << " " << m << " " << k << endl;
}
