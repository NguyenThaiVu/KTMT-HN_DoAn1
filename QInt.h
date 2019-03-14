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
	string DecToHex(QINT x);
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
};
