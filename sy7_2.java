import java.util.*;
   public class sy7_2{
   public void display(Calendar cal){
   System.out.print(cal.get(Calendar.YEAR)+".");
   System.out.print((cal.get(Calendar.MONTH)+1)+".");
System.out.print(cal.get(Calendar.DATE)+".");
}
 public void js(Calendar cal,int y,int m,int d){ 
  int a=(int)cal.get(Calendar.YEAR);
     int b=(int)cal.get(Calendar.MONTH)+1;
     int c=(int)cal.get(Calendar.DATE);
System.out.print("������"+(((a-y-1)*12)+12-m+b)+"������"+"��"+((a-y-1)*365+(12-m+b-1)*30+(a-y)/4+c+30-d)+"����");
}
public static void main(String[] args){
   Calendar calendar=Calendar.getInstance();
    sy7_2 t=new sy7_2();
    System.out.print("��ǰ��ʱ�����ڣ�");
     t.display(calendar);
     Scanner su=new Scanner(System.in);
     System.out.println("��������ĳ���������");
     int y=su.nextInt();
     int m=su.nextInt();
     int d=su.nextInt();
     t.js(calendar,y,m,d);
}
}