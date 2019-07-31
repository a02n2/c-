#include<stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

#define DATA_MAX (1000)
#define DATA_SIZE (261)
#define INPUT_KEY_MAX (256)
#define KEY_SIZE (3)
#define PUT_DATA (KEY_SIZE+1)
#define DATA "data.txt"
#define FILE_OPEN_MODE "r"
#define FILE_OPEN_ERROR "�t�@�C���̃I�[�v���Ɏ��s���܂����B"
#define PROGRAM_END_STR "EXIT"
#define INPUT_KEY_MAX (256)
#define MSG_SIZE (128)

typedef enum eMSG_NO
{
	eMSG_NO01 = 0,		/* ����ID01 */
	eMSG_NO02,		/* ����ID02 */
	eMSG_NO03,		/* ����ID03 */
	eMSG_NO04,		/* ����ID04 */
	eMSG_NO05,		/* ����ID05 */
	eMSG_MAX		/* �ő僁�b�Z�[�W�� */
} MSG_ID;

static const char MSG[eMSG_MAX][MSG_SIZE] = {
{ "3���̐�������͂��ĉ�����[�I��/EXIT]:" },
{ "[�Y���f�[�^]:" },
{ "[��������]:�Y���f�[�^�Ȃ�\n" },
{ "<ERROR>[�������ʒl]:" },
{ "" }
};

void main(void) {
	FILE *fp;
	char sBuf[DATA_MAX][DATA_SIZE];		/*�t�@�C���̒��g*/
	char key[INPUT_KEY_MAX];		/*�����L�[*/
	int checkData;		/*��v�f�[�^��������*/

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

		/*EXIT�����͂����ƏI��*/
		if (strcmp(key, PROGRAM_END_STR) == 0) {
			break;
		}

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