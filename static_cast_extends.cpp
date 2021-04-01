#include <iostream>

using namespace std;

class shape{
	private:
		int a;
	public:
		virtual void draw(){
			cout<<"shape: called draw()"<<endl;
		}
};

class triangle : public shape{
	private:
		int b = 30;
	public:
		void draw(){
			cout<<"triangle: called draw()"<<endl;
		}

		void onlyTriangle(){
			cout<<"triangle: onlyTriangle()"<<endl;
			cout<<"b: "<<b<<endl;
		}
};


int main(void){
	//upcast
	shape *ps;
	triangle t;

	cout<<"upcast"<<endl;
	ps = static_cast<shape *>(&t);
	ps -> draw();

	cout<<endl;

	shape s;
	triangle *pt;

	cout<<"down cast"<<endl;
	pt = static_cast<triangle *>(&s);
	pt -> draw();
	pt -> onlyTriangle();

	return 0;



}
