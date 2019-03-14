#include<iostream>
using namespace std;
#include<string>

class QFLOAT
{
private:
	bool sign;
	unsigned short exponent;
	unsigned int fraction[4];
public:
	void ScanQFloat();
	void PrintQFloat();
	QFLOAT BinToDec(bool *bit);
	string DecToBin(QFLOAT x);
};