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
#else	//A2
#define DATA_MAX (10000)
#define DATA_SIZE (263)
#define KEY_SIZE (4)
#define PUT_DATA (KEY_SIZE+2)
#endif
#define DATA "data.txt"
#define FILE_OPEN_MODE "r"
#define FILE_OPEN_ERROR "ファイルのオープンに失敗しました。"
#define PROGRAM_END_STR "EXIT"
#define INPUT_KEY_MAX (256)
#define MSG_SIZE (128)

// メッセージID列挙型
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
#if defined A1
{ "3桁の数字を入力して下さい[終了/EXIT]:" },
#else	//A2
{ "4桁の数字を入力して下さい[終了/EXIT]:" },
#endif
{ "[該当データ]:" },
{ "[検索結果]:該当データなし\n" },
{ "<ERROR>[検索結果値]:" },
#if defined A1
{ "" }
#else	//A2
{"入力桁数が違います\n"}
#endif
};

void main(void) {
	FILE *fp;
	static char sBuf[DATA_MAX][DATA_SIZE];		/*ファイルの中身*/
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

#if defined (A2)
		/*検索キーの長さチェック*/
		if (strlen(key) != KEY_SIZE) {
			printf(MSG[eMSG_NO05]);
			continue;
		}
#endif

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
