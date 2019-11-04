    import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class IndianFlag extends JPanel implements ActionListener
{
		Timer tm = new Timer(5, this);
		int y=370, velY=1;
		public void paintComponent(Graphics g)
		{
			super.paintComponent(g);
			g.setColor(Color.BLACK);		//for the rod
			g.fillRect(55,10,5,360);
						
			g.setColor(Color.GREEN);		//for the flag
			g.fillRect(60,(y+60),150,30);
			g.setColor(Color.WHITE);
			g.fillRect(60,(y+30),150,30);
			g.setColor(Color.BLUE);
			g.drawOval(120,(y+30),30,30);
			{
				int x1=135, y1=y+45;
				double x2, y2;
				double degree=0.0, d=0.0;
				int i, r=15;
				for(i=0; i<24; i++)
				{ 
					degree=(double)d*(3.14/180);   //convert to radians
					x2= x1+(double)r * Math.cos(degree);   //parametric equations
					y2= y1+ (double)r * Math.sin(degree);
					g.drawLine(x1, y1, (int)x2, (int)   y2);
					d= d+(360/24); //increment angle 
				}
			}
			g.setColor(Color.ORANGE);
			g.fillRect(60,y,150,30);
			
			g.setColor(Color.BLACK);
			g.fillRect(45,370,25,10);
			
			
			
			g.fillRect(310, 260, 40, 15);		//hands
			g.fillRect(310, 230, 15, 30);		
			g.fillRect(390, 260, 40, 15);		
			g.fillRect(415, 230, 15, 30);
			//g.fillRect(310, 300, 15, 5);
			
			g.fillOval(350, 215, 40, 40);		//face
			
			g.setColor(Color.blue);
			g.fillRect(350, 260, 50, 50);		//Body
			
			g.setColor(Color.GRAY);
			g.fillRect(350, 310, 15, 50);		//legs
			g.fillRect(385, 310, 15, 50);
				
			tm.start();
		}
		
		public void actionPerformed(ActionEvent e)
		{
			if(y>=20)
			{
				y = y - velY;
			}
			repaint();
		}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 IndianFlag fh= new IndianFlag();
		 JFrame frame = new JFrame("National Flag Hoisting");
         frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
         frame.setSize(600, 400);
         frame.setLocationRelativeTo(null);
         frame.setVisible(true);
         frame.add(fh);

		}
	}


