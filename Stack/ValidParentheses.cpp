class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        if(s.empty())
            return true;
        if(s.at(0) == ']' || s.at(0) == '}' || s.at(0) == ')' )
            return false;
        for(int i=0;i<s.size();i++)
        {
            if(s.at(i)=='(' || s.at(i)=='{' || s.at(i)=='[')
            {
                st.push(s.at(i));
            }
            else {
            if(st.empty() || (st.top()=='(' && s.at(i)!=')') || (st.top()=='{' && s.at(i)!='}') ||(st.top()=='[' && s.at(i)!=']')) 
                return false;
            st.pop();
                }
        }
        return st.empty();   
    }
};
