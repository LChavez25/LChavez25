import java.util.*;
class Cupcakes
{
   public static void main(String args[])
   {
    
    Scanner s= new Scanner(System.in);
    /*create Scanner object*/
    double discount,disamount=0.0,subtotal=0.0;
    /*declare double variables discount, disamount snd subtotal*/
    System.out.println("\nWelcome to the Pflugerville Bakery!");
    System.out.println("\nWe're ready to take your cupcake order");
   /*print wecome message*/
    System.out.print("\nPlease enter your name : ");
    String name= s.nextLine();
   /*read name using scanner object*/
    System.out.print("\nPlease enter the number of Red velvet cupcakes: ");
    int red=s.nextInt();
/*read number of red velvet*/
    System.out.print("\nPlease enter the number of Carmel Surprise cupcakes: ");
    int carmel=s.nextInt();
   /*read number of carmel surprise */
    System.out.print("\nPlease enter the number of Chocolate Delight cupcakes: ");
    int chocolate=s.nextInt();
    /*read number of chocolate delight*/
    System.out.println("\nEnter the day of the week you will pick up the order :");
    String day= s.next();
    /*read day*/
    int tot=red+carmel+chocolate;
    /*calculate total cupcakes*/
    if(tot>0)
    {
    /*if total cupcakes value in tot>0, then
    perform following*/
    if(red>0)
    System.out.print("\nRed Velvet cupcakes: "+red +" for $"+red*2);
    /*if red is greater than 0, print its amount*/
   
    if(carmel>0)
    System.out.print("\nCarmel Surprise cupcakes: "+carmel +" for $"+carmel*2.50);
    /*if carmel is greater than 0, print its amount*/
   
    if(chocolate>0)
    System.out.print("\nChocolate Delight cupcakes: "+chocolate +" for $"+chocolate*3);
   /*if chocolate is greater than 0, print its amount*/
  
   subtotal=(red*2+carmel*2.50+chocolate*3);
   /*calcuclate subtotal*/
   System.out.print("\n\nSubtotal \t\t\t\t\t\t\t:$"+subtotal);
   /*print subtotal*/
    
    if(tot>=12 && tot<=23)
    {
    /*if tot is a dozen then calcuclate*/
      System.out.print("\nDiscount Percentage \t\t\t\t\t:10%");
      discount=(subtotal*10)/100;
      /*calculate discount by taking 10*/
      disamount=subtotal-discount;
      /*calculate discount amount by subtracting
      subtotal and discount*/
      System.out.print("\nDiscount Amount\t\t\t\t\t\t:$"+discount);
      System.out.print("\nDiscounted Subtotal\t\t\t:$"+disamount);
     /*print discounted amount*/
    }
    else if(tot>=24)
    {
      /*if tot is greater than or equal to
       3 dozens,*/
     
      System.out.print("\nDiscount Percentage \t\t\t\t\t\t:10%");
      discount=(subtotal*15)/100;
      /*calcuclate discount by taking 15% of subtotal*/
      disamount=subtotal-discount;
      /*calcuclate discount amount*/
      System.out.print("\nDiscount Amount\t\t\t\t\t\t\t:$"+discount);
      System.out.print("\nDiscounted Subtotal\t\t\t\t\t: $"+disamount);
    /*print discount amounted*/
    }
    else
    {
      /*otherwise, set discount to 0*/
    discount=0.0;
    disamount=subtotal;
    /*set discount amount to subtotal*/
    }
   double tax = (disamount*7.25)/100;
   /*calculate tax by taking 7.25 percentage
   of disamount*/
   tax = (double) Math.round(tax * 100) / 100;
   /*round tax to 2 decimal point*/
    System.out.print("\nTax\t\t\t\t\t\t\t       :$"+tax);
   double total = disamount+tax;
/*calculate total by adding disamount and tax*/

System.out.print("\n\nTotal cost :\t\t\t\t\t\t\t\t$"+total);
System.out.print("\nThis order will be available for pickup");
System.out.print("\nBy :"+name);
System.out.print("\nOn :"+day);
/*print total, picked by name and day*/

}//if
else
{
   /*if tot is 0, then print erroressage*/
   System.out.print("\nYou should purchase atleat one cupcake");
}
   }//main
}//class
