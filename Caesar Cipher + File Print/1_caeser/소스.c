#include <stdio.h>

void encrypt(char plaintext[], int shift); //암호화 함수원형 선언
char plain[50]; //전역변수 선언

int main()
{
	int cipher_key; //암호키 변수 선언

	do {
		printf("암호키를 입력하세요(숫자 1~9): ");
		scanf("%d", &cipher_key);
	} while (1 > cipher_key || cipher_key > 9); //암호키 shift를 1에서 9까지만 입력받도록 제한

	getchar(); //gets 사용 위해 scanf의 남은 buffer(\n)를 버린다.

	printf("평문을 입력하세요: ");
	gets(plain, 50); //평문 입력 받기
	encrypt(plain, cipher_key); //encrypt 함수 시행
	
}

void encrypt(char plaintext[], int shift)
{
	int i = 0;
	FILE* fp = NULL; //파일 포인터 선언 후 NULL로 초기화
	fp = fopen("c:\\temp\\result.txt", "w"); 
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
	fclose(fp); //파일 닫기
	printf("암호화된 문자열: %s", plain); //암호화 된 값 출력
}