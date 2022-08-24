#include <iostream>
#include <string>
#include <fstream>

#include "LLEXER.h"

inline bool fileExists(const std::string& name) {
	std::ifstream f(name.c_str());
	return f.good();
}

int main(int arg, char** argO) {
	bool fileOpend = false;
	std::string filePath = "";

	for (int i = 0; i < arg; i++) {
		std::string x = argO[i];
		if (x.find(".une") != std::string::npos) {
			if (fileExists(x)) {
				filePath = x;
				fileOpend = true;
			}
		}
	}
	if (fileOpend) {
		std::string code = "";
		std::ifstream file(filePath);
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				code += line.c_str();
			}
		}
		LLEX(code);
	}
	else {
		exit(3);
	}
}
