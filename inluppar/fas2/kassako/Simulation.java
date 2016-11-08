import java.util.Random;
import java.util.*;
import  java.text.DecimalFormat;

public class Simulation {

    private Store store;
    private int time;
    private int intensity;
    private int maxGroceries;
    private int thresholdForNewRegister;
    private Random random = new Random();

    private int doneCustomers;
    private int maxWaitTime;
    private float averageWaitTime;


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

        if(this.thresholdForNewRegister <= this.store.getAverageQueueLength()) {
            this.store.openNewRegister();
        }

        if(this.intensity > random.nextInt(100)) {
            Customer c = new Customer(this.time, 1+random.nextInt(this.maxGroceries));
            this.store.newCustomer(c);
        }

        ArrayList<Customer> doneCustomersArray = new ArrayList<Customer>();
        doneCustomersArray = this.store.getDoneCustomers();
        this.doneCustomers += doneCustomersArray.size();

        if(doneCustomersArray.size() > 0) {
            for(Customer c : doneCustomersArray) {
                if(this.maxWaitTime < this.time - c.bornTime()) {
                    this.maxWaitTime = this.time - c.bornTime();
                }
                if(this.doneCustomers != 0) { // all other customers exiting the store
                    this.averageWaitTime = ((this.averageWaitTime + (this.time - c.bornTime())) / 2);
                }
                else { // first customer to exit store
                    this.averageWaitTime = this.time - c.bornTime();
                }
            }

        }
        doneCustomersArray.clear();

        this.time++;
    }

    public String smallerDecimal(double averageWaitTime) {
        DecimalFormat f = new DecimalFormat("#.00");
        return (f.format(averageWaitTime));
    }

    public String toString() {
        String humma = this.smallerDecimal(this.averageWaitTime);
        return  this.store.toString() +
                "time: " + this.time +
                "\ndoneCustomers: " + this.doneCustomers +
                "\nmaxWaitTime: " + this.maxWaitTime +
                "\naverageWaitTime: " + humma +
                "\nopenRegisters: " + this.store.amountOfOpenRegisters() +
                "\naverageQueueLength: " + this.store.getAverageQueueLength();
    }
}
