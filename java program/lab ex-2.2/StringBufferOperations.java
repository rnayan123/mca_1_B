public class StringBufferOperations {

    public static void main(String[] args) {
    
        StringBuffer stringBuffer = new StringBuffer("Hello, ");

        
        stringBuffer.append("World!");
        System.out.println("1. append(): " + stringBuffer);

    
        stringBuffer.insert(7, "Java ");
        System.out.println("2. insert(7, \"Java \"): " + stringBuffer);


        stringBuffer.replace(7, 11, "Programming");
        System.out.println("3. replace(7, 11, \"Programming\"): " + stringBuffer);

    
        stringBuffer.delete(7, 18);
        System.out.println("4. delete(7, 18): " + stringBuffer);


        char charAtIndex = stringBuffer.charAt(2);
        System.out.println("5. charAt(2): " + charAtIndex);

        
        stringBuffer.setCharAt(2, 'L');
        System.out.println("6. setCharAt(2, 'L'): " + stringBuffer);
        System.out.println(stringBuffer);

        
        int length = stringBuffer.length();
        System.out.println("7. length(): " + length);
        
        int capacity = stringBuffer.capacity();
        System.out.println("8. capacity(): " + capacity);

        
        stringBuffer.ensureCapacity(30);
        System.out.println("9. ensureCapacity(30): " + stringBuffer);

        
        String toStringResult = stringBuffer.toString();
        System.out.println("10. toString(): " + toStringResult);

        
        String substringStartResult = stringBuffer.substring(6);
        System.out.println("11. substring(6): " + substringStartResult);

    
        String substringStartEndResult = stringBuffer.substring(0, 5);
        System.out.println("12. substring(0, 5): " + substringStartEndResult);
    }
}
