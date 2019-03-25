#include"XuLyFile.h"

void XuLyFileQInt(string &fileNameInput, string &fileNameOutput)
{
	ifstream fileIn;
	fileIn.open(fileNameInput, ios_base::in);
	ofstream fileOut;
	fileOut.open(fileNameOutput, ios_base::out);
	string p1, p2, p3, p4;
	if (fileIn.fail() == true)
	{
		cout << "Khong the mo file " << endl;
		return;
	}
	while (fileIn.eof() == false)
	{
		getline(fileIn, p1, ' ');
		getline(fileIn, p2, ' ');
		getline(fileIn, p3, '\n');
		
		//xử lý chuỗi p3 
		if (p3[0] != '1' && p3[0] != '2' && p3[0] != '3' && p3[0] != '4' && p3[0] != '5' &&
			p3[0] != '6' && p3[0] != '7' && p3[0] != '8' && p3[0] != '9' && p3[0] != 'A' &&
			p3[0] != 'B' && p3[0] != 'C' && p3[0] != 'D' && p3[0] != 'E' && p3[0] != 'F')
			//nếu bắt đầu chuỗi không phải là số =>phép tính toán 2 ngôi
		{
			if (p3[1] == ' ')
			{
				p4 = p3;
				string temp;
				temp.push_back(p3[0]);
				p3 = temp;
				p4.erase(p4.begin());
				p4.erase(p4.begin());
			}
			else if (p3[2] == ' ')	//dấu == >= <= >> <<
			{
				p4 = p3;
				string temp;
				temp.push_back(p3[0]);
				temp.push_back(p3[1]);
				p3 = temp;
				p4.erase(p4.begin());
				p4.erase(p4.begin());
				p4.erase(p4.begin());
			}
			else if (p3[3] == ' ')	//ror, rol
			{
				p4 = p3;
				string temp;
				temp.push_back(p3[0]);
				temp.push_back(p3[1]);
				temp.push_back(p3[2]);
				p3 = temp;
				p4.erase(p4.begin());
				p4.erase(p4.begin());
				p4.erase(p4.begin());
				p4.erase(p4.begin());
			}
		}
		//nếu là các phép tính toán
		if (p3 == "+" || p3 == "-" || p3 == "*" || p3 == "/" || p3==">" || p3 == "<" ||
			p3 == "==" || p3 == ">=" || p3 == "<=" || p3 == "&" || p3 == "|" || p3 == "^" ||
			p3 == "ROR" || p3 == "ror" || p3 == "ROL" || p3 == "rol" || p3==">>" || p3=="<<")
		{
			XuLyToanTuHaiNgoi(fileIn, fileOut, p1, p2, p3, p4);
		}
		//nếu là phép tính toán 1 ngôi ( toán tử not )
		else if (p2 == "~")
		{
			XuLyToanTuMotNgoi(fileIn, fileOut, p1, p2, p3);
		}
		else  //nếu là phép chuyển đổi
		{
			XuLyChuyenDoi(fileIn, fileOut, p1, p2, p3);
		}
	}
	fileIn.close();
	fileOut.close();
}

void XuLyToanTuMotNgoi(ifstream & fileIn, ofstream & fileOut, string p1, string p2, string p3)
{
	QINT a;
	if (p1 == "2")
	{
		string bin;
		a.BinToDec_String(p3);
		a = ~a;
		bin = a.DecToBin_String(a);
		fileOut << bin << endl;
	}
	else if (p1 == "16")
	{
		string hex, bin;
		bin = HexToBin(p3);
		a.BinToDec_String(bin);
		a = ~a;
		bin = a.DecToBin_String(a);
		hex = BinToHex(bin);
		fileOut << hex << endl;
	}
	else if (p1 == "10")
	{
		string dec;
		a.ConvertDecToData(p3);
		a = ~a;
		dec = a.ConvertDataToDec();
		fileOut << dec << endl;
	}
}

