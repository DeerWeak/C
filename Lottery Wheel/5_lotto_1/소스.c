#include <stdio.h> //표준파일입출력 헤더
#include <stdlib.h> //rand(), atoi() 사용을 위한 헤더

int main()
{
	char address[50]; //파일의 주소 입력 받는 변수
	srand(202112); //srand()와 시드로 202112 설정

	FILE* fp = NULL; //파일 포인터 선언 후 NULL로 초기화
	printf("로또 결과 저장 경로를 입력하세요: ");
	gets(address, 50); //파일의 경로 c:\\Temp\\lotto.txt 입력 받기
	fp = fopen(address, "r"); //address 주소의 파일을 읽기모드로 열기

	if (fp == NULL) //파일이 열리지 않았으면
	{
		printf("파일 열기 실패\n");
		printf("로또 번호를 확인할 파일이 없습니다. 프로그램을 종료합니다.\n");
	}
	else //파일이 열렸으면
	{
		int i, j, n;// 반복문을 위한 i, j. 유형을 위한 n 선언
		int lotto[6]; //생성된 lotto번호를 위한 정수형 배열 선언
		int hit = 0; //맞힌 로또번호의 개수를 위한 변수
		char str1[10], str2[10], str3[10], str4[20]; //fscanf에서 문자열들 입력을 위한 변수
		int myNumber[6]; //내 로또번호 저장하는 정수형 배열
		

		printf("로또 유형을 입력하세요(숫자를 입력하세요): ");
		scanf("%d", &n); //로또 유형 입력 받기

		//로또 번호 생성하기
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
					i++; //i 증가
				}

				//이번주차 당첨번호 출력
				printf("이번주차 당첨번호는: ");
				for (i = 0; i < 6; i++) {
					printf("%d ", lotto[i]); //lotto에 입력된 값들 출력
				} printf("\n");

				//형식화된 입출력으로 lotto.txt 안의 내용들을 읽어와 변수에 저장한다.
				fscanf(fp, "%s %s %s %s %d %d %d %d %d %d",
					str1, str2, str3, str4,
					&myNumber[0], &myNumber[1], &myNumber[2],
					&myNumber[3], &myNumber[4], &myNumber[5]);

				//intnumber[]에 저장된 내 로또번호 출력
				printf("고객님의 번호는: ");
				for (i = 0; i < 6; i++) {
					printf("%d ", myNumber[i]); //
				}
				printf("입니다.\n");

				//로또 당첨 여부 확인
				for (i = 0; i < 6; i++) { //i=0부터 i=5까지 6번 반복
					for (j = 0; j < 6; j++) { //j=0부터 j=5까지 6번 반복
						if (myNumber[i] == lotto[j]) { //내[i]번 번호가 [j]번 로또번호와 같은 것이 있다면
							hit++; //hit증가
						}
					}
				}

				//당첨여부 출력
				if (hit == 6) { //hit값이 6이면 6개가 맞았다는 뜻이므로 당첨
					printf("축하합니다! 당첨입니다.\n");
				}
				else { //아닐경우 낙첨
					printf("아쉽습니다. 낙첨입니다.\n");
				}
			}
			break; //while문 탈출
		}
	}

	fclose(fp); //파일을 닫는다.
	return 0;
}