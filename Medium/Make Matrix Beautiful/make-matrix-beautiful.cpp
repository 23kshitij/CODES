//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
  
     int findMinOpeartion(vector<vector<int>> a, int n) {
        long long sumR, sumC;
        long long maxR = 0, maxC = 0, t = 0;

        for (int i = 0; i < n; i++) {
            sumR = sumC = 0;

            for (int j = 0; j < n; j++) {
                sumR += a[i][j];
                sumC += a[j][i];
                t += a[i][j];
            }

            maxR = max(maxR, sumR);
            maxC = max(maxC, sumC);
        }

        return max(maxR * n, maxC * n) - t;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends