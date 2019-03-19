#include"QInt.h"
#include"ThuVien.h"

int main()
{
	QINT n1, n2, n3;
	n1.ScanQInt();
	//n2 = n1 << 64;
	//n2.PrintQInt();
	n2.ScanQInt();
	n1.ROL(2147483545).PrintQInt();
	n1.ROR(-2147483545).PrintQInt();
	n1.ROL(n2).PrintQInt();
	n1.ROR(n3.BinToDec(string(128,'0')) - n2).PrintQInt();
	//(n3 >> n2).PrintQInt();
	//n3.PrintQInt();
	//system("pause");
	return 0;
}