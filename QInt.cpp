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

QINT QINT::operator&(const QINT& x)
{
	string bin, bin1, bin2;
	QINT result;
	//Đổi 2 số cần thực hiện phép toán AND sang dạng nhị phân
	bin1 = DecToBin(*this);
	bin2 = DecToBin(x);
	cout << bin1.length() << " " << bin2.length() << endl;
	cout << bin1 << endl << bin2 << endl;
	//Tiến hành thực hiện phép toán AND theo từng bit từ trái sang phải
	for (int i = 0; i < bin1.length(); i++)
		bin += to_string((bin1[i] - '0')&(bin2[i] - '0'));
	//Chuyển dãy bit sau khi thực hiện xong về lại dạng QINT
	result = BinToDec(bin);
	return result;
}

QINT QINT::operator|(const QINT& x)
{
	string bin, bin1, bin2;
	QINT result;
	//Đổi 2 số cần thực hiện phép toán OR sang dạng nhị phân
	bin1 = DecToBin(*this);
	bin2 = DecToBin(x);
	//Tiến hành thực hiện phép toán OR theo từng bit từ trái sang phải
	for (int i = 0; i < bin1.length(); i++)
		bin += to_string((bin1[i] - '0')|(bin2[i] - '0'));
	//Chuyển dãy bit sau khi thực hiện xong về lại dạng QINT
	result = BinToDec(bin);
	return result;
}

QINT QINT::operator^(const QINT& x)
{
	string bin, bin1, bin2;
	QINT result;
	//Đổi 2 số cần thực hiện phép toán XOR sang dạng nhị phân
	bin1 = DecToBin(*this);
	bin2 = DecToBin(x);
	//Tiến hành thực hiện phép toán XOR theo từng bit từ trái sang phải
	for (int i = 0; i < bin1.length(); i++)
		bin += to_string((bin1[i] - '0')^(bin2[i] - '0'));
	//Chuyển dãy bit sau khi thực hiện xong về lại dạng QINT
	result = BinToDec(bin);
	return result;
}

QINT QINT::operator~()
{
	string tmp, bin;
	QINT result;
	//Đổi số cần thực hiện phép toán NOT sang dạng nhị phân
	tmp = DecToBin(*this);
	//Tiến hành thực hiện phép toán NOT theo từng bit từ trái sang phải
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '0')
			bin += "1";
		else
			bin += "0";
	}
	//Chuyển dãy bit sau khi thực hiện xong về lại dạng QINT
	result = BinToDec(bin);
	return result;
}

QINT QINT::operator>>(int x)
{
	if (x < 0 || x >= 128)
		return QINT();
	//Đổi số cần thực hiện phép >> sang dạng nhị phân
	string bin = DecToBin(*this);
	//Xóa x bit cuối
	bin.erase(bin.length() - x, x);
	//Thêm x bit 0 ở đầu
	bin = string(x, '0') + bin;
	return BinToDec(bin);
}

QINT QINT::operator>>(QINT x)
{
	//Còn phần so sanh x < 0 || x >= 128, đợi Vy viết hàm

	//Đổi số cần thực hiện phép >> sang dạng nhị phân
	string bin = DecToBin(*this);
	//Xóa x bit cuối
	bin.erase(bin.length() - x.data[3], x.data[3]); //Vì x trong trường hợp này < 128 nên x cũng chính là x.data[3]
	//Thêm x bit 0 ở đầu
	bin = string(x.data[3], '0') + bin; //Vì x trong trường hợp này < 128 nên x cũng chính là x.data[3]
	return BinToDec(bin);
}

QINT QINT::operator<<(int x)
{
	if (x < 0 || x >= 128)
		return QINT();
	//Đổi số cần thực hiện phép << sang dạng nhị phân
	string bin = DecToBin(*this);
	//Xóa x bit đầu
	bin.erase(0, x);
	//Thêm x bit 0 ở cuối
	bin = bin + string(x, '0');
	return BinToDec(bin);
}

QINT QINT::operator<<(QINT x)
{
	//Còn phần so sanh x < 0 || x >= 128, đợi Vy viết hàm

	//Đổi số cần thực hiện phép << sang dạng nhị phân
	string bin = DecToBin(*this);
	//Xóa x bit đầu
	bin.erase(0, x.data[3]); //Vì x trong trường hợp này < 128 nên x cũng chính là x.data[3]
	//Thêm x bit 0 ở cuối
	bin = bin + string(x.data[3], '0'); //Vì x trong trường hợp này < 128 nên x cũng chính là x.data[3]
	return BinToDec(bin);
}

QINT QINT::ROR(int x)
{
	//Đổi số cần thực hiện phép ROR sang dạng nhị phân
	string bin = DecToBin(*this), tmp;
	//Lưu x bit cuối vào tmp
	tmp = string(bin, bin.length() - x, x);
	//Xóa x bit cuối
	bin.erase(bin.length() - x, x);
	//Thêm các bit trong tmp vào đầu
	bin = tmp + bin;
	return BinToDec(bin);
}

QINT QINT::ROL(int x)
{
	//Đổi số cần thực hiện phép ROL sang dạng nhị phân
	string bin = DecToBin(*this), tmp;
	//Lưu x bit đầu vào tmp
	tmp = string(bin, 0, x);
	//Xóa x bit đầu
	bin.erase(0, x);
	//Thêm các bit trong tmp vào cuối
	bin = bin + tmp;
	return BinToDec(bin);
}