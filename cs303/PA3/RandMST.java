import java.util.Random;
import java.util.Arrays;

public class RandMST{

    static Random rand=new Random(System.currentTimeMillis());

    public static void main(String[]args){

	int vertices,times,dimension;
	double sum;
	long time=0;
        
	if(args[0].equals("-ta")){ //test all
	    times=25;
	    for(int dim : new int[]{0,2,3,4}){
		for(vertices=16;vertices<=8192;vertices*=2){
		    sum=runMST(vertices,times,dim);
		    System.out.println(sum/times+" "+vertices+" "+times+" "+dim);
		}
	    }
	}else{

	    
	    //System.out.println(Arrays.toString(args));
	    if(args.length!=4){
		throw new IllegalArgumentException("Illegal number of arguments");
	    }

	    //System.out.println(args[1]);
	    
	    vertices=Integer.parseInt(args[1]);
	    
	    times=Integer.parseInt(args[2]);
	    
	    dimension=Integer.parseInt(args[3]);

	    time=System.currentTimeMillis();
	    sum=runMST(vertices,times,dimension);
	    time=System.currentTimeMillis()-time;

	    if(args[0].equals("-ao")){ //average only
		System.out.println(sum/times);
	    }else{
		System.out.println(sum/times+" "+vertices+" "+times+" "+dimension);
	    }
	    if(args[0].equals("-t")){//timed
		System.out.println("in "+time+"ms");
	    }
	}
    }

    public static double runMST(int vertices, int times, int dimension){
	double[]xcors=new double[1];
	double[]ycors=new double[1];
	double[]zcors=new double[1];
	double[]vcors=new double[1];
	
	double sum=0;
	for(int z=0;z<times;z++){
	    if(dimension==2){
		xcors=new double[vertices];
		ycors=new double[vertices];

		for(int g=0;g<vertices;g++){
		    xcors[g]=rand.nextDouble();
		    ycors[g]=rand.nextDouble();
		}
	    }else if(dimension==3){
		xcors=new double[vertices];
		ycors=new double[vertices];
		zcors=new double[vertices];

		for(int g=0;g<vertices;g++){
		    xcors[g]=rand.nextDouble();
		    ycors[g]=rand.nextDouble();
		    zcors[g]=rand.nextDouble();
		}
	    }else if(dimension==4){
		
		xcors=new double[vertices];
		ycors=new double[vertices];
		zcors=new double[vertices];
		vcors=new double[vertices];

		for(int g=0;g<vertices;g++){
		    xcors[g]=rand.nextDouble();
		    ycors[g]=rand.nextDouble();
		    zcors[g]=rand.nextDouble();
		    vcors[g]=rand.nextDouble();
		}
	    }
	    sum+=MST(xcors,ycors,zcors,vcors,vertices,dimension);
	}
	return sum;
    }

    public static double MST(double[]xcors,double[]ycors,double[]zcors,double[]vcors,int vertices, int dimension){
	double[]distances=new double[vertices];
	int[] prevs=new int[vertices];

	ANode node=new ANode(-1,-1);

	double sum=0;

	int optVal=vertices/8;
	if(vertices==131072){
	    optVal/=2;
	}
	AHeap minHeap=new AHeap(vertices,optVal);

	int[]verts=new int[vertices];

	for(int z=1;z<vertices;z++){
	    verts[z]=0;
	    distances[z]=Integer.MAX_VALUE;
	}
	verts[0]=1;
	distances[0]=0;

	minHeap.insert(0,distances[0]);
	double biggestEdge=-10;
	
	while (!minHeap.isEmpty()){
	    node=minHeap.deleteMin(node);
	    if(distances[node.getDex()]>biggestEdge){
		biggestEdge=distances[node.getDex()];
	    }
	    verts[node.getDex()]=1;
	    sum+=distances[node.getDex()];
	    for(int z=0;z<vertices;z++){
		if(verts[z]==0){
		    int vert1=node.getDex();

		    int vert2=z;

		    double weight;

		    if(dimension==0){
			weight=rand.nextDouble();
		    }else if(dimension==2){
			weight=Math.sqrt(Math.pow(xcors[vert1]-xcors[vert2],2)+
					 Math.pow(ycors[vert1]-ycors[vert2],2));
		    }else if(dimension==3){
		        weight=Math.sqrt(Math.pow(xcors[vert1]-xcors[vert2],2)+
					 Math.pow(ycors[vert1]-ycors[vert2],2)+
					 Math.pow(zcors[vert1]-zcors[vert2],2));
		    }else{//dim=4
			//System.out.println("dim="+dimension+" "+Arrays.toString(xcors));
			weight=Math.sqrt(Math.pow(xcors[vert1]-xcors[vert2],2)+
					 Math.pow(ycors[vert1]-ycors[vert2],2)+
					 Math.pow(zcors[vert1]-zcors[vert2],2)+
					 Math.pow(vcors[vert1]-vcors[vert2],2));
		    }
		    if(distances[z]>weight){
			distances[z]=weight;
			prevs[z]=node.getDex();
			minHeap.insert(z,distances[z]);
		    }		    
		}
	    }	    
	}
	return sum;
    }
}
