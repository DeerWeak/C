#include <stdio.h>

struct student {
	int number; //학번
	char name[20]; //이름
	char score; //평점
	double grade; //학점
};

struct student list[3]; //학생 3명을 저장할 구조체 배열

int main()
{
	int i;
	double sum = 0, average;
	//평점들의 합을 구하기 위한 sum과 평균을 내기 위한 average 선언

	struct student best; //평점이 가장 높은 학생을 저장하는 구조체

	for (i = 0; i < 3; i++)
	{
			printf("%d번째 학생 정보 입력하세요\n", i + 1);
			printf("%d번째 학생 학번: ", i + 1);
			scanf("%d", &list[i].number);
			printf("%d번째 학생 이름: ", i + 1);
			scanf("%s", &list[i].name);
			printf("%d번째 학생 평점: ", i + 1);
			scanf("%lf", &list[i].grade);

			if (list[i].grade >= 4.0) //if-else문으로 평점과 학점을 처리하여 list[].score에 저장합니다.
				list[i].score = 'A';
			else if (list[i].grade >= 3.0)
				list[i].score = 'B';
			else if (list[i].grade >= 2.0)
				list[i].score = 'C';
			else if (list[i].grade >= 1.0)
				list[i].score = 'D';
			else
				list[i].score = 'F';

			printf("\n");
	}

	for (i = 0; i < 3; i++)
		sum = sum + list[i].grade; //list의 grade값을 sum에 모두 더해준다.
	average = sum / 3; //평균값은 sum을 인원 수로 나눠준 값

	best = list[0]; //grade의 최대값을 구하기 위해 우선 best에 배열의 첫번째 구조체 전달
	for (i = 1; i < 3; i++) //list의 1번 값부터 2번 값까지
		if (list[i].grade > best.grade) //만약 0번 grade(best)보다 그 후의 grade값이 높다면
			best = list[i]; //best 구조체에 i번째 구조체를 저장

	printf("평점이 가장 높은 학생은(이름: %s, 학번: %d, 평점: %.2lf)입니다.\n\n", best.name, best.number, best.grade);
	printf("본 학급의 평균 평점은 %.2lf입니다.\n\n", average); //평점은 보통 소수점 2자리까지 계산하므로 제한해준다.

	for (i = 0; i < 3; i++)
		printf("%s 학생의 성적은 %c입니다.\n", list[i].name, list[i].score);

	return 0;
}