#include"ThuVien.h"

string DivideBy2(string number) //Trả về kết quả của chuỗi number/2
{
	if (number == "0" || number == "1")
		return "0";
	string ans;
	int idx = 0;
	int temp = number[idx] - '0';
	while (temp < 2)
	{
		temp = temp * 10 + (number[++idx] - '0');
	}
	while (number.size() > idx)
	{
		ans += (temp / 2) + '0';
		temp = (temp % 2) * 10 + number[++idx] - '0';
	}
	if (ans.length() == 0)
		return "0";
	return ans;
}

string FromDecToBin(string number)
{
	bool sign = 0;	//dau +
	if (number[0] == '-')
	{
		number.erase(number.begin() + 0);	//xoa dau -
		sign = 1;	//dau -
	}
	string result = "";
	if (number == "0")
	{
		return "0";
	}
	int temp;
	while (number != "0")
	{
		temp = number[number.length() - 1] - '0';
		if (temp % 2 == 0)
		{
			result = "0" + result;
		}
		else
			result = "1" + result;
		number = DivideBy2(number);
	}
	//
	int n = result.length();
	for (int i = 128; i > n; i--)
	{
		result = "0" + result;
	}
	//neu la so am, chuyen thanh so bu 2
	if (sign == 1)
	{
		//chuyen bit 0->1 và 1->0
		for (int i = 0; i < result.length(); i++)
		{
			if (result[i] == '0')
				result[i] = '1';
			else
				result[i] = '0';
		}
		//cong them 1
		for (int i = result.length() - 1; i >= 0; i--)
		{
			bool remain = 1;
			if (result[i] == '0' && remain == 1)
			{
				result[i] = '1';
				break;
			}
			else if (result[i] == '1' && remain == 1)
			{
				result[i] = '0';
			}

		}
	}
	return result;
}

string MultipltWith2(string number)
{
	string result;
	if (number == "0")
	{
		return "0";
	}
	int temp, remain = 0;
	for (int i = number.length() - 1; i >= 0; i--)
	{
		temp = number[i] - '0';
		temp = temp * 2 + remain;
		remain = 0;
		if (temp >= 10)
		{
			temp = temp - 10;
			remain = 1;
		}
		result = (char)(temp + '0') + result;
	}
	if (remain == 1)
	{
		result = "1" + result;
	}
	return result;
}

string SumOfTwoNumber(string str1, string str2)
{
	if (str1.length() > str2.length())
		swap(str1, str2);
	string result = "";
	int n1 = str1.length(), n2 = str2.length();

	// đảo ngược 2 chuỗi số 
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < n1; i++)
	{
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// Cộng phần còn lại của số lớn hơn ( str2)
	for (int i = n1; i < n2; i++)
	{
		int sum = ((str2[i] - '0') + carry);
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// Cộng phần dư
	if (carry)
		result.push_back(carry + '0');

	// Đảo ngược chuỗi kết quả
	reverse(result.begin(), result.end());

	return result;
}

string PowWithBase2(int n)	//2^n
{
	if (n == 0)
		return "1";
	string result = "2";	//base case 
	for (int i = 0; i < n - 1; i++)
	{
		result = MultipltWith2(result);
	}
	return result;
}

string FromBinToDec(string bin)
{
	string result = "";
	if (bin[0] == '1')	//số âm
	{
		//trừ đi 1
		for (int i = bin.length() - 1; i >= 0; i--)
		{
			if (bin[i] == '1')
			{
				bin[i] = '0';
				break;
			}
			else if (bin[i] == '0' && bin[i - 1] == '0')
			{
				bin[i] = '1';
			}
			else if (bin[i] == '0' && bin[i - 1] == '1')
			{
				bin[i] = '1';
				bin[i - 1] = '0';
				break;
			}
		}
		//đổi 0->1 và 1->0
		for (int i = bin.length() - 1; i >= 0; i--)
		{
			if (bin[i] == '0')
				bin[i] = '1';
			else
				bin[i] = '0';
		}
	}
	//
	for (int i = 0; i < bin.length(); i++)
	{
		if (bin[i] == '1')
		{
			result = SumOfTwoNumber(result, PowWithBase2(127 - i));
		}
	}
	//// thêm dấu trừ nếu số âm
	return result;
}
//////////////////////////////////////////
int LengthBool(bool* bit)
{
	int len = 0;
	while (bit[len] == true || bit[len] == false)
		len++;
	return len;
}
string BinUnsigned(string &bin)
{
	string result = "";
	int len = bin.length();
	if (bin.length() < 128)
	{
		for (int i = 0; i < 128 - len; i++)
			bin = "0" + bin;
	}
	for (int i = 0; i < bin.length(); i++)
	{
		if (bin[i] == '1')
		{
			result = SumOfTwoNumber(result, PowWithBase2(127 - i));
		}
	}
	return result;
}
string Cut2Char(string dec)
{
	string result = "00";
	result[0] = dec[0];
	result[1] = dec[1];
	return result;
}
int StringToInt(string strNumber)
{
	int inNumber = 0;
	for (int i = 0; i < strNumber.length(); i++)
	{
		inNumber = inNumber * 10 + (strNumber[i] - '0');
	}
	return inNumber;
}
string InToString(int inNumber)
{
	string strNumber;
	if (inNumber == 0) return "0";
	while (inNumber != 0)
	{
		int r = inNumber % 10;
		strNumber.push_back(r + '0');
		inNumber = inNumber / 10;
	}
	reverse(strNumber.begin(), strNumber.end());
	return strNumber;
}
string DiviceBy16(string dec, string &remain)
{
	if ((dec.length() == 1) || (dec.length() == 2 && dec[1] - '0' < 6 && dec[0] == '1'))
	{
		remain = dec;
		return "0";
	}
	string result;
	int idx = 1;
	int number = StringToInt(Cut2Char(dec));
	if (dec.length() == 2)
	{
		result.push_back((number / 16) + '0');
		remain = InToString(number % 16);
		return result;
	}
	while (idx != dec.length() - 1)
	{
		if (number < 16)
			number = number * 10 + (dec[++idx] - '0');
		result.push_back((number / 16) + '0');
		number = number % 16;
	}
	remain = InToString(number);
	return result;
}
string FromDecToHex(string dec)
{
	string result = "", remain;
	while (dec != "0")
	{
		dec = DiviceBy16(dec, remain);
		if (remain.length() == 2)
		{
			string flag = "A";
			for (int i = 0; i < 6; i++)
			{
				if (remain[1] - '0' == i) break;
				flag = flag[0] + 1;
			}
			remain = flag;
		}
		result = remain + result;
	}
	return result;
}