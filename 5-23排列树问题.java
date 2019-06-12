import java.util.Scanner;

public class kk {

    private static int MAX = 100000;
    private static int n;
    private static float min,centerx;
    private static float[] x,xr;

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        while (true){
            min = MAX;

            n = input.nextInt();

            x = new float[n+1];
            xr = new float[n+1];

            for(int i=1; i<=n; i++)
                x[i] = input.nextFloat();

            backtrack(1);

            output();
        }
    }

    private static void backtrack(int t){
        if(t > n) record();
        else
            for(int i=t; i<=n; i++){
                swap(x,t,i);
                if(constraint(t) && bound(t)){
                    change(t);
                    backtrack(t+1);
                    restore(t);
                }
                swap(x,t,i);
            }
    }

    private static void swap(float[] x, int m, int n){
        float tmp = x[m];
        x[m] = x[n];
        x[n] = tmp;
    }

    private static void record(){
        float low=0,high=0;
        for(int i=1; i<=n; i++){
            if(xr[i]-x[i] < low) low=xr[i]-x[i];
            if(xr[i]+x[i] > high) high=xr[i]+x[i];
        }
        if(high-low < min) min=high-low;
    }

    private static boolean constraint(int t){
        return true;
    }

    private static boolean bound(int t){
        centerx = center(t);
        if(centerx+x[t]+x[1] < min) return true;
        else return false;
    }

    private static void change(int t){
        xr[t] = centerx;
    }

    private static void restore(int t){
    }

    private static float center(int t){
        float temp = 0;
        for(int j=1; j<t; j++){
            float valuex = (float) (xr[j]+2.0*Math.sqrt(x[t]*x[j]));
            if(valuex > temp) temp=valuex;
        }

        return temp;
    }

    private static void output(){
        System.out.println(String.format("%.5f",min));
    }
}


