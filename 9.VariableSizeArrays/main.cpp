#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,q;
    int k[n];
    cout << "Enter the size of the array and query (between 1 and 10^5): " << endl;
    entry:
    cin >> n >> q;
    if (n > 0 && n <= 10000 && q > 0 && q <= 10000)
    {
        vector<vector<int>> vect(n);
        for (int i = 0; i < n; i++)
        {
            entry2:
            cout << "Enter the length of the array and the elements in each line (length between 1 and 3*10^5 and elements positive and less than 10^6): " << endl;
            cin >> k[i];
            if(k[i] > 0 && k[i] <= 3*10000)
            {
                vect[i] = vector<int>(k[i]);
                for(int j = 0; j < k[i]; j++)
                {
                    cin >> vect[i][j];
                    if (vect[i][j] < 0 || vect[i][j] > 10*10000)
                    {
                        cout << "Follow the rules! try again" << endl;
                        goto entry2;
                    }
                }
            }
            else
            {
                cout << "Follow the rules! try again" << endl;
                goto entry2;
            }
            
        }

        int query[q][2];
        entry3:
        cout << "Enter querries: " << endl;
        for(int i = 0; i < q; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> query[i][j];
            }
            if(query[i][1] < 0 || query[i][2] < 0 || query[i][1] > n  || query[i][2] > k[query[i][1]])
            {
                cout << "Follow the rules! try again" << endl;
                goto entry3;
            }
        }
	
	int x, y;
        for(int i = 0; i < q; i++)
        {
		x = query[i][1];
		y = query[i][2];
		cout << vect[x][y] << endl;
        }
    }
    else
    {
        cout << "Follow the rules! try again" << endl;
        goto entry;
    }
    
    return 0;
}
