#ifndef _QFLOAT_H_
#define _QFLOAT_H_

#include "ThuVien.h"

class QFLOAT
{
private:
	unsigned int data[4];
public:
	QFLOAT();
	void ScanQFloat();
	void PrintQFloat();
	
	QFLOAT BinToDec(string _128bit);
	string DecToBin();
};

#endif