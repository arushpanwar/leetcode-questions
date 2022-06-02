vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int n=a.size(),bminusa=0;
    long long int bminusasq=0;
    for(int i=0;i<n;i++){
        bminusa-=a[i];
        bminusa+=i+1;
        bminusasq-=((long long int)a[i]*(long long int)a[i]);
        bminusasq+=((long long int)(i+1)*(long long int)(i+1));
    }
    int aplusb=bminusasq/bminusa;
    vector<int> ans;
    ans.push_back((aplusb-bminusa)/2);
    ans.push_back((aplusb+bminusa)/2);
    return ans;
  int xor1;
 
    /* Will have only single set bit of xor1 */
    int set_bit_no;
 
    int i;
    *x = 0;
    *y = 0;
 
    xor1 = arr[0];
 
    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
 
    /* XOR the previous result with numbers
    from 1 to n*/
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
 
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);
 
    /* Now divide elements into two
    sets by comparing a rightmost set
    bit of xor1 with the bit at the same
    position in each element. Also,
    get XORs of two sets. The two
    XORs are the output elements.
    The following two for loops
    serve the purpose */
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            *x = *x ^ arr[i];
 
        else
            /* arr[i] belongs to second set*/
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            *x = *x ^ i;
 
        else
            /* i belongs to second set*/
            *y = *y ^ i;
    }
}
