#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#pragma warning(disable: 4996)

//#define A1 ()
//#define A2 ()
#define B1
#if defined A1
#define DATA_MAX (1000)
#define DATA_SIZE (261)
#define KEY_SIZE (3)
#define PUT_DATA (KEY_SIZE+1)
#elif defined A2
#define DATA_MAX (10000)
#define DATA_SIZE (263)
#define KEY_SIZE (4)
#define PUT_DATA (KEY_SIZE+2)
#else	//B1
#define DATA_MAX (1025)
#define DATA_SIZE (262)
#define KEY_SIZE (5)
#define PUT_DATA (KEY_SIZE)
#define NUM_KEY (2)
#endif
#define DATA "data.txt"
#define FILE_OPEN_MODE "r"
#define FILE_OPEN_ERROR "�t�@�C���̃I�[�v���Ɏ��s���܂����B"
#define PROGRAM_END_STR "EXIT"
#define INPUT_KEY_MAX (128)
#define MSG_SIZE (128)
#define END_MAX (3)
#define END_SIZE (32)

static const char END[END_MAX][END_SIZE] = { { "EXIT" },{ "QUIT" },{ "END" } };

// ���b�Z�[�WID�񋓌^
typedef enum eMSG_NO
{
	eMSG_NO01 = 0,	/* ����ID01 */
	eMSG_NO02,		/* ����ID02 */
	eMSG_NO03,		/* ����ID03 */
	eMSG_NO04,		/* ����ID04 */
	eMSG_NO05,		/* ����ID05 */
	eMSG_MAX		/* �ő僁�b�Z�[�W�� */
} MSG_ID;

static const char MSG[eMSG_MAX][MSG_SIZE] = {
#if defined A1
{ "3���̐�������͂��ĉ�����[�I��/EXIT]:" },
#elif defined A2
{ "4���̐�������͂��ĉ�����[�I��/EXIT]:" },
#else	//B1
{"ID����͂��ĉ�����[�I��/EXIT]:"},
#endif
{ "[�Y���f�[�^]:" },
{ "[��������]:�Y���f�[�^�Ȃ�\n" },
{ "<ERROR>[�������ʒl]:" },
#if defined A2
{ "���͌������Ⴂ�܂�\n" }
#else	//A1,B1
{ "" }
#endif
};

void main(void) {
	FILE *fp;
	static char sBuf[DATA_MAX][DATA_SIZE];		/*�t�@�C���̒��g*/
	char key[INPUT_KEY_MAX];		/*�����L�[*/
	int checkData;		/*��v�f�[�^��������*/
	bool endFlg = false;
#if defined B1
	char numKey[INPUT_KEY_MAX] = "";
	char strKey[INPUT_KEY_MAX] = "";
#endif

	/*�t�@�C�����J���ăf�[�^��z��Ɋi�[*/
	if ((fp = fopen(DATA, FILE_OPEN_MODE)) == NULL) {
		printf(FILE_OPEN_ERROR);
		return;
	}

	for (int i = 0; i < DATA_MAX; i++) {
		fgets(&(sBuf[i][0]), DATA_SIZE, fp);
	}
	fclose(fp);

	/*�f�[�^����*/
	while (1) {
		printf(MSG[eMSG_NO01]);
		scanf("%s", key);

		/*�I�������`�F�b�N*/
#if defined B1
		/*�啶���ɕϊ�*/
		for (int i = 0; i <= strlen(key); i++) {
			if (key[i] >= 97 && key[i] <= 122) {
				key[i] = key[i] - 32;
			}
		}

		for (int i = 0; i < END_MAX; i++) {
			if (strcmp(key, END[i]) == 0) {
				endFlg = true;
				break;
			}
		}
#else	//A1,A2
		if (strcmp(key, PROGRAM_END_STR) == 0) {
			endFlg = true;
		}
#endif
		/*�I������*/
		if (endFlg == true) {
			break;
		}

#if defined A2
		/*�����L�[�̒����`�F�b�N*/
		if (strlen(key) != KEY_SIZE) {
			printf(MSG[eMSG_NO05]);
			continue;
		}
#endif

#if defined B1
		strncpy(strKey, key, NUM_KEY);
		strcpy(numKey, key + NUM_KEY);

		sprintf(key, "%s%03s", &strKey[0], &numKey[0]);
#endif

		/*�����L�[�ƈ�v����f�[�^��T��*/
		for (int i = 0; i < DATA_MAX; i++) {

			if ((checkData = memcmp(sBuf[i], key, KEY_SIZE)) == 0) {
				printf("%s%s", MSG[eMSG_NO02], &(sBuf[i][PUT_DATA]));
				break;
			}
		}
		if (checkData != 0) {
			printf(MSG[eMSG_NO03]);
		}
	}
	return;
}
