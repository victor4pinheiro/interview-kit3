#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int partition(vector<int> &arr, int start, int end)
{
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i)
    {
        if (arr[i] < arr[pivot])
        {
            swap(arr[i], arr[j]);
            ++j;
        }
    }
    swap(arr[j], arr[pivot]);
    return j;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

void miniMaxSum(vector<int> arr)
{
    int size = arr.size() - 1;
    quickSort(arr, 0, size);

    long sumLowestValues = 0;
    long sumBiggestValues = 0;
    
    for (int i = 0; i < size; i++)
    {
        sumLowestValues += arr[i];
    }

    for (int i = 1; i <= size; i++)
    {
        sumBiggestValues += arr[i];
    }
    
    cout << sumLowestValues << " " << sumBiggestValues << endl;
}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
