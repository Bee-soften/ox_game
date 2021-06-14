#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* プロトタイプ宣言 */
void cp_hand2(char go_board[][3]);
void print_board(char go_board[][3]);

/* ｘが２つ並んでいて、３つ目となりうるマスが空白の場合はそこに着手 */
int cp_algo1(char go_board[][3]) {
	for (int i = 0; i < 3; i++) {
		if ((go_board[i][0] == 'x' && go_board[i][1] == 'x' && go_board[i][2] == ' ')
			|| (go_board[i][0] == 'x' && go_board[i][1] == ' ' && go_board[i][2] == 'x')
			|| (go_board[i][0] == ' ' && go_board[i][1] == 'x' && go_board[i][2] == 'x')) {
			go_board[i][0] = go_board[i][1] = go_board[i][2] = 'x';
			return (1);
		}

		else if ((go_board[0][i] == 'x' && go_board[1][i] == 'x' && go_board[2][i] == ' ')
			|| (go_board[0][i] == 'x' && go_board[1][i] == ' ' && go_board[2][i] == 'x')
			|| (go_board[0][i] == ' ' && go_board[1][i] == 'x' && go_board[2][i] == 'x')) {
			go_board[0][i] = go_board[1][i] = go_board[2][i] = 'x';
			return (1);
		}
		else if ((go_board[0][0] == 'x' && go_board[1][1] == 'x' && go_board[2][2] == ' ')
			|| (go_board[0][0] == 'x' && go_board[1][1] == ' ' && go_board[2][2] == 'x')
			|| (go_board[0][0] == ' ' && go_board[1][1] == 'x' && go_board[2][2] == 'x')) {
			go_board[0][0] = go_board[1][1] = go_board[2][2] = 'x';
			return (1);
		}

		else if ((go_board[0][2] == 'x' && go_board[1][1] == 'x' && go_board[2][0] == ' ')
			|| (go_board[0][2] == 'x' && go_board[1][1] == ' ' && go_board[2][0] == 'x')
			|| (go_board[0][2] == ' ' && go_board[1][1] == 'x' && go_board[2][0] == 'x')) {
			go_board[0][2] = go_board[1][1] = go_board[2][0] = 'x';
			return (1);
		}
	}
	return (0);
}

/* ｏが２つ並んでいて、３つ目となりうるマスが空白の場合はそこに着手 */
int cp_algo2(char go_board[][3]) {
	for (int i = 0; i < 3; i++) {
		if ((go_board[i][0] == 'o' && go_board[i][1] == 'o' && go_board[i][2] == ' ')
			|| (go_board[i][0] == 'o' && go_board[i][1] == ' ' && go_board[i][2] == 'o')
			|| (go_board[i][0] == ' ' && go_board[i][1] == 'o' && go_board[i][2] == 'o')) {		// 横に'o'が２つ並んでいる場所の検索
			for (int j = 0; j < 3; j++) {
				if (go_board[i][j] == ' ') {
					go_board[i][j] = 'x';
					return (1);
				}
			}																					//　空白に'x'を着手
		}

		else if ((go_board[0][i] == 'o' && go_board[1][i] == 'o' && go_board[2][i] == ' ')
			|| (go_board[0][i] == 'o' && go_board[1][i] == ' ' && go_board[2][i] == 'o')
			|| (go_board[0][i] == ' ' && go_board[1][i] == 'o' && go_board[2][i] == 'o')) {		// 縦に'o'が２つ並んでいる場所の検索
			for (int j = 0; j < 3; j++) {
				if (go_board[j][i] == ' ') {
					go_board[j][i] = 'x';														//　空白に'x'を着手
					return (1);
				}
			}
		}
		else if ((go_board[0][0] == 'o' && go_board[1][1] == 'o' && go_board[2][2] == ' ')
			|| (go_board[0][0] == 'o' && go_board[1][1] == ' ' && go_board[2][2] == 'o')
			|| (go_board[0][0] == ' ' && go_board[1][1] == 'o' && go_board[2][2] == 'o')) {		//斜めに'o'が２つ並んでいる場所の検索
			for (int j = 0; j < 3; j++) {
				if (go_board[j][j] == ' ') {
					go_board[j][j] = 'x';
					return (1);
				}
			}																					//　空白に'x'を着手
		}

		else if ((go_board[0][2] == 'o' && go_board[1][1] == 'o' && go_board[2][0] == ' ')
			|| (go_board[0][2] == 'o' && go_board[1][1] == ' ' && go_board[2][0] == 'o')
			|| (go_board[0][2] == ' ' && go_board[1][1] == 'o' && go_board[2][0] == 'o')) {		//斜めに'o'が２つ並んでいる場所の検索
			for (int j = 0; j < 3; j++) {
				if (go_board[j][2 - j] == ' ') {
					go_board[j][2 - j] = 'x';
					return (1);
				}
			}																					//　空白に'x'を着手
		}
	}
	return (0);
}

