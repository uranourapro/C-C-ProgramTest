#include"KentaSample.h"
#include"KentaFile.h"


void Sample1() {
	Test::Write("書き込み完了");
	getchar();

	Test::Read();
	getchar();
}


void Sample2() {
	Test::Delete();
}


void Sample3() {
	FileControl txt1;

	while (true) {
		txt1.AddWrite();
		txt1.Read();
	}
}