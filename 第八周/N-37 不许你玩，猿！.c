#include <stdio.h>

/*
int main()
{
	int n, m, a, b, sum = 0, counter = 0;
	scanf("%d%d", &n, &m);
	int line[100010];
	for(int i = 0; i <= 100009; i++) line[i] = i;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		line[a] = line[a]^line[b];
		line[b] = line[a]^line[b];
		line[a] = line[a]^line[b];
	}
//	for(int i = 1; i <= n; i++) printf("%d ", line[i]);
	int delta[100010];
	for(int i = 1;i <= n; i++)
	{
		delta[i] = line[i]-i;
		if(delta[i] < 0) sum+=delta[i];
	}
	while(sum)
	{
		sum = 0;
		for(int i = 1; i <= n; i++)
		{
			if(delta[i] < 0)
			{
				int t = delta[i+delta[i]];
				for(int j = i+delta[i]+2; j <=i; j++)
				{
					delta[j] = delta[j-1]-1;
					counter++;
				}
				delta[i+delta[i]] = 0;
				delta[i+delta[i]+1] = t-1;
				counter++;
			}
		}
		for(int i = 1;i <= n; i++)
		{
			if(delta[i] < 0)
			{
				sum+=delta[i];
				break;
			}
		}
	}
	printf("%d\n", counter);
	return 0;
}
*/

//王翔宇解答之后重新编写

int inverse_count(int a[], int l, int r)
{
	int flag, max, min, counter = 0;
	if(a[l]<a[r])
	{
		flag = 1;
		max = a[r];
		min = a[l];
	}
	else
	{
		flag = -1;
		max = a[l];
		min = a[r];
	}
	for(int i = l+1; i <= r-1; i++)
	{
		if((a[i] < max) && (a[i] > min)) counter++;
	}
	return flag*(2*counter+1);
}

int main()
{
	int n, m, ans = 0, l, r;
	scanf("%d%d", &n, &m);
	int line[100010];
	for(int i = 0; i <= 100009; i++) line[i] = i;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &l, &r);
		ans+=inverse_count(line, l, r);
		line[l] = line[l]^line[r];
		line[r] = line[l]^line[r];
		line[l] = line[l]^line[r];
	}
	printf("%d", ans);
	return 0;
}

//没时间了，先交一下
/*
#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

long long merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    int i, j, k;
    long long inv_count = 0;

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv_count += (n1 - i); // All remaining elements in L[i...] are greater than R[j]
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    return inv_count;
}

long long mergeSort(int arr[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);

        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  // Initialize the array as [1, 2, ..., n]
    }

    for (int i = 0; i < m; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        swap(arr, L-1, R-1);  // Apply swaps according to monkey's disruptions
    }

    long long result = mergeSort(arr, 0, n - 1);
    printf("%lld\n", result);

    return 0;
}
*/