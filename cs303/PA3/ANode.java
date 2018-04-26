public class ANode{
    int dex;
    double weight;

    public ANode(int dex,double weight){
	this.dex=dex;
	this.weight=weight;
    }

    public int getDex(){
	return dex;
    }

    public double getWeight(){
	return weight;
    }

    public void setDex(int dex){
	this.dex=dex;
    }

    public void setWeight(double weight){
	this.weight=weight;
    }

    public String toString(){
	return "{ "+dex+", "+weight+" }";
    }
}
