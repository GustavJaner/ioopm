public class Customer {

// ************* ATTRIBUTES *************
    private int bornTime;  //Tidssteget som kunden kom in i systemet
    private int groceries;

// ************ CONSTRUCTORS ************
    public Customer(int _bornTime, int _groceries) {
        this.bornTime  = _bornTime;
        this.groceries = _groceries;
    }

// ************** METHODS ***************
    public void serve() {
        this.groceries--;
    }

    public boolean isDone() {
        return this.groceries <= 0 ? true : false;
    }

    public String toString() {
        return "Customer("+bornTime+", "+groceries+")";
    }
}
