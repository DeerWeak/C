#include <stdio.h> //ǥ����������� ���
#include <stdlib.h> //atoi ����� ���� ���

void encrypt(char plaintext[], int shift); //��ȣȭ �Լ����� ����
void decrypt(); //��ȣȭ �Լ����� ����
char plain[50]; //�������� ����

int main()
{
	int cipher_key = 0, select; //��ȣŰ ���� �� ��� ���� ���� ����

	do {
		printf("��ȣȭ ���, ��ȣȭ ��带 �����ϼ���(��ȣȭ = 1, ��ȣȭ = 0): ");
		scanf("%d", &select); //��带 �Է� �޽��ϴ�.
	} while (select != 1 && select != 0); //mode���� 1�� 0���� ����

	do {
		if (select == 1) { //��ȣȭ ����̸�
			printf("��ȣŰ�� �Է��ϼ���(���� 1~9): ");
			scanf("%d", &cipher_key); //��ȣŰ �Է� �ޱ�
		}
		else break;
	} while (1 > cipher_key || cipher_key > 9); //��ȣŰ shift�� 1���� 9������ �Է¹޵��� ����

	getchar(); //gets ��� ���� scanf�� ���� buffer(\n)�� ������.

	if (select == 1) //��ȣȭ ���
	{
		printf("���� �Է��ϼ���: ");
		gets(plain, 50); //�� �Է� �ޱ�
		encrypt(plain, cipher_key); //encrypt �Լ� ����
	}
	else //��ȣȭ ���
	{
		decrypt(); //decrypt �Լ� ����
	}
	return 0;
}

void encrypt(char plaintext[], int shift)
{
	int i = 0; //�ݺ��� ���� i
	FILE* fp = NULL; //���� ������ ���� �� NULL�� �ʱ�ȭ
	fp = fopen("c:\\Temp\\result.txt", "w");
	//write���� ��� ������ ������ �����ϰ� ����.

	fprintf(fp, "key %d\n", shift); //fp ���Ͽ� key�� shift���� ���

	while (plain[i] != '\0') { //plain[i]�� �ι��ڰ� �ƴ� ����
		if (plain[i] >= 'a' && plain[i] <= 'z') { //���ڰ� a~z�� ��(�ƽ�Ű �ڵ�)
			plain[i] += shift; //���ڸ� shift�� ��ŭ + ���ش�.

			if (plain[i] > 'z') //���ڰ� z�� �ʰ��� ���(�ƽ�Ű �ڵ�)
				plain[i] -= 26; //���ĺ� ������ 26�� �� a���� �ٽ� �����ϰ� �����.
		}
		i++; //plain[i]�� �ι����̱� ������ �ݺ��ؼ� i++
	}

	fprintf(fp, "ciphertext %s", plain); //fp ���Ͽ� ciherpext�� ��ȣ�� ���
	fclose(fp); //fp������ �ݾ��ش�.
	printf("��ȣȭ�� ���ڿ�: %s", plain); //��ȣȭ �� �� ���
}

void decrypt()
{
	char address[50]; //���� �ּҸ� �Է¹޴� ���ڿ� ����
	FILE* fp = NULL; //FILE�� ī��Ű�� ������ fp����
	printf("������ ��θ� �Է��ϼ���: ");
	gets(address, 50); //������ ��� c:\\Temp\\result.txt �Է� �ޱ�

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