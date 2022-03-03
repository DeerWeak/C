#include <stdio.h>

void encrypt(char plaintext[], int shift); //함수원형 선언
void decrypt(char ciphertext[], int shift); //함수원형 선언
char cipher[50]; //전역변수 선언
char plain[50]; //전역변수 선언

int main()
{
	int shift, mode; //shift값과 암호화 혹은 복호화 모드를 입력받을 변수

	do {
		printf("암호키를 입력하세요(숫자 1~9): ");
		scanf("%d", &shift);
	} while (1 > shift || shift > 9); //암호키 shift를 1에서 9까지만 입력받도록 제한

	do {
		printf("암호화 모드, 복호화 모드를 선택하세요(암호화 = 1, 복호화 = 0): ");
		scanf("%d", &mode); // 복호화 모드를 입력 받습니다.
	} while (mode != 1 && mode != 0); //mode값을 1과 0으로 제한


	if (mode == 1)
	{
		printf("평문을 입력하세요: ");
		scanf("%s", &plain);
		encrypt(plain, shift); //encrypt 함수 시행
	}
	else if (mode == 0)
	{
		printf("암호문을 입력하세요: ");
		scanf("%s", &cipher);
		decrypt(cipher, shift); //decrypt 함수 시행
	}

	return 0;
}

void encrypt(char plaintext[], int shift)
{
	int i = 0;

	while (plain[i] != '\0') { //plain[i]가 널문자가 아닐 동안
		if (plain[i] >= 'a' && plain[i] <= 'z') { //문자가 a~z일 때(아스키 코드)
			plain[i] += shift; //문자를 shift값 만큼 + 해준다.

			if (plain[i] > 'z') //문자가 z를 초과할 경우(아스키 코드)
				plain[i] -= 26; //알파벳 개수인 26을 빼 a부터 다시 시작하게 만든다.
		}
		i++; //plain[i]가 널문자이기 전까지 반복해서 i++
	}
	printf("암호화된 문자열: %s\n", plain); //전역변수 plain 사용
}

void decrypt(char cipher[], int shift)
{
	int i = 0;

	while (cipher[i] != '\0') { //cipher[i]가 널문자가 아닐 동안
		if (cipher[i] >= 'a' && cipher[i] <= 'z') { //문자가 a~z일 때(아스키 코드)
			cipher[i] -= shift; //문자를 shift값 만큼 - 해준다.

			if (cipher[i] < 'a') //문자가 a보다 작아질 경우(아스키 코드)
				cipher[i] += 26; //알파벳 개수인 26을 더해 z부터 다시 시작하게 만든다.
		}
		i++;
	}
	printf("암호화된 문자열: %s\n", cipher); //전역변수 cipher 사용
}