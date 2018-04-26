package falstad;

import java.awt.Color;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Panel;
import java.awt.RenderingHints;

/**
 * Add functionality for double buffering to an AWT Panel class.
 * Used for drawing a maze.
 * 
 * @author pk
 *
 */
public class MazePanel extends Panel  {
	
	
	
	/* Panel operates a double buffer see
	 * http://www.codeproject.com/Articles/2136/Double-buffer-in-standard-Java-AWT
	 * for details
	 */
	// uses a delayed initialization and relies on client class to call initBufferImage()
	// before first use
	private Image bufferImage;  
	private Graphics2D graphics; // obtained from bufferImage, 
	// graphics is stored to allow clients to draw on same graphics object repeatedly
	// has benefits if color settings should be remembered for subsequent drawing operations
	
	/**
	 * Constructor. Object is not focusable.
	 */
	public MazePanel() {
		setFocusable(false);
		bufferImage = null; // bufferImage initialized separately and later
		graphics = null;
		
	}
	
	@Override
	public void update(Graphics g) {
		paint(g);
	}
	/**
	 * Method to draw the buffer image on a graphics object that is
	 * obtained from the superclass. The method is used in the MazeController.
	 * Warning: do not override getGraphics() or drawing might fail. 
	 */
	public void update() {
		paint(getGraphics());
	}
	

	/**
	 * Draws the buffer image to the given graphics object.
	 * This method is called when this panel should redraw itself.
	 */
	@Override
	public void paint(Graphics g) {
		if (null == g) {
			System.out.println("MazePanel.paint: no graphics object, skipping drawImage operation");
		}
		else {
			g.drawImage(bufferImage,0,0,null);	
		}
	}

	public void initBufferImage() {
		bufferImage = createImage(Constants.VIEW_WIDTH, Constants.VIEW_HEIGHT);
		if (null == bufferImage)
		{
			System.out.println("Error: creation of buffered image failed, presumedly container not displayable");
		}
	}
	/**
	 * Obtains a graphics object that can be used for drawing.
	 * The object internally stores the graphics object and will return the
	 * same graphics object over multiple method calls. 
	 * To make the drawing visible on screen, one needs to trigger 
	 * a call of the paint method, which happens 
	 * when calling the update method. 
	 * @return graphics object to draw on, null if impossible to obtain image
	 */
	public Graphics getBufferGraphics() {
		if (null == graphics) {
			// instantiate and store a graphics object for later use
			if (null == bufferImage)
				initBufferImage();
			if (null == bufferImage)
				return null;
			graphics = (Graphics2D) bufferImage.getGraphics();
			if (null == graphics) {
				System.out.println("Error: creation of graphics for buffered image failed, presumedly container not displayable");
			}
			// success case
			
			//System.out.println("MazePanel: Using Rendering Hint");
			// For drawing in FirstPersonDrawer, setting rendering hint
			// became necessary when lines of polygons 
			// that were not horizontal or vertical looked ragged
			graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
					RenderingHints.VALUE_ANTIALIAS_ON);
			graphics.setRenderingHint(RenderingHints.KEY_INTERPOLATION,
					RenderingHints.VALUE_INTERPOLATION_BILINEAR);
		}
		
		return graphics;
	}

	public void fillPolygon(int[] xps, int[] yps, int i) {
		getBufferGraphics().fillPolygon(xps, yps, i);

	}

	public void setColor(int color) {
		getBufferGraphics().setColor(new Color(color));
	}
	public static int getRGB(int r, int g, int b) {
		return new Color(r, g, b).getRGB();
	}

	public void fillOval(int i, int j, int cirsiz, int cirsiz2) {
		getBufferGraphics().fillOval(i, j, cirsiz, cirsiz2);
	}

	public void drawLine(int ctrx, int ctry, int aptx, int apty) {
		getBufferGraphics().drawLine(ctrx, ctry, aptx, apty);
	}
	
	public enum Colors{
		White, Black, DarkGray, Red, Yellow, Gray, Blue, Orange
	}
	
	public void setColor(Colors color) {
		switch(color) {
		case White:
			getBufferGraphics().setColor(Color.white);
			break;
		case Black:
			getBufferGraphics().setColor(Color.black);
			break;
		case DarkGray:
			getBufferGraphics().setColor(Color.darkGray);
			break;
		case Red:
			getBufferGraphics().setColor(Color.red);
			break;
		case Yellow:
			getBufferGraphics().setColor(Color.yellow);
			break;
		case Gray:
			getBufferGraphics().setColor(Color.gray);
			break;
		case Blue:
			getBufferGraphics().setColor(Color.blue);
			break;
		case Orange:
			getBufferGraphics().setColor(Color.orange);
			break;
		}
	}

	public void fillRect(int i, int j, int view_width, int k) {
		getBufferGraphics().fillRect(i, j, view_width, k);
	}

	public void drawString(String str, int i, int ypos) {
		getBufferGraphics().drawString(str, i, ypos);
	}

	public FontMetrics getFontMetrics() {
		return getBufferGraphics().getFontMetrics();
	}
	

}