/* 中央に着手 */
int cp_algo3(char go_board[][3]) {
	if (go_board[1][1] == ' ') {
		go_board[1][1] = 'x';
		return (1);
	}
	return (0);
}

/* 隅に着手（ただし、ある状況に限り辺に着手する）*/
int cp_algo4(char go_board[][3]) {

	/* ある状況における辺への着手 */
	if (((go_board[0][0] == 'o' && go_board[1][1] == 'x' && go_board[2][2] == 'o')
		|| (go_board[2][0] == 'o' && go_board[1][1] == 'x' && go_board[0][2] == 'o'))
		&& (go_board[0][1] == ' ')) {
		go_board[0][1] = 'x';
		return (1);
	}

	/*　先手がケイマまたはコスミである状況に対する、着手すべき隅の検索　*/
	for (int i = 0; i < 3; i += 2) {
		if (go_board[i][i] == ' ' && (go_board[i][1] == 'o' || go_board[i][2 - i] == 'o')
			&& (go_board[1][i] == 'o' || go_board[2 - i][i] == 'o')) {		//隅[0][0]と[2][2]の場合の検討など
			go_board[i][i] = 'x';
			return (1);
		}
		else if (go_board[i][2 - i] == ' ' && (go_board[i][1] == 'o' || go_board[i][i] == 'o')
			&& (go_board[1][2 - i] == 'o' || go_board[2 - i][2 - i] == 'o')) {		//隅[0][2]と[2][0]の場合の検討など
			go_board[i][2 - i] = 'x';
			return (1);
		}
	}

	/* 隅へ着手 */
	for (int i = 0; i < 3; i += 2) {
		if (go_board[i][2 - i] == ' ') {
			go_board[i][2 - i] = 'x';
			return (1);
		}
		else if (go_board[i][i] == ' ') {
			go_board[i][i] = 'x';
			return (1);
		}
	}
	return (0);
}

/* 辺に着手(cp_algo5は使用する必要ないかも...) */
int cp_algo5(char go_board[][3]) {
	for (int i = 0; i < 3; i += 2) {
		if (go_board[i][1] == ' ') {
			go_board[i][1] = 'x';
			return (1);
		}
		else if (go_board[1][i] == ' ') {
			go_board[1][i] = 'x';
			return (1);
		}
	}
	return (0);
}



/* コンピュータ評価値の画面表示。デバッグ時以外はこの関数を使用しない */
void print_board2(int score_board[][3]) {
	printf("+----+----+----+\n");
	printf("| %2d | %2d | %2d |\n", score_board[0][0], score_board[0][1], score_board[0][2]);
	printf("+----+----+----+\n");
	printf("| %2d | %2d | %2d |\n", score_board[1][0], score_board[1][1], score_board[1][2]);
	printf("+----+----+----+\n");
	printf("| %2d | %2d | %2d |\n", score_board[2][0], score_board[2][1], score_board[2][2]);
	printf("+----+----+----+\n");
}

