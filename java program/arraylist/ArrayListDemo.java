import java.util.*;
class ArrayListDemo
{
    public static void main(String[]args)
    {
        List<Integer> numbers=new ArrayList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        System.out.println("list:"+numbers);
         int number=numbers.get(2);
         System.out.println("Accesed element"+number);
         int removednumber=numbers.remove(1);
         System.out.println("Removed element"+removednumber);

    }
}