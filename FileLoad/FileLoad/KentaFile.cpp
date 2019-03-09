#include"KentaFile.h"
#include<fstream>
#include<string>

#define FN "test2.txt"


bool Test1() {//インプット入力読み込み
	std::ifstream ifs(FN);
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

bool Test2(std::string str) {//アウトプット出力書き込み
	std::ofstream ofs(FN, std::ios::app);

	ofs << str << "\n";//書き込み
	
	ofs.close();//終了

	return true;
}

void Test3() {//アウトプット
	std::ofstream ofs(FN, std::ios::app);
	std::string str;

	if (ofs.fail()) {
		std::cout << "ファイルが存在しなかったため、作成しました" << std::endl;
	}

	std::cout << "ファイルに書き込みたい文字を入力してください" << std::endl;

	std::cin >> str;//ユーザー入力

	ofs << str << "\n";//書き込み

	ofs.close();
}

void TestFileDelete() {
	std::ofstream ofs(FN, std::ios::trunc);
	
}