/* コンピュータ評価値の計算 */
void eval_value(char go_board[][3], int score_board[][3]) {
	int i, j, k;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (go_board[i][j] == ' ') {			//あるマスにおいて、縦横軸のみで評価値を変更する
				for (k = 0; k < 3; k++) {
					if (go_board[i][k] == 'o' && go_board[i][0] != 'x' && go_board[i][1] != 'x' && go_board[i][2] != 'x')
						score_board[i][j] -= 1;
					if (go_board[i][k] == 'x' && go_board[i][0] != 'o' && go_board[i][1] != 'o' && go_board[i][2] != 'o')
						score_board[i][j] -= 2;
					if (go_board[k][j] == 'o' && go_board[0][j] != 'x' && go_board[1][j] != 'x' && go_board[2][j] != 'x')
						score_board[i][j] -= 1;
					if (go_board[k][j] == 'x' && go_board[0][j] != 'o' && go_board[1][j] != 'o' && go_board[2][j] != 'o')
						score_board[i][j] -= 2;
				}
				if ((i == 0 && (j == 0 || j == 2)) || (i == 2 && (j == 0 || j == 2))) {	//加えて隅のマスの場合に限り、斜め軸で評価値を変更する。
					if (go_board[1][1] == 'o' && go_board[2 - i][2 - j] != 'x')
						score_board[i][j] -= 1;
					if (go_board[1][1] == 'x' && go_board[2 - i][2 - j] != 'o')
						score_board[i][j] -= 2;
					if (go_board[2 - i][2 - j] == 'o' && go_board[1][1] != 'x')
						score_board[i][j] -= 1;
					if (go_board[2 - i][2 - j] == 'x' && go_board[1][1] != 'o')
						score_board[i][j] -= 2;
				}
				if (i == 1 && j == 1) {						//加えて中央に限り、斜め軸で評価値を変更する。
					for (k = 0; k < 3; k += 2) {
						if (go_board[0][k] == 'o' && go_board[2][2 - k] != 'x')
							score_board[i][j] -= 1;
						if (go_board[0][k] == 'x' && go_board[2][2 - k] != 'o')
							score_board[i][j] -= 2;
						if (go_board[2][k] == 'o' && go_board[0][2 - k] != 'x')			//[0][0]と[0][2]の隅のパターン
							score_board[i][j] -= 1;
						if (go_board[2][k] == 'x' && go_board[0][2 - k] != 'o')			//[2][0]と[2][2]の隅のパターン
							score_board[i][j] -= 2;
					}
				}
			}
			if (go_board[i][j] != ' ')
				score_board[i][j] = 0;	//ｏかｘが入っているマスは評価値を０とする
		}
	}
}

/* クレイジーモード第４手目における、特定の条件における着手。着手しなければ0を返す。 */
int keima(char go_board[][3]) {
	if ((go_board[0][1] == 'o' && go_board[1][2] == 'o' && go_board[2][1] == 'x')
		|| (go_board[2][1] == 'o' && go_board[1][0] == 'o' && go_board[1][2] == 'x'))
		go_board[0][0] = 'x';
	else if ((go_board[0][1] == 'o' && go_board[1][0] == 'o' && go_board[2][1] == 'x')
		|| (go_board[2][1] == 'o' && go_board[1][2] == 'o' && go_board[1][0] == 'x'))
		go_board[0][2] = 'x';
	else if ((go_board[0][1] == 'o' && go_board[1][0] == 'o' && go_board[1][2] == 'x')
		|| (go_board[2][1] == 'o' && go_board[1][2] == 'o' && go_board[0][1] == 'x'))
		go_board[2][0] = 'x';
	else if ((go_board[0][1] == 'o' && go_board[1][2] == 'o' && go_board[1][0] == 'x')
		|| (go_board[2][1] == 'o' && go_board[1][0] == 'o' && go_board[0][1] == 'x'))
		go_board[2][2] = 'x';
	else
		return (0);
	return (1);
}

int crazy_algo(char go_board[][3], int score_board[][3], int turn) {
	int score_cpy[3][3] = { {0} };
	int i, j, k, l;
	int max;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			score_cpy[i][j] = score_board[i][j];	//while文の中で評価値を0に変えることがあるため、直接score_boardを変更しないように値渡しをする。
	}
	while (1) {
		max = 0;
		for (i = 0; i < 3; i++) {		//最も高い評価値のマスを検索する。
			for (j = 0; j < 3; j++) {
				if (max < score_cpy[i][j])
					max = score_cpy[i][j];
			}
		}
		for (k = 0; k < 3; k++) {			//最も評価値の高いマスにｘを入れる。
			for (l = 0; l < 3; l++) {
				if (score_cpy[k][l] == max) {
					if (turn == 1 && keima(go_board) == 1)
						return (1);
					else {
						go_board[k][l] = 'x';
						return(1);
					}
				}
			}
		}
	}
	return(0);
}



