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
//új feladat, hogy kicsirõl nagyra is tudja cserélni!
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
				//AZ ELEJE ÉS A VÉGE NAGYON FONTOS ÉS NECCES!
				if (response == 'Y' || response == 'y') {
					csere(szoveg, elozoszovege, i);
				}
			}
			//karbantartás, találtam egy új szót, akkor az aktuális helyre kell ezt a változót dobni, vagy fogja magát és kiírogatja az eddigieket
			elozoszovege = i;
		}
	}
	
	std::cout << szoveg;

	return 0;
}