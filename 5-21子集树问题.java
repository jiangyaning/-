import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class kk {

    private static class QNode{
        QNode parent;
        int i,LChild;
        int weight;
    }

    private static class Loading{
        int n;
        int c,r,Ew,wt,bestw;
        int[] bestx,w;

        private void fifobb(){
            Queue<QNode> Q =  new LinkedList();
            i = 1;
            bestE = new QNode();
            //搜索子集空间树
            while (true){
                //检查左儿子结点
                if(constraint()) enQueue(Q,1);
                //检查右儿子结点
                if(bound()) enQueue(Q,0);
                //取下一扩展结点
                if(!getNext(Q)) break;
            }
            solution(bestE);//构造最优解
        }

        private boolean constraint(){
            wt = Ew+w[i];
            if(wt <= c){
                if(wt > bestw) {bestw=wt; bestE=E;}
                if(i < n) return true;
            }

            return false;
        }

        private boolean bound(){
            return (Ew+r>bestw && i<n);
        }

        //将活结点加入到活结点队列Q中
        private void enQueue(Queue<QNode> Q, int ch){
            QNode b = new QNode();
            if(ch > 0) b.weight=wt;
            else b.weight=Ew;
            b.parent = E;
            b.i = i;
            b.LChild = ch;
            Q.add(b);
        }

        private boolean getNext(Queue<QNode> Q){
            if(Q.isEmpty()) return false;
            E = Q.poll();       //取下一扩展结点
            Ew = E.weight;      //新扩展结点所相应的载重量
            if(i < E.i) r-=w[i];//剩余集装箱重量
            i = E.i+1;

            return true;
        }

        //构造最优解
        private void solution(QNode bestE){
            int besti = bestE.i+1;
            for(int j=n; j>besti; j--) bestx[j]=0; bestx[besti]=1;
            for(int j=besti-1; j>0; j--){
                bestx[j] = bestE.LChild;
                bestE = bestE.parent;
            }
        }
    }

    private static QNode E,bestE;
    private static int i;

    public static void main(String[] args){
        int n,c;
        Scanner input = new Scanner(System.in);

        while (true){
            n = input.nextInt();
            c = input.nextInt();

            int[] w = new int[n+1];
            int[] x = new int[n+1];

            for(int i=1; i<=n; i++)
                w[i] = input.nextInt();

            System.out.println(maxLoading(w,c,n,x));
            for(int i=1; i<=n; i++)
                System.out.print(x[i]+" ");
        }
    }

    private static int maxLoading(int[] w, int c, int n, int[] bestx){
        Loading X = new Loading();
        X.c=c; X.n=n; X.Ew=0; X.bestw=0; X.r=0;
        X.w=w; X.bestx=bestx;
        for(int j=2; j<=n; j++) X.r+=w[j];
        X.fifobb();

        return X.bestw;
    }
}


