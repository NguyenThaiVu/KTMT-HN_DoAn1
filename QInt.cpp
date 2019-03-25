#include "QInt.h"
#include "ThuVien.h"

QINT::QINT()
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
}
string QINT::ConvertDataToDec()
{
	//chuyen tu data[4] thành mã nhi phân 
	string bin(128, '0');
	//doc bit
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
	bool sign = 0;	//so duong
	if (bin[0] == '1')	//so âm
	{
		sign = 1;
	}
	string result;
	result = FromBinToDec(bin);
	if (sign == 1)
	{
		result = "-" + result;
	}
	return result;
}
void QINT::ConvertDecToData(string number)
{
	string bin = FromDecToBin(number);
	//
	for (int i = 0; i < bin.length(); i++)
	{
		//bat bit tai vi trí i
		if (bin[i] == '1')
		{
			this->data[i / 32] = (1 << (32 - 1 - (i % 32))) | this->data[i / 32];
		}
	}
}
void QINT::ScanQInt()
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
	string number;
	getline(cin >> ws, number);
	this->ConvertDecToData(number);
}

void QINT::PrintQInt()
{
	string result = this->ConvertDataToDec();
	cout << result << endl;
}

void QINT::DocBit(QINT &x, string &bin)
{
	if (bin.length() < 128)
	{
		for (int i = bin.length(); i < 128; i++)
		{
			bin = bin + '0';
		}
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

void QINT::BatBit(QINT &x, string &bin)
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
string QINT::DecToBin_String(QINT x)
{
	string bin;
	DocBit(x, bin);
	//xóa những số 0 dư thừa phía trước
	while (bin[0] == '0' && bin.length() > 1)
	{
		bin.erase(bin.begin());
	}
	return bin;
}
QINT QINT::BinToDec_String(string bit)
{
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
	int len = bit.length();
	if (bit.length() < 128)
	{
		for (int i = 0; i < 128 - len; i++)
			bit = '0' + bit;
	}
	BatBit(*this, bit);
	return *this;
}

string QINT::DecToHex_String(QINT x)
{
	string bin, dec, hex;
	DocBit(x, bin);
	dec = FromBinToDec(bin);
	hex = FromDecToHex(dec);
	return hex;
}

string QINT::BinToHex_String(string bit)
{
	QINT x;
	x.BinToDec_String(bit);
	string hex;
	hex = DecToHex_String(x);
	return hex;
}

bool * QINT::DecToBin(QINT x)
{
	bool* bit = new bool[128];
	string bin;
	for (int i = 0; i < 128; i++)
	{
		if (bin[i] == '0') bit[i] = false;
		else bit[i] = true;
	}
	return bit;
}

QINT QINT::BinToDec(bool * bin)
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
	BatBit(*this, bit);
	return *this;
}

char* QINT::DecToHex(QINT x)
{
	string bin, dec, strHex;
	DocBit(x, bin);
	dec = FromBinToDec(bin);
	strHex = FromDecToHex(dec);
	int len = strHex.length();
	char* hex = new char[len];
	for (int i = 0; i < strHex.length(); i++)
		hex[i] = strHex[i];
	hex[len] = '\0';
	return hex;
}

char * QINT::BinToHex(bool * bit)
{
	QINT x;
	x.BinToDec(bit);
	string bin = "";
	for (int i = 0; i < LengthBool(bit); i++)
	{
		if (bit[i] == true) bin = bin + "1";
		else bin = bin + "0";
	}
	x.BinToDec_String(bin);
	char* hex = new char[bin.length()];
	hex = DecToHex(x);
	return hex;
}

//phep toan + so sanh
QINT QINT::operator+(QINT q2) 
{
	string number;
	QINT q3;

	string s1 = this->ConvertDataToDec();
	string s2 = q2.ConvertDataToDec();
	if ((CheckSign(s1) == 0) && (CheckSign(s2) == 0)) { //TH 2 so duong thi cong lai
		number = SumOfTwoNumbers(s1, s2);
	}
	else if ((CheckSign(s1) == 1) && (CheckSign(s2) == 1)) { //TH 2 so deu am thi xoa dau roi cong lai
		s1.erase(0, 1);
		s2.erase(0, 1);
		number = SumOfTwoNumbers(s1, s2);
		number.insert(0, 1, '-'); //sau do them dau '-' vao ket qua
	}
	else {
		if (CheckSign(s1) == 1) { //TH s1 am va s2 duong thi xoa dau s1
			s1.erase(0, 1);
			swap(s1, s2); //doi vi tri va xem nhu s2 - s1
		}
		else s2.erase(0, 1); //TH s1 duong va s2 am thi tru nhau
		number = SubtractionOfTwoNumbers(s1, s2);
	}
	q3.ConvertDecToData(number);
	return q3;
}

QINT QINT::operator-(QINT q2) {
	string number;
	QINT q3;

	string s1 = this->ConvertDataToDec();
	string s2 = q2.ConvertDataToDec();

	if ((CheckSign(s1) == 0) && (CheckSign(s2) == 1)) { //TH s1 duong va s2 am thi xoa dau s2 va cong lai
		s2.erase(0, 1);
		number = SumOfTwoNumbers(s1, s2);
	}
	else if ((CheckSign(s1) == 1) && (CheckSign(s2) == 0)) { //TH s1 am va s2 duong thi xoa dau s1 va cong lai
		s1.erase(0, 1);
		number = SumOfTwoNumbers(s1, s2);
		number.insert(0, 1, '-'); //them dau '-' vao ket qua
	}
	else {
		if (CheckSign(s1) == 1) { //TH s1 am va s2 am thi xoa dau ca 2
			s1.erase(0, 1);
			s2.erase(0, 1);
			swap(s1, s2); //doi vi tri va xem nhu s2 - s1
		}
		number = SubtractionOfTwoNumbers(s1, s2); //tru nhau
	}
	q3.ConvertDecToData(number);
	return q3;
}

QINT QINT::operator*(QINT q2) 
{
	string number;
	QINT q3;

	string s1 = this->ConvertDataToDec();
	string s2 = q2.ConvertDataToDec();

	if ((CheckSign(s1) == 0) && (CheckSign(s2) == 0)) 
	{ 
		//TH ca 2 duong thi cong ca 2 lai voi nhau
		number = MultiplyWithBigNum(s1, s2);
	}
	else if ((CheckSign(s1) == 1) && (CheckSign(s2) == 1)) 
	{//TH ca 2 am thi xoa dau ca 2 va nhan voi nhau
		s1.erase(0, 1);
		s2.erase(0, 1);
		number = MultiplyWithBigNum(s1, s2);
	}
	else if (CheckSign(s1) == 1) 
	{ //TH s1 am va s2 duong thi xoa dau s1 nhan lai voi nhau
		s1.erase(0, 1);
		number = MultiplyWithBigNum(s1, s2);
		number.insert(0, 1, '-'); //them dau '-' vao ket qua
	}
	else {
		//TH s1 duong va s2 am thi xoa dau s2 nhan lai voi nhau
		s2.erase(0, 1);
		number = MultiplyWithBigNum(s1, s2);
		number.insert(0, 1, '-'); //them dau '-' vao ket qua
	}
	q3.ConvertDecToData(number);
	return q3;
}

QINT QINT::operator/(QINT q2) {
	string number;
	QINT q3;

	string s1 = this->ConvertDataToDec();
	string s2 = q2.ConvertDataToDec();

	if ((CheckSign(s1) == 0) && (CheckSign(s2) == 0)) { //TH ca 2 duong thi chia ca 2 cho nhau
		number = Division(s1, s2);
	}
	else if ((CheckSign(s1) == 1) && (CheckSign(s2) == 1)) {//TH ca 2 am thi xoa dau ca 2 va chia cho nhau
		s1.erase(0, 1);
		s2.erase(0, 1);
		number = Division(s1, s2);
	}
	else if (CheckSign(s1) == 1) { //TH s1 am va s2 duong thi xoa dau s1 chia cho nhau
		s1.erase(0, 1);
		number = Division(s1, s2);
		number.insert(0, 1, '-'); //them dau '-' vao ket qua
	}
	else {
		//TH s1 duong va s2 am thi xoa dau s2 roi chia cho nhau
		s2.erase(0, 1);
		number = Division(s1, s2);
		number.insert(0, 1, '-'); //them dau '-' vao ket qua
	}
	if (number == "Syntax Error!") {
		cout << "Syntax Error!";
		return q3;
	}
	q3.ConvertDecToData(number);
	return q3;
}

QINT QINT::operator%(QINT q2) {
	string number;
	QINT q3;

	string s1 = this->ConvertDataToDec();
	string s2 = q2.ConvertDataToDec();

	if ((CheckSign(s1) == 0) && (CheckSign(s2) == 0)) { //TH ca 2 duong thi chia ca 2 cho nhau
		number = Modulo(s1, s2);
	}
	else if ((CheckSign(s1) == 1) && (CheckSign(s2) == 1)) {//TH ca 2 am thi xoa dau ca 2 va chia cho nhau
		s1.erase(0, 1);
		s2.erase(0, 1);
		number = Modulo(s1, s2);
	}
	else if (CheckSign(s1) == 1) { //TH s1 am va s2 duong thi xoa dau s1 chia cho nhau
		s1.erase(0, 1);
		number = Modulo(s1, s2);
		number.insert(0, 1, '-'); //them dau '-' vao ket qua
	}
	else {
		//TH s1 duong va s2 am thi xoa dau s2 roi chia cho nhau
		s2.erase(0, 1);
		number = Modulo(s1, s2);
		number.insert(0, 1, '-'); //them dau '-' vao ket qua
	}
	if (number == "Syntax Error!") {
		cout << "Syntax Error!";
		return q3;
	}
	q3.ConvertDecToData(number);
	return q3;
}

bool QINT::operator<(QINT q2) 
{
	QINT temp = *this;
	temp = temp - q2;
	if (temp.ConvertDataToDec() < "0") return true;
	else return false;
}

bool QINT::operator>(QINT q2) 
{
	QINT temp = *this;
	temp = temp - q2;
	if (temp.ConvertDataToDec() > "0") return true;
	else return false;
}

bool QINT::operator==(QINT q2) {
	QINT temp = *this;
	temp = temp - q2;
	if (temp.ConvertDataToDec() == "0") return true;
	else return false;
}

bool QINT::operator>=(QINT q2) {
	QINT temp = *this;
	temp = temp - q2;
	if (temp.ConvertDataToDec() < "0") return false;
	else return true;
}

bool QINT::operator<=(QINT q2) {
	QINT temp = *this;
	temp = temp - q2;
	if (temp.ConvertDataToDec() > "0") return false;
	else return true;
}

bool QINT::operator=(QINT q2) {
	string temp;
	temp = q2.ConvertDataToDec();
	this->data[0] = this->data[1] = this->data[2] = this->data[3] = 0;
	this->ConvertDecToData(temp);
	return 1;
}

QINT QINT::operator&(QINT& x)
{
	string bin, bin1, bin2;
	QINT result;
	//Đổi 2 số cần thực hiện phép toán AND sang dạng nhị phân
	DocBit(x, bin1);
	DocBit(*this, bin2);
	//Tiến hành thực hiện phép toán AND theo từng bit từ trái sang phải
	for (int i = 0; i < bin1.length(); i++)
		bin += to_string((bin1[i] - '0')&(bin2[i] - '0'));
	//Chuyển dãy bit sau khi thực hiện xong về lại dạng QINT
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::operator|(QINT& x)
{
	string bin, bin1, bin2;
	QINT result;
	//Đổi 2 số cần thực hiện phép toán OR sang dạng nhị phân
	DocBit(x, bin1);
	DocBit(*this, bin2);
	//Tiến hành thực hiện phép toán OR theo từng bit từ trái sang phải
	for (int i = 0; i < bin1.length(); i++)
		bin += to_string((bin1[i] - '0') | (bin2[i] - '0'));
	//Chuyển dãy bit sau khi thực hiện xong về lại dạng QINT
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::operator^(QINT& x)
{
	string bin, bin1, bin2;
	QINT result;
	//Đổi 2 số cần thực hiện phép toán XOR sang dạng nhị phân
	DocBit(x, bin1);
	DocBit(*this, bin2);
	//Tiến hành thực hiện phép toán XOR theo từng bit từ trái sang phải
	for (int i = 0; i < bin1.length(); i++)
		bin += to_string((bin1[i] - '0') ^ (bin2[i] - '0'));
	//Chuyển dãy bit sau khi thực hiện xong về lại dạng QINT
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::operator~()
{
	string tmp, bin;
	QINT result;
	//Đổi số cần thực hiện phép toán NOT sang dạng nhị phân
	DocBit(*this, tmp);
	//Tiến hành thực hiện phép toán NOT theo từng bit từ trái sang phải
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '0')
			bin += "1";
		else
			bin += "0";
	}
	//Chuyển dãy bit sau khi thực hiện xong về lại dạng QINT
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::operator>>(int x)
{
	if (x < 0 || x >= 128)
		return QINT();
	//Đổi số cần thực hiện phép >> sang dạng nhị phân
	string bin;
	DocBit(*this, bin);
	QINT result;
	//Xóa x bit cuối
	bin.erase(bin.length() - x, x);
	//Thêm x bit 0 ở đầu
	bin = string(x, '0') + bin;
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::operator>>(QINT x)
{
	QINT x1, x2, result;
	x1.BinToDec_String(string(128, '0')); //000...0000
	x2.BinToDec_String(string(121, '0') + string(7, '1')); //00...1111111)
	if (x < x1 || x > x2) // x < 0 (00...0) || x > 127 (00...1111111)
		return QINT();
	//Đổi số cần thực hiện phép >> sang dạng nhị phân
	string bin;
	DocBit(*this, bin);
	//Xóa x bit cuối
	bin.erase(bin.length() - x.data[3], x.data[3]); //Vì x trong trường hợp này < 128 nên x cũng chính là x.data[3]
	//Thêm x bit 0 ở đầu
	bin = string(x.data[3], '0') + bin; //Vì x trong trường hợp này < 128 nên x cũng chính là x.data[3]
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::operator<<(int x)
{
	if (x < 0 || x >= 128)
		return QINT();
	//Đổi số cần thực hiện phép << sang dạng nhị phân
	string bin;
	DocBit(*this, bin);
	QINT result;
	//Xóa x bit đầu
	bin.erase(0, x);
	//Thêm x bit 0 ở cuối
	bin = bin + string(x, '0');
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::operator<<(QINT x)
{
	QINT x1, x2, result;
	x1.BinToDec_String(string(128, '0')); //000...0000
	x2.BinToDec_String(string(121, '0') + string(7, '1')); //00...1111111)
	if (x < x1 || x > x2) // x < 0 (00...0) || x > 127 (00...1111111)
		return QINT();
	//Đổi số cần thực hiện phép << sang dạng nhị phân
	string bin;
	DocBit(*this, bin);
	//Xóa x bit đầu
	bin.erase(0, x.data[3]); //Vì x trong trường hợp này < 128 nên x cũng chính là x.data[3]
	//Thêm x bit 0 ở cuối
	bin = bin + string(x.data[3], '0'); //Vì x trong trường hợp này < 128 nên x cũng chính là x.data[3]
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::ROR(int x) //ROR 130 bit cũng giống ROR 2 bit
{
	if (x < 0)
		return this->ROL(-x);
	if (x == 0)
		return *this;
	//Đổi số cần thực hiện phép ROR sang dạng nhị phân
	string bin, tmp;
	DocBit(*this, bin);
	QINT result;
	//Lưu x bit cuối vào tmp
	tmp = string(bin, bin.length() - x % 128, x % 128);
	//Xóa x bit cuối
	bin.erase(bin.length() - x % 128, x % 128);
	//Thêm các bit trong tmp vào đầu
	bin = tmp + bin;
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::ROR(QINT x)
{
	QINT x1, x2, result;
	x1.BinToDec_String(string(128, '0')); //000...0000
	x2.BinToDec_String(string(120, '0') + "1" + string(7, '0')); //000...10000000 (128)
	if (x < x1) //x < 0
		return this->ROL(x1 - x);  //return this->ROL(-x) cũng giống return this->ROL(0-x)
	if (x == x1) //x == 0
		return *this;
	//Đổi số cần thực hiện phép ROR sang dạng nhị phân
	string bin, tmp;
	DocBit(*this, bin);
	//Lưu x bit cuối vào tmp
	tmp = string(bin, bin.length() - (x % x2).data[3], (x % x2).data[3]); //vì x % 128 < 128 nên nó cũng chính là phần trong data[3]
	//Xóa x bit cuối
	bin.erase(bin.length() - (x % x2).data[3], (x % x2).data[3]); //vì x % 128 < 128 nên nó cũng chính là phần trong data[3]
	//Thêm các bit trong tmp vào đầu
	bin = tmp + bin;
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::ROL(int x) //ROL 130 bit cũng giống ROL 2 bit
{
	if (x < 0)
		return this->ROR(-x);
	if (x == 0)
		return *this;
	//Đổi số cần thực hiện phép ROL sang dạng nhị phân
	string bin, tmp;
	DocBit(*this, bin);
	QINT result;
	//Lưu x bit đầu vào tmp
	tmp = string(bin, 0, x % 128);
	//Xóa x bit đầu
	bin.erase(0, x);
	bin.erase(0, x % 128);
	//Thêm các bit trong tmp vào cuối
	bin = bin + tmp;
	result.BinToDec_String(bin);
	return result;
}

QINT QINT::ROL(QINT x)
{
	QINT x1, x2, result;
	x1.BinToDec_String(string(128, '0')); //000...0000
	x2.BinToDec_String(string(120, '0') + "1" + string(7, '0')); //000...10000000 (128)
	if (x < x1) //x < 0
		return this->ROR(x1 - x);  //return this->ROR(-x) cũng giống return this->ROR(0-x)
	if (x == x1) // x == 0
		return *this;
	//Đổi số cần thực hiện phép ROL sang dạng nhị phân
	string bin, tmp;
	DocBit(*this, bin);
	//Lưu x bit đầu vào tmp
	tmp = string(bin, 0, (x % x2).data[3]); //vì x % 128 < 128 nên nó cũng chính là phần trong data[3]
	//Xóa x bit đầu
	bin.erase(0, (x % x2).data[3]); //vì x % 128 < 128 nên nó cũng chính là phần trong data[3]
	//Thêm các bit trong tmp vào cuối
	bin = bin + tmp;
	result.BinToDec_String(bin);
	return result;
}