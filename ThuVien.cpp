#include"ThuVien.h"

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
		return string(128, '0');
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
		number = Division(number, "2");
	}
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

string PowWithBase2(int n)	//2^n
{
	if (n == 0)
		return "1";
	string result = "2";	//base case 
	for (int i = 0; i < n - 1; i++)
	{
		result = MultiplyWithSmallNum(result, 2);
	}
	return result;
}

string FromBinToDec(string bin)
{
	string result = "0";
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
			result = SumOfTwoNumbers(result, PowWithBase2(127 - i));
		}
	}
	//// thêm dấu trừ nếu số âm
	return result;
}

string Cut2Char(string dec)
{
	if (dec.length() < 2)
	{
		return dec;
	}
	string result = "00";
	result[0] = dec[0];
	result[1] = dec[1];
	return result;
}

int FromStringToInt(string strNumber)
{
	int inNumber = 0;
	for (int i = 0; i < strNumber.length(); i++)
	{
		inNumber = inNumber * 10 + (strNumber[i] - '0');
	}
	return inNumber;
}

string FromIntToString(int inNumber)
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

string DivideBy16(string dec, string &remain)
{
	if ((dec.length() == 1) || (dec.length() == 2 && dec[1] - '0' < 6 && dec[0] == '1'))
	{
		remain = dec;
		return "0";
	}
	string result;
	int idx = 1;
	int number = FromStringToInt(Cut2Char(dec));
	if (dec.length() == 2)
	{
		result.push_back((number / 16) + '0');
		remain = FromIntToString(number % 16);
		return result;
	}
	while (idx != dec.length() - 1)
	{
		if (number < 16)
			number = number * 10 + (dec[++idx] - '0');
		result.push_back((number / 16) + '0');
		number = number % 16;
	}
	remain = FromIntToString(number);
	return result;
}

string FromDecToHex(string dec)
{
	string result = "", remain;
	if (dec == "0")
	{
		result = "0";
	}
	while (dec != "0")
	{
		dec = DivideBy16(dec, remain);
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

char NumToString(int number) 
{
	return (char)(number + 48);
}

int StringToNum(char c) 
{
	return c - '0';
}

bool CheckSign(string s) 
{
	if (s[0] == '-') return 1;
	else return 0;
}

bool CompareUnsignedInt(string s1, string s2) //so sanh 2 chuoi co do dai bang nhau
{ 
	//xóa những số 0 ở đầu dãy số
	if (s1[0] == '0')
	{
		while (s1[0] == 0)
		{
			s1.erase(s1.begin());
		}
	}
	if (s2[0] == '0')
	{
		while (s2[0] == 0)
		{
			s2.erase(s2.begin());
		}
	}
	//
	if (s1.length() > s2.length())
		return 1;
	if (s1.length() < s2.length())
		return 0;
	for (int i = 0; i < s1.length(); i++) 
	{
		if (s1[i] > s2[i]) return 1;
		if (s1[i] < s2[i]) return 0;
	}
	return 1;
}

string SumOfTwoNumbers(string s1, string s2) 
{
	TheSameLength(s1, s2);

	string result;
	int l = s1.length();

	int temp = 0;
	for (int i = l - 1; i >= 0; i--) //cong tu phai sang trai
	{ 
		temp = StringToNum(s1[i]) + StringToNum(s2[i]) + temp; //cong 2 so lai va cong them phan nguyen cua 10
		result.insert(0, 1, NumToString(temp % 10)); //lay phan du cua 10
		temp = temp / 10; //nho phan nguyen cua 10(hay con goi la nho 1)
	}
	if (temp > 0) result.insert(0, 1, NumToString(temp)); //neu phan nguyen cua 10 lon hon 0 thi viet phan nguyen do vao phia truoc
	return result;
}

string SubtractionOfTwoNumbers(string s1, string s2) 
{
	int temp = 0;
	int sign;
	string result;

	if (CompareUnsignedInt(s1, s2) == 0) {
		//neu s2 lon hon s1 thi ta doi cho 2 so va danh dau tru
		sign = 1;
		swap(s1, s2);
	}
	else sign = 0; //nguoc lai khong doi va danh dau cong

	TheSameLength(s1, s2);
	int l = s1.length();

	for (int i = l - 1; i >= 0; i--) {
		if (s1[i] < s2[i]) {
			temp = StringToNum(s1[i]) + 10 - StringToNum(s2[i]) - temp;//muon 1 de tru
			result.insert(0, 1, NumToString(temp));
			temp = 1;//nho 1
		}
		else {
			temp = StringToNum(s1[i]) - StringToNum(s2[i]) - temp; //tru binh thuong
			result.insert(0, 1, NumToString(temp));
			temp = 0;
		}
	}
	while ((result[0] == '0') && (result.length() > 1)) result.erase(0, 1);
	if (sign == 1) result.insert(0, 1, '-');
	return result;
}

string MultiplyWithSmallNum(string s1, int n) 
{
	//gan giong voi phep cong, nhan roi cong lai
	string result;
	int temp = 0;
	int l = s1.length();
	for (int i = l - 1; i >= 0; i--) {
		temp = n * StringToNum(s1[i]) + temp;
		result.insert(0, 1, NumToString(temp % 10));
		temp = temp / 10;
	}
	if (temp > 0) result.insert(0, 1, NumToString(temp));
	while ((result[0] == '0') && (result.length() > 1)) result.erase(0, 1);
	return result;
}

string MultiplyWithBigNum(string s1, string s2) 
{
	int j = 0;
	int l = s2.length();
	string result;
	for (int i = l - 1; i >= 0; i--) 
	{
		string temp = MultiplyWithSmallNum(s1, StringToNum(s2[i])); //tinh tung so cua s2 nhan voi ca chuoi s1
		temp.insert(temp.length(), j, '0'); //them so j lan so 0 vao cuoi chuoi moi lan tinh de duoc cai thap
		result = SumOfTwoNumbers(result, temp); //cong lai
		j++;
	}
	while ((result[0] == '0') && (result.length() > 1)) result.erase(0, 1);
	return result;
}

void TheSameLength(string &s1, string &s2) 
{
	
	int l1 = s1.length(), l2 = s2.length();
	if (l1 > l2) //neu l1 > l2 thi them (l1-l2) so 0 vao dau chuoi s2
	{ 
		for (int i = l2; i < l1; i++) 
		{
			s2.insert(0, 1, '0');
		}
	}
	else 
	{
		for (int i = l1; i < l2; i++) 
		{ 
			s1.insert(0, 1, '0');
		}
	}
}

//*************** for QFloat

string ConvertFractionalPart_FromDecToBin(string number)
{
	string result;
	int count = 0;
	while (!number.empty())
	{
		if (number[0] >= '5')
		{
			result = result + '1';
			number = MultiplyWithSmallNum(number, 2);
			number.erase(0, 1);// xóa số 1 đầu chuỗi
		}
		else
		{
			result = result + '0';
			number = MultiplyWithSmallNum(number, 2);
		}

		// giới hạn Max Lenght cho chuỗi nhị phân chứa phần thập phân.		
		count++;
		if (count == 16383)
			break;

		//xóa các số 0 vô nghĩa
		for (int i = number.length() - 1; i >= 0; i--)
		{
			if (number[i] == '0')
				number.pop_back();
			else
				break;
		}
	}
	return result;

}

bool IsEqualWithZero(string number)
{
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] != '0')
			return false;
	}
	return true;
}

