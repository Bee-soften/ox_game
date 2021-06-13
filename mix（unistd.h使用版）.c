#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* �v���g�^�C�v�錾 */
void cp_hand2(char go_board[][3]);
void print_board(char go_board[][3]);

/* �����Q����ł��āA�R�ڂƂȂ肤��}�X���󔒂̏ꍇ�͂����ɒ��� */
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

/* �����Q����ł��āA�R�ڂƂȂ肤��}�X���󔒂̏ꍇ�͂����ɒ��� */
int cp_algo2(char go_board[][3]) {
	for (int i = 0; i < 3; i++) {
		if ((go_board[i][0] == 'o' && go_board[i][1] == 'o' && go_board[i][2] == ' ')
			|| (go_board[i][0] == 'o' && go_board[i][1] == ' ' && go_board[i][2] == 'o')
			|| (go_board[i][0] == ' ' && go_board[i][1] == 'o' && go_board[i][2] == 'o')) {		// ����'o'���Q����ł���ꏊ�̌���
			for (int j = 0; j < 3; j++) {
				if (go_board[i][j] == ' ') {
					go_board[i][j] = 'x';
					return (1);
				}
			}																					//�@�󔒂�'x'�𒅎�
		}

		else if ((go_board[0][i] == 'o' && go_board[1][i] == 'o' && go_board[2][i] == ' ')
			|| (go_board[0][i] == 'o' && go_board[1][i] == ' ' && go_board[2][i] == 'o')
			|| (go_board[0][i] == ' ' && go_board[1][i] == 'o' && go_board[2][i] == 'o')) {		// �c��'o'���Q����ł���ꏊ�̌���
			for (int j = 0; j < 3; j++) {
				if (go_board[j][i] == ' ') {
					go_board[j][i] = 'x';														//�@�󔒂�'x'�𒅎�
					return (1);
				}
			}
		}
		else if ((go_board[0][0] == 'o' && go_board[1][1] == 'o' && go_board[2][2] == ' ')
			|| (go_board[0][0] == 'o' && go_board[1][1] == ' ' && go_board[2][2] == 'o')
			|| (go_board[0][0] == ' ' && go_board[1][1] == 'o' && go_board[2][2] == 'o')) {		//�΂߂�'o'���Q����ł���ꏊ�̌���
			for (int j = 0; j < 3; j++) {
				if (go_board[j][j] == ' ') {
					go_board[j][j] = 'x';
					return (1);
				}
			}																					//�@�󔒂�'x'�𒅎�
		}

		else if ((go_board[0][2] == 'o' && go_board[1][1] == 'o' && go_board[2][0] == ' ')
			|| (go_board[0][2] == 'o' && go_board[1][1] == ' ' && go_board[2][0] == 'o')
			|| (go_board[0][2] == ' ' && go_board[1][1] == 'o' && go_board[2][0] == 'o')) {		//�΂߂�'o'���Q����ł���ꏊ�̌���
			for (int j = 0; j < 3; j++) {
				if (go_board[j][2 - j] == ' ') {
					go_board[j][2 - j] = 'x';
					return (1);
				}
			}																					//�@�󔒂�'x'�𒅎�
		}
	}
	return (0);
}

/* �����ɒ��� */
int cp_algo3(char go_board[][3]) {
	if (go_board[1][1] == ' ') {
		go_board[1][1] = 'x';
		return (1);
	}
	return (0);
}

