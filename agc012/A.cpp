#include <bits/stdc++.h>

int main()
{
    int N;
    scanf("%d", &N);
    std::vector<int> A(3*N);
    for(int i = 0; i < 3*N; i++) {
	scanf("%d", &A[i]);
    }
    std::sort(A.begin(), A.end());
    std::reverse(A.begin(), A.end());
    long sum = 0;
    for(int i = 0; i < N; i++) {
	sum += A[2*i + 1];
    }
    std::cout << sum << std::endl;
}
