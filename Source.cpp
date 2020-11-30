#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;

bool Count(char* s, char C)
{
    if (s[0] == 0) return false;
    if (s[0] == C) return true;
    return Count(s + 1, s[0]);
}

void Change_r(char* s, char* newStr, char& state, int& strPos, int& Str)
{
    if (s[strPos] == 0)
    {
        if (state == 'a') newStr[Str++] = 'a';
        if (state == 'b') newStr[Str++] = 'b';
        if (state == 'c') newStr[Str++] = 'c';
        newStr[Str++] = '\0';
        return;
    }

    switch (s[strPos])
    {
    case 'B':
        if (state == 'B')
        {
            newStr[Str++] = 'D';
            state = ' ';
        }
        else
        {
            if (state == 'b') newStr[Str++] = 'b';
            if (state == 'c') newStr[Str++] = 'c';
            state = 'a';
        }
        break;
    case 'A':
        if (state == 'A')
        {
            newStr[Str++] = 'e';
            state = ' ';
        }
        else
        {
            if (state == 'a') newStr[Str++] = 'a';
            if (state == 'c') newStr[Str++] = 'c';
            state = 'b';
        }
        break;
    case 'S':
        if (state == 'S')
        {
            newStr[Str++] = 'l';
            state = ' ';
        }
        else {
            if (state == 'b') newStr[Str++] = 'b';
            if (state == 'c') newStr[Str++] = 'c';
            state = 'a';
        }
        break;
    case 'I':
        if (state == 'I')
        {
            newStr[Str++] = 'p';
            state = ' ';
        }
        else
        {
            if (state == 'b') newStr[Str++] = 'b';
            if (state == 'c') newStr[Str++] = 'c';
            state = 'a';
        }
        break;
    case 'C':
        if (state == 'C')
        {
            newStr[Str++] = 'D';
            newStr[Str++] = 'e';
            newStr[Str++] = 'l';
            newStr[Str++] = 'p';
            newStr[Str++] = 'h';
            newStr[Str++] = 'i';
            state = ' ';
        }
        else
        {
            if (state == 'a') newStr[Str++] = 'a';
            if (state == 'b') newStr[Str++] = 'b';
            state = 'c';
        }
        break;
    default:
        if (state == 'a') newStr[Str++] = 'a';
        if (state == 'b') newStr[Str++] = 'b';
        if (state == 'c') newStr[Str++] = 'c';
        newStr[Str++] = s[strPos];
        state = ' ';
        break;
    }
    strPos++;

    Change_r(s, newStr, state, strPos, Str);
    return;
}

int main() {
    char str[101];
    char newStr[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    bool changed = Count(str, ' ');

    char state = ' ';
    int strPos = 0;
    int newStrPos = 0;

    Change_r(str, newStr, state, strPos, newStrPos);

    cout << "String: " << str << endl << endl;
    if (changed)
    {
        cout << "String was modified." << endl;
        cout << "Modified string (result): " << newStr << endl;
    }
    else
    {
        cout << "String was not modified." << endl;
    }

    return 0;
}
 