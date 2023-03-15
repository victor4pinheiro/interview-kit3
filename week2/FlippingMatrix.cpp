#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

vector<vector<int>> reverseRow(vector<vector<int>> matrix, int length) {
    for (int i = 0; i < length / 2; i++) {
        for (int j = 0; j < length / 2; j++) {
            int max = matrix[i][j];
            // same row
            if (max < matrix[i][length - j - 1])
                max = matrix[i][length - j - 1];
            

            // same column
            if (max < matrix[length - i - 1][j])
                max = matrix[length - i - 1][j];
                           

            // same diagonal
            if (max < matrix[length - i - 1][length - j - 1])
               max = matrix[length - i - 1][length - j - 1];

            matrix[i][j] = max;
        }
    }

    return matrix;
}

int flippingMatrix(vector<vector<int>> matrix) {
    int length = matrix.size();

    matrix = reverseRow(matrix, length);
     int sum = 0;

    for (int i = 0; i < length / 2; i++) {
        for (int j = 0; j < length / 2; j++)
            sum += matrix[i][j];
    }
    
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> matrix(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            matrix[i].resize(2 * n);

            string matrix_row_temp_temp;
            getline(cin, matrix_row_temp_temp);

            vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

            for (int j = 0; j < 2 * n; j++) {
                int matrix_row_item = stoi(matrix_row_temp[j]);

                matrix[i][j] = matrix_row_item;
            }
        }

        int result = flippingMatrix(matrix);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

