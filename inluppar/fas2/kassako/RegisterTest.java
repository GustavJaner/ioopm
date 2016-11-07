public class RegisterTest {
    public static void main(String args[]) {

        Register r = new Register();

        Customer c0 = new Customer(0, 3);
        Customer c1 = new Customer(1, 1);
        Customer c2 = new Customer(2, 2);

        r.open();
        r.addToQueue(c0);
        r.addToQueue(c1);
        r.addToQueue(c2);
        System.out.println(r);

        System.out.println("length of Queue is: " + r.getQueueLength());

        do {
            r.step();
            System.out.println("step..");
            if(r.currentCustomerIsDone() == true) {
                r.removeCurrentCustomer();
                System.out.println("removing customer!");
            }
        } while(r.hasCustomers() == true);

        System.out.println("length of Queue is: " + r.getQueueLength());
        r.close();
        System.out.println(r);
    }
}
