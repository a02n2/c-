#include<stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

void main(void) {
	FILE *fp;
	char sBuf[1000][261];	/*�t�@�C���̒��g*/
	char key[256];	/*�����L�[*/
	char *adr;		/*�����L�[�ƍ��v����f�[�^�̃A�h���X*/

	/*�t�@�C�����J���ăf�[�^��z��Ɋi�[*/
	if ((fp = fopen("data.txt", "r")) == NULL) {
		printf("�t�@�C���̃I�[�v���Ɏ��s���܂����B");
		return;
	}

	for (int i = 0; i < 1000; i++) {
		fgets(&(sBuf[i][0]), 261, fp);
	}
	fclose(fp);

	/*�f�[�^����*/
	while (1) {
		printf("3���̐�������͂��ĉ�����[�I��/EXIT]:");
		scanf("%s", key);

		/*EXIT�����͂����ƏI��*/
		if (strcmp(key, "EXIT") == 0) {
			return;
		}

		/*�����L�[�̒�����3�łȂ��ƃf�[�^�Ȃ�*/
		if (strlen(key) != 3) {
			printf("[��������]:�Y���f�[�^�Ȃ�\n");
			continue;
		}
		
		/*�����L�[�ƍ��v����f�[�^��T��*/
		for (int i = 0; i < 1000; i++) {
			adr = strstr(sBuf[i], key);
			if (adr != NULL) {
				printf("[�Y���f�[�^]:%s", &(sBuf[i][4]));
				break;
			}
		}
		if (adr == NULL) {
			printf("[��������]:�Y���f�[�^�Ȃ�\n");
		}
	}
}