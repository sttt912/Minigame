#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

class Table {
public:
	int x, y, x1, y1;
	int player = 0;
	int gamer = 0;
	int intf;
	/*на проході*/
	int pawn_attack_white_x = 10;
	int pawn_attack_white_y = 10;
	int pawn_attack_black_x = 10;
	int pawn_attack_black_y = 10;
	/*на проході*/
	string locals;

	/*Рокировка*/
	bool can_white_castle_left = true;
	bool can_white_castle_right = true;
	bool can_black_castle_left = true;
	bool can_black_castle_right = true;
	/*Рокировка*/

	char alfavit[8] = { 'a','b','c','d','e','f','g','h' };
	string playe_field[8][8] = {
		{ "WR","WN","WB","WQ","WK","WB","WN","WR" },
		{ "WP","WP","WP","WP","WP","WP","WP","WP" },
		{ "  ","  ","  ","  ","  ","  ","  ","  " },
		{ "  ","  ","  ","  ","  ","  ","  ","  " },
		{ "  ","  ","  ","  ","  ","  ","  ","  " },
		{ "  ","  ","  ","  ","  ","  ","  ","  " },
		{ "BP","BP","BP","BP","BP","BP","BP","BP" },
		{ "BR","BN","BB","BQ","BK","BB","BN","BR" }
	};

public:
	void DrowScreenPlayer(); //отрисовка игрового поля
	void EnterHod(); //ввод ходу
	void colorfig(); //перевірки кольору
	void movefig(); //робимо уведення ходу
	void validator(); //перевірки допустимих ходів
	void pawn(); //пешка
	void change(int status);
	void horse(); //horse
	void king();//king
	void queen(); //королева
	void rook();
	void bishop();
	bool on_map(int corx,int cory);
	void move(int x1, int y1); //рухаєм фігуру
	bool is_check(); //checmate
	/*рокировка*/
	//void fcan_white_castle_left();
	//void fcan_white_castle_right();
	//void fcan_black_castle_left();
	//void fcan_black_castle_right();
};

/*
void Table::fcan_white_castle_left() {
	if (playe_field[0][5] == "  " && playe_field[0][6] == "  ") {
		move(x1, y1);
	}
	
}

void Table::fcan_white_castle_right() {

	move(x1, y1);
}

void Table::fcan_black_castle_left() {

	move(x1, y1);
}

void Table::fcan_black_castle_right() {

	move(x1, y1);
}
*/
void Table::move(int x1, int y1) {
	playe_field[y][x] = "  ";
	playe_field[y1][x1] = locals;
	player++;
}

bool Table::is_check() {
	/*вивод тексту що фігура під шахом*/
	if (playe_field[y1][x1] == "WK") {
		cout << "Checkmate white" << endl;
		intf = 1;
		ifstream in("new.txt");
		if (in.is_open()) {
			for (int row = 0; row<8; row++) {
				for (int col = 0; col<8; col++) {
					getline(in, playe_field[row][col]);
				}
			}
		}
		in.close();
		return false;
	}

	if (playe_field[y1][x1] == "BK") {
		cout << "Checkmate black" << endl;
		intf = 1;
		ifstream in("save.txt");
		if (in.is_open()) {
			for (int row = 0; row<8; row++) {
				for (int col = 0; col<8; col++) {
					getline(in, playe_field[row][col]);
				}
			}
		}
		in.close();
		return false;
	}
	/*Фігура під шахом*/
	return true;
}

void Table::queen() {
	if (playe_field[y][x][1] == 'Q') {
		int sx = x;
		int sy = y;
		int dx = x1;
		int dy = y1;

		int delta_x = 0;
		int delta_y = 0;

		if (dx > sx) {
			delta_x++;
		}
		if (dx < sx) {
			delta_x--;
		}
		if (dy > sy) {
			delta_y++;
		}
		if (dy < sy) {
			delta_y--;
		}

		//if (abs(delta_x) + abs(delta_y) == 0) {
			do {
				sx += delta_x;
				sy += delta_y;
				if (!on_map(sx, sy)) {
					break;
				}
				if (sx == dx && sy == dy && playe_field[y1][x1][0] != 'W' && gamer == 0) {
					if (is_check()) {
						move(x1, y1);
						break;
					}
					else {
						break;
					}
				}
				if (sx == dx && sy == dy && playe_field[y1][x1][0] != 'B' && gamer == 1) {
					if (is_check()) {
						move(x1, y1);
						break;
					}
					else {
						break;
					}
				}

				if (playe_field[sy][sx] != "  ") {
					break;
				}
			} while (on_map(sx, sy));
		//}
	}
}

