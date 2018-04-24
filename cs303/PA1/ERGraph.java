import java.util.Random;
import java.util.LinkedList;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Collections;

public class ERGraph{

    final int ARRAY_LIST=0;
    final int LINKED_LIST=1;

    LinkedList<Node> vertices= new LinkedList<Node>();
    LinkedList<int[]>edges= new LinkedList<int[]>();
    Random randy=new Random();
    ERGraph(int n, double p){
	for(int z=0;z<n;z++){
	    //all nodes are vertex nodes
	    //so we'll add them all to our vertices
	    getVertices().add(new Node(z));
	}
	//System.out.println(vertices);
	for(int z=0;z<n;z++){
	    for(int g=0;g<z;g++){
		if(randy.nextDouble()<p){
		    //System.out.println(randy.nextDouble());
		    getEdges().add(new int[]{z,g});
		}
	    }
	}
	for( int[] z : edges){
	    //System.out.println(Arrays.toString(z));
	    getVertices().get(z[0]).addNeighbor(getVertices().get(z[1]));
	    //System.out.println(getVertices().get(z[0]));
	    getVertices().get(z[1]).addNeighbor(getVertices().get(z[0]));
	}
	//System.out.println(vertices);
    }

    void DFSComponent(Node n, HashSet<Node> visited){
	for( Node v : n.getNeighbors()){
	    if(!visited.contains(v)){
		visited.add(v);
		DFSComponent(v, visited);
	    }
	}
    }

    public LinkedList<HashSet<Node>> connectedComponents(LinkedList<Node> vertices){
	LinkedList<HashSet<Node>>components=new LinkedList<HashSet<Node>>();
	HashSet<Node>cumulativeVisited=new HashSet<Node>();
	
	for(Node v : vertices){
	    if(!cumulativeVisited.contains(v)){
		HashSet<Node>componentVisited=new HashSet<Node>();
		componentVisited.add(v);
		DFSComponent(v, componentVisited);
		
		components.add(componentVisited);
		cumulativeVisited.addAll(componentVisited);
	    }
	}
	return components;
    }

    public int largestComponentSize(LinkedList<Node>vertices){
	LinkedList<Integer> sizes=new LinkedList<Integer>();
	for(HashSet<Node> z : connectedComponents(vertices)){
	    sizes.add(z.size());
	}
	return Collections.max(sizes);
    }

    public int largestComponentSize(){
	return largestComponentSize(getVertices());
    }


    //Given a graph G and a threshold t, write a function to test whether G contains a connected component of t vertices or more.
    public static int tVerticesOrMore(int t, ERGraph g){
	if(t>g.largestComponentSize()){
	    return 0;//# of vertices is lower than t, so the test fails
	}
	return 1;//otherwise largestComponentSize() must be t or higher
    }

    public LinkedList<Node> getVertices(){
	return vertices;
    }

    public LinkedList<int[]> getEdges(){
	return edges;
    }
    
    
    class Node{
	
	int index;
	LinkedList<Node>neighbors;
	
	Node(int dex){
	    index=dex;
	    neighbors=new LinkedList<Node>();
	}
	public void addNeighbor(Node nbor){
	    neighbors.add(nbor);
	}
	public String toString(){
	    return Integer.toString(index);
	}
	public LinkedList<Node> getNeighbors(){
	    return neighbors;
	}
    }
    
    public String toString(){
	return Integer.toString(largestComponentSize());
    }
}
