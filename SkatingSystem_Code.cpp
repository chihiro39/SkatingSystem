#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Player_number 6
#define Judge_number 5 //�Ƃ肠�������

// �V�K������X�P�[�e�B���O�ŕ׋�����

// �܂��ł��Ă��Ȃ�����
// ��������������
// �X�P�[�e�B���O�����̊֐���
// �t�@�C������̓��o��
// �T�[�o�E�N���C�A���g����
// �A�v���P�[�V������


void QSort(int x[], int left, int right);
void Swap(int x[], int i, int j);
void ShowData(int x[], int n);

/* �N�C�b�N�\�[�g���s�� */
void QSort(int x[], int left, int right)
{
	int i, j;
	int pivot;

	i = left;                      /* �\�[�g����z��̈�ԏ������v�f�̓Y�� */
	j = right;                     /* �\�[�g����z��̈�ԑ傫���v�f�̓Y�� */

	pivot = x[(left + right) / 2]; /* ��l��z��̒����t�߂ɂƂ� */

	while (1) {                    /* �������[�v */

		while (x[i] < pivot)       /* pivot ���傫���l�� */
			i++;                   /* �o��܂� i �𑝉������� */

		while (pivot < x[j])       /* pivot ��菬�����l�� */
			j--;                   /*  �o��܂� j ������������ */
		if (i >= j)                /* i >= j �Ȃ� */
			break;                 /* �������[�v���甲���� */

		Swap(x, i, j);             /* x[i] �� x[j]������ */
		i++;                       /* ���̃f�[�^ */
		j--;
	}
	//ShowData(x, 10);               /* �r���o�߂�\�� */

	if (left < i - 1)              /* ��l�̍��� 2 �ȏ�v�f������� */
		QSort(x, left, i - 1);     /* ���̔z��� Q �\�[�g���� */
	if (j + 1 <  right)            /* ��l�̉E�� 2 �ȏ�v�f������� */
		QSort(x, j + 1, right);    /* �E�̔z��� Q �\�[�g���� */
}

/* �z��̗v�f���������� */
void Swap(int x[], int i, int j)
{
	int temp;

	temp = x[i];
	x[i] = x[j];
	x[j] = temp;
}