void Table::bishop() {
	if (playe_field[y][x][1] == 'B') {
		int sx = x;
		int sy = y;
		int dx = x1;
		int dy = y1;

		int delta_x = 0;
		int delta_y = 0;

		if (dx > sx) {
			delta_x++;
		}
		if (dx < sx) {
			delta_x--;
		}
		if (dy > sy) {
			delta_y++;
		}
		if (dy < sy) {
			delta_y--;
		}

		if (abs(delta_x) + abs(delta_y) == 2) {
			do {
				sx += delta_x;
				sy += delta_y;
				if (!on_map(sx, sy)) {
					break;
				}
				if (sx == dx && sy == dy && playe_field[y1][x1][0] != 'W' && gamer == 0) {
					if (is_check()) {
						move(x1, y1);
						break;
					}
					else {
						break;
					}
				}
				if (sx == dx && sy == dy && playe_field[y1][x1][0] != 'B' && gamer == 1) {
					if (is_check()) {
						move(x1, y1);
						break;
					}
					else {
						break;
					}
				}
				if (playe_field[sy][sx] != "  ") {
					break;
				}
			} while (on_map(sx, sy));
		}
	}
}

bool Table::on_map(int corx, int cory) {
	return (corx>=0 && corx<=7 && cory >= 0 && cory <= 7);
}

void Table::rook() {
	if (playe_field[y][x][1] == 'R') {
		int sx = x;
		int sy = y;
		int dx = x1;
		int dy = y1;

		int delta_x = 0;
		int delta_y = 0;

		if (dx > sx) {
			delta_x++;
		}
		if (dx < sx) {
			delta_x--;
		}
		if (dy > sy) {
			delta_y++;
		}
		if (dy < sy) {
			delta_y--;
		}

		if (abs(delta_x) + abs(delta_y) == 1) {
			do {
				sx += delta_x;
				sy += delta_y;
				if (!on_map(sx,sy)) {
					break;
				}
				if (sx == dx && sy == dy && playe_field[y1][x1][0] != 'W' && gamer == 0) {
					if (is_check()) {
						move(x1, y1);
						/*Рокировка*/
						if (x==0 && y==0) { //лево
							can_white_castle_left = false;
						}
						if (x == 7 && y == 0) {//право
							can_white_castle_right = false;
						}
						/*Рокировка*/
						break;
					}
					else {
						break;
					}
				}
				if (sx == dx && sy == dy && playe_field[y1][x1][0] != 'B' && gamer == 1) {
					if (is_check()) {
						move(x1, y1);
						/*Рокировка*/
						if (x == 0 && y == 7) { //лево
							can_black_castle_left = false;
						}
						if (x == 7 && y == 7) {//право
							can_black_castle_right = false;
						}
						/*Рокировка*/
						break;
					}
					else {
						break;
					}
				}
				if (playe_field[sy][sx] != "  ") {
					break;
				}

			} while (on_map(sx, sy));
		}
	}

}

