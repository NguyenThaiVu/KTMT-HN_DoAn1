#include"XuLyFile.h"

int main()
{
	string fileNameInput, fileNameOutput;
	getline(cin >> ws, fileNameInput);
	getline(cin >> ws, fileNameOutput);
	int chon;
	cout << "=====THONG BAO=====" << endl;
	cout << "Neu xu ly file QINT, nhap 1" << endl;
	cout << "Neu xu ly file QFLOAT, nhap 2" << endl;
	while (1)
	{
		cin >> chon;
		if (chon == 1)
		{
			XuLyFileQInt(fileNameInput, fileNameOutput);
			break;
		}
		else if (chon == 2)
		{
			XuLyFileQFloat(fileNameInput, fileNameOutput);
			break;
		}
		else
			cout << "Nhap sai, moi nhap lai" << endl;
	}
	
	system("pause");
	return 0;
}