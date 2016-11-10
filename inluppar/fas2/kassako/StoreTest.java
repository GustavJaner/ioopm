public class StoreTest {
    public static void main(String args[]) {

        Store s = new Store(5);
        int thresholdForNewRegister = 2;

        System.out.println("s.amountOfRegisters: " + s.amountOfRegisters());
        System.out.println("s.amountOfOpenRegisters: " + s.amountOfOpenRegisters());


        for(int i=0; i < 5; i++) {
            Customer c = new Customer(0, 1);

            if(thresholdForNewRegister <= s.getAverageQueueLength()) {
                System.out.println("ny kassa!");
                s.openNewRegister();
            }
            s.newCustomer(c);
        }

        System.out.println("s.amountOfOpenRegisters: " + s.amountOfOpenRegisters());

        do {
            s.step();
            System.out.println("step..");
            s.getDoneCustomers();
        } while(s.amountOfOpenRegisters() != 0);




        s.getDoneCustomers();

        System.out.println("s.amountOfOpenRegisters: " + s.amountOfOpenRegisters());
    }
}
