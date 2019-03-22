#include "QFloat.h"
const int g_biased = 16383;
const size_t g_MaxOfExponentBit = 15;
const size_t g_MaxOfMantissaBit = 112;

QFLOAT::QFLOAT()
{
	data[0] = data[1] = data[2] = data[3] = 0;
}

void QFLOAT::ScanQFloat()
{
	string number;
	getline(cin >> ws, number);
	string ieee = GetBin(number);

	for (int i = 0; i < ieee.length(); i++)
	{
		//bật bit tại vị trí i
		if (ieee[i] == '1')
		{
			this->data[i / 32] = (1 << (32 - 1 - (i % 32))) | this->data[i / 32];
		}
	}
}

void QFLOAT::PrintQFloat()
{
	string qfloat;
	qfloat = this->GetQFloat();
	cout << qfloat << endl;
}

QFLOAT QFLOAT::BinToDec(bool* bit)
{
	this->data[0] = 0;
	this->data[1] = 0;
	this->data[2] = 0;
	this->data[3] = 0;

	string ieee;
	for (int i = 0; i < 128; i++)
	{
		if (bit[i] == 0)
			ieee.push_back('0');
		else if (bit[i] == 1)
			ieee.push_back('1');
		else
			break;
	}
	if (ieee.length() < 128)  // nếu chuỗi có độ dài < 128 thì thêm các bit 0 vào đầu cho đủ 128 bit
	{
		string zeropadding(128 - ieee.length(), '0');
		ieee = zeropadding + ieee;
	}
	else if (ieee.length() > 128) // nếu chuỗi dài hơn 128bit thì xóa các bit cuối sao cho còn lại 128bit
	{
		ieee.erase(128, ieee.length() - 128);
	}

	for (int i = 0; i < ieee.length(); i++)
	{
		//bật bit tại vị trí i
		if (ieee[i] == '1')
		{
			this->data[i / 32] = (1 << (32 - 1 - (i % 32))) | this->data[i / 32];
		}

	}
	return *this;
}

bool* QFLOAT::DecToBin()
{
	bool* ieee = nullptr;
	ieee = new bool[128];

	//Bật bit trên chuỗi ieee từ data[]
	for (int i = 0; i < 128; i++)
	{
		ieee[i] = (this->data[i / 32] & (1 << (31 - i % 32)));
	}
	return ieee;
}

QFLOAT QFLOAT::BinToDec_String(string ieee)
{
	this->data[0] = 0;
	this->data[1] = 0;
	this->data[2] = 0;
	this->data[3] = 0;

	for (int i = 0; i < ieee.length(); i++)
	{
		//bật bit tại vị trí i
		if (ieee[i] == '1')
		{
			this->data[i / 32] = (1 << (32 - 1 - (i % 32))) | this->data[i / 32];
		}
	}
	return *this;
}

string QFLOAT::DecToBin_String()
{
	string ieee(128, '0');
	//Bật bit trên chuỗi ieee từ data[]
	for (int i = 0; i < ieee.length(); i++)
	{
		bool tmp = (this->data[i / 32] & (1 << (31 - i % 32)));
		ieee[i] = tmp + 48;
	}
	return ieee;
}

string QFLOAT::GetQFloat()
{
	string ieee(128, '0');
	//Bật bit trên chuỗi ieee từ data[]
	for (int i = 0; i < ieee.length(); i++)
	{
		bool tmp = (data[i / 32] & (1 << (31 - i % 32)));
		ieee[i] = tmp + 48;
	}

	//chuỗi dấu (vị trí thứ 0 trong ieee)
	string signBits;
	if (ieee[0] == '1')
		signBits = "-";

	// Chuỗi mũ (từ vị trí thứ 1 - 15 trong ieee)
	string expStr;
	expStr.insert(0, ieee, 1, 15);

	// chuỗi định trị (các bit còn lại trong ieee)
	string mantissa;
	mantissa.insert(0, ieee, 16, 112);


	unsigned int exp = BinaryToDecimal(expStr);
	int e = exp - g_biased;

	string integerPart_Dec;
	string fractionalPart_Dec;
	string qfloat;

	if (e == -g_biased)	 // E có bit toàn 0
	{
		if (IsEqualWithZero(mantissa))	 // TH mũ =0 và định trị =0
		{
			qfloat = "0";
		}
		else	// denormalized numbers
		{
			e++;
			integerPart_Dec = "0";
			fractionalPart_Dec = BinToDec_Of_FractionalPart(mantissa);
			qfloat = signBits + integerPart_Dec + "." + fractionalPart_Dec + " x2^(" + to_string(e) + ")";
		}
	}
	else if (e == 0)
	{
		integerPart_Dec = "1";
		fractionalPart_Dec = BinToDec_Of_FractionalPart(mantissa);
		qfloat = signBits + integerPart_Dec + "." + fractionalPart_Dec;
	}
	else if (e <= -1)
	{
		integerPart_Dec = "0";
		fractionalPart_Dec = BinToDec_Of_FractionalPart("1" + mantissa);
		if (e < -1)
		{
			e++;
			qfloat = signBits + integerPart_Dec + "." + fractionalPart_Dec + " x2^(" + to_string(e) + ")";
		}
		else
			qfloat = signBits + integerPart_Dec + "." + fractionalPart_Dec;
	}
	else if (e == 112)
	{
		integerPart_Dec = "1" + mantissa;
		string temp(128 - e, '0');
		integerPart_Dec = FromBinToDec(temp + integerPart_Dec);
		qfloat = signBits + integerPart_Dec;
	}
	else if (e == g_biased + 1)	   // E toàn bit 1
	{
		if (IsEqualWithZero(mantissa))	  // phần đinh trị toàn bit 0
		{
			qfloat = "Infinity";
		}
		else	   // định trị !=0
		{
			qfloat = "NaN";			// số báo lỗi
		}
	}
	else if (e > 0 && e < 112)
	{
		integerPart_Dec.insert(0, mantissa, 0, e);
		integerPart_Dec = "1" + integerPart_Dec;
		fractionalPart_Dec.insert(0, mantissa, e, 112 - e + 1);
		//
		string temp(128 - e - 1, '0');
		integerPart_Dec = FromBinToDec(temp + integerPart_Dec);
		fractionalPart_Dec = BinToDec_Of_FractionalPart(fractionalPart_Dec);
		qfloat = signBits + integerPart_Dec + "." + fractionalPart_Dec;
	}
	else if (e > 112)
	{
		integerPart_Dec = "1" + mantissa;
		//
		string temp(128 - integerPart_Dec.length(), '0');
		integerPart_Dec = FromBinToDec(temp + integerPart_Dec);
		qfloat = signBits + integerPart_Dec + " x2^(" + to_string(e - 112) + ")";
	}
	return qfloat;
}

