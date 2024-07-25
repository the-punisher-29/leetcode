/*used merge sort here
1->tc-o n*logn---each time half div then lin time to merge  so....
2->it uses least sc-i.e o n----rec stack uses o logn space and temp vec uses n/2 space in worst case
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int e=nums.size()-1;
        mrgS(nums,0,e);
        return nums;
    }
private:
    void mrgS(vector<int> &nums,int s,int e){
        //edge case handling
        if(s>=e) return;
        int mid=s+(e-s)/2;
        //recursive prop
        mrgS(nums,s,mid);
        mrgS(nums,mid+1,e);
        //merge both parts
        cmb(nums,s,mid,e);
    }

    void cmb(vector<int> &nums,int s,int m,int e){
        vector<int>temp(e-s+1);
        int i=s,j=m+1,k=0;
        while(i<=m && j<=e){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=m){
            temp[k++]=nums[i++];
        }
        while(j<=e){
            temp[k++]=nums[j++];
        }
        for(int p=0;p<k;p++){
            nums[s+p]=temp[p];
        }
    }
};