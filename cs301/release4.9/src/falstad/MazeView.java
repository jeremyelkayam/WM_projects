package falstad;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JPanel;

import falstad.Constants.StateGUI;
import falstad.MazePanel.Colors;
import generation.Order;

/**
 * Implements the screens that are displayed whenever the game is not in 
 * the playing state. The screens shown are the title screen, 
 * the generating screen with the progress bar during maze generation,
 * and the final screen when the game finishes.
 * @author pk
 *
 */
public class MazeView extends DefaultViewer {
	

	// need to know the maze model to check the state 
	// and to provide progress information in the generating state
	private MazeController controller ;
	private Graphics gfx;
	
	public MazeView(MazeController c) {
		super() ;
		controller = c ;
	}
	
	public void setGraphics(Graphics gc) {
		this.gfx=gc;
	}
	
	public Graphics getGraphics() {
		return gfx;
	}

	@Override
	public void redraw(MazePanel gc, StateGUI state, int px, int py, int view_dx,
			int view_dy, int walk_step, int view_offset, RangeSet rset, int ang) {
		//dbg("redraw") ;
		switch (state) {
		case STATE_TITLE:
			redrawTitle(gc);
			break;
		case STATE_GENERATING:
			redrawGenerating(gc);
			break;
		case STATE_PLAY:
			// skip this one
			break;
		case STATE_FINISH:
			redrawFinish(gc);
			break;
		}
	}
	
	private void dbg(String str) {
		System.out.println("MazeView:" + str);
	}
	
	// 
	
	String[]builder= {"DFS","Prim","Eller"};
	String[]drivers= {"Wizard","Wall Follower","Pledge","Explorer","Manual"};
	Integer[]skill= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	JComboBox<String> builder_box=new JComboBox<String>(builder);
	JComboBox<String> drivers_box=new JComboBox<String>(drivers);
	JComboBox<Integer> skill_box=new JComboBox<Integer>(skill);
	JButton button=new JButton("Submit");
	
	/**
	 * Helper method for redraw to draw the title screen, screen is hard coded
	 * @param  gc graphics is the off screen image
	 */
	void redrawTitle(MazePanel gc) {
		
		// produce white background
		gc.setColor(Colors.White);
		gc.fillRect(0, 0, Constants.VIEW_WIDTH, Constants.VIEW_HEIGHT);
		// write the title 
		gc.setFont(largeBannerFont);
		FontMetrics fm = gc.getFontMetrics();
		gc.setColor(Colors.Red);
		centerString(gc, fm, "MAZE", 100);
		// write the reference to falstad
		gc.setColor(Colors.Blue);
		gc.setFont(smallBannerFont);
		fm = gc.getFontMetrics();
		centerString(gc, fm, "by Paul Falstad", 160);
		centerString(gc, fm, "www.falstad.com", 190);
		// write the instructions
		gc.setColor(Colors.Black);
		centerString(gc, fm, "To start, choose your maze settings.", 250);
		centerString(gc, fm, "Select a generation algorithm, solving algorithm, and", 300);
		centerString(gc, fm, "difficulty from the drop-down menus, and press submit.", 320);
		centerString(gc, fm, "Version 2.0", 350);


		builder_box.setLightWeightPopupEnabled(false);
		drivers_box.setLightWeightPopupEnabled(false);
		skill_box.setLightWeightPopupEnabled(false);
		
		Panel panel=controller.getPanel();
		
		JPanel p1 = new JPanel();
		p1.setLayout(new FlowLayout());
		p1.setBackground(Color.WHITE);
		p1.setLocation(20,0);
		p1.setSize(75,30);
		p1.add(builder_box);
		p1.setVisible(true);
		panel.add(p1);
		
		JPanel p2 = new JPanel();
		p2.setLayout(new FlowLayout());
		p2.setBackground(Color.WHITE);
		p2.setLocation(100,0);
		p2.setSize(150,30);
		p2.add(drivers_box);
		p2.setVisible(true);
		panel.add(p2);

		JPanel p3 = new JPanel();
		p3.setLayout(new FlowLayout());
		p3.setBackground(Color.WHITE);
		p3.setLocation(250,0);
		p3.setSize(60,30);
		p3.add(skill_box);
		p3.setVisible(true);
		panel.add(p3);
		
		JPanel p4 = new JPanel();
		p4.setLayout(new FlowLayout());
		p4.setBackground(Color.WHITE);
		p4.setLocation(300,0);
		p4.setSize(100,30);
		p4.add(button);
		p4.setVisible(true);
		panel.add(p4);
		
		button.addActionListener(new ButtonListener());
		
		panel.paintComponents(gc.getGraphics());
		
		//System.out.println("MazeView: set up title screen");
	}
	