void explain(void) {

	while (1) {
		char mark[3][3] = { {'7', '8', '9'}, {'4', '5', '6'}, {'1', '2', '3'} };
		char buf[100];

		printf("\n ------------------------------------------------------------\n");
		printf(" 〇×ゲームの説明をするよ。\n");
		printf(" ３×３マスの中へ、交互に〇と×の「しるし」を付けていくよ。\n");
		printf(" タテ・ヨコ・ナナメに自分の「しるし」を３つ並べた方の勝ちだ！\n");
		printf(" 番号を入力することで、「しるし」を付けるマスを選んでね。\n");
		printf(" マスの番号は次のようになっているよ。\n");
		printf(" さあ、はじめてみよう！\n");
		print_board(mark);

		printf(" エンターで戻る:\n");
		printf(" ------------------------------------------------------------\n");
		fgets(buf, sizeof(buf), stdin);
		for (int i = 0; i < 100; i++)
			if (buf[i] == '\n')
				return;
	}
}

void print_board(char go_board[][3]) {
	usleep(300000);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", go_board[0][0], go_board[0][1], go_board[0][2]);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", go_board[1][0], go_board[1][1], go_board[1][2]);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", go_board[2][0], go_board[2][1], go_board[2][2]);
	printf("+---+---+---+\n\n");
}

void first_hand(char go_board[][3]) {
	char buf[100];
	int board_number = 0;

	print_board(go_board);
	printf("先手の手番です。\n");

	while (!(board_number >= 1 && board_number <= 9)) {
		printf("1～9の数値を入力してください:");
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &board_number);
		if (board_number == 1 || board_number == 2 || board_number == 3) {
			if (go_board[2][board_number - 1] == ' ')
				go_board[2][board_number - 1] = 'o';
			else {
				printf("その場所は既に埋まっています。\n\n");
				board_number = 0;
			}
		}
		else if (board_number == 4 || board_number == 5 || board_number == 6) {
			if (go_board[1][board_number % 4] == ' ')
				go_board[1][board_number % 4] = 'o';
			else {
				printf("その場所は既に埋まっています。\n\n");
				board_number = 0;
			}
		}
		else if (board_number == 7 || board_number == 8 || board_number == 9) {
			if (go_board[0][board_number % 7] == ' ')
				go_board[0][board_number % 7] = 'o';
			else {
				printf("その場所は既に埋まっています。\n\n");
				board_number = 0;
			}
		}
	}
}

void second_hand(char go_board[][3]) {
	char buf[100];
	int board_number = 0;

	print_board(go_board);
	printf("後手の手番です。\n");
	while (!(board_number >= 1 && board_number <= 9)) {
		printf("1～9の数値を入力してください:");
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &board_number);
		if (board_number == 1 || board_number == 2 || board_number == 3) {
			if (go_board[2][board_number - 1] == ' ')
				go_board[2][board_number - 1] = 'x';
			else {
				printf("その場所は既に埋まっています。\n\n");
				board_number = 0;
			}
		}
		else if (board_number == 4 || board_number == 5 || board_number == 6) {
			if (go_board[1][board_number % 4] == ' ')
				go_board[1][board_number % 4] = 'x';
			else {
				printf("その場所は既に埋まっています。\n\n");
				board_number = 0;
			}
		}
		else if (board_number == 7 || board_number == 8 || board_number == 9) {
			if (go_board[0][board_number % 7] == ' ')
				go_board[0][board_number % 7] = 'x';
			else {
				printf("その場所は既に埋まっています。\n\n");
				board_number = 0;
			}
		}
	}
}

/*レベル弱の動作*/
void cp_hand1(char go_board[][3]) {
	srand((unsigned int)time(NULL));
	int r = rand() % 5;

	if (r == 0 || r == 2 || r == 4) {
		cp_hand2(go_board);
		return;
	}
	print_board(go_board);
	printf("CPの手番です。\n");
	usleep(300000);
	printf("考慮中...\n");
	usleep(1000000);
	if (cp_algo3(go_board) == 0) {
		if (cp_algo4(go_board) == 0)
			cp_algo5(go_board);
	}
}

