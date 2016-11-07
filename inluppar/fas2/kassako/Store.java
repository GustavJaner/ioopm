import java.util.*;

public class Store {

// ************* ATTRIBUTES *************
    private Register[] registers;

// ************ CONSTRUCTORS ************
    public Store(int amountReg) {

        registers = new Register[amountReg];

        for(int i = 0; i < amountReg; i++) {
            this.registers[i] = new Register();
        }
        this.registers[0].open();
    }

// ************** METHODS ***************
    public void step() {
        for(Register r : this.registers) {
                if(r.isOpen() && r.hasCustomers()) {
                    r.step();
                }
        }
    }

// **************
    public ArrayList<Customer> getDoneCustomers() {
        ArrayList<Customer> doneCustomers = new ArrayList<Customer>();

        for(Register r : this.registers) {
            if(r.isOpen() && r.currentCustomerIsDone() == true) {
                doneCustomers.add(r.removeCurrentCustomer());
                System.out.println("removing customer!");
            }
            if(r.hasCustomers() == false) {
                r.close();
            }
        }
        return doneCustomers;
    }

// **************
    public int getAverageQueueLength() {
        int sum = 0;
        for(Register r : this.registers) {
            sum += r.getQueueLength();
        }
        if(this.amountOfOpenRegisters != 0) {
            return (sum/this.amountOfOpenRegisters());
        }
        else {
            return sum;
        }
    }

// **************
    public int amountOfRegisters() {
        int amount=0;
        for(Register r : this.registers) {
                amount++;
        }
        return amount;
    }

// **************
    public int amountOfOpenRegisters() {
        int amount = 0;
        for(Register r : this.registers) {
            if(r.isOpen())
                amount++;
        }
        return amount;
    }

// **************
    public void newCustomer(Customer c) {
        Register smallest = this.registers[0];

        if(this.amountOfOpenRegisters() == 1) {
            this.registers[0].addToQueue(c);
        }
        else {
            for(int i = 1; i < this.amountOfRegisters(); i++) {
                if(this.registers[i].getQueueLength() < smallest.getQueueLength())
                    smallest = this.registers[i];

            smallest.addToQueue(c);
            }
        }
    }

// **************
    public void openNewRegister() {
        if(this.amountOfRegisters() < this.amountOfOpenRegisters()) {
            this.registers[this.amountOfOpenRegisters()].open();
        }
        else {
            System.out.print("all registers already open...");
        }
    }
}
