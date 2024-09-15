#pragma once
#define _CRT_SECURE_NO_WARNINGS

class dzString
{
private:
	char* str;
	int length;
public:
	dzString();
	dzString(bool askSize);
	dzString(const char* initializedString);
	~dzString();
	int getLength() const;
	const char* getString() const;
	void inputString();
	void printString() const;
	void dzStrcpy(dzString& obj);
	bool dzStrStr(const char* str);
	int dzChr(char c);
	int dzStrLen();
	void dzStrCat(dzString& b);
	void dzDelChr(char c);
	int dzStrCmp(dzString& b);
};

