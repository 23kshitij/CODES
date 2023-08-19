//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int n = r - l + 1; // Calculate the size of the subarray
        int pivotIdx = l + (rand() % n); // Choose a random pivot index
        swap(arr[pivotIdx], arr[r]); // Move the pivot element to the end
        
        int pivot = arr[r];
        int pivotIdxCorrected = l;
        
        for (int i = l; i <= r - 1; i++) {
            if (arr[i] <= pivot) {
                swap(arr[i], arr[pivotIdxCorrected]);
                pivotIdxCorrected++;
            }
        }
        
        swap(arr[pivotIdxCorrected], arr[r]);
        
        if (pivotIdxCorrected - l == k - 1) {
            return arr[pivotIdxCorrected];
        } else if (pivotIdxCorrected - l > k - 1) {
            return kthSmallest(arr, l, pivotIdxCorrected - 1, k);
        } else {
            return kthSmallest(arr, pivotIdxCorrected + 1, r, k - pivotIdxCorrected + l - 1);
        }
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends