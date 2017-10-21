int Solution::gcd(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return A>=B ? (B==0? A : A%B==0? B : gcd(A%B, B)) : (A==0? B : B%A==0? A : gcd(B%A, A));
}
