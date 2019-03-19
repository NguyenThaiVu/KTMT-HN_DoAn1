#include"QInt.h"
#include"ThuVien.h"

int main()
{
	QINT n, n1, n2;
	n1.ScanQInt();
	//n2 = n1 << 64;
	//n2.PrintQInt();
	n2.ScanQInt();
	//n2.PrintQInt();
	n = n1&n2;
	n.PrintQInt();
	//system("pause");
	return 0;
}