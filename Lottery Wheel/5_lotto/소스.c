#include <stdio.h> //ǥ����������� ���
#include <stdlib.h> //rand(), atoi() ����� ���� ���

int main()
{
	char address[50]; //������ �ּ� �Է� �޴� ����
	srand(202112); //srand()�� �õ�� 202112 ����

	FILE* fp = NULL; //���� ������ ���� �� NULL�� �ʱ�ȭ
	printf("�ζ� ��� ���� ��θ� �Է��ϼ���: ");
	gets(address, 50); //������ ��� c:\\Temp\\lotto.txt �Է� �ޱ�
	fp = fopen(address, "r");
	//address �ּ��� ������ �б���� ����

	if (fp == NULL) //������ ������ �ʾ�����
	{
		printf("���� ���� ����\n");
		printf("�ζ� ��ȣ�� Ȯ���� ������ �����ϴ�. ���α׷��� �����մϴ�.\n");
	}
	else //������ ��������
	{
		int i, j, n;// �ݺ����� ���� i, j. ������ ���� n ����
		int lotto[6]; //������ lotto��ȣ�� ���� ������ �迭 ����
		int hit = 0; //���� �ζǹ�ȣ�� ������ ���� ����
		char str1[10], str2[10], str3[10], str4[20]; //fscanf���� ���ڿ��� �Է��� ���� ����
		int* myNumber; //�� �ζǹ�ȣ �����ϴ� ������ ������ �迭
		myNumber = (int*)malloc(6 * sizeof(int)); //int�� 6�� ��ŭ �����Ҵ� ���ش�.

		printf("�ζ� ������ �Է��ϼ���(���ڸ� �Է��ϼ���): ");
		scanf("%d", &n); //�ζ� ���� �Է� �ޱ�

		while (1) { //��� �ݺ�
			for (i = 0; i < 6; i++) { //6�� �ݺ��Ѵ�
				while (i < 6) { //i�� 6�� �������� ������
					lotto[i] = ((rand() % n) + 1);
					//���� ������ n���� ���� 0 ~ (n-1)�� ������ ���� ��� 1�� ����
					//1 ~ n ������ ���� lotto�� �ִ´�.

					for (j = 0; j < i; j++) {
						//�ߺ��� ���� ���ϱ� ���� lotto[0]���� lotto[i]���� �˻�
						if (lotto[i] == lotto[j]) { //�ռ� ���� ��ȣ�� �����ٸ�
							i--; //i�� ���ҽ��� lotto[i]�� �ٽ� �̴´�
							break; //�ݺ��� ������
						}
					}
					i++;
				}

				printf("�̹����� ��÷��ȣ��: ");
				for (i = 0; i < 6; i++) {
					printf("%d ", lotto[i]); //lotto�� �Էµ� ���� ���
				} printf("\n");

				//����ȭ�� ��������� lotto.txt ���� ������� �о�� ������ �����Ѵ�.
				fscanf(fp, "%s %s %s %s %d %d %d %d %d %d",
					str1, str2, str3, str4,
					&myNumber[0], &myNumber[1], &myNumber[2],
					&myNumber[3], &myNumber[4], &myNumber[5]);

				//intnumber[]�� ����� �� �ζǹ�ȣ ���
				printf("������ ��ȣ��: ");
				for (i = 0; i < 6; i++) {
					printf("%d ", myNumber[i]); //
				}
				printf("�Դϴ�.\n");

				for (i = 0; i < 6; i++) { //6�� �ݺ��Ѵ�
					for(j = 0; j < 6; j++) {
						if (myNumber[i] == lotto[j]) { //�� �ζ� ��ȣ�� ���� �ζ� ��ȣ�� ���� ���� �ִٸ�
							hit++;
							}
						}
					}

				if (hit == 6) {
					printf("�����մϴ�! ��÷�Դϴ�.\n");
				}
				else {
					printf("�ƽ����ϴ�. ��÷�Դϴ�.\n");
				}
			}
			break; //while�� Ż��
		}
	}

	fclose(fp); //������ �ݴ´�.
	return 0;
}