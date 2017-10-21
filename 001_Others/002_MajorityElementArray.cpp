int Solution::majorityElement(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    unordered_map<int, int> count;
    for(int i = 0; i < n; i++) {
        if(count.find(A[i]) == count.end()) {
            count.insert(pair<int,int>(A[i], 1));
        } else {
            count[A[i]]++;
        }
        if(count[A[i]] > n/2) return A[i];
    }
}