unsigned int BinaryToDecimal(string n)
{
	string num = n;
	unsigned int decValue = 0;

	unsigned int base = 1;

	int len = num.length();
	for (int i = len - 1; i >= 0; i--)
	{
		if (num[i] == '1')
			decValue += base;
		base = base * 2;
	}

	return decValue;
}

string BinToDec_Of_FractionalPart(string fractionalPart)
{
	string result("0");
	string temp("1");
	for (int i = 0; i < fractionalPart.length(); i++)
	{
		int exp = -(i + 1);
		temp = MultiplyWithSmallNum(temp, 5);

		string zeropadding0(-exp - temp.length(), '0');
		temp = zeropadding0 + temp;

		if (fractionalPart[i] == '1')
		{
			string zeropadding(abs(1.*temp.length() - result.length()), '0');
			if (temp.length() < result.length())
			{
				temp = temp + zeropadding;
				result = SumOfTwoNumbers(result, temp);
				temp.erase(temp.length() - zeropadding.length(), zeropadding.length());
			}
			else
			{
				result = result + zeropadding;
				result = SumOfTwoNumbers(result, temp);
			}

		}
	}
	return result;
}

string Division(string s1, string s2) 
{
	string result;
	string temp = "0";
	int l1 = s1.length();
	int l2 = s2.length();

	if (s2 == "0") return "Syntax Error!"; //TH mau bang 0
	if (l1 < l2) return "0"; //TH so bi chia co do dai nho hon so chia thi tra ra 0
	for (int i = 0; i < l1; i++)//xet tu trai sang phai
	{ 
		if (temp[0] == '0') //neu temp = 0 thi xoa temp va them so ke tiep vao temp
		{ 
			temp.erase(0, 1);
			temp.insert(0, 1, s1[i]);
		}
		else temp.insert(temp.length(), 1, s1[i]); //khong thi them so ke tiep vao temp
		if (CompareUnsignedInt(temp, s2) == 1) //neu temp lon hon hoac bang s2 thi xet tiep
		{ 
			for (int j = 1; j <= 10; j++) // nhan temp voi j de tim so gan nhat nho hon temp va chia het cho s2
			{ 
				if (CompareUnsignedInt(temp, MultiplyWithSmallNum(s2, j)) == 0) //neu temp < s2*j thi ngung
				{ 
					result.insert(result.length(), 1, NumToString(j - 1)); //tim duoc temp/s2 thi luu vao result
					temp = SubtractionOfTwoNumbers(temp, MultiplyWithSmallNum(s2, j - 1)); //temp = temp%(s2*j), tuc la phan du
					break;
				}
			}
		}
		else result.insert(result.length(), 1, '0'); //neu temp<s2 thi luu 0 vao insert
	}
	while ((result[0] == '0') && (result.length() > 1)) result.erase(0, 1);
	return result;
}

