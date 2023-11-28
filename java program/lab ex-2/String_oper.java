import java.util.Arrays;

public class String_oper{

    public static void main(String[] args) {
        String str = "We realizes that while our workers were thriving, the surrounding villages were still suffering. It became our goal to uplift their quality of life as well. I remember seeing a family of 4 on a motorbike in the heavy Bombay rain — I knew I wanted to do more for these families who were risking their lives for lack of an alternative. The alternative mentioned here is the Tata Nano, which soon after came as the world’s cheapest car on retail at a starting price of only Rs 1 lakh. These were the words of Ratan Tata in a recent post by Humans of Bombay which formed the basis of his decision to come up with a car like Tata Nano.";

       
        char firstChar = str.charAt(0);
        System.out.println("charAt(0): " + firstChar);

       System.out.println("****************************************");
        String compareString = "We realize";
        int compareToResult = str.compareTo(compareString);
        System.out.println("compareTo(\"We realize\"): " + compareToResult);
        System.out.println("****************************************");
        
        String concatString = str.concat(" Thank you for reading.");
        System.out.println("concat(): " + concatString);
        System.out.println(str);
         System.out.println("****************************************");
         
        
        boolean containsResult = str.contains("Tata Nano");
        System.out.println("contains(\"Tata Nano\"): " + containsResult);

        System.out.println("****************************************");
        boolean endsWithResult = str.endsWith("Nano.");
        System.out.println("endsWith(\"Nano.\"): " + endsWithResult);
         System.out.println("****************************************");
        
        boolean equalsResult = str.equals(compareString);
        System.out.println("equals(\"We realize\"): " + equalsResult);

        System.out.println("****************************************");
        boolean equalsIgnoreCaseResult = str.equalsIgnoreCase(compareString);
        System.out.println("equalsIgnoreCase(\"We realize\"): " + equalsIgnoreCaseResult);
          System.out.println("****************************************");
       
        String formattedString = String.format("Formatted String: %s", str);
        System.out.println("format(): " + formattedString);
        System.out.println("****************************************");
      
        byte[] byteArr = str.getBytes();
        System.out.println("getBytes(): " + new String(byteArr));
        System.out.println("****************************************");
      
        char[] charArr = new char[10];
        str.getChars(10, 20, charArr, 0);
        System.out.println("getChars(10, 20): " + new String(charArr));
        System.out.println("****************************************");
        
        int indexOfResult = str.indexOf("Tata");
        System.out.println("indexOf(\"Tata\"): " + indexOfResult);
        System.out.println("****************************************");
        
        String internedString = str.intern();
        System.out.println("intern(): " + internedString);
       System.out.println("****************************************");
        
        boolean isEmptyResult = str.isEmpty();
        System.out.println("isEmpty(): " + isEmptyResult);
         System.out.println("****************************************");
        
        String[] words = {"We", "realize", "thrive"};
        String joinedString = String.join(" ", words);
        System.out.println("join(): " + joinedString);
        System.out.println("****************************************");
        
        int lastIndexOfResult = str.lastIndexOf('a');
        System.out.println("lastIndexOf('a'): " + lastIndexOfResult);
        System.out.println("****************************************");
       
        int lengthResult = str.length();
        System.out.println("length(): " + lengthResult);
        System.out.println("****************************************");
        
        String replacedString = str.replace('a', 'X');
        System.out.println("replace('a', 'X'): " + replacedString);
        System.out.println("****************************************");
       
        String regexReplacedString = str.replaceAll("r", "R");
        System.out.println("replaceAll(\"r\", \"R\"): " + regexReplacedString);
        System.out.println("****************************************");
       
        String[] splitString = str.split("\\s+");
        System.out.println("split(\"\\s+\"): " + Arrays.toString(splitString));

       
        boolean startsWithResult = str.startsWith("We");
        System.out.println("startsWith(\"We\"): " + startsWithResult);
         System.out.println("****************************************");
       
        String substringResult = str.substring(50, 100);
        System.out.println("substring(50, 100): " + substringResult);
        System.out.println("****************************************");

       
        char[] charArray = str.toCharArray();
        System.out.println("toCharArray(): " + Arrays.toString(charArray));
        System.out.println("****************************************");
       
        String lowercaseString = str.toLowerCase();
        System.out.println("toLowerCase(): " + lowercaseString);
        System.out.println("****************************************");
      
        String uppercaseString = str.toUpperCase();
        System.out.println("toUpperCase(): " + uppercaseString);
       System.out.println("****************************************");
       
        String trimmedString = "   Trimmed String   ";
        System.out.println("Original String (with leading and trailing spaces): " + trimmedString);
        System.out.println("Trimmed String: " + trimmedString.trim());

      System.out.println("****************************************");
        int number = 42;
        String valueOfString = String.valueOf(number);
        System.out.println("valueOf(): " + valueOfString);
    }
}
