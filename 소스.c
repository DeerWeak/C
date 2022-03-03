#include <stdio.h>

void encrypt(char plaintext[], int shift); //�Լ����� ����
void decrypt(char ciphertext[], int shift); //�Լ����� ����
char cipher[50]; //�������� ����
char plain[50]; //�������� ����

int main()
{
	int shift, mode; //shift���� ��ȣȭ Ȥ�� ��ȣȭ ��带 �Է¹��� ����

	do {
		printf("��ȣŰ�� �Է��ϼ���(���� 1~9): ");
		scanf("%d", &shift);
	} while (1 > shift || shift > 9); //��ȣŰ shift�� 1���� 9������ �Է¹޵��� ����

	do {
		printf("��ȣȭ ���, ��ȣȭ ��带 �����ϼ���(��ȣȭ = 1, ��ȣȭ = 0): ");
		scanf("%d", &mode); // ��ȣȭ ��带 �Է� �޽��ϴ�.
	} while (mode != 1 && mode != 0); //mode���� 1�� 0���� ����


	if (mode == 1)
	{
		printf("���� �Է��ϼ���: ");
		scanf("%s", &plain);
		encrypt(plain, shift); //encrypt �Լ� ����
	}
	else if (mode == 0)
	{
		printf("��ȣ���� �Է��ϼ���: ");
		scanf("%s", &cipher);
		decrypt(cipher, shift); //decrypt �Լ� ����
	}

	return 0;
}

void encrypt(char plaintext[], int shift)
{
	int i = 0;

	while (plain[i] != '\0') { //plain[i]�� �ι��ڰ� �ƴ� ����
		if (plain[i] >= 'a' && plain[i] <= 'z') { //���ڰ� a~z�� ��(�ƽ�Ű �ڵ�)
			plain[i] += shift; //���ڸ� shift�� ��ŭ + ���ش�.

			if (plain[i] > 'z') //���ڰ� z�� �ʰ��� ���(�ƽ�Ű �ڵ�)
				plain[i] -= 26; //���ĺ� ������ 26�� �� a���� �ٽ� �����ϰ� �����.
		}
		i++; //plain[i]�� �ι����̱� ������ �ݺ��ؼ� i++
	}
	printf("��ȣȭ�� ���ڿ�: %s\n", plain); //�������� plain ���
}

void decrypt(char cipher[], int shift)
{
	int i = 0;

	while (cipher[i] != '\0') { //cipher[i]�� �ι��ڰ� �ƴ� ����
		if (cipher[i] >= 'a' && cipher[i] <= 'z') { //���ڰ� a~z�� ��(�ƽ�Ű �ڵ�)
			cipher[i] -= shift; //���ڸ� shift�� ��ŭ - ���ش�.

			if (cipher[i] < 'a') //���ڰ� a���� �۾��� ���(�ƽ�Ű �ڵ�)
				cipher[i] += 26; //���ĺ� ������ 26�� ���� z���� �ٽ� �����ϰ� �����.
		}
		i++;
	}
	printf("��ȣȭ�� ���ڿ�: %s\n", cipher); //�������� cipher ���
}