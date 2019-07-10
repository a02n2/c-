#include<stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

#define DATA_MAX (1000)
#define DATA_SIZE (261)
#define INPUT_KEY_MAX (256)
#define KEY_SIZE (3)

void main(void) {
	FILE *fp;
	char sBuf[DATA_MAX][DATA_SIZE];		/*�t�@�C���̒��g*/
	char key[INPUT_KEY_MAX];		/*�����L�[*/
	int checkData;		/*��v�f�[�^��������*/

	/*�t�@�C�����J���ăf�[�^��z��Ɋi�[*/
	if ((fp = fopen("data.txt", "r")) == NULL) {
		printf("�t�@�C���̃I�[�v���Ɏ��s���܂����B");
		return;
	}

	for (int i = 0; i < DATA_MAX; i++) {
		fgets(&(sBuf[i][0]), DATA_SIZE, fp);
	}
	fclose(fp);

	/*�f�[�^����*/
	while (1) {
		printf("3���̐�������͂��ĉ�����[�I��/EXIT]:");
		scanf("%s", key);

		/*EXIT�����͂����ƏI��*/
		if (strcmp(key, "EXIT") == 0) {
			break;
		}

		/*�����L�[�̒����`�F�b�N*/
		if (strlen(key) != KEY_SIZE) {
			printf("[��������]:�Y���f�[�^�Ȃ�\n");
			continue;
		}
		
		/*�����L�[�ƈ�v����f�[�^��T��*/
		for (int i = 0; i < DATA_MAX; i++) {
			if ((checkData = memcmp(sBuf[i], key, KEY_SIZE)) == 0) {
				printf("[�Y���f�[�^]:%s", &(sBuf[i][4]));
				break;
			}
		}
		if (checkData != 0) {
			printf("[��������]:�Y���f�[�^�Ȃ�\n");
		}
	}
	return;
}