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
bool* QINT::DecToBin(QINT x)
{
	bool* bit = new bool[128];
	string bin;
	DBit(x, bin);
	for (int i = 0; i < 128; i++)
	{
		if (bin[i] == '0') bit[i] = false;
		else bit[i] = true;
	}
	return bit;
}
QINT QINT::BinToDec(bool* bin)
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
	string bit = "";
	for (int i = 0; i < LengthBool(bin); i++)
	{
		if (bin[i] == true) bit = bit + "1";
		else bit = bit + "0";
	}
	int len = bit.length();
	if (len < 128)
	{
		for (int i = 0; i < 128 - len; i++)
			bit = "0" + bit;
	}
	BBit(*this, bit);
	return *this;
}

char* QINT::DecToHex(QINT x)
{
	string bin, dec, strHex;
	DBit(x, bin);
	dec = FromBinToDec(bin);
	strHex = FromDecToHex(dec);
	int len = strHex.length();
	char* hex = new char[len];
	for (int i = 0; i < strHex.length(); i++)
		hex[i] = strHex[i];
	hex[len] = '\0';
	return hex;
}
QINT QINT::BinToDecUnsigned(string bin)
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
	string dec;
	dec = BinUnsigned(bin);
	BBit(*this, bin);
	return *this;
}
char* QINT::BinToHex(bool* bit)
{
	QINT x;
	x.BinToDec(bit);
	string bin = "";
	for (int i = 0; i < LengthBool(bit); i++)
	{
		if (bit[i] == true) bin = bin + "1";
		else bin = bin + "0";
	}
	x.BinToDecUnsigned(bin);
	char* hex = new char[bin.length()];
	hex = DecToHex(x);
	return hex;
}