void Table::king(){
	if (playe_field[y][x][1] == 'K') {
		//if (x1 == x + 1 || x1 == x - 1 || y1 == y + 1 || y1 == y - 1) {
		if (abs(x1-x)<=1 && abs(y1-y)<=1){
			if (playe_field[y1][x1][0] != 'W' && gamer==0) {
				move(x1, y1);
				/*Рокировка*/
				can_white_castle_left = false;
				can_white_castle_right = false;
				/*Рокировка*/
			}else if (playe_field[y1][x1][0] != 'B' && gamer == 1) {
				move(x1, y1);
				/*Рокировка*/
				can_black_castle_left = false;
			    can_black_castle_right = false;
				/*Рокировка*/
			}
		}
		/*Рокировка*/
		//if (abs(x1 - x) == 2) { //жовжина два хода
			//if (x==4) { //король не двигався x
				if (y==0 && playe_field[y][x][0] == 'W' && playe_field[y1][x1] == "  ") {//
					if (x == 4 && y == 0 && x1 == 6 && y1 == 0) {
						move(x1, y1);
					}
					if (x == 4 && y == 0 && x1 == 2 && y1 == 0) {
						move(x1, y1);
					}
					//move(x1, y1);
				}
				if (y == 7 && playe_field[y][x][0] == 'B' && playe_field[y1][x1] == "  ") {//
					if (x == 4 && y == 7 && x1 == 6 && y1 == 7) {
						move(x1, y1);
					}
					if (x == 4 && y == 7 && x1 == 2 && y1 == 7) {
						move(x1, y1);
					}
					//move(x1, y1);
				}
			}
		}
		/*Рокировка*/
	//}
//}

void Table::horse() {
	if (playe_field[y][x][1] == 'N') {
		if ((x1 == x - 1 && y1 == y + 2) || (x1 == x + 1 && y1 == y - 2) || (x1 == x - 1 && y1 == y - 2) || (x1 == x + 1 && y1 == y + 2)||
			(x1 == x +2 && y1 == y - 2) || (x1 == x - 2 && y1 == y + 1) || (x1 == x - 2 && y1 == y - 1) || (x1 == x + 2 && y1 == y + 1)
			) {
			if (playe_field[y1][x1][0] != 'W' && gamer == 0) {
				move(x1, y1);
			}
			else if (playe_field[y1][x1][0] != 'B' && gamer == 1) {
				move(x1, y1);
			}
		}
	}
}
void Table::pawn() {
	/*Ловим на проході*/
	int sx = x;
	int sy = y;
	int dx = x1;
	int dy = y1;
	/*Ловим на проході*/


	if (playe_field[y][x] == "WP") { 
		if (x1 == x && y1 == y + 2 && playe_field[y + 1][x] == "  " && y==1) { //ход на два хода вперед (перший хід)
			move(x1, y1);
			pawn_attack_white_x = x1;
			pawn_attack_white_y = y1-1;
		}else if (x1 == x && y1 == y + 1 && playe_field[y + 1][x] == "  ") { //на один хід
			move(x1, y1);
			//обнуляем на проході
			pawn_attack_white_x = 10;
			pawn_attack_white_y = 10;
		}
		else if (playe_field[y + 1][x + 1][0] == 'B' || playe_field[y + 1][x - 1][0] == 'B') { //взяття
			if (playe_field[y1][x1] == "  ") {
				cout << "Invalid enter";
			}
			else if (playe_field[y1][x1] == "  ") {
				cout << "Invalid enter";
			}
			else {
				move(x1, y1);
				pawn_attack_white_x = 10;
				pawn_attack_white_y = 10;
			}
		}
		/*на проході*/
		if (dx == pawn_attack_black_x && dy == pawn_attack_black_y) {
			if (sy == 4) {
				if (abs(sx - dx) == 1 && abs(sy - dy)) {
					playe_field[dy - 1][dx] = "  ";
					move(dx, dy);
				}
			}
		}
		/*на проході*/
		change(7); //виконуєм "мрію білої пішки"
	}
	if (playe_field[y][x] == "BP") {
		if (x1 == x && y1 == y - 2 && playe_field[y - 1][x] == "  " && y==6) {
			move(x1, y1);
			pawn_attack_black_x = x1;
			pawn_attack_black_y = y1 + 1;
		}else if (x1 == x && y1 == y - 1 && playe_field[y - 1][x] == "  ") {
			move(x1, y1);
			pawn_attack_black_x = 10;
			pawn_attack_black_y = 10;
		}
		else if (playe_field[y + 1][x - 1][0] == 'W' || playe_field[y - 1][x - 1][0] == 'W') {
			if (playe_field[y1][x1] == "  ") {
				cout << "Invalid enter";
			}
			else if (playe_field[y1][x1] == "  ") {
				cout << "Invalid enter";
			}
			else {
				move(x1, y1);
				pawn_attack_black_x = 10;
				pawn_attack_black_y = 10;
			}
		}
		/*на проході*/
		if (dx == pawn_attack_white_x && dy == pawn_attack_white_y) {
			if (sy == 3) {
				if (abs(sx - dx) == 1 && abs(sy - dy)) {
					playe_field[dy+1][dx] = "  ";
					move(dx, dy);
				}
			}
		}
		change(0); //виконуєм "мрію чорної пішки"
	}
}

