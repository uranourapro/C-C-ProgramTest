#include"FileTest.h"
#include<iostream>
#include<fstream>

//関数ベースのファイル読み込み練習

namespace Test {

	const std::string FileName = "test.txt";//namespace Testで使用するテキストファイルの名前

	bool Read() {//インプット入力読み込み
		std::ifstream ifs(FileName);
		std::string str;

		if (ifs.fail()) {
			std::cout << "ファイルの読み込みに失敗しました" << std::endl;
			return false;
		}

		while (std::getline(ifs, str)) {
			std::cout << str << std::endl;
		}

		return true;

	}

	bool Write(std::string str) {//アウトプット出力書き込み
		std::ofstream ofs(FileName, std::ios::app);

		ofs << str << "\n";//書き込み

		ofs.close();//終了

		return true;

	}

	void Write2() {//アウトプット
		std::ofstream ofs(FileName, std::ios::app);
		std::string str;

		if (ofs.fail()) {
			std::cout << "ファイルが存在しなかったため、作成しました" << std::endl;
		}

		std::cout << "ファイルに書き込みたい文字を入力してください" << std::endl;

		std::cin >> str;//ユーザー入力

		ofs << str << "\n";//書き込み

		ofs.close();

	}

	void Delete() {
		std::ofstream ofs(FileName, std::ios::trunc);

	}
}
