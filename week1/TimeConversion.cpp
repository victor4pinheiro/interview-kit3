#include <bits/stdc++.h>
#include <string>
#define PERIOD_POSITION 8

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string timeConversion(string s)
{
    char period = s[PERIOD_POSITION];

    if (period == 'P' && s.substr(0,2) != "12")
    {
        s[0] = s[0] + 1;
        s[1] = s[1] + 2;
    } else if (period == 'A' && s.substr(0,2) == "12") {
        s[0] = '0';
        s[1] = '0';
    }

    return s.substr(0, 8);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
