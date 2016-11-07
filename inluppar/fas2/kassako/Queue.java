public class Queue {

// ************* ATTRIBUTES *************
    private Node first;
    private Node last;
    private int length;

// ************ CONSTRUCTORS ************
    public Queue() {}

// ************** METHODS ***************
    public void enQueue(Customer c) {
        Node newNode = new Node(c);
        if(this.length == 0) {
            this.first = this.last = newNode;
        }
        else {
            this.last.setNext(newNode);
            this.last = newNode;
        }
        this.length++;
    }

    public Customer deQueue() {
        Node doneCustomer = this.first;
        this.first = doneCustomer.next(); // removes first Node
        this.length--;
        if(this.length == 0) {
            this.last = null;
        }
        return doneCustomer.customer();
    }

    public boolean isEmpty() {
        return length == 0 ? true : false;
    }

    public Customer first() {
        return this.first.customer();
    }

    public int length() {
        return this.length;
    }


//**************** NODE *****************
    private class Node {

// ************* ATTRIBUTES *************
        private Customer customer;
        private Node next;

// ************ CONSTRUCTORS ************
        public Node(Customer c) {
            this.customer = c;
            this.next = null;
        }

// ************** METHODS ***************
        public void setNext(Node next) {
            this.next = next;
        }

        public Customer customer() {
            return this.customer;
        }

        public Node next() {
            return this.next;
        }
    }
}
