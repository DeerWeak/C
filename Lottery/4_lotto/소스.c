#include <stdio.h> //ǥ����������� ���
#include <stdlib.h> //rand() ����� ���� ���

int main()
{
	int i, j, n;// �ݺ����� ���� i, j. ������ ���� n ����
	int lotto[6]; //lotto �迭 ����

	FILE* fp = NULL; //���� ������ ���� �� NULL�� �ʱ�ȭ
	fp = fopen("c:\\Temp\\lotto.txt", "w");
	//write���� ��� ������ ������ �����ϰ� ����.

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

			fprintf(fp, "���õ� ��ȣ�� ������ �����ϴ�: "); //lotto.txt ���Ͽ� ���� ���
			printf("���õ� ��ȣ�� ������ �����ϴ�: ");
			for (i = 0; i < 6; i++) {
				printf("%d ", lotto[i]); //lotto�� �Էµ� ���� ���
				fprintf(fp, "%d ", lotto[i]); //lotto�� �Էµ� ������ lotto.txt ���Ϸ� ���
			}
		}
		break; //while�� Ż��
	}

	fclose(fp); //fp �ݾ��ֱ�
	return 0;
}