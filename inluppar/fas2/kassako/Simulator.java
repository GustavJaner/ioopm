public class Simulator{
    public static void main(String[] args) throws InterruptedException{

        int steps = 150;
        Simulation s = new Simulation(5, 80, 7, 3);

        for(int i = 0; i < steps; i++){
            System.out.print("\033[2J\033[;H");
            s.step();
            System.out.println(s);
            Thread.sleep(300);
        }
        System.out.println("");
        System.out.println("Simulation finished!");
    }
}
