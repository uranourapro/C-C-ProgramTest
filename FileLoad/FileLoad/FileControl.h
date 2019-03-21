#pragma once
#include<iostream>
#include<map>


/*
	ファイル制御クラス
	インスタンス生成時にファイルの
	名前を設定する
*/


class FileControl {
public:
	FileControl(std::string ext = ".txt");
	//ファイル書き出し
	void Print();
	//ファイル書き込み
	void AddWrite();
	//設定
	bool SetInputFileName(int challenge_num = 1);
	bool SetInputFileName(std::string file_extension, int challenge_num = 1);
	//安全保障（ファイル存在確認）
	void OpenTest();

private:
	std::string text_name;			//ファイル名
	std::string file_extension_name;//ファイル拡張子名
};



