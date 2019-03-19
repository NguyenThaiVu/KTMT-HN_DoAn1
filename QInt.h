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
	void DBit(QINT &x, string &bin);
	void BBit(QINT &x, string &bin);
	string DecToBin(QINT x);
	QINT BinToDec(string bit);
	string BinToHex(string bit);
	string DecToHex(QINT x);
	/*const QINT operator+(const QINT&) const;
	const QINT operator-(const QINT&) const;
	const QINT operator*(const QINT&) const;
	const QINT operator/(const QINT&) const;
	bool operator<(const QINT&) const;
	bool operator>(const QINT&) const;
	bool operator==(const QINT&) const;
	bool operator>=(const QINT&) const;
	bool operator<=(const QINT&) const;
	bool operator=(const QINT&) const;*/
	QINT operator&(const QINT& x);
	QINT operator|(const QINT& x);
	QINT operator^(const QINT& x);
	QINT operator~();
	QINT operator>>(int x);		//dich phai 1
	QINT operator>>(QINT x);	//dich phai 2	
	QINT operator<<(int x);		//dich trai 1
	QINT operator<<(QINT x);	//dich trai 2
	QINT ROL(int x);
	QINT ROR(int x);
};
