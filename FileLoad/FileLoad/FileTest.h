#pragma once
#include<string>

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
