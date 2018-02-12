#include<iostream>
#include<math.h>
class Vec
{
public:
	Vec(double X,double Y):x(X),y(Y){}
	double x,y;
	
	//basic
	Vec operator+(Vec c);
	Vec operator-(Vec c);
	Vec operator+(double c);//在向量方向上增加c单位长度即|V|=|V|+c; 
	Vec operator-(double c);//在向量方向上减少c单位长度即|V|=|V|-c; 
	double operator^(Vec c);//叉乘膜 
	Vec operator*(double c);
	Vec operator/(double c);
	double operator*(Vec c);//点乘 
	double mo();//取膜 
	void setLength(double c);
	
	double operator|(Vec c);//射影
	
	//Debug
	void print(){std::cout<<x<<" "<<y<<" "<<mo()<<std::endl;}
};
Vec Vec::operator+(Vec c)
{
	return Vec(x+c.x,y+c.y);
}
Vec Vec::operator-(Vec c)
{
	return Vec(x-c.x,y-c.y);
}
Vec Vec::operator+(double c)
{
	double m=mo();
	return Vec(x+c/m*x,y+c/m*y);
}
Vec Vec::operator-(double c)
{
	double m=mo();
	return Vec(x-c/m*x,y-c/m*y);
}
double Vec::operator^(Vec c)
{
	return x*c.y-c.x*y;
}
Vec Vec::operator*(double c)
{
	return Vec(x*c,y*c);
}
Vec Vec::operator/(double c)
{
	return Vec(x/c,y/c);
}
double Vec::operator*(Vec c)
{
	return c.x*x+c.y*y;
}
double Vec::mo()
{
	return hypot(x,y);
}
void Vec::setLength(double c)
{
	double m=mo();
	x=c/m*x;
	y=c/m*y;
}


double Vec::operator|(Vec c)
{
	return (c.x*x+c.y*y)/c.mo();
}
int main()
{
	Vec i(100,100);
	i.setLength(320);
	std::cout<<""<<std::endl;
	i.print();
	return 0;
}
