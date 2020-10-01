class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return 0;
        }

        vector<int> m1(26,0), m2(26,0);
        int same = 0;
        int cnt = 0;

        for (int i = 0; i < s1.size(); i++) {
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (m1[i] == m2[i]) {
                same++;
            }
        }

        for (int i = s1.size(); i < s2.size(); i++) {
            if (same == 26) {
                return true;
            }

            char l = s2[i - s1.size()] - 'a';
            char r = s2[i] - 'a';

            m2[l]--;
            if (m1[l] == m2[l]) {
                same++;
            } else if (m1[l] == m2[l] + 1) {
                same--;
            }

            m2[r]++;
            if (m1[r] == m2[r]) {
                same++;
            } else if (m1[r] == m2[r] - 1) {
                same--;
            }
        }

        return same == 26;
    }
};
