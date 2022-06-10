#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
int delta(int n)//一行n个像素，最后补几个字节
{
	return n % 4 ? 4 - ((n * 3) % 4) : 0;
}
int main(int argc, char* argv[])
{
	if (argc != 3)
		cout << "文件读取错误\n";
	ifstream is(argv[1], ios::in | ios::binary);
	if (!is)
		cout << "源文件读取错误\n";
	ofstream os(argv[2], ios::out | ios::binary);
	tagBITMAPFILEHEADER fileh;
	tagBITMAPINFOHEADER infoh;
	is.read((char*)&fileh, sizeof(tagBITMAPFILEHEADER));
	is.read((char*)&infoh, sizeof(tagBITMAPINFOHEADER));
	swap(infoh.biWidth, infoh.biHeight);
	swap(infoh.biXPelsPerMeter, infoh.biYPelsPerMeter);
	os.write((char*)&fileh, sizeof(tagBITMAPFILEHEADER));
	os.write((char*)&infoh, sizeof(tagBITMAPINFOHEADER));
	int h = infoh.biHeight, w = infoh.biWidth;
	int isDelta = delta(h);
	RGBTRIPLE* EmptyBlue = new RGBTRIPLE[w * h];
	for (int i = 0; i < w; i++){//读入每个像素
		is.read((char*)EmptyBlue + i * h * 3, h * 3);
		is.seekg(isDelta, ios::cur);
	}
	int osDelta = delta(w);
	char* empty = new char[osDelta];
	for (int i = 0; i < osDelta; i++)
		empty[i] = 0;
	for (int i = h - 1; i >= 0; i--){
		for (int j = 0; j < w; j++)
			os.write((char*)(EmptyBlue + j * h + i), sizeof(RGBTRIPLE));
		os.write(empty, osDelta);
	}
	is.close();
	os.close();
	cout << "旋转成功\n";
	return 0;
}
