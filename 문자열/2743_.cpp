/*
	2743 �ܾ� ���� ���

	�ܾ �Է¹ް� ���̸� ��� ����
	strlen�̳� string�� length�� size�� �̿��ϸ� ������
	�̷� ���� ����� �� ���� ��쿡��
	������ ���� ���̸� �� �� �ִ�.
	scanf("%s", s);
	int len = 0;
	for (int i=0; s[i]; i++) {
		len += 1;
	}
	printf("%d\n", len);

	strlen �Լ��� �ð� ���⵵�� O(N)�̱� ������,
	������ ���� �ۼ��ϸ� O(N^2) �ڵ��̴�.

	for (int i=0; i<strlen(s); i++) {
		// Do something
	}

	�Ʒ��� ���� �ۼ��ϴ� ���� �ùٸ���.

	int len = strlen(s);
	for (int i=0; i<len; i++) {
		// Do something
	}
*/