#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
S;M;plasticCup()

C;V;mobile phone

C;C;coffee machine

S;C;LargeSoftwareBook

C;M;white sheet of paper

S;V;pictureFrame
*/

class Conversor
{
private:
    char operation;
    char method;
    string text;

public:
    char getOperation(void)
    {
        return operation;
    }

    void setOperation(char operation)
    {
        this->operation = operation;
    }

    char getMethod(void)
    {
        return method;
    }

    void setMethod(char method)
    {
        this->method = method;
    }

    string getText(void)
    {
        return text;
    }

    void setText(string text)
    {
        this->text = text;
    }

    string convert(char operation) {
        string newText;

        if (operation == 'S')
            cout << "S" << endl;
            // newText = strip(method, text);
        else if (operation == 'C')
            newText = combine(this->method, this->text);

        return newText;
    }

    string strip(char method, string text) {
        if (method == 'V') {

        } else if (method == 'M') {

        } else if (method == 'C') {

        }

        return NULL;
    }

    string combine(char method, string text) {
        string tmp;

        if (method == 'C')
            text[0] = toupper(text[0]);
        else if(method == 'M')
            text.append("()");

        tmp.push_back(text[0]);
        
        for (int i = 1; i < text.length(); i++)
        {
            if (text[i - 1] == ' ') {
                tmp.push_back(toupper(text[i]));
            } else if (text[i] != ' ') {
                tmp.push_back(text[i]);
            }            
        }
        
        return tmp;
    }
};

int main()
{
    string input;

    getline(cin, input);
    
    Conversor conversor;

    conversor.setOperation(input[0]);
    conversor.setMethod(input[2]);
    conversor.setText(input.substr(4, input.length() - 1));

    cout << conversor.convert(conversor.getOperation());

    return 0;
}
