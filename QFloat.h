#include<iostream>
using namespace std;
#include<string>
#include "ThuVien.h"
#ifndef _QFLOAT_H_
#define _QFLOAT_H_

class QFLOAT
{
private:
	unsigned int data[4];
public:
	QFLOAT();
	void ScanQFloat();
	void PrintQFloat();
	QFLOAT BinToDec(bool* bit);
	bool* DecToBin();
	//hàm phụ
	QFLOAT BinToDec_String(string _128bit);
	string DecToBin_String();
	string GetQFloat();
	string GetBin(string number);
};
#endif // !_QInt_H_