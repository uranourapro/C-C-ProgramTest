#pragma once
#include<map>

enum DataList {
	Data1,
	Data2,
	Data3,
	Data4,
	Data5,
	TotalData
};


/*
データ保存クラス
内容はまだ未定
*/

class FileData {
public:
	FileData(int data);

private:
	int data_num;
	int data_list[TotalData];

};

class FileLoader {
public:
	bool SetNewData(int data);//作りたいデータ番号

private:
	std::map<FileData&, int> f_data;

};