/* n �̃f�[�^��\������ */
void ShowData(int x[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d  ", x[i]);
	printf("\n");
}



int main() {
	int Table[Player_number][Judge_number] = { {3,3,3,3,3},
												{1,2,4,4,1},
												{4,1,2,1,5},
												{5,5,5,5,4},
												{2,4,1,2,2},
												{6,6,6,6,6} };
	int Table_sort[Player_number][Judge_number + 1] = { {0} };

	int (*p_Table)[Judge_number] = NULL;
	int (*p_Table_sort)[Judge_number + 1] = NULL;

	p_Table = Table;
	p_Table_sort = Table_sort;

	/*
	{ 0, 3, 3, 3, 3, 6 },
	{ 0, 1, 1, 4, 4, 4 },
	{ 0, 1, 2, 4, 4, 6 },
	{ 0, 2, 2, 5, 5, 5 },
	{ 0, 1, 2, 5, 5, 6 },
	{ 0, 1, 2, 6, 6, 6 } };//0����o�͗p�̗�Ƃ���
	*/
	//	int index_mark[Player_number] = { 0 };
	//	int majority[Player_number] = { 0 };
	//	int adding[Player_number] = { 0 };
	//	int comprasion[Player_number] = { 0 };

	int check_rank_all[Player_number] = { 0 };
	char buf[10];
	int check_judge_num[Judge_number] = { 0 };
	int check_judge_numall = 0;
	int judge_num = 0;
	do{
		memset(buf, 0, sizeof(buf));
		fprintf(stdout, "�W���b�W�ԍ��𔼊p�����œ��͂��Ă��������i�`�F1�C�@�a�F2�C�@�b�F3�C�c�j\n�W���b�W�ԍ��F");
		fgets(buf, sizeof(buf), stdin);
		//	fprintf(stdout, "�������o��\n");
		//	fprintf(stdout, buf);

		//���͂����p�������`�F�b�N

		judge_num = atoi(buf) - 1;//�u0�v~�u�W���b�W�̐�-1�v���Ƃ�(�C���f�b�N�X�̂���)
		//	fprintf(stdout, "���l���o��\n");
		//	fprintf(stdout, "%d", judge_num);

		check_judge_num[judge_num] += 1;//�o�^�ς�
		if (check_judge_num[judge_num] > 1) {
			fprintf(stdout, "�d�����ēo�^���悤�Ƃ��Ă��܂��I\n");
			check_judge_num[judge_num] = 0;//�d����h���ł������������Ă��܂��Ă���
			continue;
		}
		int judged_rank = 0;
		int check_input_rank = 0;

		do {
			check_input_rank = 0;//������
			for (int i = 0; i < Player_number; i++) {
				check_rank_all[i] = i + 1;
			}
			fprintf(stdout, "���ʂ��𔼊p����(1~7)�œ��͂��Ă�������\n");
			for (int i = 0; i < Player_number; i++) {
				fprintf(stdout, "\n%d�Ԗڂɗx�����l�̏��ʂ́H\n���ʁF", i + 1);
				fgets(buf, sizeof(buf), stdin);
				judged_rank = atoi(buf);
				memset(buf, 0, sizeof(buf));
				Table[i][judge_num] = judged_rank;
				check_rank_all[judged_rank - 1] -= judged_rank;
			}
			for (int i = 0; i < Player_number; i++) {
				check_input_rank += check_rank_all[i];
				//							fprintf(stdout, "%d", check_input_rank);
				//							fprintf(stdout, " %d\n", check_rank_all[i]);

			}
			if (check_input_rank == 0) {
				fprintf(stdout, "���͂ɖ��Ȃ�\n");
			}
			else {
				fprintf(stdout, "���̓~�X����I\n");
			}

		} while (check_input_rank != 0);
		for (check_judge_numall = 0; check_judge_numall < Judge_number; check_judge_numall++) {
			if (check_judge_num[check_judge_numall] != 1) {
				fprintf(stdout, "check_judge_num[%d] = %d\n", check_judge_numall, check_judge_num[check_judge_numall]);
				break;
			}
		}
		fprintf(stdout, "check_judge_numall�@%d\n", check_judge_numall);
	} while (check_judge_numall != Judge_number);

	//�J���}�Ő؂�

	//���ꂼ��̑I��Ɋ��蓖�Ă�

	//�ق�Ƃ͑I����\���̉����Atable�ƌ��т���B
	//	int b[Player_number + 1] = { 1,1,1,1,1,1 };
		//input
		//�܂��͏����l�Ƃ��ē���Ă݂�
		//check input

		//Table�̓���
/*	int check = 0;
	do{
		fprintf(stdout, "Table input\n");
		fprintf(stdout, "Judge is 5 member\n");
		for (int j = 0; j < Judge_number; j++) {
			for (int i = 0; i < Player_number; i++) {
				fprintf(stdout, "%d�W���b�W��%d�Ԃ̏��ʂ́H", j, i);
				fprintf(stdin, "%d", Table[i][j]);
			}
			fprintf(stdout, "\n");
		}
		fprintf(stdout, "OK? (Yes = 1 / No = 0)\n");
		fprintf(stdin, "%d", check);
	}while(check != 1);
*/
		//Table�̏o��
		fprintf(stdout, "�ȉ��̓��e�œ��͂��󂯕t���܂���\n");
		fprintf(stdout, "A\tB\tC\tD\tE\tF\tG\tH\n");
		for (int i = 0; i < Player_number; i++) {
			for (int j = 0; j < Judge_number; j++) {
				fprintf(stdout, "%d\t", Table[i][j]);
			}
			fprintf(stdout, "\n");
		}
	//sort table
	for (int i = 0; i < Player_number; i++) {
		for (int j = 0; j < Judge_number; j++) {
			Table_sort[i][j + 1] = Table[i][j];
		}
	}//�N�C�b�N�\�[�g
	for (int i = 0; i < Player_number; i++) {
		QSort(Table_sort[i], 1, Judge_number);
		Table_sort[i][0] = 1;//1�ʂ���ǂꂾ��������i���Z����j���Ń����L���O���邽��1�����Ă���
	}
	//Table_sort�̏o��
	fprintf(stdout, "Table_sort \n");
	for (int i = 0; i < Player_number; i++) {
		for (int j = 1; j < Judge_number + 1; j++) {
			fprintf(stdout, "%d\t", Table_sort[i][j]);
		}
		fprintf(stdout,"\n");
	}

	int center_num = Player_number / 2;
	fprintf(stdout, "center = %d\n", center_num);
	fprintf(stdout, "�����l \n");
	for (int i = 0; i < Player_number; i++) {
		fprintf(stdout, "%d�� %d\n", i, Table_sort[i][center_num]);
	}

	//skating�J�n
	int award_rank = 1;
	int check_rank = 1;

	//while (award_rank <= Player_number) {
		//center check
	fprintf(stdout, "�P���Ƀ\�[�g\n");

		for (int i = 1; i < Player_number; i++) {
			for (int j = 0; j <= i-1; j++) {
//				fprintf(stdout, "�����Oi=%d, j=%d, rank_i=%d, rank_j=%d", i, j, Table_sort[i][0], Table_sort[j][0]);

				if (Table_sort[j][center_num] < Table_sort[i][center_num]) {
					Table_sort[i][0]++;
				}
				if (Table_sort[j][center_num] > Table_sort[i][center_num]) {
					Table_sort[j][0]++;
				}
//				fprintf(stdout, "	������i=%d, j=%d, rank_i=%d, rank_j=%d\n", i, j, Table_sort[i][0], Table_sort[j][0]);
			}
		}

		fprintf(stdout, "�ߔ����Ń\�[�g\n");

		for (int i = 1; i < Player_number; i++) {
			for (int j = 0; j <= i - 1; j++) {
//				fprintf(stdout, "�����Oi=%d, j=%d, rank_i=%d, rank_j=%d", i, j, Table_sort[i][0], Table_sort[j][0]);
				if (Table_sort[j][0] == Table_sort[i][0]) {
					//�ߔ���
					int right = 0;
					int check_majority = Table_sort[i][center_num];
					while (right < Judge_number - center_num &&
						(Table_sort[j][center_num + (right)] == Table_sort[i][center_num + (right)])) {

						right++;
						if (Table_sort[i][center_num + (right - 1)] != Table_sort[i][center_num + (right)]) {
							if (Table_sort[j][center_num + (right - 1)] == Table_sort[j][center_num + (right)]) {
								Table_sort[i][0]++;
								break;
							}
						}
						if (Table_sort[j][center_num + (right - 1)] != Table_sort[j][center_num + (right)]) {
							if (Table_sort[i][center_num + (right - 1)] == Table_sort[i][center_num + (right)]) {
								Table_sort[j][0]++;
								break;//next ��ʉ��Z��
							}
						}
					}
				}
//				fprintf(stdout, "	������i=%d, j=%d, rank_i=%d, rank_j=%d\n", i, j, Table_sort[i][0], Table_sort[j][0]);
			}
		}
		fprintf(stdout, "��ʉ��Z\n");
		for (int i = 1; i < Player_number; i++) {
			for (int j = 0; j <= i - 1; j++) {
//				fprintf(stdout, "�����Oi=%d, j=%d, rank_i=%d, rank_j=%d", i, j, Table_sort[i][0], Table_sort[j][0]);
				if (Table_sort[j][0] == Table_sort[i][0]) {
					//��ʉ��Z
					int sum_i = 0;
					int sum_j = 0;
					for (int index = 1; index < center_num; index++) {
						sum_i += Table_sort[i][index];
						sum_j += Table_sort[j][index];
					}
					if (sum_j < sum_i) {
						Table_sort[i][0]++;
					}
					else if (sum_j > sum_i) {
						Table_sort[j][0]++;
					}
				}
//				fprintf(stdout, "	������i=%d, j=%d, rank_i=%d, rank_j=%d\n", i, j, Table_sort[i][0], Table_sort[j][0]);
			}
		}
		fprintf(stdout, "���ʔ�r\n");
		for (int i = 1; i < Player_number; i++) {
			for (int j = 0; j <= i - 1; j++) {
//				fprintf(stdout, "�����Oi=%d, j=%d, rank_i=%d, rank_j=%d", i, j, Table_sort[i][0], Table_sort[j][0]);
				if (Table_sort[j][0] == Table_sort[i][0]) {
					//���ʔ�r
					int right = 0;
					while (right < Judge_number - center_num &&
						(Table_sort[j][center_num + (right)] == Table_sort[i][center_num + (right)])) {
						right++;
						if (Table_sort[j][center_num + (right)] < Table_sort[i][center_num + (right)]) {
							Table_sort[i][0]++;
							break;
						}
						if (Table_sort[j][center_num + (right)] > Table_sort[i][center_num + (right)]) {
							Table_sort[j][0]++;
							break;
						}
					}
					//����
				}
//				fprintf(stdout, "	������i=%d, j=%d, rank_i=%d, rank_j=%d\n", i, j, Table_sort[i][0], Table_sort[j][0]);
			}
		}
		//kekka
		fprintf(stdout, "���� \n");
		for (int i = 0; i < Player_number; i++) {
			fprintf(stdout, "%d�ԁ@%d��\n", i, Table_sort[i][0]);
		}

		fprintf(stdout, "���ʕ\�@�o�� \n");
		{
			int out_player_num = 0;
			for (int i = 1; i <= Player_number; i++) {
				for (int j = 0; j < Player_number;j++) {
					if (Table_sort[j][0] == i) {
						out_player_num = j;
					}
				}
				fprintf(stdout, "%d�ʁ@%d��\n", i, out_player_num);
			}

		}

		/*int i= 0;
		for (int index_player = 0; index_player < Player_number; index_player++) {
			if (Table_sort[index_player][center_num] == check_rank) {
				index_mark[i] = index_player;
				i++;
			}
		}
		int INDEX_MARK_LEN = i;
		//same number 1
		//���m�菇�ʂ̏�ʂ�^����@*
		if (INDEX_MARK_LEN == 1) {
			Table_sort[index_mark[i]][0] = award_rank;
			//continue;//�Ȃ��Ă��悳�����H
		}
		else if (INDEX_MARK_LEN != 1) {
			//������
			for (int i = 0; i <= INDEX_MARK_LEN; i++) {
				int j = 0;
				while(j < Judge_number - center_num) {
					if (Table_sort[index_mark[i]][center_num + (j + 1)] == check_rank) {
						j++;
					}
				}
				majority[i] = j;
			}
			//k[i]�̒�����r
			int i = 0;
			if (majority[i] < majority[i + 1]) {
				if () {
				}
				Table_sort[index_mark[i]][0] = award_rank;
			}
			else if (majority[i] > majority[i + 1]) {

			}
			else if (majority[i] = majority[i + 1]) {
				//��ʉ��Z
				int check_sum[Player_number] = NULL;
				for (int i = 0;;i++) {
					check_sum[index_mark[i]] += Table_sort[index_mark[i]][i];
				}
			}

	}
		check_rank++;
		}

			
			//same any numbers
				//������
					//*
					//��ʉ��Z
						//*
						//���ʔ�r
							//*
							//��������

		//end for rank+j�͂���(j�l���ʂ����܂���) check_rank++;
	//end skating ���m�菇�ʂȂ�

	//output
	*/
	return 0;
}