void Table::change(int status) {
	if (y1==status) {
		int n;
		cout << "Enter new figure" << endl;
		cout << "1 - Queen" << endl;
		cout << "2 - Horse" << endl;
		cout << "3 - Rook" << endl;
		cout << "4 - Bishop" << endl;
		cin >> n;
		if (n==1) {
			playe_field[y1][x1][1] = 'Q';
		}
		if (n == 2) {
			playe_field[y1][x1][1] = 'N';
		}
		if (n == 3) {
			playe_field[y1][x1][1] = 'R';
		}
		if (n == 4) {
			playe_field[y1][x1][1] = 'B';
		}
	}
}
void Table::validator() {
	pawn(); //валітор ходів пешки
	horse(); //кінь
	king();//король
	queen();//королева
	rook();//башня
	bishop();//ферзь
}

void Table::movefig() {
	locals = playe_field[y][x];
	char literaldop;
	int numberdop;
	cout << "Enter zone go (a1-h8):";
	cin >> literaldop;
	cin >> numberdop;
	y1 = numberdop - 1;
	for (int i = 0; i<8; i++) {
		if (alfavit[i] == literaldop) {
			x1 = i;
		}
	}
	validator();
}

void Table::colorfig() {
	if (gamer == 1 && playe_field[y][x][0] == 'B') {
		movefig();
	}
	else if (gamer == 0 && playe_field[y][x][0] == 'W') {
			movefig();
		}
		else {
			cout << "Invalid enter" << endl;
		}
	//}
}
void Table::EnterHod() {
	char literal;

	cout << "Enter literal zone (a1-h8) or s10 to save game:";
	cin >> literal;
	cin >> y;

	/*save game*/
	if (literal == 's') {
		ofstream out;
		out.open("save.txt");
		if (out.is_open()) {
			for (int row = 0; row<8; row++) {
				for (int col = 0; col<8; col++) {
					out << playe_field[row][col] << endl;
				}
			}
		}
		out.close();
		cout << "Save sucefull" << endl;
	}
	/*save game*/

	y = y - 1;
	for (int i = 0; i<8; i++) {
		if (alfavit[i] == literal) {
			x = i;
		}
	}
	if (playe_field[y][x] == "  ") {
		cout << "Invalid enter" << endl;
	}
	else {
		colorfig();
	}

}

void Table::DrowScreenPlayer() {
	system("cls");
	if (player % 2) {
		gamer = 1;
		cout << "\tTurns: black" << endl;
	}
	else {
		gamer = 0;
		cout << "\tTurns: white" << endl;
	}
	cout << "\tWhite Player" << endl;
	cout << "  ";
	for (int i = 0; i<8; i++) {
		cout << " " << alfavit[i] << " ";
	}
	cout << endl;
	cout << "   ";
	for (int i = 0; i<12; i++) {
		cout << "__";
	}
	cout << endl;
	for (int row = 0; row<8; row++) {
		cout << row + 1 << " ";
		for (int col = 0; col<8; col++) {
			cout << "|" << playe_field[row][col];
		}
		cout << "| ";
		cout << row + 1 << " " << endl;
		cout << "   ";
		for (int col = 0; col<12; col++) {
			cout << "--";
		}
		cout << endl;
	}
	cout << "   ";
	cout << endl;
	cout << "  ";
	for (int i = 0; i<8; i++) {
		cout << " " << alfavit[i] << " ";
	}
	cout << endl;
	cout << "\tBlack Player" << endl;
}