string Modulo(string s1, string s2) 
{
	string result;
	if (s2 == "0") return "Syntax Error!";
	result = SubtractionOfTwoNumbers(s1, MultiplyWithBigNum(s2, Division(s1, s2))); //phan du se bang s1 - s2*(s1/s2))
	return result;
}

string HexToBin(string hex)
{
	string bin;
	long int i = 0;
	while (hex[i]) {

		switch (hex[i]) 
		{
		case '0':
			bin += "0000";
			break;
		case '1':
			bin += "0001";
			break;
		case '2':
			bin += "0010";
			break;
		case '3':
			bin += "0011";
			break;
		case '4':
			bin += "0100";
			break;
		case '5':
			bin += "0101";
			break;
		case '6':
			bin += "0110";
			break;
		case '7':
			bin += "0111";
			break;
		case '8':
			bin += "1000";
			break;
		case '9':
			bin += "1001";
			break;
		case 'A':
		case 'a':
			bin += "1010";
			break;
		case 'B':
		case 'b':
			bin += "1011";
			break;
		case 'C':
		case 'c':
			bin += "1100";
			break;
		case 'D':
		case 'd':
			bin += "1101";
			break;
		case 'E':
		case 'e':
			bin += "1110";
			break;
		case 'F':
		case 'f':
			bin += "1111";
			break;
		default:
			cout << "\nInvalid hexadecimal digit " << hex[i];
		}
		i++;
	}
	return bin;
}

string BinToHex(string bin)
{
	string hex;
	string temp;
	while (bin.length() >= 4)
	{
		temp = "";
		temp.push_back(bin[bin.length() - 1]);
		bin.erase(bin.end() - 1);
		temp.push_back(bin[bin.length() - 1]);
		bin.erase(bin.end() - 1);
		temp.push_back(bin[bin.length() - 1]);
		bin.erase(bin.end() - 1);
		temp.push_back(bin[bin.length() - 1]);
		bin.erase(bin.end() - 1);
		reverse(temp.begin(), temp.end());
		if (temp == "0000")
			hex = hex + '0';
		else if (temp == "0001")
			hex = hex + '1';
		else if (temp == "0010")
			hex = hex + '2';
		else if (temp == "0011")
			hex = hex + '3';
		else if (temp == "0100")
			hex = hex + '4';
		else if (temp == "0101")
			hex = hex + '5';
		else if (temp == "0110")
			hex = hex + '6';
		else if (temp == "0111")
			hex = hex + '7';
		else if (temp == "1000")
			hex = hex + '8';
		else if (temp == "1001")
			hex = hex + '9';
		else if (temp == "1010")
			hex = hex + 'A';
		else if (temp == "1011")
			hex = hex + 'B';
		else if (temp == "1100")
			hex = hex + 'C';
		else if (temp == "1101")
			hex = hex + 'D';
		else if (temp == "1110")
			hex = hex + 'E';
		else if (temp == "1111")
			hex = hex + 'F';
	}
	//phần dư còn lại
	temp = "";
	while (bin.length() > 0)
	{
		temp.push_back(bin[bin.length() - 1]);
		bin.erase(bin.end() - 1);
	}
	reverse(temp.begin(), temp.end());
	if (temp == "0" || temp == "00" || temp == "000")
		hex = hex + '0';
	else if (temp == "1" || temp == "01" || temp == "001")
		hex = hex + '1';
	else if (temp == "10" || temp == "010")
		hex = hex + '2';
	else if (temp == "11" || temp == "011")
		hex = hex + '3';
	else if (temp == "100")
		hex = hex + '4';
	else if (temp == "101")
		hex = hex + '5';
	else if (temp == "110")
		hex = hex + '6';
	else  if (temp == "111")
		hex = hex + '7';
	reverse(hex.begin(), hex.end());
	return hex;
}

int LengthBool(bool* bit)
{
	int len = 0;
	while (bit[len] == true || bit[len] == false)
		len++;
	return len;
}