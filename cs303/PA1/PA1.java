import java.io.*;


public class PA1{

    public static void main(String[]args)throws IOException{

	if(args.length!=2){
	    System.out.println("Invalid # of arguments found");
	    args=new String[]{"40","PA1"};
	}

	System.out.println("Using n="+args[0]);
	System.out.println("Outputting percentages to "+args[1]+".csv");

	
	BufferedWriter writer=new BufferedWriter(new FileWriter(args[1]+".csv"));
	String initial="c-values,percentage";
	writer.write(initial,0,initial.length());
	writer.newLine();
	int n=Integer.parseInt(args[0]);
	for(double c=.2;c<3.1;c+=0.2){
	    ERGraph[]graphs=new ERGraph[500];
	    double percentage=0;
	    for(int z=0;z<graphs.length;z++){
		graphs[z]=new ERGraph(n, c/n);
		percentage+=ERGraph.tVerticesOrMore((n*3)/4,graphs[z]);
	    }
	    percentage/=5;
	    String cvaluePercent=""+c+","+percentage;
	    writer.write(cvaluePercent,0,cvaluePercent.length());
	    writer.newLine();
	    //System.out.println("c="+c);
	}
	writer.close();
    }

}
