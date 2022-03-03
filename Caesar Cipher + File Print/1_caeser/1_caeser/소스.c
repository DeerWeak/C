#include <stdio.h>

void encrypt(char plaintext[], int shift); //��ȣȭ �Լ����� ����
char plain[50]; //�������� ����

int main()
{
	int cipher_key; //��ȣŰ ���� ����

	do {
		printf("��ȣŰ�� �Է��ϼ���(���� 1~9): ");
		scanf("%d", &cipher_key);
	} while (1 > cipher_key || cipher_key > 9); //��ȣŰ shift�� 1���� 9������ �Է¹޵��� ����

	getchar(); //gets ��� ���� scanf�� ���� buffer(\n)�� ������.

	printf("���� �Է��ϼ���: ");
	gets(plain, 50); //�� �Է� �ޱ�
	encrypt(plain, cipher_key); //encrypt �Լ� ����
	
}

void encrypt(char plaintext[], int shift)
{
	int i = 0;
	FILE* fp = NULL; //���� ������ ���� �� NULL�� �ʱ�ȭ
	fp = fopen("c:\\temp\\result.txt", "w"); 
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
	fclose(fp); //���� �ݱ�
	printf("��ȣȭ�� ���ڿ�: %s", plain); //��ȣȭ �� �� ���
}