#ifndef _QInt_H_
#define  _QInt_H_

#include<iostream>
using namespace std;
#include<string>

class QINT
{
private:
	unsigned int data[4];
public:
	QINT();
	string ConvertDataToDec();	//Hàm trả về chuỗi thập phân mà QINT đang giữ
	void ConvertDecToData(string);	//Hàm chuyển từ số thập phân (dạng chuỗi) vào data
	void ScanQInt();
	void PrintQInt();
	void DocBit(QINT &x, string &bin);	//Hàm đọc bit từ QINT và trả vào chuỗi bin
	void BatBit(QINT &x, string &bin);	//Hàm bật bit QINT (đọc từ chuỗi bin)
	string DecToBin_String(QINT x);		//Hàm chuyển từ số QINT sang số nhị phân (dạng chuỗi)
	QINT BinToDec_String(string bit);	//Hàm chuyển từ số nhị phân (dạng chuỗi) và trả về kiểu QINT
	string BinToHex_String(string bit);	//Hàm chuyển từ số nhị phân (dạng chuỗi) sang số thập phân kiểu Hex (chuỗi)
	string DecToHex_String(QINT x);		//Hàm chuyển từ QINT sang Hex (dạng chuỗi)
	bool* DecToBin(QINT x);			//Hàm chuyển từ số QINT sang số nhị phân (bool*)
	QINT BinToDec(bool* bin);		//Hàm chuyển từ số nhị phân (bool*) và trả về kiểu QINT
	char* BinToHex(bool* bit);		//Hàm chuyển từ số nhị phân (bool*) sang số thập phân kiểu Hex (chuỗi)
	char* DecToHex(QINT x);			//Hàm chuyển từ QINT sang Hex (dạng chuỗi)
	QINT operator+(QINT);
	QINT operator-(QINT);
	QINT operator*(QINT);
	QINT operator/(QINT);
	QINT operator%(QINT);
	bool operator<(QINT);
	bool operator>(QINT);
	bool operator==(QINT);
	bool operator>=(QINT);
	bool operator<=(QINT);
	bool operator=(QINT);
	QINT operator&(QINT&);
	QINT operator|(QINT&);
	QINT operator^(QINT&);
	QINT operator~();
	QINT operator>>(int x);		//dich phai 1
	QINT operator>>(QINT x);	//dich phai 2	
	QINT operator<<(int x);		//dich trai 1
	QINT operator<<(QINT x);	//dich trai 2
	QINT ROR(int x);
	QINT ROR(QINT x);
	QINT ROL(int x);
	QINT ROL(QINT x);
};
#endif // !_QInt_H_