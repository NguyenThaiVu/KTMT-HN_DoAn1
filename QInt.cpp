#include "QInt.h"
#include "ThuVien.h"

QINT::QINT()
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
}
void QINT::ScanQInt()
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
	string number;
	getline(cin >> ws, number);
	//
	string bin = FromDecToBin(number);
	//
	for (int i = 0; i < bin.length(); i++)
	{
		//bật bit tại vị trí i
		if (bin[i] == '1')
		{
			this->data[i / 32] = (1 << (32 - 1 - (i % 32))) | this->data[i / 32];
		}
	}
}

void QINT::PrintQInt()
{
	//chuyển từ data[4] thành mã nhị phân 
	string bin;
	for (int i = 0; i < 128; i++)
	{
		bin = bin + '0';
	}
	//đọc bit
	bool bit;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			bit = (this->data[i] >> (32 - 1 - (31 - j))) & 1;
			if (bit == 1)
			{
				bin[32 * i + (31 - j)] = '1';
			}
		}
	}

	bool sign = 0;	//số dương
	if (bin[0] == '1')	//số âm
	{
		sign = 1;
	}
	string result;
	result = FromBinToDec(bin);
	if (sign == 1)
	{
		result = "-" + result;
	}
	cout << result << endl;
}

/////////////////
void QINT::DBit(QINT &x, string &bin)
{
	for (int i = 0; i < 128; i++)
	{
		bin = bin + '0';
	}
	//đọc bit
	bool bit;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			bit = (x.data[i] >> (32 - 1 - (31 - j))) & 1;
			if (bit == 1)
			{
				bin[32 * i + (31 - j)] = '1';
			}
		}
	}
}
void QINT::BBit(QINT &x, string &bin)
{
	for (int i = 0; i < bin.length(); i++)
	{
		//bật bit tại vị trí i 
		if (bin[i] == '1')
		{
			x.data[i / 32] = (1 << (32 - 1 - (i % 32))) | x.data[i / 32];
		}
	}
}
string QINT::DecToBin(QINT x)
{
	string bin;
	DBit(x, bin);
	return bin;
}
QINT QINT::BinToDec(string bit)
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
	int len = bit.length();
	if (bit.length() < 128)
	{
		for (int i = 0; i < 128 - len; i++)
			bit = bit[0] + bit;
	}
	BBit(*this, bit);
	return *this;
}

string QINT::DecToHex(QINT x)
{
	string bin, dec, hex;
	DBit(x, bin);
	dec = FromBinToDec(bin);
	hex = FromDecToHex(dec);
	return hex;
}
QINT QINT::BinToDecUnsigned(string bin)
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
	string dec;
	dec = FromBinToUnsignedInt(bin);
	BBit(*this, bin);
	return *this;
}
string QINT::BinToHex(string bit)
{
	QINT x;
	x.BinToDec(bit);
	string hex;
	x.BinToDecUnsigned(bit);
	hex = DecToHex(x);
	return hex;
}
