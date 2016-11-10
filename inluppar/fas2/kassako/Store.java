import java.util.*;

public class Store {

// ************* ATTRIBUTES *************
    private Register[] registers;

// ************ CONSTRUCTORS ************
    public Store(int amountReg) {

        this.registers = new Register[amountReg]; // just creates the array
        for(int i = 0; i < amountReg; i++) {
            this.registers[i] = new Register();
        }
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
            if(r.isOpen() && r.hasCustomers() && r.currentCustomerIsDone()) {
                doneCustomers.add(r.removeCurrentCustomer());
            }
            if(r.isOpen() && r.hasCustomers() == false) {
                r.close();
            }
        }
        return doneCustomers;
    }

// **************
    public int getAverageQueueLength() {
        int sum = 0;
        for(Register r : this.registers) {
            if(r.isOpen()) {
                sum += r.getQueueLength();
            }
        }
        if(this.amountOfOpenRegisters() != 0) {
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
    public void newCustomer(Customer c, int thresholdForNewRegister) {
        if(this.amountOfOpenRegisters() == 0) {
            this.openNewRegister();
        }
        else if(thresholdForNewRegister <= this.getAverageQueueLength()) {
            this.openNewRegister();
        }

        Register smallest = this.registers[0];
        if(this.amountOfOpenRegisters() == 1) {
            this.registers[0].addToQueue(c);
        }
        else {
            for(int i = 1; i < this.amountOfOpenRegisters(); i++) {
                if(this.registers[i].getQueueLength() < smallest.getQueueLength()) {
                    smallest = this.registers[i];
                }
            smallest.addToQueue(c);
            }
        }
    }

// **************
    public void openNewRegister() {
        if(this.amountOfRegisters() > this.amountOfOpenRegisters()) {
            int index = this.amountOfOpenRegisters();
            this.registers[index].open();
        }
        else {
            return;
        }
    }

// **************
    public String toString() {
        String lol = "";
        for(Register r : this.registers) {
            lol += r.toString();
        }
        return lol;
    }
}