	private class ButtonListener implements ActionListener{
		private RobotDriver driver;
		public void actionPerformed(ActionEvent e) {
			String driver = (String) drivers_box.getSelectedItem();
			String builder = (String) builder_box.getSelectedItem();
			
			switch(driver) {
			case "Wizard":
				this.driver=new Wizard(controller);
				break;
			case "Wall Follower":
				this.driver=new WallFollower(controller);
				break;
			case "Pledge":
				this.driver=new Pledge(controller);
				break;
			case "Manual":
				this.driver=new ManualDriver(controller);
				break;
			case "Explorer":
				this.driver=new Explorer(controller);
			}
			
			switch(builder) {
			case "DFS":
				controller.setBuilder(Order.Builder.DFS);
				break;
			case "Prim":
				controller.setBuilder(Order.Builder.Prim);
				break;
			case "Eller":
				controller.setBuilder(Order.Builder.Eller);
				break;
			}
			controller.setSkillLevel(((int)skill_box.getSelectedItem()));
			controller.switchToGeneratingScreen();
		}
	}
	/**
	 * Helper method for redraw to draw final screen, screen is hard coded
	 * @param gc graphics is the off screen image
	 */
	void redrawFinish(MazePanel gc) {
		// produce blue background
		if(controller.getRobotBattery()>=0) {
			gc.setColor(Colors.Blue);
		}else {
			gc.setColor(Colors.Red);
		}
		gc.fillRect(0, 0, Constants.VIEW_WIDTH, Constants.VIEW_HEIGHT);
		// write the title 
		gc.setFont(largeBannerFont);
		FontMetrics fm = gc.getFontMetrics();
		gc.setColor(Colors.Yellow);
		if(controller.getRobotBattery()>=0) {
			gc.setColor(Colors.Yellow);
			centerString(gc, fm, "You won!", 100);
		}else {
			gc.setColor(Colors.Blue);
			centerString(gc, fm, "You lost :(", 100);
		}
		// write some extra blufb
		gc.setColor(Colors.Orange);
		gc.setFont(smallBannerFont);
		fm = gc.getFontMetrics();
		if(controller.getRobotBattery()>=0) {
			centerString(gc, fm, "Congratulations!", 160);
		}
		// write the instructions
		gc.setColor(Colors.White);
		centerString(gc, fm, "Your final distance traveled was: "+controller.getRobotDistance(), 220);
		gc.setColor(Colors.White);
		centerString(gc, fm, "Your power consumed was: "+(3000-controller.getRobotBattery()), 250);
		gc.setColor(Colors.White);
		centerString(gc, fm, "Pick your settings to play again!", 300);
		controller.getPanel().paintComponents(gc.getGraphics());
	}

	/**
	 * Helper method for redraw to draw screen during phase of maze generation, screen is hard coded
	 * only attribute percentdone is dynamic
	 * @param gc graphics is the off screen image
	 */
	void redrawGenerating(MazePanel gc) {
		// produce yellow background
		gc.setColor(Colors.Yellow);
		gc.fillRect(0, 0, Constants.VIEW_WIDTH, Constants.VIEW_HEIGHT);
		// write the title 
		gc.setFont(largeBannerFont);
		FontMetrics fm = gc.getFontMetrics();
		gc.setColor(Colors.Red);
		centerString(gc, fm, "Building maze", 150);
		gc.setFont(smallBannerFont);
		fm = gc.getFontMetrics();
		// show progress
		gc.setColor(Colors.Black);
		if (null != controller)
			centerString(gc, fm, controller.getPercentDone()+"% completed", 200);
		else
			centerString(gc, fm, "Error: no controller, no progress", 200);
		// write the instructions
		centerString(gc, fm, "Hit escape to stop", 300);
	}
	
	private void centerString(MazePanel gc, FontMetrics fm, String str, int ypos) {
		gc.drawString(str, (Constants.VIEW_WIDTH-fm.stringWidth(str))/2, ypos);
	}

	final Font largeBannerFont = new Font("TimesRoman", Font.BOLD, 48);
	final Font smallBannerFont = new Font("TimesRoman", Font.BOLD, 16);

}
