// In a party of N people, only one person is known to everyone. Such a person
// may be present in the party, if yes, (s)he doesn’t know anyone in the party.
// We can only ask questions like “does A know B? “. Find the stranger
// (celebrity) in the minimum number of questions.

// For this problem there are other two approches also like
// graph and recursion.
// But for now I am using the STACK approach to solve the problem.

import java.util.Stack;

class FindCelebrityProblem {
    // Person with 2 is celebrity

    static int celebs[][] = { { 0, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 0, 0, 0 } };

    // Returns true if a knows
    // b, false otherwise
    static boolean knows(int a, int b) {
        boolean res = (celebs[a][b] == 1) ? true : false;
        return res;
    }

    // Returns -1 if celebrity
    // is not present. If present,
    // returns id (value from 0 to n-1).
    static int findCelebrity(int n) {
        Stack<Integer> obj1 = new Stack<>();
        int c;

        // Step 1 :Push everybody
        // onto stack
        for (int i = 0; i < n; i++) {
            obj1.push(i);
        }

        while (obj1.size() > 1) {
            // Step 2 :Pop off top
            // two persons from the
            // stack, discard one
            // person based on return
            // status of knows(A, B).
            int a = obj1.pop();
            int b = obj1.pop();

            // Step 3 : Push the
            // remained person onto stack.
            if (knows(a, b)) {
                obj1.push(b);
            }

            else
                obj1.push(a);
        }

        c = obj1.pop();

        // Step 5 : Check if the last
        // person is celebrity or not
        for (int i = 0; i < n; i++) {
            // If any person doesn't
            // know 'c' or 'a' doesn't
            // know any person, return -1
            if (i != c && (knows(c, i) || !knows(i, c)))
                return -1;
        }
        return c;
    }

    // Driver Code
    public static void main(String[] args) {
        int n = 4; // total number of people
        int foundCeleb = findCelebrity(n);
        if (foundCeleb == -1) {
            System.out.println("There is no Celebrity in the Party!");
        } else
            System.out.println("The Celebrity is in the party with Id " + foundCeleb + " .");
    }
}
