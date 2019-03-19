#include<iostream>
using namespace std;
#include<string>

string DivideBy2(string number);
string FromDecToBin(string number);
string MultipltWith2(string number);
string SumOfTwoNumber(string str1, string str2);
string PowWithBase2(int n);	//2^n
string FromBinToDec(string Bin);

//Phep toan + So sanh
char NumToString(int number);
int StringToNum(char c);
//int StringToNum(string s);
bool CheckSign(string &s);
int CompareUnsignedInt(string s1, string s2);
string Plus(string s1, string s2);
string Minus(string s1, string s2);
string MultiplyWithSmallNum(string s1, int n);
string MultiplyWithBigNum(string s1, string s2);
string Division(string s1, string s2);
void TheSameLength(string &s1, string &s2);
string Modulo(string s1, string s2);