class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int Lsum=0;
        for(int i=0;i<k;++i){
            Lsum+=cardPoints[i];
        }
        int mx=Lsum;
        for(int Rsum=0,i=0;i<k;++i){
            Rsum+=cardPoints[n-i-1];
            Lsum-=cardPoints[k-1-i];
            mx=max(mx,Lsum+Rsum);
        }
        return mx;
    }
};
