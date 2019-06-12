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
            //�����Ӽ��ռ���
            while (true){
                //�������ӽ��
                if(constraint()) enQueue(Q,1);
                //����Ҷ��ӽ��
                if(bound()) enQueue(Q,0);
                //ȡ��һ��չ���
                if(!getNext(Q)) break;
            }
            solution(bestE);//�������Ž�
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

        //��������뵽�������Q��
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
            E = Q.poll();       //ȡ��һ��չ���
            Ew = E.weight;      //����չ�������Ӧ��������
            if(i < E.i) r-=w[i];//ʣ�༯װ������
            i = E.i+1;

            return true;
        }

        //�������Ž�
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


