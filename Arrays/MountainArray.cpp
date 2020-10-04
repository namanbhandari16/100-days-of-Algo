class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool inc = false, dec=false;
        if(A.size() >= 3)
        {
            for(int i=0;i<A.size()-1;i++)
            {
                if(A[i+1] <= A[i])
                {
                    for(int j=A.size()-1;j>i;j--)
                    {
                        if(A[j-1] <= A[j])
                            return false;
                        else
                            dec=true;
                    }
                }
                else
                    inc =true;
            }
            if(inc && dec)
                return true;
            else 
                return false;
        }
        else
            return false;
    }
};
