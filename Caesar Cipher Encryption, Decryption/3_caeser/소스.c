#include <stdio.h> //표준파일입출력 헤더
#include <stdlib.h> //atoi 사용을 위한 헤더

void encrypt(char plaintext[], int shift); //암호화 함수원형 선언
void decrypt(); //복호화 함수원형 선언
char plain[50]; //전역변수 선언

int main()
{
	int cipher_key = 0, select; //암호키 변수 및 모드 선택 변수 선언

	do {
		printf("암호화 모드, 복호화 모드를 선택하세요(암호화 = 1, 복호화 = 0): ");
		scanf("%d", &select); //모드를 입력 받습니다.
	} while (select != 1 && select != 0); //mode값을 1과 0으로 제한

	do {
		if (select == 1) { //암호화 모드이면
			printf("암호키를 입력하세요(숫자 1~9): ");
			scanf("%d", &cipher_key); //암호키 입력 받기
		}
		else break;
	} while (1 > cipher_key || cipher_key > 9); //암호키 shift를 1에서 9까지만 입력받도록 제한

	getchar(); //gets 사용 위해 scanf의 남은 buffer(\n)를 버린다.

	if (select == 1) //암호화 모드
	{
		printf("평문을 입력하세요: ");
		gets(plain, 50); //평문 입력 받기
		encrypt(plain, cipher_key); //encrypt 함수 시행
	}
	else //복호화 모드
	{
		decrypt(); //decrypt 함수 시행
	}
	return 0;
}

void encrypt(char plaintext[], int shift)
{
	int i = 0; //반복문 위한 i
	FILE* fp = NULL; //파일 포인터 선언 후 NULL로 초기화
	fp = fopen("c:\\Temp\\result.txt", "w");
	//write모드로 열어서 파일이 없으면 생성하고 연다.

	fprintf(fp, "key %d\n", shift); //fp 파일에 key와 shift값을 출력

	while (plain[i] != '\0') { //plain[i]가 널문자가 아닐 동안
		if (plain[i] >= 'a' && plain[i] <= 'z') { //문자가 a~z일 때(아스키 코드)
			plain[i] += shift; //문자를 shift값 만큼 + 해준다.

			if (plain[i] > 'z') //문자가 z를 초과할 경우(아스키 코드)
				plain[i] -= 26; //알파벳 개수인 26을 빼 a부터 다시 시작하게 만든다.
		}
		i++; //plain[i]가 널문자이기 전까지 반복해서 i++
	}

	fprintf(fp, "ciphertext %s", plain); //fp 파일에 ciherpext와 암호문 출력
	fclose(fp); //fp파일을 닫아준다.
	printf("암호화된 문자열: %s", plain); //암호화 된 값 출력
}

void decrypt()
{
	char address[50]; //파일 주소를 입력받는 문자열 변수
	FILE* fp = NULL; //FILE을 카리키는 포인터 fp선언
	printf("파일의 경로를 입력하세요: ");
	gets(address, 50); //파일의 경로 c:\\Temp\\result.txt 입력 받기

	fp = fopen(address, "r"); //address 경로를 읽기모드로 연다.

	if (fp == NULL) //파일이 열리지 않았으면
	{
		printf("파일 열기 실패\n");
		printf("복호화할 파일이 없습니다. 프로그램을 종료합니다.\n");
	}
	else //파일이 열렸으면
	{
		int i = 0; //반복문 시행 위한 변수 i
		char buffer[50]; //문장을 가져오는 buffer
		char strsum[50] = ""; //buffer를 합치기 위한 변수, 초기화
		char cipher[50]; //암호문만 저장하는 변수
		int shift = 0; //key 값 찾기 위한 변수
		char charshift; //key 값 변환 위한 변수

		while (fgets(buffer, 50, fp) != NULL) {
			//50크기의 버퍼로 fp파일에서 한문장씩 buffer를 가져와
			strcat(strsum, buffer); // strsum에 buffer를 이어 붙인다.
		}

		for (i = 17; i < 50; i++) { //복호화된 문장 시작점인 17번째 부터 끝까지
			cipher[i - 17] = strsum[i];
			//cipher에 strsum의 복호화된 문장만 넣는다.
		}

		shift = atoi(&strsum[4]);
		//strsum에 저장된 문자열 key값을 shift에 정수로 변환하여 넣어준다.

		i = 0; //i값이 50이 되었기 때문에 0으로 초기화
		while (cipher[i] != '\0') { //cipher[i]가 널문자가 아닐 동안
			if (cipher[i] >= 'a' && cipher[i] <= 'z') { //문자가 a~z일 때(아스키 코드)
				cipher[i] -= shift; //문자를 shift값 만큼 - 해준다.

				if (cipher[i] < 'a') //문자가 a보다 작아질 경우(아스키 코드)
					cipher[i] += 26; //알파벳 개수인 26을 더해 z부터 다시 시작하게 만든다.
			}
			i++;
		}

		printf("복호화된 문자열: %s\n", cipher); //전역변수 cipher 사용
		fclose(fp); //파일을 닫는다.
	}
}