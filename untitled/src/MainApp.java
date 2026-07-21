import javax.swing.JButton;
import javax.swing.JFrame;

public class MainApp {
    public static void main(String[] args) {
        JFrame frame = new JFrame("My first java app!");
        frame.setSize(500, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton button = new JButton("Click me!");
        frame.add(button);

        frame.setVisible(true);
    }
}
