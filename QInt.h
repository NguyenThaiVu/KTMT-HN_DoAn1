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
	bool* DecToBin(QINT x);
	QINT BinToDec(bool* bin);
	char* BinToHex(bool* bit);
	QINT BinToDecUnsigned(string bit);
	char* DecToHex(QINT x);
	const QINT operator+(const QINT&) const;
	const QINT operator-(const QINT&) const;
	const QINT operator*(const QINT&) const;
	const QINT operator/(const QINT&) const;
	bool operator<(const QINT&) const;
	bool operator>(const QINT&) const;
	bool operator==(const QINT&) const;
	bool operator>=(const QINT&) const;
	bool operator<=(const QINT&) const;
	bool operator=(const QINT&) const;
	const QINT operator&(const QINT&) const;
	const QINT operator|(const QINT&) const;
	const QINT operator^(const QINT&) const;
	const QINT operator~() const;
	const QINT operator>>(int x) const;		//dich phai 1
	const QINT operator>>(QINT x) const;	//dich phai 2	
	const QINT operator<<(int x) const;		//dich trai 1
	const QINT operator<<(QINT x) const;	//dich trai 2
	void DBit(QINT &x, string &bin);
	void BBit(QINT &x, string &bin);
};
