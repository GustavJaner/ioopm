import java.util.Random;
import java.util.*;

public class Simulation {

    private Store store;
    private int time;
    private int intensity;
    private int maxGroceries;
    private int thresholdForNewRegister;
    private Random random = new Random();

    private int doneCustomers;
    private int maxWaitTime;
    private int averageWaitTime;


    public Simulation(int amountReg, int _intensity, int _maxGroceries, int _threshold) {
        this.store = new Store(amountReg);
        this.time  = 0;
        this.intensity = _intensity;
        this.maxGroceries = _maxGroceries;
        this.thresholdForNewRegister = _threshold;
        this.doneCustomers = 0;
        this.maxWaitTime = 0;
        this.averageWaitTime = 0;
    }

    void step() {

        this.store.step();

        if(this.intensity > random.nextInt(100)) {
            Customer c = new Customer(this.time, 1+random.nextInt(this.maxGroceries-1));
            this.store.newCustomer(c);
        }

        if(this.thresholdForNewRegister <= this.store.getAverageQueueLength()) {
            this.store.openNewRegister();
        }

        ArrayList<Customer> doneCustomersArray = new ArrayList<Customer>();
        doneCustomersArray = this.store.getDoneCustomers();

        this.doneCustomers += doneCustomersArray.size();

        if(doneCustomersArray.size() > 0) {
            for(Customer c : doneCustomersArray) {
                if(this.maxWaitTime < this.time - c.bornTime()) {
                    this.maxWaitTime = this.time - c.bornTime();
                }
                if(this.doneCustomers != 0) {
                    this.averageWaitTime = ((this.averageWaitTime + (this.time - c.bornTime())) / this.doneCustomers);
                }
                else {
                    this.averageWaitTime = this.time - c.bornTime();
                }
            }

        }
        doneCustomersArray.clear();

        this.time++;
    }

    public String toString() {
        return "doneCustomers: " +this.doneCustomers+ "\nmaxWaitTime: " +this.maxWaitTime+
                "\naverageWaitTime: " +this.averageWaitTime;
    }
}
