import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.Set;
public class FindAllPairsForSum {

   public static void main(String args[]) {

      /* This is how to declare HashMap */
      HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();

      int [] arr = {1, 4, 5, 17, 9, 6, 2, 3, 9, 11, 8};
      int val = 12;

      for(int i = 0; i<arr.length; i++){
        for(int j = i+1; j<arr.length; j++){
            if(arr[i] + arr[j] == val){
                hmap.put(arr[i], arr[j]);
            }
        }
      }

      for(Map.Entry m : hmap.entrySet()){
        System.out.println("The pairs of integers in this array that add up to " + 
        val + " are " + m.getKey() + " and " + m.getValue());
      }
   }
}
