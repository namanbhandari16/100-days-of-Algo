Q. Implement a binary search algorithm.

import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();    //Getting n as input
		int x = sc.nextInt();    //Getting x which needs to be searched as input
		int[] a = new int[n];
		for(int i = 0 ; i < n ; i++) {
			a[i] = sc.nextInt();
		}
		int l = 0;    //Lower limit of index`
        int r = n - 1;  //Upper limit of index
        int c = 0;    //Result
        while(l <= r) {
            int m = (r - l) / 2 + l;   //Calculating the mid index
            if(a[m] == x) {       //Checking if mid is our required index or not
                writer.println("YES");    //Print YES if found
                c = 1;
                break;
            }
            else if(a[m] < x) {   //If mid contains less than x, then we update l=mid+1
                l = m + 1;
            }
            else{
                r = m - 1;     //Else r=mid-1;
            }
        }
        if(c == 0) {
            writer.println("NO");    //Print NO if not found
        }
    }
    
}
