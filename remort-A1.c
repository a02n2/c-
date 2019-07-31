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
#define FILE_OPEN_ERROR "ファイルのオープンに失敗しました。"
#define PROGRAM_END_STR "EXIT"
#define INPUT_KEY_MAX (256)
#define MSG_SIZE (128)

typedef enum eMSG_NO
{
	eMSG_NO01 = 0,		/* 文言ID01 */
	eMSG_NO02,		/* 文言ID02 */
	eMSG_NO03,		/* 文言ID03 */
	eMSG_NO04,		/* 文言ID04 */
	eMSG_NO05,		/* 文言ID05 */
	eMSG_MAX		/* 最大メッセージ数 */
} MSG_ID;

static const char MSG[eMSG_MAX][MSG_SIZE] = {
{ "3桁の数字を入力して下さい[終了/EXIT]:" },
{ "[該当データ]:" },
{ "[検索結果]:該当データなし\n" },
{ "<ERROR>[検索結果値]:" },
{ "" }
};

void main(void) {
	FILE *fp;
	char sBuf[DATA_MAX][DATA_SIZE];		/*ファイルの中身*/
	char key[INPUT_KEY_MAX];		/*検索キー*/
	int checkData;		/*一致データ検索結果*/

	/*ファイルを開いてデータを配列に格納*/
	if ((fp = fopen(DATA, FILE_OPEN_MODE)) == NULL) {
		printf(FILE_OPEN_ERROR);
		return;
	}

	for (int i = 0; i < DATA_MAX; i++) {
		fgets(&(sBuf[i][0]), DATA_SIZE, fp);
	}
	fclose(fp);

	/*データ検索*/
	while (1) {
		printf(MSG[eMSG_NO01]);
		scanf("%s", key);

		/*EXITが入力されると終了*/
		if (strcmp(key, PROGRAM_END_STR) == 0) {
			break;
		}

		/*検索キーと一致するデータを探す*/
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