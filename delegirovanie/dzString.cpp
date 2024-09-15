#define _CRT_SECURE_NO_WARNINGS
#include "dzString.h"
#include <iostream>
using namespace std;

dzString::dzString()
{
	length = 80;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) 
	{
		str[i] = 'X';
	}
	str[length] = '\0';
}

dzString::dzString(bool askSize)
{
	cout << "Enter the desired string size: ";
	cin >> length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) 
	{
		str[i] = 'X';
	}
	str[length] = '\0';
}

dzString::dzString(const char* initializedString)
{
	length = static_cast<int>(strlen(initializedString));
	str = new char[length + 1];
	strcpy_s(str, length + 1, initializedString);
}


dzString::~dzString()
{
	delete[] str;
}

int dzString::getLength() const
{
	return length;
}

const char* dzString::getString() const
{
	return str;
}

void dzString::inputString()
{
	cout << "Enter a string: ";
	char buffer[1000];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(buffer, 1000);
	length = strlen(buffer);
	delete[] str;
	str = new char[length + 1];
	strcpy(str, buffer);
}

void dzString::printString() const
{
	cout << str << endl;
}

void dzString::dzStrcpy(dzString& obj)
{
	delete[] str;
	length = obj.getLength();
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.getString());
}

bool dzString::dzStrStr(const char* substring)
{
	return strstr(str, substring) != nullptr;
}

int dzString::dzChr(char c)
{
	for (int i = 0; i < length; ++i) 
	{
		if (str[i] == c) 
		{
			return i;
		}
	}
	return -1; 
}

int dzString::dzStrLen()
{
	return length;
}

void dzString::dzStrCat(dzString& b)
{
	int newLength = length + b.getLength();
	char* newStr = new char[newLength + 1];
	strcpy_s(newStr, newLength + 1, str); 
	strcat_s(newStr, newLength + 1, b.getString()); 
	delete[] str;
	str = newStr;
	length = newLength;
}


void dzString::dzDelChr(char c)
{
    int newLength = 0;
    for (int i = 0; i < length; ++i)
    {
        if (str[i] != c)
        {
            str[newLength++] = str[i]; 
        }
    }
    str[newLength] = '\0';
    length = newLength; 
}

int dzString::dzStrCmp(dzString& b)
{
	int comparison = strcmp(str, b.getString());
	if (comparison < 0) {
		return -1;
	}
	else if (comparison > 0) {
		return 1;
	}
	return 0;
}
