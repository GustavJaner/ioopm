public class Register {

// ************* ATTRIBUTES *************
    private boolean open;
    private Queue queue;

// ************ CONSTRUCTORS ************
    public Register() {
        this.open = false;
        this.queue = new Queue();
    }

// ************** METHODS ***************
    public void step() {
        (this.queue.first()).serve();
    }

    public void open() {
        this.open = true;
    }

    public void close() {
        this.open = false;
    }

    public void addToQueue(Customer c) {
        this.queue.enQueue(c);
    }

    public Customer removeCurrentCustomer() {
        if(this.queue.length() == 0) {
            throw new EmptyQueueException();
        }
        return this.queue.deQueue();
    }

    public boolean isOpen() {
        return open == true ? true : false;
    }

    public boolean hasCustomers() {
        return this.queue.isEmpty() == false ? true : false;
    }

    public boolean currentCustomerIsDone() {
        if(this.queue.length() == 0) {
            throw new EmptyQueueException();
        }
        return (this.queue.first()).isDone() == true ? true : false;
    }

    public int getQueueLength() {
        return this.queue.length();
    }

    public String toString() {
        if(this.isOpen()) {
            return "    " + this.queue.toString() + "\n";
        }
        else {
            return "X   [ ]\n";
        }
    }

    public class EmptyQueueException extends RuntimeException{}
}