/*レベル中の動作*/
void cp_hand2(char go_board[][3]) {
	srand((unsigned int)time(NULL));
	int r = rand() % 5;

	print_board(go_board);
	printf("CPの手番です。\n");
	usleep(300000);
	printf("考慮中...\n");
	usleep(1000000);
	if (cp_algo1(go_board) == 0) {
		if (cp_algo2(go_board) == 0) {
			usleep(3000000);
			if (r == 0 || r == 2) {
				if (cp_algo5(go_board) == 0) {
					if (cp_algo4(go_board) == 0)
						cp_algo3(go_board);
				}
			}
			else if (cp_algo3(go_board) == 0) {
				if (cp_algo4(go_board) == 0) {
					cp_algo5(go_board);
				}
			}
		}
	}
}

/*レベル強の動作*/
void cp_hand3(char go_board[][3]) {
	print_board(go_board);
	printf("CPの手番です。\n");
	usleep(300000);
	printf("考慮中...\n");
	usleep(1000000);
	if (cp_algo1(go_board) == 0) {
		if (cp_algo2(go_board) == 0) {
			usleep(3000000);
			if (cp_algo3(go_board) == 0) {
				if (cp_algo4(go_board) == 0)
					cp_algo5(go_board);
			}
		}
	}
}

void crazy_hand(char go_board[][3], int score_board2[][3], int turn) {
	print_board(go_board);
	printf("CPの手番です。\n");
	usleep(300000);
	printf("考慮中...\n");
	usleep(9100000 - (3000000 * turn));
	crazy_algo(go_board, score_board2, turn);
}

int win_or_lose(char go_board[][3]) {
	int i, a = 0;

	for (i = 0; i < 3; i++) {
		if (go_board[i][0] != ' ' && go_board[i][0] == go_board[i][1] && go_board[i][1] == go_board[i][2])	//先手または後手が横3列並んだ場合
			a = 1;
		if (go_board[0][i] != ' ' && go_board[0][i] == go_board[1][i] && go_board[1][i] == go_board[2][i])	//先手または後手が縦3列並んだ場合
			a = 1;
		if (go_board[1][1] != ' ' && go_board[0][0] == go_board[1][1] && go_board[1][1] == go_board[2][2])	//先手または後手が斜め3列に並んだ場合
			a = 1;
		if (go_board[1][1] != ' ' && go_board[0][2] == go_board[1][1] && go_board[1][1] == go_board[2][0])	//先手または後手が斜め3列に並んだ場合
			a = 1;
	}
	return(a);
}

void vs_human(void)
{
	char go_board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
	int win = 0;

	for (int i = 0; i < 5; i++) {
		first_hand(go_board);
		win = win_or_lose(go_board);
		if (win == 1) {
			print_board(go_board);
			usleep(300000);
			printf("+-------------+\n");
			printf("|先手の勝ち！!|\n");
			printf("+-------------+\n\n");
			break;
		}
		if (i != 4)
			second_hand(go_board);
		win = win_or_lose(go_board);
		if (win == 1) {
			print_board(go_board);
			usleep(300000);
			printf("+-------------+\n");
			printf("|後手の勝ち！!|\n");
			printf("+-------------+\n\n");
			break;
		}
	}
	if (win == 0) {
		print_board(go_board);
		usleep(300000);
		printf("+--------+\n");
		printf("|引き分け|\n");
		printf("+--------+\n\n");
	}
	usleep(2000000);
}

