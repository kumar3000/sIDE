import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("sIDE");
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        frame.setSize(1080, 720);
        frame.setResizable(false);
        frame.setVisible(true);

        ImageIcon img = new ImageIcon("Vitruvian.jpg");
        frame.setIconImage(img.getImage());
        frame.getContentPane().setBackground(Color.black);
    }
}
