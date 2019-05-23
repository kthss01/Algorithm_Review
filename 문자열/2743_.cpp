/*
	2743 단어 길이 재기

	단어를 입력받고 길이를 재는 문제
	strlen이나 string의 length나 size를 이용하면 되지만
	이런 것을 사용할 수 없는 경우에는
	다음과 같이 길이를 잴 수 있다.
	scanf("%s", s);
	int len = 0;
	for (int i=0; s[i]; i++) {
		len += 1;
	}
	printf("%d\n", len);

	strlen 함수의 시간 복잡도는 O(N)이기 때문에,
	다음과 같이 작성하면 O(N^2) 코드이다.

	for (int i=0; i<strlen(s); i++) {
		// Do something
	}

	아래와 같이 작성하는 것이 올바르다.

	int len = strlen(s);
	for (int i=0; i<len; i++) {
		// Do something
	}
*/