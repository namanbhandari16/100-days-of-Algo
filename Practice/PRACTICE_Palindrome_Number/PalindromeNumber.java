class PalindromeNumber {
    public boolean isPalindrome(int x) {
        String l =  String.valueOf(x);
        String s = "";
        for (int i=String.valueOf(x).length()-1;i >= 0;i--) {
            s += l.charAt(i);
        }
        return l.equals(s);   
    }
}