/* ���ɒ���i�������A����󋵂Ɍ���ӂɒ��肷��j*/
int cp_algo4(char go_board[][3]) {

	/* ����󋵂ɂ�����ӂւ̒��� */
	if (((go_board[0][0] == 'o' && go_board[1][1] == 'x' && go_board[2][2] == 'o')
		|| (go_board[2][0] == 'o' && go_board[1][1] == 'x' && go_board[0][2] == 'o'))
		&& (go_board[0][1] == ' ')) {
		go_board[0][1] = 'x';
		return (1);
	}

	/*�@��肪�P�C�}�܂��̓R�X�~�ł���󋵂ɑ΂���A���肷�ׂ����̌����@*/
	for (int i = 0; i < 3; i += 2) {
		if (go_board[i][i] == ' ' && (go_board[i][1] == 'o' || go_board[i][2 - i] == 'o')
			&& (go_board[1][i] == 'o' || go_board[2 - i][i] == 'o')) {		//��[0][0]��[2][2]�̏ꍇ�̌����Ȃ�
			go_board[i][i] = 'x';
			return (1);
		}
		else if (go_board[i][2 - i] == ' ' && (go_board[i][1] == 'o' || go_board[i][i] == 'o')
			&& (go_board[1][2 - i] == 'o' || go_board[2 - i][2 - i] == 'o')) {		//��[0][2]��[2][0]�̏ꍇ�̌����Ȃ�
			go_board[i][2 - i] = 'x';
			return (1);
		}
	}

	/* ���֒��� */
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

/* �ӂɒ���(cp_algo5�͎g�p����K�v�Ȃ�����...) */
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



/* �R���s���[�^�]���l�̉�ʕ\���B�f�o�b�O���ȊO�͂��̊֐����g�p���Ȃ� */
void print_board2(int score_board[][3]) {
	printf("+----+----+----+\n");
	printf("| %2d | %2d | %2d |\n", score_board[0][0], score_board[0][1], score_board[0][2]);
	printf("+----+----+----+\n");
	printf("| %2d | %2d | %2d |\n", score_board[1][0], score_board[1][1], score_board[1][2]);
	printf("+----+----+----+\n");
	printf("| %2d | %2d | %2d |\n", score_board[2][0], score_board[2][1], score_board[2][2]);
	printf("+----+----+----+\n");
}

/* �R���s���[�^�]���l�̌v�Z */
void eval_value(char go_board[][3], int score_board[][3]) {
	int i, j, k;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (go_board[i][j] == ' ') {			//����}�X�ɂ����āA�c�����݂̂ŕ]���l��ύX����
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
				if ((i == 0 && (j == 0 || j == 2)) || (i == 2 && (j == 0 || j == 2))) {	//�����ċ��̃}�X�̏ꍇ�Ɍ���A�΂ߎ��ŕ]���l��ύX����B
					if (go_board[1][1] == 'o' && go_board[2 - i][2 - j] != 'x')
						score_board[i][j] -= 1;
					if (go_board[1][1] == 'x' && go_board[2 - i][2 - j] != 'o')
						score_board[i][j] -= 2;
					if (go_board[2 - i][2 - j] == 'o' && go_board[1][1] != 'x')
						score_board[i][j] -= 1;
					if (go_board[2 - i][2 - j] == 'x' && go_board[1][1] != 'o')
						score_board[i][j] -= 2;
				}
				if (i == 1 && j == 1) {						//�����Ē����Ɍ���A�΂ߎ��ŕ]���l��ύX����B
					for (k = 0; k < 3; k += 2) {
						if (go_board[0][k] == 'o' && go_board[2][2 - k] != 'x')
							score_board[i][j] -= 1;
						if (go_board[0][k] == 'x' && go_board[2][2 - k] != 'o')
							score_board[i][j] -= 2;
						if (go_board[2][k] == 'o' && go_board[0][2 - k] != 'x')			//[0][0]��[0][2]�̋��̃p�^�[��
							score_board[i][j] -= 1;
						if (go_board[2][k] == 'x' && go_board[0][2 - k] != 'o')			//[2][0]��[2][2]�̋��̃p�^�[��
							score_board[i][j] -= 2;
					}
				}
			}
			if (go_board[i][j] != ' ')
				score_board[i][j] = 0;	//�������������Ă���}�X�͕]���l���O�Ƃ���
		}
	}
}

