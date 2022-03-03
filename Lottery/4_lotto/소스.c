#include <stdio.h> //표준파일입출력 헤더
#include <stdlib.h> //rand() 사용을 위한 헤더

int main()
{
	int i, j, n;// 반복문을 위한 i, j. 유형을 위한 n 선언
	int lotto[6]; //lotto 배열 선언

	FILE* fp = NULL; //파일 포인터 선언 후 NULL로 초기화
	fp = fopen("c:\\Temp\\lotto.txt", "w");
	//write모드로 열어서 파일이 없으면 생성하고 연다.

	printf("로또 유형을 입력하세요(숫자를 입력하세요): ");
	scanf("%d", &n); //로또 유형 입력 받기

	while (1) { //계속 반복
		for (i = 0; i < 6; i++) { //6번 반복한다
			while (i < 6) { //i가 6과 같아지기 전까지
				lotto[i] = ((rand() % n) + 1);
				//난수 생성후 n으로 나눠 0 ~ (n-1)의 나머지 값을 얻고 1을 더해
				//1 ~ n 사이의 값을 lotto에 넣는다.

				for (j = 0; j < i; j++) {
					//중복된 수를 피하기 위해 lotto[0]부터 lotto[i]까지 검사
					if (lotto[i] == lotto[j]) { //앞서 같은 번호가 뽑혔다면
						i--; //i를 감소시켜 lotto[i]를 다시 뽑는다
						break; //반복문 나가기
					}
				}
				i++;
			}

			fprintf(fp, "선택된 번호는 다음과 같습니다: "); //lotto.txt 파일에 문장 출력
			printf("선택된 번호는 다음과 같습니다: ");
			for (i = 0; i < 6; i++) {
				printf("%d ", lotto[i]); //lotto에 입력된 값들 출력
				fprintf(fp, "%d ", lotto[i]); //lotto에 입력된 값들을 lotto.txt 파일로 출력
			}
		}
		break; //while문 탈출
	}

	fclose(fp); //fp 닫아주기
	return 0;
}