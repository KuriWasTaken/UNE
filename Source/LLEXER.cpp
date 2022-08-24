#include <iostream>
#include <string>

int LLEX(std::string str) {

	int plank[10] = {};
	for (int i = 0; i < 10; i++)
		plank[i] = 0;

	int nailIndex = 0;
	bool nailPunched = false;
	int nailValue = 0;

	int plankLeft = 10;

	bool initializeedPlank = false;

	bool inLoop = false;
	int maxLoopIterations = 0;
	int currentLoopIteration = 0;
	std::string loopScript = "";


	for (int i = 0; i < (int)str.length(); i++) {
		if (plankLeft == 0) {
			initializeedPlank = false;
		}
		if (str[i] == *"=") {
			initializeedPlank = true;
			plankLeft = 10;
			for (int i = 0; i < 10; i++) {
				plank[i] = 0;
			}
			nailIndex = 0;
			nailValue = 0;
		}
		else if (initializeedPlank == true) {
			if (str[i] == *"+") {
				nailIndex += 1;
				plankLeft -= 1;
				nailValue = 0;
				//std::cout << plankLeft << std::endl;
			}
			else if (str[i] == *".") {
				nailValue += 1;
			}
			else if (str[i] == *",") {
				nailValue -= 1;
			}
			else if (str[i] == *"v") {
				plank[nailIndex] = nailValue;
			}
			else if (str[i] == *"p") {
				std::cout << char(plank[nailIndex]);
			}
			else if (str[i] == *"¤" ) {

				if (str[i + 1] == *"0") {
					maxLoopIterations = 0*10;
				}
				else if (str[i + 1] == *"1") {
					maxLoopIterations = 1 * 10;
				}
				else if (str[i + 1] == *"2") {
					maxLoopIterations = 2 * 10;
				}
				else if (str[i + 1] == *"3") {
					maxLoopIterations = 3 * 10;
				}
				else if (str[i + 1] == *"4") {
					maxLoopIterations = 4 * 10;
				}
				else if (str[i + 1] == *"5") {
					maxLoopIterations = 5 * 10;
				}
				else if (str[i + 1] == *"6") {
					maxLoopIterations = 6 * 10;
				}
				else if (str[i + 1] == *"7") {
					maxLoopIterations = 7 * 10;
				}
				else if (str[i + 1] == *"8") {
					maxLoopIterations = 8 * 10;
				}
				else if (str[i + 1] == *"9") {
					maxLoopIterations = 9 * 10;
				}
				//std::cout << maxLoopIterations << std::endl;
				int i2 = i+3;
				while (str[i2] != *"}") {
					loopScript += str[i2];
					i2 += 1;
				}
				for (int a = 0; a < maxLoopIterations-1; a++) {
					for (int b = 0; b < (int)loopScript.length(); b++) {
						if (loopScript[b] == *"+") {
							nailIndex += 1;
							plankLeft -= 1;
							nailValue = 0;
							//std::cout << plankLeft << std::endl;
						}
						else if (loopScript[b] == *".") {
							nailValue += 1;
						}
						else if (loopScript[b] == *",") {
							nailValue -= 1;
						}
						else if (loopScript[b] == *"v") {
							plank[nailIndex] = nailValue;
						}
						else if (loopScript[b] == *"p") {
							std::cout << char(plank[nailIndex]);
						}
					}
				}
				//nailValue = 0;
				maxLoopIterations = 0;
				currentLoopIteration = 0;
				loopScript = "";
			}
		}
	}
	return 0;
}
