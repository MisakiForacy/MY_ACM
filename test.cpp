#include <bits/stdc++.h>

using namespace std;

int main()
{
	int target = 5;
	int a[] = {1, 2, 5, 5, 6, 7, 9};
	int l = 0, r = 7;
	while (l <= r) 
	{
		int mid = (l + r) / 2;
		if (a[mid] >= target) 
			r = mid;
		else
			l = mid + 1;
	}
}