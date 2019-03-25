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
	QFLOAT BinToDec_String(string _128bit);	//Hàm chuyển từ dãy nhị phân (dạng chuỗi) sang QFLOAT
	string DecToBin_String();	//Hàm chuyển từ QFLOAT sang dãy nhị phân
	string GetQFloat();	//Hàm chuyển từ QFLOAT sang số thập phân (dạng chuỗi)
	string GetBin(string number);	//Hàm chuyển từ số thập phân dạng chuỗi sang nhị phân
};
#endif // !_QInt_H_