#include <stdio.h> //ǥ����������� ���
#include <stdlib.h> //rand() ����� ���� ���

struct lottoinfo { //�ζ� ������ �����ϴ� ����ü
	int lottonumber; //�ζ� ��ȣ
	int lottofrq; //�ζ� ��ȣ ���� �� ��
	int print; //��¿��� ���� ����
};

int main()
{
	int i = 0, j = 0, k = 0; //�ݺ����� ���� ����
	int n, time; //����, ���� Ƚ��
	int maxamount = 0; //�ִ������� ����. �켱�� 0���� �ʱ�ȭ

	struct lottoinfo* maxs[100]; //�ִ������� ���� ����ü ������ �迭
	struct lottoinfo* lotto[150]; //150ũ���� ����ü ������ �迭. 6�� ��ȣ�� �ζ� 25ȸ ����
	struct lottoinfo* frequent; //�ִ������� �����ϴ� ������ ����ü
	struct lottoinfo* temp; //���� ���� �ӽ� ���� ����ü ������

	//����ü ������ �迭�� ��ü ũ�⿡�� ���(����ü ������)�� ũ��� ������ ��� ������ ����
	for (i = 0; i < sizeof(lotto) / sizeof(struct lottoinfo*); i++) //��� ������ŭ �ݺ�
	{
		lotto[i] = malloc(sizeof(struct lottoinfo)); //�� ��ҿ� ����ü ũ�⸸ŭ �޸� �Ҵ�
	}

	if (lotto == NULL) //���� �޸� �Ҵ� ������ �� ��� ����
	{
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}
	else
	{
		printf("�ζ� ������ �Է��ϼ���(���ڸ� �Է��ϼ���): ");
		scanf("%d", &n); //���� �Է� �ޱ�
		printf("�ζ� ���� Ƚ���� �Է��ϼ���(���ڸ� �Է��ϼ���): ");
		scanf("%d", &time); //Ƚ�� �Է� �ޱ�

		for (i = 0; i < 6 * time; i++) //��ü �ζ� ���� ������ (6 * Ƚ��)��ŭ �ݺ�
		{
			lotto[i]->lottofrq = 0; //lotto[i]�� ����Ƚ�� 0���� �ʱ�ȭ
			lotto[i]->print = 0; //����Ʈ �����ߴ��� ���� 0���� �ʱ�ȭ
		}

		while (1) //��� �ݺ�
		{
			for (k = 0; k < time; k++) //�Է� ���� Ƚ�� ��ŭ �ݺ�
			{
				for (i = 0; i < 6; i++)
				{
					while (i < 6)
					{
						lotto[i + (6 * k)]->lottonumber = ((rand() % n) + 1);
						//lotto ����ü ������ �迭 'i + (6 * k)'�ε����� �ζǹ�ȣ �Է�
						//���� ������ n���� ���� 0 ~ (n-1)�� ������ ���� ��� 1�� ����
						//1 ~ n ������ ���� lotto�� �ִ´�.

						for (j = 0; j < i; j++)
						{
							//�ߺ��� ���� ���ϱ� ���� lotto[0]���� lotto[i]���� �˻�
							if (lotto[i]->lottonumber == lotto[j]->lottonumber)
							{ //�ռ� ���� ��ȣ�� �����ٸ� i�� ���ҽ�Ű�� if�� Ż�� �� lotto[i]�� �ٽ� �̴´�
								i--;
								break;
							}
						}
						i++;
					}
				}
			}break;
		}

		frequent = lotto[0]; //frequent������ �켱 [0]�� ����ü ����
		maxs[0] = frequent; //�ִ� ����迭�� frequent ����

		//���� Ƚ�� ����
		for (i = 0; i < 6 * time; i++)
		{
			for (j = 0; j < 6 * time; j++)
			{
				if (lotto[i]->lottonumber == lotto[j]->lottonumber)
					//lotto���ڰ� ���� ���� �ִٸ�
				{
					lotto[i]->lottofrq++; //����ü�� lottofrq(���� Ƚ��)�� ���� ��Ų��.
				}

				if (lotto[i]->lottofrq >= frequent->lottofrq)
					//lotto[i]�� ���� Ƚ���� frequent�� ����Ƚ��(lotttofrq)���� ���ٸ�
				{
					frequent = lotto[i]; //frequent�� lotto[i]�� �ȴ�.
				}
			}
		}

		//����ü ����Ʈ ���� ���� ����
		for (i = 0; i < (6 * time - 1); i++)
		{
			for (j = 0; j < (6 * time - 1) - i; j++)
			{
				if (lotto[j]->lottonumber > lotto[j + 1]->lottonumber)
					//���� lotto[j]�� lottonumber���� lotto[j+1]�� ������ ũ�ٸ�
				{
					temp = lotto[j];
					lotto[j] = lotto[j + 1];
					lotto[j + 1] = temp;
					//�ӽ� ������ temp, lotto[j], lotto[j+1]�� ��ġ�� ���� �ٲ� �������� �����Ѵ�.
				}
			}
		}

		//����ü ������ �迭 ��� ����
		printf("�ζǸ� %dȸ ������ ��� ����Դϴ�.\n", time);
		for (i = 0; i < 6 * time; i++)
		{ //lotto[i]�� print���� 0���� �ʱ�ȭ �Ǿ��ִ�.
			if (lotto[i]->print == 0) //lotto[i]->print ���� 0�̸�
			{
				printf("%2d��(��) %d�� ���Խ��ϴ�\n", lotto[i]->lottonumber, lotto[i]->lottofrq);
				//� ���ڰ� ��� ���Դ��� ����ϱ�

				for (j = 0; j < 6 * time; j++)
				{
					if (lotto[j]->lottonumber == lotto[i]->lottonumber)
					{ //lottonumber���� lotto[i]�� ���� lotto[j]���� �ڿ� �ִٸ�
						lotto[j]->print++;
						//�� lotto[j]���� print������ ������Ų��.
						//�ᱹ lotto[j]���� i�ݺ����� if (lotto[i]->print == 0)���� ����
						//�ߺ��Ǵ� �ζ� ���� ��µ��� �ʴ´�.
					}
				}
			}
		}

		//�ߺ��� �ִ� ������ ã��
		j = 0; //j�� 0���� �ʱ�ȭ
		for (i = 0; i < 6 * time; i++)
		{
			if (lotto[i]->lottofrq == frequent->lottofrq)
			{ //frequent�� lottofrq���� ���� ū ����ü���� ���� �Ǿ��ִ�.
				//�ٵ� �� �ִ밪�� lottofrq�� ���� ���� �ִٸ�
				maxs[j] = lotto[i]; //maxs�迭�� lotto[i]���� �־��ش�.
				j++; //j�� �������� maxs�迭�� ����ĭ���� �̵�
				maxamount++; //0���� �ʱ�ȭ �� maxamount���� ������Ų��.
			}
		}

		//�ִ� ������ ����ϱ�
		printf("\n���� ���� ������ ���ڴ� ");
		for (i = 0; i < maxamount; i = i + maxs[0]->lottofrq)
			//i=0���� i�� maxmount���� ������ ���� �ݺ�.
			//i�� �ݺ����� maxs�迭���� lottofrq(�ִ� ���� Ƚ��)��ŭ �����Ѵ�.
			//�ᱹ maxs�迭 �� lottonumber�� �ٸ� ���鸸 1ȸ ��µȴ�.
		{
			printf("%d, ", maxs[i]->lottonumber);
		} printf("\b\b �Դϴ�\n");
	}

	//���� �迭 ����
	for (int i = 0; i < sizeof(lotto) / sizeof(struct lottoinfo*); i++) // ��� ������ŭ �ݺ�
	{
		free(lotto[i]); // �� ����� ���� �޸� ����
	}

	return 0;
}