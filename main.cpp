using std::cout;
using std::string;

int SayHello(){
	cout << "Hello!\n";
	return 0;
}

int ClickWithLeft(int msg){
	cout << "left click!"<<msg<<"\n";
	return 0;
}

int ClickWithRigth(int msg){
	cout << "rigth click!"<<msg<<"\n";
	return 0;
}

int JustAKey(string value,int msg){
	if(value == "down"){
		cout << "just a down key!"<<msg<<"\n";
	}

	if(value == "up"){
		cout << "just an up key!"<<msg<<"\n";
	}
	
	return 0;
}