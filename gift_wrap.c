cost = 2 * (length * height + length * width + height * width) * 1; // for standard wrapping
cost = 2 * (length * height + length * width + height * width) * 2; // for holiday edition.
Please find the Code below.
import java.util.Scanner;
public class GiftWrap {
   public static void main(String[] args) {
       boolean repeat = true;
       Scanner sc = new Scanner(System.in);
       int option = 0;
       long length, height, width, cost;
       while (repeat) {
           option = 0;
           while (option != 1 && option != 2) {
               System.out.println("***Hello! Please pick from the following options:***");
               System.out.println("1) Buy standard wrapping paper press 1");
               System.out.println("2) Buy holiday edition wrapping paper press 2");
               option = sc.nextInt();
           }
           if (option == 1) {
               System.out.println("You have selected standard wrapping paper.");
           } else {
               System.out.println("You have selected holiday edition paper.");
           }
           System.out.println("Please enter the size of your gift(in inches):");
           System.out.println("Enter Length:");
           length = sc.nextInt();
           System.out.println("Enter Height:");
           height = sc.nextInt();
           System.out.println("Enter Width:");
           width = sc.nextInt();
           cost = 2 * (length * height + length * width + height * width) * option;
           System.out.println("You will pay $" + cost + " at the counter. Thanks You for shopping with us!");
           System.out.println("Please Y or y to repeat or any other key to exit");
           char ch = sc.next().charAt(0);
           if (ch != 'y' && ch != 'Y') {
               repeat = false;
           }
       }
   }
}




