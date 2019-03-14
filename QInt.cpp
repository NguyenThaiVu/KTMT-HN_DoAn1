#include "QInt.h"
#include "ThuVien.h"

QINT::QINT()
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
}

void QINT::ScanQInt()
{
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
