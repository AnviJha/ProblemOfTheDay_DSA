class Solution {
public:
    int minOperations(string s) {
        int n =s.size();

        if(is_sorted(s.begin(),s.end())){
            //already sorted string 
            return 0;
        } 
        if(n == 2){
            //string cant be sorted as we need to take substring not the whole string 
             return -1;
        }
        //smallest and largest cahracter 

        char mini = *min_element(s.begin(),s.end());
        char maxi = *max_element(s.begin(),s.end());
        //if either smallest or either largest character is in its position , then only one operation to sort n-1 character 
        if(s[0] == mini || s[n-1] == maxi){
            return 1;
        }
        //if both the smallest is in s[n-1] postion and largest is in s[0] position then it will require 3 operation (ex : edc) && s[0] and s[n-1] be non repeating character (ex : jgg only 2 operations)
        if(s[0] == maxi && s[n-1] == mini  && count(s.begin() ,s.end(),maxi) == 1 && count(s.begin(),s.end(),mini)==1 ){
            return 3;
        }

        return 2;
    }
};