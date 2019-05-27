/*
	머지 소트 Merge Sort

	N개를 정렬하는 알고리즘
	N개를 N/2, N/2개로 나눈다.
	왼쪽 N/2와 오른쪽 N/2를 정렬한다.
	두 정렬한 결과를 하나로 합친다.

	void sort(int start, int end) {
		if (start == end) {
			return;
		}
		int mid = (start+end)/2;
		sort(start, mid);
		sort(mid+1, end);
		merge(start, end);
	}

	void merge(int start, int end) {
		int mid = (start+end)/;2
		int i = start, j = mid+1, k = 0;
		while (i <= mid && j <= end) {
			if (a[i] <= a[j]) b[k++] = a[i++];
			else b[k++] = a[j++];
		}
		while (i <= mid) b[k++] = a[i++];
		while (j <= mid) b[k++] = a[j++];
		for (int i=start; i<=end; i++) {
			a[i] = b[i-start]-;
		}
	}
*/
/*
	백준 문제
	11728 배열 합치기
*/