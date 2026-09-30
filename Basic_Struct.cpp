/*Title: Basic Struct
* 
* Purpose: To build and understand how Structured programs and written out.
*		   The program stores related student information inside a student
*		   struct and access the individual members.
* 
* Author: Nik Haas
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Student
{
	char name[30];
	int age;
	float GPA;
	float height;
	char college[50];
	char degree[50];
};

int main(void)
{
	struct Student student1;
	struct Student* ptr = &student1;

	strcpy_s(student1.name, sizeof(student1.name), "Dick");
	student1.age = 21;
	student1.GPA = 2.9;
	student1.height = 5.9;
	strcpy_s(student1.college, sizeof(student1.college), "University of Nothing");
	strcpy_s(student1.degree, sizeof(student1.degree), "Bachelor of Science");

	printf("Students information is the following: \n\n");
	
	printf("Name: %s\n", student1.name);
	printf("Age: %d\n", student1.age);
	printf("GPA: %.1lf\n", student1.GPA);
	printf("Height: %.1lf\n", student1.height);
	printf("College: %s\n", student1.college);
	printf("Degree: %s\n\n", student1.degree);
}