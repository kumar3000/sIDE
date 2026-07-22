import java.awt.*;
import javax.swing.*;

public class DragFrame extends JFrame {
    private final Point objPos = new Point(100, 100);

    public DragFrame() {
        setTitle("Follow Cursor");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel canvas = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                // Draw a circle following the cursor
                g2d.setColor(Color.RED);
                g2d.fillOval(objPos.x, objPos.y, 50, 50);
            }
        };

        // Attach MouseMotionListener
        CursorTracker listener = new CursorTracker(objPos);
        canvas.addMouseMotionListener(listener);
        canvas.addMouseListener(listener); // Needed if tracking drags as well

        add(canvas);
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(DragFrame::new);
    }
}