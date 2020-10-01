/*
    Throne Inheritance : https://leetcode.com/contest/weekly-contest-208/problems/throne-inheritance/
*/

class ThroneInheritance {
public:

    /*
        root stores the name of current king
        map stores the children of everyone
        dead stores the persons who are dead
    */
    string root;
    map <string, vector<string> > m;
    set <string> dead;

    // Initializing with the king name
    ThroneInheritance(string kingName) {
        root = kingName;
    }

    // Adding a child to the parent vector
    void birth(string parentName, string childName) {
        m[parentName].push_back(childName);
    }

    // Adding the name to dead
    void death(string name) {
        dead.insert(name);
    }

    // Returning the Inheritance Order
    vector<string> getInheritanceOrder() {
        vector <string> ans;
        dfs(root, ans);
        return ans;
    }

    // Utility function to get inheritance order
    void dfs(string root, vector <string> &ans) {
        if (dead.find(root) == dead.end()) ans.push_back(root);
        for (auto s : m[root]) {
            dfs(s, ans);
        }
    }
};