/* �N���C�W�[���[�h��S��ڂɂ�����A����̏����ɂ����钅��B���肵�Ȃ����0��Ԃ��B */
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
			score_cpy[i][j] = score_board[i][j];	//while���̒��ŕ]���l��0�ɕς��邱�Ƃ����邽�߁A����score_board��ύX���Ȃ��悤�ɒl�n��������B
	}
	while (1) {
		max = 0;
		for (i = 0; i < 3; i++) {		//�ł������]���l�̃}�X����������B
			for (j = 0; j < 3; j++) {
				if (max < score_cpy[i][j])
					max = score_cpy[i][j];
			}
		}
		for (k = 0; k < 3; k++) {			//�ł��]���l�̍����}�X�ɂ�������B
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
		printf(" �Z�~�Q�[���̐����������B\n");
		printf(" �R�~�R�}�X�̒��ցA���݂ɁZ�Ɓ~�́u���邵�v��t���Ă�����B\n");
		printf(" �^�e�E���R�E�i�i���Ɏ����́u���邵�v���R���ׂ����̏������I\n");
		printf(" �ԍ�����͂��邱�ƂŁA�u���邵�v��t����}�X��I��łˁB\n");
		printf(" �}�X�̔ԍ��͎��̂悤�ɂȂ��Ă����B\n");
		printf(" �����A�͂��߂Ă݂悤�I\n");
		print_board(mark);

		printf(" �G���^�[�Ŗ߂�:\n");
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
	printf("���̎�Ԃł��B\n");

	while (!(board_number >= 1 && board_number <= 9)) {
		printf("1�`9�̐��l����͂��Ă�������:");
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &board_number);
		if (board_number == 1 || board_number == 2 || board_number == 3) {
			if (go_board[2][board_number - 1] == ' ')
				go_board[2][board_number - 1] = 'o';
			else {
				printf("���̏ꏊ�͊��ɖ��܂��Ă��܂��B\n\n");
				board_number = 0;
			}
		}
		else if (board_number == 4 || board_number == 5 || board_number == 6) {
			if (go_board[1][board_number % 4] == ' ')
				go_board[1][board_number % 4] = 'o';
			else {
				printf("���̏ꏊ�͊��ɖ��܂��Ă��܂��B\n\n");
				board_number = 0;
			}
		}
		else if (board_number == 7 || board_number == 8 || board_number == 9) {
			if (go_board[0][board_number % 7] == ' ')
				go_board[0][board_number % 7] = 'o';
			else {
				printf("���̏ꏊ�͊��ɖ��܂��Ă��܂��B\n\n");
				board_number = 0;
			}
		}
	}
}

void second_hand(char go_board[][3]) {
	char buf[100];
	int board_number = 0;

	print_board(go_board);
	printf("���̎�Ԃł��B\n");
	while (!(board_number >= 1 && board_number <= 9)) {
		printf("1�`9�̐��l����͂��Ă�������:");
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &board_number);
		if (board_number == 1 || board_number == 2 || board_number == 3) {
			if (go_board[2][board_number - 1] == ' ')
				go_board[2][board_number - 1] = 'x';
			else {
				printf("���̏ꏊ�͊��ɖ��܂��Ă��܂��B\n\n");
				board_number = 0;
			}
		}
		else if (board_number == 4 || board_number == 5 || board_number == 6) {
			if (go_board[1][board_number % 4] == ' ')
				go_board[1][board_number % 4] = 'x';
			else {
				printf("���̏ꏊ�͊��ɖ��܂��Ă��܂��B\n\n");
				board_number = 0;
			}
		}
		else if (board_number == 7 || board_number == 8 || board_number == 9) {
			if (go_board[0][board_number % 7] == ' ')
				go_board[0][board_number % 7] = 'x';
			else {
				printf("���̏ꏊ�͊��ɖ��܂��Ă��܂��B\n\n");
				board_number = 0;
			}
		}
	}
}

/*���x����̓���*/
void cp_hand1(char go_board[][3]) {
	srand((unsigned int)time(NULL));
	int r = rand() % 5;

	if (r == 0 || r == 2 || r == 4) {
		cp_hand2(go_board);
		return;
	}
	print_board(go_board);
	printf("CP�̎�Ԃł��B\n");
	usleep(300000);
	printf("�l����...\n");
	usleep(1000000);
	if (cp_algo3(go_board) == 0) {
		if (cp_algo4(go_board) == 0)
			cp_algo5(go_board);
	}
}

