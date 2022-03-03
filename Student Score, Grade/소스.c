#include <stdio.h>

struct student {
	int number; //�й�
	char name[20]; //�̸�
	char score; //����
	double grade; //����
};

struct student list[3]; //�л� 3���� ������ ����ü �迭

int main()
{
	int i;
	double sum = 0, average;
	//�������� ���� ���ϱ� ���� sum�� ����� ���� ���� average ����

	struct student best; //������ ���� ���� �л��� �����ϴ� ����ü

	for (i = 0; i < 3; i++)
	{
			printf("%d��° �л� ���� �Է��ϼ���\n", i + 1);
			printf("%d��° �л� �й�: ", i + 1);
			scanf("%d", &list[i].number);
			printf("%d��° �л� �̸�: ", i + 1);
			scanf("%s", &list[i].name);
			printf("%d��° �л� ����: ", i + 1);
			scanf("%lf", &list[i].grade);

			if (list[i].grade >= 4.0) //if-else������ ������ ������ ó���Ͽ� list[].score�� �����մϴ�.
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
		sum = sum + list[i].grade; //list�� grade���� sum�� ��� �����ش�.
	average = sum / 3; //��հ��� sum�� �ο� ���� ������ ��

	best = list[0]; //grade�� �ִ밪�� ���ϱ� ���� �켱 best�� �迭�� ù��° ����ü ����
	for (i = 1; i < 3; i++) //list�� 1�� ������ 2�� ������
		if (list[i].grade > best.grade) //���� 0�� grade(best)���� �� ���� grade���� ���ٸ�
			best = list[i]; //best ����ü�� i��° ����ü�� ����

	printf("������ ���� ���� �л���(�̸�: %s, �й�: %d, ����: %.2lf)�Դϴ�.\n\n", best.name, best.number, best.grade);
	printf("�� �б��� ��� ������ %.2lf�Դϴ�.\n\n", average); //������ ���� �Ҽ��� 2�ڸ����� ����ϹǷ� �������ش�.

	for (i = 0; i < 3; i++)
		printf("%s �л��� ������ %c�Դϴ�.\n", list[i].name, list[i].score);

	return 0;
}