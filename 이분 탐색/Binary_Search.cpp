/*
	�̺� Ž�� Binary Search

	���ĵǾ� �ִ� ����Ʈ���� � ���� ������ ã�� �˰���
	����Ʈ�� ũ�⸦ N�̶�� ���� ��
	lgN�� �ð��� �ɸ���
	�ð� ���⵵�� lgN�� ������
	ũ�Ⱑ N�� ����Ʈ�� ����ؼ� �������� ������ �����̴�.
	2^k = N �� ��, k = lgN

	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			position = mid;
			break;
		}
		else if (a[mid] > x) {
			right = mid - 1;
		} 
		else {
			left = mid + 1;
		}
	}
*/
/*
	���� ����
	10815 ���� ī��
	10816 ���� ī�� 2
*/