/*���x�����̓���*/
void cp_hand2(char go_board[][3]) {
	srand((unsigned int)time(NULL));
	int r = rand() % 5;

	print_board(go_board);
	printf("CP�̎�Ԃł��B\n");
	usleep(300000);
	printf("�l����...\n");
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

/*���x�����̓���*/
void cp_hand3(char go_board[][3]) {
	print_board(go_board);
	printf("CP�̎�Ԃł��B\n");
	usleep(300000);
	printf("�l����...\n");
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
	printf("CP�̎�Ԃł��B\n");
	usleep(300000);
	printf("�l����...\n");
	usleep(9100000 - (3000000 * turn));
	crazy_algo(go_board, score_board2, turn);
}

int win_or_lose(char go_board[][3]) {
	int i, a = 0;

	for (i = 0; i < 3; i++) {
		if (go_board[i][0] != ' ' && go_board[i][0] == go_board[i][1] && go_board[i][1] == go_board[i][2])	//���܂��͌�肪��3����񂾏ꍇ
			a = 1;
		if (go_board[0][i] != ' ' && go_board[0][i] == go_board[1][i] && go_board[1][i] == go_board[2][i])	//���܂��͌�肪�c3����񂾏ꍇ
			a = 1;
		if (go_board[1][1] != ' ' && go_board[0][0] == go_board[1][1] && go_board[1][1] == go_board[2][2])	//���܂��͌�肪�΂�3��ɕ��񂾏ꍇ
			a = 1;
		if (go_board[1][1] != ' ' && go_board[0][2] == go_board[1][1] && go_board[1][1] == go_board[2][0])	//���܂��͌�肪�΂�3��ɕ��񂾏ꍇ
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
			printf("|���̏����I!|\n");
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
			printf("|���̏����I!|\n");
			printf("+-------------+\n\n");
			break;
		}
	}
	if (win == 0) {
		print_board(go_board);
		usleep(300000);
		printf("+--------+\n");
		printf("|��������|\n");
		printf("+--------+\n\n");
	}
	usleep(2000000);
}

/* cp�����Ԃ̏ꍇ�̗���@*/
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
			printf("|���Ȃ��̏����I!|\n");
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
			printf("|���Ȃ��̕����I!|\n");
			printf("+---------------+\n\n");
			break;
		}
	}
	if (win == 0) {
		print_board(go_board);
		usleep(1000000);
		printf("+--------+\n");;
		printf("|��������|\n");
		printf("+--------+\n\n");
	}
	usleep(2000000);
}

void vs_crazy(int mode) {
	char go_board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
	int win = 0;

	printf("\n+--------------------------------+\n");
	printf("|�R���񂾂ق��̕�������I      |\n");
	printf("|�Ȃ�Ƃ����������܂Ŏ����������I|\n");
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
			printf("|���Ȃ��̕����I!|\n");
			printf("+---------------+\n\n");
			break;
		}

		int score_board2[3][3] = { {15, 16, 15}, {16, 15, 16}, {15, 16, 15} };
		eval_value(go_board, score_board2);		//core_board2�Ń��Z�b�g���ꂽ�]���l���A���߂Čv�Z����K�v������B
		if (i != 4)
			crazy_hand(go_board, score_board2, i);	//�]���l�ɖ߂Â��Ă�����͂���B
		eval_value(go_board, score_board2);		//�����͌�̕]���l���v�Z���邱�ƂŁA
		if (mode == 9)
			print_board2(score_board2);				//�f�o�b�O���[�h�̏ꍇ�A���݂̕]���l��\������B
		win = win_or_lose(go_board);
		if (win == 1) {
			print_board(go_board);
			usleep(1000000);
			printf("+---------------+\n");
			printf("|���Ȃ��̏����I!|\n");
			printf("+---------------+\n\n");
			break;
		}
	}
	if (win == 0) {
		print_board(go_board);
		usleep(1000000);
		printf("+------------+\n");;
		printf("|���������I�I|�@�@�@��������I�I\n");
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
		printf(" 1:1�l�v���C\n");
		printf(" 2:2�l�v���C\n");
		printf(" 0:���[������\n");
		printf(" -------------\n");
		while (1) {
			printf("�v���C���[�h�I���@��������͂��Ă�������: ");
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
					printf(" 1:CP���x����\n");
					printf(" 2:CP���x����\n");
					printf(" 3:CP���x����\n");
					printf(" 4:�N���C�W�[���[�h\n");
					printf(" ------------------\n");
					printf(" 9:�f�o�b�O���[�h\n");
					printf(" 0:�߂�\n");
					printf(" ------------------\n\n");
					while (1) {
						printf("�ΐ탂�[�h�I���@��������͂��Ă�������: ");
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
