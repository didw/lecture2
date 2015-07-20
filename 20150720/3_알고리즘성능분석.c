// 3_알고리즘성능분석.c
// 알고리즘의 성능 표기법
// 1. 공간 복잡도 : 알고리즘을 실행하여 종료할 때까지 필요한 메모리 크기
// 2. 시간 복잡도 : 알고리즘을 실행하여 필요한 시간

// 공간 복잡도
// 변수 저장하기 위한 공간
// 순환 스택을 사용하기 위한 공간

// 교재 p.6의 공간 복잡도를 계산해 보세요.
// 예제1. 공간 복잡도

float abc(float a, float b, float c)
{
	return (a + b + b*c + (a + b - c) / (a + b) + 4.0);
}

// 예제2. 공간 복잡도
float Sum(float a[], int n)
{
	float s = 0.0;
	int i;
	for (i = 0; i <= n; i++)
		s += a[i];
	return s;
}

// 예제3. 공간 복잡도
float RSum(float a[], int n)
{
	if (n <= 0)
		return 0.0;
	else
		return RSum(a, n - 1) + a[n];
}