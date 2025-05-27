class Solution {
public:
    int differenceOfSums(int n, int m) {
        int count = ((n)*(n+1))/2;

        int divisible = (n/(m))*(2*m + (n/m -1)*m)/2;

        cout<<count<<" "<<divisible<<endl;

        return count - divisible - divisible;
    }
};