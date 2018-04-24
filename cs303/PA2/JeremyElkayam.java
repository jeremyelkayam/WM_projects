import java.util.Arrays;
import java.util.Random;
import java.util.ArrayList;


public class JeremyElkayam{

    private static int[] toIntArr(ArrayList<Integer>g){
	int[]result=new int[g.size()];
	for(int z=0;z<g.size();z++){
	    result[z]=g.get(z);
	}
	return result;
    }
    

    public static void main(String[]args){
	Random randy=new Random();
	int[]testArr={7, 2, 4, 6, 9, 11, 2, 6, 10, 6, 15, 6, 14, 2, 7, 5, 13, 9, 12, 15};

	System.out.println("testArr: "+Arrays.toString(testArr));
	System.out.println("Using algorithm 1 with testArr and k=10: "+algorithmOne(testArr,10));
	
	int[]stuff=new int[(int)Math.pow(10,7)*5];
	for(int z=0;z<stuff.length;z++){
	    stuff[z]=randy.nextInt((int)Math.pow(10,5));
	}
	
	System.out.println("Generated random array of size 10^7.");

	long time;
	int[]stuffCopy=stuff.clone();

	//test algorithm 1
	time=System.currentTimeMillis();
	int med=algorithmOne(stuffCopy,stuffCopy.length/2);
	time=System.currentTimeMillis()-time;
	
	System.out.println("Median found using using quickselect: "+med+"\n in "+time+"ms");
	

	//test algorithm 2
	stuffCopy=stuff.clone();
	
	time=System.currentTimeMillis();
	med=algorithmTwo(stuffCopy,stuffCopy.length/2);
	time=System.currentTimeMillis()-time;
	
	System.out.println("Median found using using deterministic select: "+med+"\nin "+time+"ms");
	
	
	//test algorithm 3

	stuffCopy=stuff.clone();
	
	time=System.currentTimeMillis();
	algorithmThree(stuffCopy);
	time=System.currentTimeMillis()-time;
	
	System.out.println("Median found using using quicksort: "+stuffCopy[stuffCopy.length/2]+"\n in "+time+"ms");
	
    }


    private static int select(int[]list, int l, int r, int dex){
	Random rand=new Random();
	//basecase
	if(r<=l){
	    return list[r-(l-r)/2];
	}
	//random pivot
	int pivot=rand.nextInt(r-l)+l;

	//move pivot to beginning of list
	int tmp=list[l];
	list[l]=list[pivot];
	list[pivot]=tmp;

	//partition
	int i=l;
	for(int z=l+1;z<r+1;z++){
	    if(list[z]<list[l]){
		i+=1;
		tmp=list[i];
		list[i]=list[z];
		list[z]=tmp;
	    }
	}

	//move pivot to correct location
	tmp=list[i];
	list[i]=list[l];
	list[l]=tmp;

	//partition recursively, one side only
	if(dex==i){
	    return list[i];
	}else if(dex<i){
	    return select(list,l,i-1,dex);
	}else{
	    return select(list,i+1,r,dex);
	}
    }

    private static int algorithmOne(int[]items, int dex){//randomized selection, a.k.a. quickselect
	if(items.length<1){
	    return -1;
	}
	return select(items, 0, items.length-1,dex);
    }

    private static int algorithmTwo(int[]items,int k){
	if(items.length<=10){
	    Arrays.sort(items);
	    return items[k];
	}
	int[]medians=new int[items.length/5];
	for(int z=0;z<items.length/5-2;z++){
	    //if((items.length/5)-z<10)
		//System.out.println("start index: "+z*5+" end index: "+(z+1)*5);
	    medians[z]=select(items,z*5,(z+1)*5,3);
	}
	int M=algorithmOne(medians,medians.length-1/2);
	
	//partition around M
	
        ArrayList<Integer>L1=new ArrayList<Integer>();
        ArrayList<Integer>L2=new ArrayList<Integer>();
        ArrayList<Integer>L3=new ArrayList<Integer>();

	for(int item : items){
	    if(item<M){
		L1.add(item);
	    }else if(item>M){
		L3.add(item);
	    }else{
		L2.add(item);
	    }
	}
	
	int[]Lone = toIntArr(L1);
	    int[]Ltwo = toIntArr(L2);
	    int[]Lthree = toIntArr(L3);

	if(k<=Lone.length){
	    return algorithmOne(Lone,k);
	}else if(k>Lone.length+Ltwo.length){
	    return algorithmOne(Lthree,k-Lone.length-Ltwo.length);
	}else return M;
    }
    private static void sort(int[]list, int l, int r){
	Random rand=new Random();
	//basecase
        if(r<=l){
	    return;
	}
        //choose random pivot
        int pivot = rand.nextInt(r-l)+l;

	int tmp=list[l];
	list[l]=list[pivot];
	list[pivot]=tmp;

	//partition
	int i=l;
	for(int z=l+1;z<r+1;z++){
	    if(list[z]<list[l]){
		i+=1;
		tmp=list[i];
		list[i]=list[z];
		list[z]=tmp;
	    }
	}

        //place pivot in proper position
	tmp=list[i];
	list[i]=list[l];
	list[l]=tmp;

        //sort left and right partitions
        sort(list, l, i-1);
        sort(list, i+1, r);

    }

    private static void algorithmThree(int[]items){
	sort(items, 0, items.length-1);
    }
}