/* cpが後手番の場合の流れ　*/
void vs_cp1(int mode) {
	char go_board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
	int win = 0;

	for (int i = 0; i < 5; i++) {
		first_hand(go_board);
		win = win_or_lose(go_board);
		if (win == 1) {
			print_board(go_board);
			usleep(1000000);
			printf("+---------------+\n");
			printf("|あなたの勝ち！!|\n");
			printf("+---------------+\n\n");
			break;
		}
		if (mode == 1 && i != 4)
			cp_hand1(go_board);
		else if (mode == 2 && i != 4)
			cp_hand2(go_board);
		else if (mode == 3 && i != 4)
			cp_hand3(go_board);
		win = win_or_lose(go_board);
		if (win == 1) {
			print_board(go_board);
			usleep(1000000);
			printf("+---------------+\n");
			printf("|あなたの負け！!|\n");
			printf("+---------------+\n\n");
			break;
		}
	}
	if (win == 0) {
		print_board(go_board);
		usleep(1000000);
		printf("+--------+\n");;
		printf("|引き分け|\n");
		printf("+--------+\n\n");
	}
	usleep(2000000);
}

void vs_crazy(int mode) {
	char go_board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
	int win = 0;

	printf("\n+--------------------------------+\n");
	printf("|３つ並んだほうの負けだよ！      |\n");
	printf("|なんとか引き分けまで持ち込もう！|\n");
	printf("+--------------------------------+\n");
	usleep(2000000);

	for (int i = 0; i < 5; i++) {
		int score_board1[3][3] = { {15, 16, 15}, {16, 15, 16}, {15, 16, 15} };
		first_hand(go_board);
		eval_value(go_board, score_board1);
		if (mode == 9)
			print_board2(score_board1);
		win = win_or_lose(go_board);
		if (win == 1) {
			print_board(go_board);
			usleep(1000000);
			printf("+---------------+\n");
			printf("|あなたの負け！!|\n");
			printf("+---------------+\n\n");
			break;
		}

		int score_board2[3][3] = { {15, 16, 15}, {16, 15, 16}, {15, 16, 15} };
		eval_value(go_board, score_board2);		//core_board2でリセットされた評価値を、改めて計算する必要がある。
		if (i != 4)
			crazy_hand(go_board, score_board2, i);	//評価値に戻づいてｘを入力する。
		eval_value(go_board, score_board2);		//ｘ入力後の評価値を計算することで、
		if (mode == 9)
			print_board2(score_board2);				//デバッグモードの場合、現在の評価値を表示する。
		win = win_or_lose(go_board);
		if (win == 1) {
			print_board(go_board);
			usleep(1000000);
			printf("+---------------+\n");
			printf("|あなたの勝ち！!|\n");
			printf("+---------------+\n\n");
			break;
		}
	}
	if (win == 0) {
		print_board(go_board);
		usleep(1000000);
		printf("+------------+\n");;
		printf("|引き分け！！|　　　見事じゃ！！\n");
		printf("+------------+\n\n");
	}
	usleep(2000000);
}

int main(void) {
	char buf1[100], buf2[100];
	int mode1, mode2;

	while (1) {
		mode1 = -1;
		printf("\n -------------\n");
		printf(" 1:1人プレイ\n");
		printf(" 2:2人プレイ\n");
		printf(" 0:ルール説明\n");
		printf(" -------------\n");
		while (1) {
			printf("プレイモード選択　数字を入力してください: ");
			fgets(buf1, sizeof(buf1), stdin);
			sscanf(buf1, "%d", &mode1);
			if (mode1 == 0) {
				explain();
				break;
			}
			else if (mode1 == 2) {
				vs_human();
				break;
			}
			else if (mode1 == 1)
			{
				while (1) {
					mode2 = -1;
					printf("\n ------------------\n");
					printf(" 1:CPレベル弱\n");
					printf(" 2:CPレベル中\n");
					printf(" 3:CPレベル強\n");
					printf(" 4:クレイジーモード\n");
					printf(" ------------------\n");
					printf(" 9:デバッグモード\n");
					printf(" 0:戻る\n");
					printf(" ------------------\n\n");
					while (1) {
						printf("対戦モード選択　数字を入力してください: ");
						fgets(buf2, sizeof(buf2), stdin);
						sscanf(buf2, "%d", &mode2);
						if (mode2 == 1 || mode2 == 2 || mode2 == 3) {
							vs_cp1(mode2);
							break;
						}
						else if (mode2 == 4 || mode2 == 9) {
							vs_crazy(mode2);
							break;
						}
						else if (mode2 == 0)
							break;
					}
					if (mode2 == 0)
						break;
				}
				break;
			}
		}
	}
	return (0);
}
