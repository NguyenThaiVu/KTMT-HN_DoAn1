#include"ThuVien.h"

string DivideBy2(string number)
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
	string result="2";	//base case 
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
			else if (bin[i] == '0' && bin[i-1]=='0')
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
	return result;
}

//Phep toan + So sanh

char NumToString(int number){
	return (char)(number + 48);
}

int StringToNum(char c){
	return c - '0';
}

//int StringToNum(string s){
//	int number = 0;
//	int l = s.length();
//	for (int i = l - 1; i >= 0; i--){
//		if (i == l - 1) number += StringToNum(s[i]);
//		else{
//			int temp = StringToNum(s[i]);
//			for (int j = 0; j < l - i - 1; j++){
//				temp = temp * 10;
//			}
//			number += temp;
//		}
//	}
//	return number;
//}


bool CheckSign(string &s){
	if (s[0] == '-') return 1;
	else return 0;
}

int CompareUnsignedInt(string s1, string s2){ //so sanh 2 chuoi co do dai bang nhau
	if (s1.length() > s2.length()) return 1;
	if (s1.length() < s2.length()) return 0;
	for (int i = 0; i < s1.length(); i++){
		if (s1[i] > s2[i]) return 1;
		if (s1[i] < s2[i]) return 0;
	}
	return -1;
}

string Plus(string s1, string s2){
	TheSameLength(s1, s2);

	string result;
	int l = s1.length();

	int temp = 0;
	for (int i = l - 1; i >= 0; i--){ //cong tu phai sang trai
		temp = StringToNum(s1[i]) + StringToNum(s2[i]) + temp; //cong 2 so lai va cong them phan nguyen cua 10
		result.insert(0, 1, NumToString(temp % 10)); //lay phan du cua 10
		temp = temp / 10; //nho phan nguyen cua 10(hay con goi la nho 1)
	}
	if (temp > 0) result.insert(0, 1, NumToString(temp)); //neu phan nguyen cua 10 lon hon 0 thi viet phan nguyen do vao phia truoc
	return result;
}

string Minus(string s1, string s2){
	int temp = 0;
	int sign;
	string result;

	if (CompareUnsignedInt(s1, s2) == 0){
		//neu s2 lon hon s1 thi ta doi cho 2 so va danh dau tru
		sign = 1;
		swap(s1, s2);
	}
	else sign = 0; //nguoc lai khong doi va danh dau cong

	TheSameLength(s1, s2);
	int l = s1.length();

	for (int i = l - 1; i >= 0; i--){
		if (s1[i] < s2[i]){
			temp = StringToNum(s1[i]) + 10 - StringToNum(s2[i]) - temp;//muon 1 de tru
			result.insert(0, 1, NumToString(temp));
			temp = 1;//nho 1
		}
		else{
			temp = StringToNum(s1[i]) - StringToNum(s2[i]) - temp; //tru binh thuong
			result.insert(0, 1, NumToString(temp));
			temp = 0;
		}
	}
	while ((result[0] == '0') && (result.length() > 1)) result.erase(0, 1);
	if (sign == 1) result.insert(0, 1, '-');
	return result;
}

string MultiplyWithSmallNum(string s1, int n){
	//gan giong voi phep cong, nhan roi cong lai
	string result;
	int temp = 0;
	int l = s1.length();
	for (int i = l - 1; i >= 0; i--){
		temp = n*StringToNum(s1[i]) + temp;
		result.insert(0, 1, NumToString(temp % 10));
		temp = temp / 10;
	}
	if (temp > 0) result.insert(0, 1, NumToString(temp));
	while ((result[0] == '0') && (result.length() > 1)) result.erase(0, 1);
	return result;
}

string MultiplyWithBigNum(string s1, string s2){
	int j = 0;
	int l = s2.length();
	string result;
	for (int i = l - 1; i >= 0; i--){
		string temp = MultiplyWithSmallNum(s1, StringToNum(s2[i])); //tinh tung so cua s2 nhan voi ca chuoi s1
		temp.insert(temp.length(), j, '0'); //them so j lan so 0 vao cuoi chuoi moi lan tinh de duoc cai thap
		result = Plus(result, temp); //cong lai
		j++;
	}
	while ((result[0] == '0') && (result.length() > 1)) result.erase(0, 1);
	return result;
}

//string Division(string s1, string s2){
//	string result;
//	string temp;
//	char pos;
//	int l1 = s1.length();
//	int l2 = s2.length();
//
//	if (s2 == "0") return "Syntax Error!";
//	if (l1 < l2) return "0";
//	for (int i = 0; i < l1; i++){
//		pos = s1[i];
//		temp.insert(temp.length(), 1, pos);
//		if (CompareUnsignedInt(temp, s2) == -1) result = "1";
//		else if (CompareUnsignedInt(temp, s2) == 1){
//			for (int j = 1; j < 10; j++){
//				if (CompareUnsignedInt(temp, MultiplyWithSmallNum(s2, j)) == 1){
//					result.insert(result.length(), 1, j - 1);
//					temp = Minus(temp, MultiplyWithSmallNum(s2, j - 1));
//					break;
//				}
//			}
//		}
//		else result.insert(result.length(), 1, '0');
//	}
//	return result;
//}

void TheSameLength(string &s1, string &s2){//Ham lam cho do dai 2 chuoi bang chuoibang nhau bang cach them so khong vao dau
	int l1 = s1.length(), l2 = s2.length();
	if (l1 > l2){ //neu l1 > l2 thi them (l1-l2) so 0 vao dau chuoi s2
		for (int i = l2; i < l1; i++){
			s2.insert(0, 1, '0');
		}
	}
	else{
		for (int i = l1; i < l2; i++){ //nguoc lai
			s1.insert(0, 1, '0');
		}
	}
}

string Modulo(string s1, string s2){
	string result;
	result = Minus(s1, MultiplyWithBigNum(s2, Division(s1, s2))); //phan du se bang s1 - s2*(s1/s2))
	return result;
}

string Division(string s1, string s2){
	string result;
	string temp;
	int l1 = s1.length();
	int l2 = s2.length();

	if (s2 == "0") return "Syntax Error!"; //TH mau bang 0
	if (l1 < l2) return "0"; //TH so bi chia co do dai nho hon so chia thi tra ra 0
	for (int i = 0; i < l1; i++){ //xet tu trai sang phai
		if (temp[0] == '0'){ //neu temp = 0 thi xoa temp va them so ke tiep vao temp
			temp.erase(0, 1);
			temp.insert(0, 1, s1[i]);
		}
		else temp.insert(temp.length(), 1, s1[i]); //khong thi them so ke tiep vao temp
		if (CompareUnsignedInt(temp, s2) == 1){ //neu temp lon hon hoac bang s2 thi xet tiep
			for (int j = 1; j < 10; j++){ //duyet vong for nhan temp voi j de tim so gan nhat nho hon temp va chia het cho s2
				if (CompareUnsignedInt(temp, MultiplyWithSmallNum(s2, j)) == 0){ //neu temp < s2*j thi ngung
					result.insert(result.length(), 1, NumToString(j - 1)); //tim duoc temp/s2 thi luu vao result
					temp = Minus(temp, MultiplyWithSmallNum(s2, j - 1)); //temp = temp%(s2*j), tuc la phan du
					break;
				}
			}
		}
		else result.insert(result.length(), 1, '0'); //neu temp<s2 thi luu 0 vao insert
	}
	while ((result[0] == '0') && (result.length() > 1)) result.erase(0, 1);
	return result;
}