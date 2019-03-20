#pragma once
#include<iostream>
#include<map>


namespace Test {
	//読み込み：ファイルに書いてある内容を表示する
	//ファイル作成はできない
	bool Read();

	//引数指定書き込み：引数で渡した内容をファイルに書き込む
	//ファイル作成できる
	bool Write(std::string str);

	//ユーザー書き込み：ユーザーが入力した内容をファイルに書き込む
	//ファイル作成できる
	void Write2();

	//消去：書き込まれているものを全て消去する
	//ファイル作成できる
	void Delete();
}

enum DataList {
	Data1,
	Data2,
	Data3,
	Data4,
	Data5,
	TotalData
};

/*
	ファイル制御クラス
	インスタンス生成時にファイルの
	名前を設定する
*/


class FileControl {
public:
	FileControl(std::string ext = ".txt");
	//ファイル書き出し
	void Read();
	//ファイル書き込み
	void AddWrite();
	//設定
	bool SetFileName(int challenge_num = 1);
	bool SetFileName(std::string file_extension, int challenge_num = 1);
	//安全保障（ファイル存在確認）
	void OpenTest();

private:
	std::string text_name;			//ファイル名
	std::string file_extension_name;//ファイル拡張子名
};



/*
	データ保存クラス
	内容はまだ未定
*/

class FileData;//前方参照

class FileLoader {
public:
	std::map<FileData, int> f_data;
	bool SetNewData(int data);//作りたいデータ番号

private:


};

class FileData {
public:
	FileData(int data);

private:
	int data_num;
	int data_list[TotalData];

};