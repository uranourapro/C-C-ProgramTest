#include"KentaFile.h"
#include<fstream>
#include<string>


namespace {

	#define FN "test.txt"//namespace Testで使用するテキストファイルの名前

	//文字列の後ろから文字を抜き出す関数
	//posが何番目か lenが抜き出す長さ
	std::string SubstrBack(std::string str, int pos, int len) {
		const int length = str.length();
		return str.substr(length - pos, len);
	}
}

//-----------------------------------------------------------------------------------

namespace Test {

	bool Read() {//インプット入力読み込み
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

	bool Write(std::string str) {//アウトプット出力書き込み
		std::ofstream ofs(FN, std::ios::app);

		ofs << str << "\n";//書き込み

		ofs.close();//終了

		return true;

	}

	void Write2() {//アウトプット
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

	void Delete() {
		std::ofstream ofs(FN, std::ios::trunc);

	}
}


//-----------------------------------------------------------------------------------
//TextTestクラスのメンバ関数
//-----------------------------------------------------------------------------------



//	[コンストラクタ]
//	引数①：使用する拡張子（デフォルト引数 = .txt）

FileControl::FileControl(std::string ext) {

	while (!SetFileName(ext, 5)) {
		std::cout << "警告：有効なファイル名を入力してください\n" << std::endl;
	}

	//ファイルが存在するかどうかのテスト
	OpenTest();

	//テキストの内容を表示する
	Read();

}


//	[ファイルの内容表示]
//	ファイルの中身を全て表示する
//	※ファイル読み込みに失敗した場合、再設定をしてくれる

void FileControl::Read() {

	std::ifstream ifs(text_name);

	if (ifs.fail()) {
		std::cout << "ファイルの読み込みに失敗しました\n\n" << 
			"登録されたファイルが削除されてしまった恐れがあります\n\n" <<
			"再設定を行います\n"<<std::endl;

		while (!SetFileName(100));//再設定

		std::cout << "設定を終了します\n結果：成功\n" << std::endl;
	}

	std::string str;

	std::cout << "*設定されているファイルの読み込み*\n" << std::endl;

	while (std::getline(ifs, str)) {//表示
		std::cout << str << std::endl;
	}

	std::cout << "\n" << std::endl;//改行を二回

}


//	[ファイル書き込み]
//	書き込みたいものを入力すると、
//	ファイルの新しい行に書き込まれる

void FileControl::AddWrite() {

	std::cout << "\n書き込みたいものを入力してください" << std::endl;

	std::ofstream ofs(text_name, std::ios::app);
	
	std::string str;

	std::cin >> str;

	ofs << str << std::endl;

	std::cout << std::endl;

}


//	[ファイル名の再設定]
//	引数①：入力(設定)可能回数（デフォルト引数 = 1）

bool FileControl::SetFileName(int challenge_num) {

	return SetFileName(file_extension_name, challenge_num);

}


//	[ファイル名の再設定]
//	引数①：使用する拡張子
//	引数②：入力(設定)可能回数（デフォルト引数 = 1）

bool FileControl::SetFileName(std::string file_extension,int challenge_num) {

	//拡張子を設定　以降、再設定が無い限り、この拡張子のファイルを管理する
	file_extension_name = file_extension;

	std::cout << "使用するファイル名を入力してください\n拡張子："<< file_extension_name << std::endl;

	std::string str;

	for (int i = 0;i < challenge_num;++i) {

		std::cin >> str;//入力

		int file_ext_len = file_extension.length();//入力したファイル名の長さを変数に入れる

		if (str.length() >= file_ext_len) {//指定した拡張子より長ければひとまずオッケー

			std::string ext = SubstrBack(str, file_ext_len, file_ext_len);

			if (ext == file_extension) {

				text_name = str;//ファイル名保存

				std::cout << "\n設定を終了します\n結果：成功" << std::endl;

				return true;//成功
			}
		}
		std::cout << "設定に失敗しました\n残り入力可能回数" << challenge_num - (i + 1) << std::endl;
	}

	std::cout << "\n設定を終了します\n結果：失敗" << std::endl;
	return false;//失敗

}

//	[ファイルオープンチェック]
//	ファイルが存在しない場合、この関数で生成できる
//	呼び出すと、そのファイルの安全が保障される

void FileControl::OpenTest() {

	std::ifstream ifs(text_name);

	if (ifs.fail()) {
		//ファイルが存在しない
		std::ofstream ofs(text_name);

		std::cout << "設定したファイルが存在しなかったため、新しく生成しました" << std::endl;
	}

}


/*
	セーブ関係関数
	ゲームのセーブのようなものを作りたい
*/

bool FileLoader::SetNewData(int data) {
	

	return false;

}

FileData::FileData(int data) {


}
