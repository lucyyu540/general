import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the sherlockAndAnagrams function below.
    static int sherlockAndAnagrams(String s) {
        int result = 0;
        int n = s.length();
        //list out all the substrings possible from s
        //substrings are letters adjacent
        //declaring dynamically sized array
        String[][] substrings = new String[n-1][];
        MyMap[][] maps = new MyMap[n-1][];//array of object
        //MyMap example = new MyMap();
        //example.map --> some hashmap <String, Integer>
        
        for (int i=0; i < n-1; i ++) {
            substrings[i] = new String[n-i];
            maps[i] = new MyMap[n-i];
        }
        //putting substrings in the array
        for (int i = 0 ; i < n-1; i ++) {//length = i + 1
            int length = i +1;
            for (int j = 0 ; j < n-i; j ++) {//jth substring
                substrings[i][j] = s.substring(j, j+length);
                //System.out.println(substrings[i][j]);
                maps[i][j] = new MyMap();
                mapString(maps[i][j].map, substrings[i][j]);
            }
        }
        //take one substring, indicate letters on a hashmap and compare the substring to all other substrings
        //this means that at one point, it is necessary to get a separate map for ALL substrings.

        for (int i = 0 ; i < n-1 ; i++) {//length = i+ 1 
            int pairs = n -i;
            for (int x = 0 ; x < pairs; x ++) {
                //Map<String, Integer> pivotMap = maps[i][x].map;
                for (int y = x+1 ; y < pairs ; y++) {
                    //Map<String, Integer> temp = maps[i][y].map;
                    if (compareMaps(maps[i][x].map, maps[i][y].map)) {
                        result ++;
                    }
                }

            }
        }
        return result;
    }
    static boolean compareMaps(HashMap<String,Integer> m1, HashMap<String,Integer> m2) {
        int n = m1.size(); 
        if (m2.size() != n) {//need to be equal sizes
            return false;
        }
        for (Map.Entry<String, Integer> entry : m1.entrySet()) {
            String str = entry.getKey(); 
            int val = entry.getValue();
            if(!m2.containsKey(str)) {// letter not contained in m2
                return false;
            }
            if (m2.get(str) != val) {// letter count doesn't match
                return false;
            }
        }
        return true;
    }
    static void mapString(HashMap<String, Integer> map, String s) {
        String[] temp = s.split("");
        int n = s.length();
        for (int i = 0 ; i < n; i ++) {
            if (!map.containsKey(temp[i])){
                map.put(temp[i], 1);//insert new alpha
            }
            else {
                int currentCount = map.get(temp[i]);
                map.put(temp[i], currentCount+1);//incre
            }
        }
    }
  

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        String str = args[0];
        System.out.println(sherlockAndAnagrams(str));
        /**
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = sherlockAndAnagrams(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
        */
    }
}

class MyMap {
    HashMap<String, Integer> map = new HashMap<String, Integer>();
}
