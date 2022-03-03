#include <stdio.h> //표준파일입출력 헤더
#include <stdlib.h> //rand() 사용을 위한 헤더

struct lottoinfo { //로또 정보를 저장하는 구조체
	int lottonumber; //로또 번호
	int lottofrq; //로또 번호 출현 빈도 수
	int print; //출력여부 위한 변수
};

int main()
{
	int i = 0, j = 0, k = 0; //반복문을 위한 변수
	int n, time; //유형, 실행 횟수
	int maxamount = 0; //최다출현값 개수. 우선은 0으로 초기화

	struct lottoinfo* maxs[100]; //최다출현값 저장 구조체 포인터 배열
	struct lottoinfo* lotto[150]; //150크기의 구조체 포인터 배열. 6개 번호의 로또 25회 가능
	struct lottoinfo* frequent; //최다출현값 저장하는 포인터 구조체
	struct lottoinfo* temp; //정렬 위한 임시 저장 구조체 포인터

	//구조체 포인터 배열의 전체 크기에서 요소(구조체 포인터)의 크기로 나눠서 요소 개수를 구함
	for (i = 0; i < sizeof(lotto) / sizeof(struct lottoinfo*); i++) //요소 개수만큼 반복
	{
		lotto[i] = malloc(sizeof(struct lottoinfo)); //각 요소에 구조체 크기만큼 메모리 할당
	}

	if (lotto == NULL) //동적 메모리 할당 오류가 날 경우 종료
	{
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	else
	{
		printf("로또 유형을 입력하세요(숫자를 입력하세요): ");
		scanf("%d", &n); //유형 입력 받기
		printf("로또 수행 횟수를 입력하세요(숫자를 입력하세요): ");
		scanf("%d", &time); //횟수 입력 받기

		for (i = 0; i < 6 * time; i++) //전체 로또 숫자 개수인 (6 * 횟수)만큼 반복
		{
			lotto[i]->lottofrq = 0; //lotto[i]의 출현횟수 0으로 초기화
			lotto[i]->print = 0; //프린트 수행했는지 여부 0으로 초기화
		}

		while (1) //계속 반복
		{
			for (k = 0; k < time; k++) //입력 받은 횟수 만큼 반복
			{
				for (i = 0; i < 6; i++)
				{
					while (i < 6)
					{
						lotto[i + (6 * k)]->lottonumber = ((rand() % n) + 1);
						//lotto 구조체 포인터 배열 'i + (6 * k)'인덱스에 로또번호 입력
						//난수 생성후 n으로 나눠 0 ~ (n-1)의 나머지 값을 얻고 1을 더해
						//1 ~ n 사이의 값을 lotto에 넣는다.

						for (j = 0; j < i; j++)
						{
							//중복된 수를 피하기 위해 lotto[0]부터 lotto[i]까지 검사
							if (lotto[i]->lottonumber == lotto[j]->lottonumber)
							{ //앞서 같은 번호가 뽑혔다면 i를 감소시키고 if문 탈출 후 lotto[i]를 다시 뽑는다
								i--;
								break;
							}
						}
						i++;
					}
				}
			}break;
		}

		frequent = lotto[0]; //frequent변수에 우선 [0]번 구조체 전달
		maxs[0] = frequent; //최댓값 저장배열에 frequent 전달

		//출현 횟수 조사
		for (i = 0; i < 6 * time; i++)
		{
			for (j = 0; j < 6 * time; j++)
			{
				if (lotto[i]->lottonumber == lotto[j]->lottonumber)
					//lotto숫자가 같은 것이 있다면
				{
					lotto[i]->lottofrq++; //구조체의 lottofrq(출현 횟수)를 증가 시킨다.
				}

				if (lotto[i]->lottofrq >= frequent->lottofrq)
					//lotto[i]의 출현 횟수가 frequent의 출현횟수(lotttofrq)보다 많다면
				{
					frequent = lotto[i]; //frequent는 lotto[i]가 된다.
				}
			}
		}

		//구조체 리스트 버블 정렬 시작
		for (i = 0; i < (6 * time - 1); i++)
		{
			for (j = 0; j < (6 * time - 1) - i; j++)
			{
				if (lotto[j]->lottonumber > lotto[j + 1]->lottonumber)
					//만약 lotto[j]의 lottonumber값이 lotto[j+1]의 값보다 크다면
				{
					temp = lotto[j];
					lotto[j] = lotto[j + 1];
					lotto[j + 1] = temp;
					//임시 포인터 temp, lotto[j], lotto[j+1]의 위치를 서로 바꿔 오름차순 정렬한다.
				}
			}
		}

		//구조체 포인터 배열 출력 시작
		printf("로또를 %d회 수행한 결과 통계입니다.\n", time);
		for (i = 0; i < 6 * time; i++)
		{ //lotto[i]의 print값은 0으로 초기화 되어있다.
			if (lotto[i]->print == 0) //lotto[i]->print 값이 0이면
			{
				printf("%2d는(은) %d번 나왔습니다\n", lotto[i]->lottonumber, lotto[i]->lottofrq);
				//어떤 숫자가 몇번 나왔는지 출력하기

				for (j = 0; j < 6 * time; j++)
				{
					if (lotto[j]->lottonumber == lotto[i]->lottonumber)
					{ //lottonumber값이 lotto[i]와 같은 lotto[j]값이 뒤에 있다면
						lotto[j]->print++;
						//그 lotto[j]값의 print변수를 증가시킨다.
						//결국 lotto[j]값은 i반복문의 if (lotto[i]->print == 0)으로 인해
						//중복되는 로또 값이 출력되지 않는다.
					}
				}
			}
		}

		//중복된 최다 출현값 찾기
		j = 0; //j값 0으로 초기화
		for (i = 0; i < 6 * time; i++)
		{
			if (lotto[i]->lottofrq == frequent->lottofrq)
			{ //frequent는 lottofrq값이 가장 큰 구조체값이 대입 되어있다.
				//근데 그 최대값과 lottofrq가 같은 값이 있다면
				maxs[j] = lotto[i]; //maxs배열에 lotto[i]값을 넣어준다.
				j++; //j값 증가시켜 maxs배열의 다음칸으로 이동
				maxamount++; //0으로 초기화 된 maxamount값을 증가시킨다.
			}
		}

		//최다 출현값 출력하기
		printf("\n가장 많이 출현한 숫자는 ");
		for (i = 0; i < maxamount; i = i + maxs[0]->lottofrq)
			//i=0부터 i가 maxmount보다 작을때 까지 반복.
			//i는 반복마다 maxs배열값의 lottofrq(최다 출현 횟수)만큼 증가한다.
			//결국 maxs배열 중 lottonumber가 다른 값들만 1회 출력된다.
		{
			printf("%d, ", maxs[i]->lottonumber);
		} printf("\b\b 입니다\n");
	}

	//동적 배열 해제
	for (int i = 0; i < sizeof(lotto) / sizeof(struct lottoinfo*); i++) // 요소 개수만큼 반복
	{
		free(lotto[i]); // 각 요소의 동적 메모리 해제
	}

	return 0;
}