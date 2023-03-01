#include <bits/stdc++.h>
#include <cctype>
#include <unordered_set>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    string isPangram = "not pangram";
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i])) {
            char letter = tolower(s[i]);
            replace(s.begin(), s.end(), s[i], letter);
        }
    }

    unordered_set<char> text(s.begin(), s.end());

    if (text.size() == 26)
        isPangram = "pangram";

    return isPangram;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

