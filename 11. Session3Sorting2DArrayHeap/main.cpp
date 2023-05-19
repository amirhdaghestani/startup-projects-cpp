#include <iostream>

using namespace std;

void* sort_insertion(int a[], int ind)
{
	int temp = 0;
	for(int i = 1; i < ind; i++)
	{
		for(int j = i; j >= 0; j--)
		{
			if(a[j] > a[j-1])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

int main()
{
	int n,m;
	cin >> n >> m;

	int** a = new int*[n];
	for(int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
        
	cout << endl << "Entery array: " << endl;
	for(int i = 0; i < n; i++)
        {
                for(int j = 0; j < m; j++)
                {       
                        cout << a[i][j] << " ";
                }
		cout << endl;
        }

	cout << endl << "Rows sorted: " << endl;

	int aa[m];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			aa[j] = a[i][j];
		}
		sort_insertion(aa, m);
		for(int j = 0; j < m; j++)
			a[i][j]  = aa[j];
	}
	
	for(int i = 0; i < n; i++)
        {
                for(int j = 0; j < m; j++)
                {
                        cout << a[i][j] << " ";
                }
                cout << endl;
        }

        cout << endl << "Columns sorted: " << endl;

	for(int i = 0; i < m; i++)
        {
		for(int j = 0; j < n; j++)
                {
                        aa[j] = a[j][i];
                }
                sort_insertion(aa, n);
                for(int j = 0; j < n; j++)
                        a[j][i]  = aa[j];
        }

        for(int i = 0; i < n; i++)
        {
                for(int j = 0; j < m; j++)
                {
                        cout << a[i][j] << " ";
                }
                cout << endl;
        }

	return 0;
}
