#include<stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

//#define A1 ()
#define A2 ()
#if defined (A1)
	#define DATA_MAX (1000)
	#define DATA_SIZE (261)
	#define KEY_SIZE (3)
	#define PUT_DATA (KEY_SIZE+1)
	#define DATA "data_A1.txt"
#else	//A2
	#define DATA_MAX (10000)
	#define DATA_SIZE (262)
	#define KEY_SIZE (4)
	#define PUT_DATA (KEY_SIZE+2)
	#define DATA "data_A2.txt"
#endif
#define INPUT_KEY_MAX (256)
#define MSG_MAX (5)
#define MSG_SIZE (128)

static const char MSG[MSG_MAX][MSG_SIZE] = { 
	{
#if defined A1
		"3���̐�������͂��ĉ�����[�I��/EXIT]:"
#else
		"4���̐�������͂��ĉ�����[�I��/EXIT]:"
#endif
	},
	{"[�Y���f�[�^]:"},
	{"[��������]:�Y���f�[�^�Ȃ�\n" },
	{"<ERROR>[�������ʒl]:"},
	{"���͌������Ⴂ�܂�\n"}
	};

void main(void) {
	FILE *fp;
	static char sBuf[DATA_MAX][DATA_SIZE];		/*�t�@�C���̒��g*/
	char key[INPUT_KEY_MAX];		/*�����L�[*/
	int checkData;		/*��v�f�[�^��������*/

	/*�t�@�C�����J���ăf�[�^��z��Ɋi�[*/
	if ((fp = fopen(DATA, "r")) == NULL) {
		printf("�t�@�C���̃I�[�v���Ɏ��s���܂����B");
		return;
	}

	for (int i = 0; i < DATA_MAX; i++) {
		fgets(&(sBuf[i][0]), DATA_SIZE, fp);
	}
	fclose(fp);

	/*�f�[�^����*/
	while (1) {
		printf(MSG[0]);
		scanf("%s", key);

		/*EXIT�����͂����ƏI��*/
		if (strcmp(key, "EXIT") == 0) {
			break;
		}

		/*�����L�[�̒����`�F�b�N*/
		if (strlen(key) != KEY_SIZE) {
#if defined (A1)
			printf(MSG[2]);
#else
			printf(MSG[4]);
#endif
			continue;
		}

		/*�����L�[�ƈ�v����f�[�^��T��*/
		for (int i = 0; i < DATA_MAX; i++) {
			if ((checkData = memcmp(sBuf[i], key, KEY_SIZE)) == 0) {
				printf("%s%s", MSG[1], &(sBuf[i][PUT_DATA]));
				break;
			}
		}
		if (checkData != 0) {
			printf(MSG[2]);
		}
	}
	return;
}