#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	long double y;
	cin >> y;
	long double result = (7 * t(0.25f) + 2 * t(1 + y)) / (6 - t(pow(y, 2) - 1));
	if (isinf(result))
	{
		cout << "Result = " << 0;
	}
	else
	{
		cout << "Result = " << result;
	}
}