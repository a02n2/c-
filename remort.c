#include<stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

void main(void) {
	FILE *fp;
	char sBuf[1000][261];	/*ファイルの中身*/
	char key[256];	/*検索キー*/
	char *adr;		/*検索キーと合致するデータのアドレス*/

	/*ファイルを開いてデータを配列に格納*/
	if ((fp = fopen("data.txt", "r")) == NULL) {
		printf("ファイルのオープンに失敗しました。");
		return;
	}

	for (int i = 0; i < 1000; i++) {
		fgets(&(sBuf[i][0]), 261, fp);
	}
	fclose(fp);

	/*データ検索*/
	while (1) {
		printf("3桁の数字を入力して下さい[終了/EXIT]:");
		scanf("%s", key);

		/*EXITが入力されると終了*/
		if (strcmp(key, "EXIT") == 0) {
			return;
		}

		/*検索キーの長さが3でないとデータなし*/
		if (strlen(key) != 3) {
			printf("[検索結果]:該当データなし\n");
			continue;
		}
		
		/*検索キーと合致するデータを探す*/
		for (int i = 0; i < 1000; i++) {
			adr = strstr(sBuf[i], key);
			if (adr != NULL) {
				printf("[該当データ]:%s", &(sBuf[i][4]));
				break;
			}
		}
		if (adr == NULL) {
			printf("[検索結果]:該当データなし\n");
		}
	}
}