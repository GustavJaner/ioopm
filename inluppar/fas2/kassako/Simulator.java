import java.util.Scanner; // #include <Scanner>

public class Simulator{
    public static void main(String[] args) throws InterruptedException{

        int steps = 100;
        Simulation s = new Simulation(5, 40, 7, 3);

        for(int i = 0; i < steps; i++){
            // Scanner sc = new Scanner(System.in);
            // sc.nextInt();
            System.out.print("\033[2J\033[;H");
            s.step();
            System.out.println(s);
            Thread.sleep(500);
        }
        System.out.println("\nSimulation finished!");
    }
}
