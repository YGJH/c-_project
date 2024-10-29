#include <stdio.h>
#include <chrono>
signed main() {
	long long i;
	double j;
	//wstring_convert<codecvt_utf8<wchar_t>> utf8;
	//wstring ws = ";
	//string s = utf8.to_bytes(ws);
	const char *tmp = "█";
	const char cc = '%';
	const long long N = 1000;
	double per = 0;
	auto st = std::chrono::high_resolution_clock::now();
	for(i = 1  ; i <= N ; i++) {
		printf("\r| ");
		double time = (double)i / N * 40;
		for(j = 0 ; (time - j) > (double)1e-9 ; j++) 
			printf("%s", tmp);
		for(; 40- j > (double)1e-9 ; j++) {
			putchar(' ');
		}
		per = (double)i / N * 100;
		printf(" | %.4lf %c" , per , cc);
		printf(" (%lld / %lld)  " , i , N);
	}
	auto en = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = en - st;
	printf("\n%lf s\n" , dur.count());
	return 0;
}
