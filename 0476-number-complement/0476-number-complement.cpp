class Solution {
public:
    int findComplement(int num) {
        if(num==0) return 1;
        //init app- convert int to string binary then flip then abck to int and return--0(logn)


        // bit manip --masking--O(1)
        int mask=num;
        mask|=mask>>1;
        mask|=mask>>2;
        mask|=mask>>4;
        mask|=mask>>8;
        mask|=mask>>16;

        return num^mask;

    }
};