#include<stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

#define DATA_MAX (1000)
#define DATA_SIZE (261)
#define INPUT_KEY_MAX (256)
#define KEY_SIZE (3)

void main(void) {
	FILE *fp;
	char sBuf[DATA_MAX][DATA_SIZE];		/*ファイルの中身*/
	char key[INPUT_KEY_MAX];		/*検索キー*/
	int checkData;		/*一致データ検索結果*/

	/*ファイルを開いてデータを配列に格納*/
	if ((fp = fopen("data.txt", "r")) == NULL) {
		printf("ファイルのオープンに失敗しました。");
		return;
	}

	for (int i = 0; i < DATA_MAX; i++) {
		fgets(&(sBuf[i][0]), DATA_SIZE, fp);
	}
	fclose(fp);

	/*データ検索*/
	while (1) {
		printf("3桁の数字を入力して下さい[終了/EXIT]:");
		scanf("%s", key);

		/*EXITが入力されると終了*/
		if (strcmp(key, "EXIT") == 0) {
			break;
		}

		/*検索キーの長さチェック*/
		if (strlen(key) != KEY_SIZE) {
			printf("[検索結果]:該当データなし\n");
			continue;
		}
		
		/*検索キーと一致するデータを探す*/
		for (int i = 0; i < DATA_MAX; i++) {
			if ((checkData = memcmp(sBuf[i], key, KEY_SIZE)) == 0) {
				printf("[該当データ]:%s", &(sBuf[i][4]));
				break;
			}
		}
		if (checkData != 0) {
			printf("[検索結果]:該当データなし\n");
		}
	}
	return;
}