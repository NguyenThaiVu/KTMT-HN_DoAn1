#ifndef _ThuVien_H
#define  _ThuVien_H

#include<iostream>
using namespace std;
#include<string>
#include <string.h>
#include <sstream>
#include <math.h>

string DivideBy2(string number);
string FromDecToBin(string number);
string MultipltWith2(string number);
string SumOfTwoNumber(string str1, string str2);
string PowWithBase2(int n);	//2^n
string FromBinToDec(string Bin);


//********function for Qfloat

// Chuyển phần thập phân từ Dec sang Bin
string ConvertFractionalPart_FromDecToBin(string number);

// kiểm tra chuỗi có bằng 0 hay không
bool IsEqualWithZero(string number);

unsigned int BinaryToDecimal(string n);

// Nhân 1 số nguyên lớn (kiểu string) với 1 số nguyên nhỏ (int). Chỉ áp dụng cho số không âm
string MultiplyBignumWithSmallnum(string n, int a);

string BinToDec_Of_FractionalPart(string n);


#endif