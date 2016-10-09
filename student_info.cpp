#include<iostream>

using namespace std;
int myAtoi(char *str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';
    return res;
}
char *mystrcpy(char *dst, const char *src)
{
    char *ptr;
    ptr = dst;
    while(*dst++=*src++);
    return(ptr);
}
class student{
private:
	char stu_name[100];
	int stu_age;
	char stu_id[100];
	int gpa[4];
	int average_gpa;
public:
	void setName(char *name){
		mystrcpy(stu_name,name);
	}
	void printName()
	{
		cout << stu_name;
	}
	void setAge(int age){
		stu_age = age;
	}
	void printAge(){
		cout << stu_age;
	}
	void setID(char *id){
		mystrcpy(stu_id, id);
	}
	void printID(){
		cout << stu_id;
	}
	void set_gpa(int gpa1,int gpa2,int gpa3,int gpa4){
		gpa[0] = gpa1;
		gpa[1] = gpa2;
		gpa[2] = gpa3;
		gpa[3] = gpa4;
	}
	void print_avg_gpa(student a){
		average_gpa = (a.gpa[0]+a.gpa[1]+a.gpa[2]+a.gpa[3])/4;
		cout << average_gpa;
	}

};

int main() {
    char name[100];
    char str_age[100];
    int age;
    char id[100];
    char str_g1[10];
    char str_g2[10];
    char str_g3[10];
    char str_g4[10];
    int g1,g2,g3,g4;

    cin.getline(name,100,',');
    cin.getline(str_age,100,',');
    age = myAtoi(str_age);
    cin.getline(id,100,',');
    cin.getline(str_g1,10,',');
    cin.getline(str_g2,10,',');
    cin.getline(str_g3,10,',');
    cin.getline(str_g4,10);
    g1 = myAtoi(str_g1);
    g2 = myAtoi(str_g2);
    g3 = myAtoi(str_g3);
    g4 = myAtoi(str_g4);

    student sample;
    sample.setName(name);
    sample.setID(id);
    sample.setAge(age);
    sample.set_gpa(g1,g2,g3,g4);

    sample.printName();
    cout << "," ;
    sample.printAge();
    cout << ",";
    sample.printID();
    cout << ",";
    sample.print_avg_gpa(sample);
    return 0;
}
