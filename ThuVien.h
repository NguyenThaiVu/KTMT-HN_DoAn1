#include<iostream>
using namespace std;
#include<string>
#include <string.h>
#include <sstream>
#include <math.h>

// ********function for QInt
string FromDecToBin(string number);
string PowWithBase2(int n);	//2^n
string FromBinToDec(string bin);
string Cut2Char(string dec);	//hàm trả về 2 ký tự đầu của chuỗi 
int FromStringToInt(string strNumber);
string FromIntToString(int inNumber);
string DivideBy16(string dec, string &remain);	//chia số thập phân (dạng chuỗi) cho 16 và nhận về phần dư
string FromDecToHex(string dec);
char NumToString(int number);	//chuyển từ số (0 -> 9) kiểu int sang kiểu char
int StringToNum(char c);		//chuyển từ char (0 -> 9) sang kiểu int	
bool CheckSign(string s);		//kiểm tra dấu của số thập phân (dạng chuỗi): '0' dương '1' âm
bool CompareUnsignedInt(string s1, string s2);
string SumOfTwoNumbers(string s1, string s2);	//tổng của 2 số thập phân (dạng chuỗi)
string SubtractionOfTwoNumbers(string s1, string s2); //hiệu của 2 số thập phân (dạng chuỗi)
string MultiplyWithSmallNum(string s1, int n);	//nhân 1 số thập phân (dạng chuỗi) với 1 số kiểu int
string MultiplyWithBigNum(string s1, string s2);	//tích của 2 số thập phân (dạng chuỗi)
string Division(string s1, string s2);	//thương của 2 số thập phân (dạng chuỗi)
string Modulo(string s1, string s2);	//phần dư của 2 số thập phân (dạng chuỗi)
string HexToBin(string hex);
string BinToHex(string bin);
void TheSameLength(string &s1, string &s2); //Hàm làm cho 2 chuỗi có độ dài bằng nhau
int LengthBool(bool* bit);	

//********function for Qfloat
// Chuyển phần thập phân từ Dec sang Bin
string ConvertFractionalPart_FromDecToBin(string number);
// kiểm tra chuỗi có bằng 0 hay không
bool IsEqualWithZero(string number);
unsigned int BinaryToDecimal(string n);
// Nhân 1 số nguyên lớn (kiểu string) với 1 số nguyên nhỏ (int). Chỉ áp dụng cho số không âm
string BinToDec_Of_FractionalPart(string n);