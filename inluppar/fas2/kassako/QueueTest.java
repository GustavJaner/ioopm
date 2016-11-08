public class QueueTest {
    public static void main(String args[]) {

        Queue q = new Queue();

        Customer c0 = new Customer(0, 2);
        Customer c1 = new Customer(1, 1);
        Customer c2 = new Customer(2, 2);

        q.enQueue(c0);
        q.enQueue(c1);
        q.enQueue(c2);
        System.out.println("length is now: " + q.length());

        System.out.println(q);

        c0.serve();
        c0.serve();
        if(c0.isDone())
            q.deQueue();
        System.out.println("first in Queue: " + q.first());
        c1.serve();
        if(c1.isDone())
            q.deQueue();
        c2.serve();
        c2.serve();
        if(c2.isDone())
            q.deQueue();

        System.out.println("length is now: " + q.length());
        System.out.println("Queue is empty: " + q.isEmpty());

    }
}
