#include <iostream>
#include <string>


bool isCapital(const char karakter) {
	return (karakter >= 'A' && karakter <= 'Z');
}

bool isWhitespace(const char karakter) {
	return karakter == ' ' || karakter == '\t';
}

void csere(std::string& szoveg, const int mettol, const int meddig) {
	for (int i = mettol; i < meddig; i++) {
		if (isCapital(szoveg[i])) {
			szoveg[i] += 32;
		}
	}
}
//�j feladat, hogy kicsir�l nagyra is tudja cser�lni!
int main() {
	std::string szoveg;
	std::cout << "Kerem a hasznalni kivant szoveget: " << std::endl;
	std::getline(std::cin, szoveg);

	if (szoveg.empty()) {
		return 1;
	}
	int elozoszovege = 0;
	char response;
	szoveg.push_back(' ');
	for (int i = 0; i < szoveg.length(); i++) {
		if (isWhitespace(szoveg[i])) {
			if (i - elozoszovege != 1) {
				std::cout << "Szeretne a szot kisbetusre cserelni? " << szoveg.substr(elozoszovege == 0 ? 0 : elozoszovege +1, i - elozoszovege) << std::endl;
				std::cin >> response;
				//AZ ELEJE �S A V�GE NAGYON FONTOS �S NECCES!
				if (response == 'Y' || response == 'y') {
					csere(szoveg, elozoszovege, i);
				}
			}
			//karbantart�s, tal�ltam egy �j sz�t, akkor az aktu�lis helyre kell ezt a v�ltoz�t dobni, vagy fogja mag�t �s ki�rogatja az eddigieket
			elozoszovege = i;
		}
	}
	
	std::cout << szoveg;

	return 0;
}