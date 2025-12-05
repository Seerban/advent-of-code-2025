import java.io.File;
import java.util.Scanner;

public class solution_p1 {
    // in part1 bank is made of 2 batteries (numbers)
    public static String max_bank(char[] s) {
        int maxidx1 = 0, maxidx2 = 0;

        // Get maximum
        for(int i = 0; i < s.length; ++i)
            if(s[i] > s[maxidx1])
                maxidx1 = i;
        
        // if max1 is not last then largest number will be made max1 then max2 from (max1,s.length)
        if(maxidx1 < s.length - 1) {
            maxidx2 = maxidx1 + 1;

            for(int i = maxidx1 + 1; i < s.length; ++i)
                if(s[i] > s[maxidx2])
                    maxidx2 = i;
            
            return "" + maxidx1 + maxidx2; 
        }
        else { // otherwise it will be max2 from (0, max1) as the larger place value
            maxidx2 = 0;

            for(int i = 0; i < s.length; ++i)
                if(s[i] > s[maxidx2])
                    maxidx2 = i;
            
            return "" + maxidx2 + maxidx1; 
        }
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(new File("input.txt"));

        int sum = 0;

        while (sc.hasNextLine()) {
            String line = sc.nextLine();

            String res = max_bank( line.toCharArray() );
            int n = Integer.parseInt(res);
            sum += n;
        }

        System.out.print(sum);

        sc.close();
    }
}