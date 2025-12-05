import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class solution_p2 {
    // in part1 bank is made of 12 batteries
    public static String max_bank(char[] s) {
        List<Integer> maxidx = new ArrayList<>(Collections.nCopies(12, -1));
        maxidx.set(0, 0);

        // Get maximum from start to length-12 as biggest digit matters most
        for(int i = 0; i < s.length - 11; ++i)
            if(s[i] > s[maxidx.get(0)])
                maxidx.set(0, i);
        
        for(int i = 0; i < 11; ++i) {
            // Go right until a non-used battery is found
            for(int j = maxidx.get(i)+1; j < s.length; ++j) {
                if(maxidx.contains(j)) continue; // skip if already used battery
                maxidx.set(i+1, j);
                break;
            }
            
            // If found, look for max on right side (pick last index if max repeats)
            // we don't want to select from the tail of the list until necessary so we only until (batteryCount - 12 + batteries added)
            if(maxidx.get(i+1) >= 0)
                for(int j = maxidx.get(i); j < s.length - (10 - i); ++j) {
                    if(maxidx.contains(j)) continue; // skip if already used battery
                    if(s[maxidx.get(i+1)] < s[j]) {
                        maxidx.set(i+1, j);
                    }
                }

            // if not found, guaranteed to be on left side
            if(maxidx.get(i+1) == -1)
                for(int j = 0; j < maxidx.get(i); ++j) {
                    if(maxidx.contains(j)) continue; // skip if already used battery
                    if(maxidx.get(i+1) < s[j])
                        maxidx.set(i+1, j);
                }
        }

        String res = "";
        Collections.sort(maxidx);
        for(int i = 0; i < 12; ++i)
            res += s[ maxidx.get(i) ];
        return res;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(new File("input.txt"));

        long sum = 0;

        while (sc.hasNextLine()) {
            String line = sc.nextLine();

            String res = max_bank( line.toCharArray() );
            long n = Long.parseLong(res);
            sum += n;
        }

        System.out.print(sum);

        sc.close();
    }
}