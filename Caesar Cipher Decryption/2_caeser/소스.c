#include <stdio.h> //표준파일입출력 헤더
#include <stdlib.h> //atoi 사용을 위한 헤더

void decrypt(); //복호화 함수원형 선언
char address[50]; //파일 주소를 입력받는 문자열 배열 전역변수

int main()
{
	printf("파일의 경로를 입력하세요: ");
	gets(address, 50); //파일의 경로 c:\\Temp\\result.txt 입력 받기
	
	decrypt(); //decrypt 함수 시행

	return 0;
}

void decrypt()
{
	FILE* fp = NULL; //FILE을 카리키는 포인터 fp선언
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