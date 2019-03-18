#include<iostream>
using namespace std;
#include<string>

class QINT
{
private:
	unsigned int data[4];
public:
	QINT();
	void ScanQInt();
	void PrintQInt();
	string DecToBin(QINT x);
	QINT BinToDec(string bit);
	string BinToHex(string bit);
	QINT BinToDecUnsigned(string bit);
	string DecToHex(QINT x);
	QINT operator+(const QINT&);
	QINT operator-(const QINT&);
	QINT operator*(const QINT&);
	QINT operator/(const QINT&);
	bool operator<(const QINT&);
	bool operator>(const QINT&);
	bool operator==(const QINT&);
	bool operator>=(const QINT&);
	bool operator<=(const QINT&);
	bool operator=(const QINT&);
	QINT operator&(const QINT&);
	QINT operator|(const QINT&);
	QINT operator^(const QINT&);
	QINT operator~();
	QINT operator>>(int x);		//dich phai 1
	QINT operator>>(QINT x);	//dich phai 2	
	QINT operator<<(int x);		//dich trai 1
	QINT operator<<(QINT x);	//dich trai 2
	void DBit(QINT &x, string &bin);
	void BBit(QINT &x, string &bin);
};
