#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dzString.h"
using namespace std;

int main()
{
	dzString firstString;
    cout << "80-lentgh string: '" << firstString.getString() << "'" << endl;

    dzString secondString(true);
    cout << secondString.getLength() << "-length string: '" << secondString.getString() << "'" << endl;

    dzString initializedString("That's my homework!");
    cout << "Initialized string by constructor: '" << initializedString.getString() << "'" << endl;

    dzString inputStr;
    inputStr.inputString();
    inputStr.printString();
    
    dzString str1("It Stepa");
    dzString str2;
    str2.dzStrcpy(str1);
    str2.printString();

    if (str1.dzStrStr("ell")) 
    {
        cout << "Substring found" << endl;
    }
    else 
    {
        cout << "Substring not found" << endl;
    }

    int index = str1.dzChr('p');
    if (index != -1) 
    {
        cout << "Character found at index " << index << endl;
    }
    else 
    {
        cout << "Character not found" << endl;
    }

    cout << "Length of str1: " << str1.dzStrLen() << endl;
    cout << "Length of str2: " << str2.dzStrLen() << endl;

    dzString str3(" The best!");
    str1.dzStrCat(str3);
    str1.printString();
    cout << "Length of concatenated str1: " << str1.dzStrLen() << endl;

    str1.dzDelChr('a');
    str1.printString();
    cout << "Length of str1 after deleting 'a': " << str1.dzStrLen() << endl;

    int cmp = str1.dzStrCmp(str2);
    if (cmp == 0) {
        cout << "0" << endl;
    }
    else if (cmp > 0) {
        cout << "1" << endl;
    }
    else {
        cout << "-1" << endl;
    }

    return 0;
};
