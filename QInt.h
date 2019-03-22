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
	string ConvertDataToDec();
	void ConvertDecToData(string);
	void ScanQInt();
	void PrintQInt();
	string DecToBin_String(QINT x);		//hàm hỗ trợ 
	QINT BinToDec_String(string bit);	//hàm hỗ trợ
	string BinToHex_String(string bit);	//hàm hỗ trợ
	bool* DecToBin(QINT x);
	QINT BinToDec(bool* bin);
	char* BinToHex(bool* bit);
	char* DecToHex(QINT x);
	QINT BinToDecUnsigned(string bit);
	string DecToHex_String(QINT x);
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
	void DocBit(QINT &x, string &bin);
	void BatBit(QINT &x, string &bin);
};
#endif // !_QInt_H_