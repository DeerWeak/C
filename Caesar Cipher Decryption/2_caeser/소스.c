#include <stdio.h> //ǥ����������� ���
#include <stdlib.h> //atoi ����� ���� ���

void decrypt(); //��ȣȭ �Լ����� ����
char address[50]; //���� �ּҸ� �Է¹޴� ���ڿ� �迭 ��������

int main()
{
	printf("������ ��θ� �Է��ϼ���: ");
	gets(address, 50); //������ ��� c:\\Temp\\result.txt �Է� �ޱ�
	
	decrypt(); //decrypt �Լ� ����

	return 0;
}

void decrypt()
{
	FILE* fp = NULL; //FILE�� ī��Ű�� ������ fp����
	fp = fopen(address, "r"); //address ��θ� �б���� ����.

	if (fp == NULL) //������ ������ �ʾ�����
	{
		printf("���� ���� ����\n");
		printf("��ȣȭ�� ������ �����ϴ�. ���α׷��� �����մϴ�.\n");
	}
	else //������ ��������
	{
		int i = 0; //�ݺ��� ���� ���� ���� i
		char buffer[50]; //������ �������� buffer
		char strsum[50] = ""; //buffer�� ��ġ�� ���� ����, �ʱ�ȭ
		char cipher[50]; //��ȣ���� �����ϴ� ����
		int shift = 0; //key �� ã�� ���� ����
		char charshift; //key �� ��ȯ ���� ����

		while (fgets(buffer, 50, fp) != NULL) {
			//50ũ���� ���۷� fp���Ͽ��� �ѹ��徿 buffer�� ������
			strcat(strsum, buffer); // strsum�� buffer�� �̾� ���δ�.
		}

		for (i = 17; i < 50; i++) { //��ȣȭ�� ���� �������� 17��° ���� ������
			cipher[i - 17] = strsum[i];
			//cipher�� strsum�� ��ȣȭ�� ���常 �ִ´�.
		}
		
		shift = atoi(&strsum[4]);
		//strsum�� ����� ���ڿ� key���� shift�� ������ ��ȯ�Ͽ� �־��ش�.
	
		i = 0; //i���� 50�� �Ǿ��� ������ 0���� �ʱ�ȭ
		while (cipher[i] != '\0') { //cipher[i]�� �ι��ڰ� �ƴ� ����
			if (cipher[i] >= 'a' && cipher[i] <= 'z') { //���ڰ� a~z�� ��(�ƽ�Ű �ڵ�)
				cipher[i] -= shift; //���ڸ� shift�� ��ŭ - ���ش�.

				if (cipher[i] < 'a') //���ڰ� a���� �۾��� ���(�ƽ�Ű �ڵ�)
					cipher[i] += 26; //���ĺ� ������ 26�� ���� z���� �ٽ� �����ϰ� �����.
			}
			i++;
		}

		printf("��ȣȭ�� ���ڿ�: %s\n", cipher); //�������� cipher ���
		fclose(fp); //������ �ݴ´�.
	}
}