import java.awt.Point;
import java.awt.event.MouseEvent;
import javax.swing.event.MouseInputAdapter;

public class CursorTracker extends MouseInputAdapter {
    private Point objectPosition;

    public CursorTracker(Point objectPosition) {
        this.objectPosition = objectPosition;
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        // Center the object directly on the cursor
        int objectWidth = 50;
        int objectHeight = 50;

        int newX = e.getX() - (objectWidth / 2);
        int newY = e.getY() - (objectHeight / 2);

        objectPosition.setLocation(newX, newY);

        // Trigger UI update
        e.getComponent().repaint();
    }

    static void main(String[] args) {

    }
}