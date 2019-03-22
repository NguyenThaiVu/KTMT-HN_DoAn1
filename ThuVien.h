#include<iostream>
using namespace std;
#include<string>
#include <string.h>
#include <sstream>
#include <math.h>

// ********function for QInt
string DivideBy2(string number);
string FromDecToBin(string number);
string MultipltWith2(string number);
string SumOfTwoNumber(string str1, string str2);
string PowWithBase2(int n);	//2^n
string FromBinToDec(string Bin);
//
string FromBinToUnsignedInt(string &bin);
string Cut2Char(string dec);
int FromStringToInt(string strNumber);
string FromIntToString(int inNumber);
string DivideBy16(string dec, string &remain);
string FromDecToHex(string dec);
//
char NumToString(int number);
int StringToNum(char c);
bool CheckSign(string &s);
bool CompareUnsignedInt(string s1, string s2);
string Plus(string s1, string s2);
string Minus(string s1, string s2);
string MultiplyWithSmallNum(string s1, int n);
string MultiplyWithBigNum(string s1, string s2);
string Division(string s1, string s2);
string Modulo(string s1, string s2);
void TheSameLength(string &s1, string &s2);

//********function for Qfloat

// Chuyển phần thập phân từ Dec sang Bin
string ConvertFractionalPart_FromDecToBin(string number);

// kiểm tra chuỗi có bằng 0 hay không
bool IsEqualWithZero(string number);

unsigned int BinaryToDecimal(string n);

// Nhân 1 số nguyên lớn (kiểu string) với 1 số nguyên nhỏ (int). Chỉ áp dụng cho số không âm
string MultiplyBignumWithSmallnum(string n, int a);

string BinToDec_Of_FractionalPart(string n);
//
string HexToBin(string hex);

int LengthBool(bool* bit);