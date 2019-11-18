#include <stdio.h>

int fibo_get_sum(int n)
{
	int second = 0, first = 0, current = 0, result = 0;

	for (int it = 0; it < n; it++)
    {
        if(it == 0 || it == 1)
            current = it;
        else
            current = second + first;

		second = first;
		first = current;
        result += current;
	}

	return result;
}

/* solower way to make it work in order
int print_Fibo(int n) {
  if (n == 0 || n == 1)
	return n;
  else
	return (print_Fibo(n-1) + print_Fibo(n-2));
}
*/

int main()
{
	int result = fibo_get_sum(16);
	printf("%d", result);
	getchar();
	return 0;
}
