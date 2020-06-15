#include "table.h"

int main() {
	int menu;
	ifstream in("save.txt");
	Table Game;
	Game.intf = 0;
	do {
		cout << "Game menu:" << endl;
		cout << "1. New Game" << endl;
		cout << "2. Load Game" << endl;
		cout << "3. Exit" << endl;
		cin >> menu;
		switch (menu) {
		case 1:
			Game.intf = 0;
			Game.can_white_castle_left = true;
			Game.can_white_castle_right = true;
			Game.can_black_castle_left = true;
			Game.can_black_castle_right = true;
			while (Game.intf != 1) {
				Game.DrowScreenPlayer();
				//cout<<"WL"<< Game.can_white_castle_left<<endl;
				//cout <<"WR"<< Game.can_white_castle_right<<endl;
				//cout << "BL" << Game.can_black_castle_left << endl;;
				//cout << "BR" << Game.can_black_castle_right << endl;;
				Game.EnterHod();
			}
			break;
		case 2:
			/*load game*/
			if (in.is_open()) {
				for (int row = 0; row<8; row++) {
					for (int col = 0; col<8; col++) {
						getline(in, Game.playe_field[row][col]);
					}
				}
			}
			in.close();
			Game.intf = 0;
			Game.can_white_castle_left = true;
			Game.can_white_castle_right = true;
			Game.can_black_castle_left = true;
			Game.can_black_castle_right = true;
			while (Game.intf != 1) {
				Game.DrowScreenPlayer();
				Game.EnterHod();
			}
			break;
		case 3:
			exit(0);
			break;
		default:
			system("cls");
			break;
		}

	} while (menu != 4);

	system("pause");
}