void XuLyToanTuHaiNgoi(ifstream & fileIn, ofstream & fileOut, string p1, string p2, string p3, string p4)
{
	QINT a, b, c;
	if (p1 == "2")
	{
		a.BinToDec_String(p2);
		b.BinToDec_String(p4);
		if (p3 == "+")
			c = a + b;
		else if (p3 == "-")
			c = a - b;
		else if (p3 == "*")
			c = a * b;
		else if (p3 == "/")
			c = a / b;
		else if (p3 == "<")
		{
			if (a < b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == ">")
		{
			if (a > b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "==")
		{
			if (a == b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == ">=")
		{
			if (a >= b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "<=")
		{
			if (a <= b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "&")
			c = a & b;
		else if (p3 == "|")
			c = a | b;
		else if (p3 == "^")
			c = a ^ b;
		else if (p3 == ">>")
		{
			b.ConvertDecToData(p4);
			c = a >> b;
		}
		else if (p3 == "<<")
		{
			b.ConvertDecToData(p4);
			c = a << b;
		}
		else if (p3 == "ror" || p3 == "ROR")
		{
			b.ConvertDecToData(p4);
			c = a.ROR(b);
		}
		else if (p3 == "rol" || p3 == "ROL")
		{
			b.ConvertDecToData(p4);
			c = a.ROL(b);
		}
		string bin;
		bin = c.DecToBin_String(c);
		fileOut << bin << endl;
	}
	else if (p1 == "16")
	{
		string hex;
		string bin1, bin2, bin;
		bin1 = HexToBin(p2);
		bin2 = HexToBin(p4);
		a.BinToDec_String(bin1);
		b.BinToDec_String(bin2);
		if (p3 == "+")
			c = a + b;
		else if (p3 == "-")
			c = a - b;
		else if (p3 == "*")
			c = a * b;
		else if (p3 == "/")
			c = a / b;
		else if (p3 == ">")
		{
			if (a > b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "<")
		{
			if (a < b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "==")
		{
			if (a == b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == ">=")
		{
			if (a >= b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "<=")
		{
			if (a <= b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "&")
			c = a & b;
		else if (p3 == "|")
			c = a | b;
		else if (p3 == "^")
			c = a ^ b;
		else if (p3 == ">>")
			c = a >> b;
		else if (p3 == "<<")
			c = a << b;
		else if (p3 == "ror" || p3 == "ROR")
			c = a.ROR(b);
		else if (p3 == "rol" || p3 == "ROL")
			c = a.ROL(b);
		bin = c.DecToBin_String(c);
		hex = c.BinToHex_String(bin);
		fileOut << hex << endl;
	}
	else if (p1 == "10")
	{
		a.ConvertDecToData(p2);
		b.ConvertDecToData(p4);
		if (p3 == "+")
			c = a + b;
		else if (p3 == "-")
			c = a - b;
		else if (p3 == "*")
			c = a * b;
		else if (p3 == "/")
			c = a / b;
		else if (p3 == ">")
		{
			if (a > b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "<")
		{
			if (a < b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "==")
		{
			if (a == b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == ">=")
		{
			if (a >= b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "<=")
		{
			if (a <= b)
				c.ConvertDecToData("1");
			else
				c.ConvertDecToData("0");
		}
		else if (p3 == "&")
			c = a & b;
		else if (p3 == "|")
			c = a | b;
		else if (p3 == "^")
			c = a ^ b;
		else if (p3 == ">>")
			c = a >> b;
		else if (p3 == "<<")
			c = a << b;
		else if (p3 == "ror" || p3 == "ROR")
			c = a.ROR(b);
		else if (p3 == "rol" || p3 == "ROL")
			c = a.ROL(b);
		string numberDec;
		numberDec = c.ConvertDataToDec();
		fileOut << numberDec << endl;
	}
}

void XuLyChuyenDoi(ifstream & fileIn, ofstream & fileOut, string p1, string p2, string p3)
{
	QINT a;
	if (p1 == "2")
	{
		if (p2 == "10")
		{
			string dec;
			a.BinToDec_String(p3);
			dec = a.ConvertDataToDec();
			fileOut << dec << endl;
		}
		else if (p2 == "16")
		{
			string hex;
			hex=a.BinToHex_String(p3);
			fileOut << hex << endl;
		}
	}
	else if (p1 == "10")
	{
		if (p2 == "2")
		{
			string bin;
			a.ConvertDecToData(p3);
			bin = a.DecToBin_String(a);
			fileOut << bin << endl;
		}
		else if (p2 == "16")
		{
			string hex;
			a.ConvertDecToData(p3);
			hex = a.DecToHex_String(a);
			fileOut << hex << endl;
		}
	}
	else if (p1 == "16")
	{
		if (p2 == "2")
		{
			string bin;
			bin = HexToBin(p3);
			fileOut << bin << endl;
		}
		else if (p2 == "10")
		{
			string bin;
			bin = HexToBin(p3);
			a.BinToDec_String(bin);
			string dec;
			dec = a.ConvertDataToDec();
			fileOut << dec << endl;
		}
	}
}

void XuLyFileQFloat(string fileNameInput, string fileNameOutput)
{
	ifstream fileIn;
	ofstream fileOut;
	fileIn.open(fileNameInput, ios_base::in);
	fileOut.open(fileNameOutput, ios_base::out);
	//
	if (fileIn.fail() == true)
	{
		cout << "Khong the mo file " << endl;
		return;
	}
	//
	QFLOAT a;
	string p1, p2, p3;
	while (fileIn.eof() == false)
	{
		getline(fileIn, p1, ' ');
		getline(fileIn, p2, ' ');
		getline(fileIn, p3, '\n');
		if (p1 == "2" && p2 == "10")	//chuyển từ hệ 2 sang hệ 10
		{
			a.BinToDec_String(p3);
			fileOut << a.GetQFloat() << endl;
		}
		else if (p1 == "10" && p2 == "2")	//chuyển từ hệ 10 sang hệ 2
		{
			string bin = a.GetBin(p3);
			fileOut << bin << endl;
		}
	}
	fileIn.close();
	fileOut.close();
}



