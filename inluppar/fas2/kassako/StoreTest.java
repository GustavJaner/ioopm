public class StoreTest {
    public static void main(String args[]) {

        Store s = new Store(5);

        System.out.println("s.amountOfRegisters: " + s.amountOfRegisters());
        System.out.println("s.amountOfOpenRegisters: " + s.amountOfOpenRegisters());

        Customer c0 = new Customer(0, 1);
        Customer c1 = new Customer(1, 1);
        Customer c2 = new Customer(2, 4);

        s.newCustomer(c0);
        s.newCustomer(c1);
        s.newCustomer(c2);

        do {
            s.step();
            System.out.println("step..");
            s.getDoneCustomers();
        } while(s.amountOfOpenRegisters() != 0);

        System.out.println("s.amountOfOpenRegisters: " + s.amountOfOpenRegisters());
    }
}
