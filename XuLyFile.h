#include"QFloat.h"
#include"QInt.h"
#include"ThuVien.h"
#include<fstream>

void XuLyToanTuMotNgoi(ifstream &fileIn, ofstream &fileOut,
	string p1, string p2, string p3);
void XuLyToanTuHaiNgoi(ifstream &fileIn, ofstream &fileOut,
	string p1, string p2, string p3, string p4);
void XuLyChuyenDoi(ifstream &fileIn, ofstream &fileOut,
	string p1, string p2, string p3);
void XuLyFileQInt(string &fileNameInput, string &fileNameOutput);
//
void XuLyFileQFloat(string fileNameInput, string fileNameOutput);