string QFLOAT::GetBin(string number)
{
	char signBits = '0';
	if (number[0] == '-')
	{
		signBits = '1';
		// Xóa dấu nếu là số âm
		number.erase(0, 1);
	}

	// Token phần nguyên vào biến integerPart_Dec, phần thập phân vào biến fractionalPart_Dec
	string integerPart_Dec;
	string fractionalPart_Dec;

	istringstream ss(number);
	getline(ss, integerPart_Dec, '.');
	getline(ss, fractionalPart_Dec, '.');


	// Chuyển phần nguyên và phần thập phân thành các chuỗi nhị phân tương ứng:
	// 1) Chuyển phần nguyên:
	string integerPart_Bin = FromDecToBin(integerPart_Dec);
	for (int i = 0; i < integerPart_Bin.length(); i++)  // Xóa số 0 "vô nghĩa" của phần nguyên
	{
		if (integerPart_Bin[i] == '0')
		{
			integerPart_Bin.erase(0, 1);
			i--;
		}
		else
			break;
	}
	// 2) Chuyển phần thập phân:
	string fractionalPart_Bin = ConvertFractionalPart_FromDecToBin(fractionalPart_Dec);


	// Chuẩn hóa dấu chấm động theo chuẩn IEEE
	int exp = 0;
	string mantissa; // phần định trị
	if (IsEqualWithZero(integerPart_Bin)) // nếu phần nguyên = 0 thì dịch chuyển dấu chấm động sang phải (và ngược lại)	  (theo chuẩn IEEE)
	{

		for (int i = 0; i < fractionalPart_Bin.length(); i++)
		{
			// mỗi lần dịch chuyển dấu chấm động sang phải, giảm biến exp 1 đơn vị
			// ví dụ: 0.0101 [exp đang = 0]  --> 0.101 x 2^(-1)		[exp=-1]
			--exp;

			// Nếu phần tử đang xét bằng '1' thì xóa xóa nó và break khỏi vòng lặp
			if (fractionalPart_Bin[i] == '1')
			{
				fractionalPart_Bin.erase(0, 1);
				break;
			}
			// Nếu phần tử đang xét bằng '0' thì cũng xóa nó
			fractionalPart_Bin.erase(0, 1);
			i--;
		}

		// Ví dụ: 0.0010011 [exp=0]--> 1.0011 [exp=-3] ---xóa '1' đầu---> mantissa=0011 
		mantissa = fractionalPart_Bin;
	}
	else
	{	// Ví dụ: 1001101.0011 ---> 1.0011010011 (exp=6)    (phần nguyên có chiều dài là 7 --> exp=6 --> exp= lenght-1) 
		exp = integerPart_Bin.length() - 1;
		integerPart_Bin.erase(0, 1); // xóa số '1' đầu chuỗi

		//Sau khi chuẩn hóa, ghép phần nguyên và phần thập phân lại. Ta được phần định trị
		mantissa = integerPart_Bin + fractionalPart_Bin;
	}

	//Chuyển phần mũ về chuỗi nhị phân
	int e = exp + g_biased;
	string expStr = to_string(e); //chuyển số về chuỗi
	expStr = FromDecToBin(expStr);

	// Xóa hoặc thêm số 0 "vô nghĩa" ở phía trước sao cho PHẦN MŨ đủ 15 bits
	if (expStr.length() < g_MaxOfExponentBit)
	{
		while (expStr.length() < g_MaxOfExponentBit)
			expStr = '0' + expStr;
	}
	else if (expStr.length() > g_MaxOfExponentBit)
	{
		while (expStr.length() > g_MaxOfExponentBit)
			expStr.erase(0, 1);
	}


	//Thêm các bit 0 vào PHẦN ĐỊNH TRỊ cho đủ 112 bit, nếu đã đủ thì xóa bớt, chỉ lấy đúng 112 bit ở phần định trị
	if (mantissa.length() < g_MaxOfMantissaBit)
	{
		while (mantissa.length() < g_MaxOfMantissaBit)
			mantissa = mantissa + '0';
	}
	else if (mantissa.length() > g_MaxOfMantissaBit)
	{
		while (mantissa.length() > g_MaxOfMantissaBit)
			mantissa.pop_back();
	}


	// ********* GHÉP 3 CHUỖI: DẤU + PHẪN MŨ + PHẦN ĐỊNH TRỊ
	string ieee = signBits + expStr + mantissa;
	return ieee;
}
