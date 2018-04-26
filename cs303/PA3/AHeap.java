public class AHeap{

    int children;
    int size;
    int maxSize;
    ANode[]nodes;
    int[]vertPosition;

    public AHeap(int size,int children){
	maxSize=size;
	this.size=0;
	this.children=children;
	nodes=new ANode[size];
	vertPosition=new int[size];
	for(int z=0;z<size;z++){
	    vertPosition[z]=-1;
	}
	//System.out.println(children);
    }
    
    public int findVert(int vert){
	if (vertPosition[vert]!=-1){
	    return vertPosition[vert];
	}
	return -1;
    }

    public void swap(ANode a, ANode b, int aDex, int bDex){
	vertPosition[a.getDex()]=bDex;
	vertPosition[b.getDex()]=aDex;
    }

    public boolean isEmpty(){
	return size==0;
    }

    public boolean isFull(){
	return size==maxSize;
    }

    public ANode deleteMin(ANode min){
	if(isEmpty()){
	    System.out.println("heap empty");
	    return min;
	}
	//System.out.println(min);

	min.setDex(nodes[0].getDex());
	min.setWeight(nodes[0].getWeight());
	vertPosition[nodes[0].getDex()]=-1;
	if(!isEmpty()){
	    vertPosition[nodes[size-1].getDex()]=0;
	}
	nodes[0]=nodes[size-1];
	size--;

	minHeapify(0);

	return min;
    }

    public void insert(int vert,double dist){
	if(isFull()){
	    System.out.println("heap is full");
	    return;
	}

	if(findVert(vert)!=-1){
	    nodes[vertPosition[vert]].setWeight(dist);

	    minHeapify(vertPosition[vert]);
	    propagate(vertPosition[vert]);
	}else{
	    nodes[size]=new ANode(vert,dist);
	    vertPosition[vert]=size;
	    propagate(size);
	    size++;
	}
    }

    public void propagate(int insPos){
	while (insPos > 0 && nodes[insPos].getWeight() < nodes[getParent(insPos)].getWeight()) {
	    int parPos = getParent(insPos);
	    swap(nodes[insPos], nodes[parPos], insPos, insPos);
	    ANode temp=nodes[insPos];
	    nodes[insPos]=nodes[parPos];
	    nodes[parPos]=temp;
	    insPos = parPos;
	}
    }
    
    public int getParent(int z){
	//System.out.println(children);
	return (z-1)/children;
    }

    public int getChild(int z,int k){
	return (children*z)+k;
    }

    public void minHeapify(int parent){
	int swap=parent;
	boolean swapping=true;

	while(swapping){
	    for(int z=1;z<children+1;z++){
		
		int kid=getChild(parent,z);
		if(kid<size){
		    if(nodes[kid].getWeight()<nodes[kid].getWeight()){
			swap=kid;
		    }
		}
	    }
	    if(swap!=parent){
		swap(nodes[parent],nodes[swap],parent,swap);
	        ANode temp=nodes[swap];
		nodes[swap]=nodes[parent];
		nodes[parent]=temp;
		parent=swap;
	    }else{
		swapping=false;
	    }	    
	}
    }

    public String toString(){
	String result="";
	for(int z=0;z<size;z++){
	    result+="["+nodes[z].getDex()+", "+nodes[z].getWeight()+"], ";
	}
	return result;
    }
}
