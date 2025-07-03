#include<iostream>
#include<fstream>
#include<windows.h>  // For Windows console colors
using namespace std;

const int MAX_COURSES = 50;
const int MAX_STUDENTS = 200;

// Course data arrays
int courseIds[MAX_COURSES];
char courseTitles[MAX_COURSES][50];
char courseInstructors[MAX_COURSES][50];
int courseCapacities[MAX_COURSES];
int courseEnrolled[MAX_COURSES];

// Student data arrays
int studentIds[MAX_STUDENTS];
char studentNames[MAX_STUDENTS][50];
int studentCourseIds[MAX_STUDENTS];

int courseCount = 0;
int studentCount = 0;
// Color constants
#define RED 12
#define GREEN 10
#define BLUE 9
#define YELLOW 14
#define CYAN 11
#define MAGENTA 13
#define WHITE 15
// Function declarations
bool authenticate(int userType);
void loadCourses();
void saveCourses();
void loadStudents();
void saveStudents();
void addCourse();
void updateCourse();
void deleteCourse();
void viewCourses();
void assignInstructor();
void viewStudentsEnrolled();
void removeStudent();
void enrollStudent();
void agentViewAvailableCourses();
void searchCourse();
void agentViewStudentsEnrolled();
void agentRemoveStudent();
void updateStudentInfo();
void courseAvailability();
void adminMenu();
void agentMenu();
void clearFiles();

// Color function to set console text color
void setColor(int color) 
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, color);
}
int main() 
{
loadCourses();
loadStudents();
int userType;
    
setColor(CYAN);
cout<< "\n";
cout<< "**************************************************\n";
cout<< "*                                                *\n";
cout<< "*        WELCOME TO COURSE MANAGEMENT            *\n";
cout<< "*                   SYSTEM                       *\n";
cout<< "*                                                *\n";
cout<< "*     ****   ****   *   *  ****   ****  *****    *\n";
cout<< "*    *      *    *  *   *  *   *  *     *        *\n";
cout<< "*    *      *    *  *   *  ****   ****  ****     *\n";
cout<< "*    *      *    *  *   *  *  *       * *        *\n";
cout<< "*     ****   ****    ***   *   *  ****  *****    *\n";
cout<< "*                                                *\n";
cout<< "*     ***    ***    ****   *   *    ****         *\n";
cout<< "*     ** ** ** **  **  **  ** **   **  **        *\n";
cout<< "*     **  ***  **  **  **  * * *   **  **        *\n";
cout<< "*     **       **   ****   **  **   ****         *\n";
cout<< "*                                                *\n";
cout<< "**************************************************\n";
setColor(WHITE);
cout<< "\n";
cout<< "Please select your choice:\n";
setColor(YELLOW);
cout<< "1. Admin Menu\n";
cout<< "2. Agent Menu\n";
setColor(WHITE);
cout<< "Enter your choice: ";
cin>> userType;
    
if (userType == 1) 
{
if (authenticate(1)) 
{
adminMenu();
}
} else if (userType == 2) 
{
if (authenticate(2)) 
{
agentMenu();
}
} else {
setColor(RED);
cout<< "Invalid choice!\n";
setColor(WHITE);
}
    
return 0;
}
// Custom string functions to replace built-in functions
int customStrlen(const char* str) 
{
int len = 0;
while (str[len] != '\0') 
{
len++;
}
return len;
}

void customStrcpy(char* dest, const char* src) 
{
int i = 0;
while (src[i] != '\0') 
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
}

int customStrcmp(const char* str1, const char* str2) 
{
int i = 0;
while (str1[i] != '\0' && str2[i] != '\0') 
{
if (str1[i] != str2[i]) 
{
return str1[i] - str2[i];
}
i++;
}
return str1[i] - str2[i];
}

char* customStrstr(const char* haystack, const char* needle) 
{
if (*needle == '\0') 
{
return (char*)haystack;
}
    
for (int i = 0; haystack[i] != '\0'; i++) 
{
int j = 0;
while (haystack[i + j] == needle[j] && needle[j] != '\0') 
{
j++;
}
if (needle[j] == '\0') 
{
return (char*)&haystack[i];
}
}
return nullptr;
}


// Authentication function
bool authenticate(int userType) 
{
char username[50], password[50];
    
setColor(CYAN);
cout<< "\n--- Login Required ---\n";
setColor(WHITE);
cout<< "Username: ";
cin>> username;
cout<< "Password: ";
cin>> password;
    
if (userType == 1) 
{ // Admin
if (customStrcmp(username, "haseeb") == 0 && customStrcmp(password, "haseebahmad") == 0) 
{
setColor(GREEN);
cout<< "Admin login successful!\n";
setColor(WHITE);
return true;
}
} else if (userType == 2) 
{ // Agent
if (customStrcmp(username, "agent") == 0 && customStrcmp(password, "123") == 0) 
{
setColor(GREEN);
cout<< "Agent login successful!\n";
setColor(WHITE);
return true;
}
}
    
setColor(RED);
cout<< "Invalid username or password!\n";
setColor(WHITE);
return false;
}

// Clear files function
void clearFiles() 
{
ofstream file;
file.open("courses.txt", ios::trunc);
file.close();
file.open("students.txt", ios::trunc);
file.close();
}

// Utility Functions for File Handling (text files)
void loadCourses() 
{
ifstream file;
file.open("courses.txt");
if (!file.is_open()) 
{
return; // File doesn't exist yet
}
    
courseCount = 0;
while (file >> courseIds[courseCount]) 
{
file.ignore();
file.getline(courseTitles[courseCount], 50);
file.getline(courseInstructors[courseCount], 50);
file >> courseCapacities[courseCount] >> courseEnrolled[courseCount];
file.ignore();
courseCount++;
if (courseCount >= MAX_COURSES) break;
}
file.close();
}

void saveCourses() 
{
clearFiles(); // Clear file first
ofstream file;
file.open("courses.txt");
for (int i = 0; i < courseCount; i++) 
{
file<< courseIds[i] << endl;
file<< courseTitles[i] << endl;
file<< courseInstructors[i] << endl;
file<< courseCapacities[i] << " " << courseEnrolled[i] << endl;
}
file.close();
}

void loadStudents() 
{
ifstream file;
file.open("students.txt");
if (!file.is_open()) 
{
return; // File doesn't exist yet
}
    
studentCount = 0;
while (file >> studentIds[studentCount]) 
{
file.ignore();
file.getline(studentNames[studentCount], 50);
file >> studentCourseIds[studentCount];
file.ignore();
studentCount++;
if (studentCount >= MAX_STUDENTS) break;
}
    file.close();
}

void saveStudents() 
{
ofstream file;
file.open("students.txt");
for (int i = 0; i < studentCount; i++) 
{
file<< studentIds[i] << endl;
file<< studentNames[i] << endl;
file<< studentCourseIds[i] << endl;
}
file.close();
}

// Admin Functions
void addCourse() 
{
if (courseCount >= MAX_COURSES) 
{
setColor(RED);
cout<< "Course limit reached!\n";
setColor(WHITE);
return;
}
    
cout<< "Enter Course ID: ";
cin>> courseIds[courseCount];
cin.ignore();
cout<< "Enter Course Title: ";
cin.getline(courseTitles[courseCount], 50);
cout<< "Enter Instructor Name: ";
cin.getline(courseInstructors[courseCount], 50);
cout<< "Enter Course Capacity: ";
cin>> courseCapacities[courseCount];
courseEnrolled[courseCount] = 0;
    
courseCount++;
saveCourses();
setColor(GREEN);
cout<< "Course added successfully!\n";
setColor(WHITE);
}

void updateCourse() 
{
int id;
cout<< "Enter Course ID to update: ";
cin>> id;
for (int i = 0; i < courseCount; i++) {
if (courseIds[i] == id) 
{
cout<< "Enter new title: ";
cin.ignore();
cin.getline(courseTitles[i], 50);
cout<< "Enter new instructor: ";
cin.getline(courseInstructors[i], 50);
cout<< "Enter new capacity: ";
cin>> courseCapacities[i];
saveCourses();
setColor(GREEN);
cout<< "Course updated successfully!\n";
setColor(WHITE);
return;
}
}
setColor(RED);
cout<< "Course not found.\n";
setColor(WHITE);
}

void deleteCourse() 
{
int id;
cout<< "Enter Course ID to delete: ";
cin>> id;
for (int i = 0; i < courseCount; i++) 
{
if (courseIds[i] == id) 
{
// Shift all elements left to fill the gap
for (int j = i; j < courseCount - 1; j++) 
{
courseIds[j] = courseIds[j + 1];
customStrcpy(courseTitles[j], courseTitles[j + 1]);
customStrcpy(courseInstructors[j], courseInstructors[j + 1]);
courseCapacities[j] = courseCapacities[j + 1];
courseEnrolled[j] = courseEnrolled[j + 1];
}
courseCount--;
saveCourses();
setColor(GREEN);
cout<< "Course deleted.\n";
setColor(WHITE);
return;
}
}
setColor(RED);
cout<< "Course not found.\n";
setColor(WHITE);
}

void viewCourses() 
{
setColor(CYAN);
cout<< "\nAvailable Courses:\n";
setColor(WHITE);
for (int i = 0; i < courseCount; i++) 
{
cout<< "ID: "<< courseIds[i]
<< ", Title: " << courseTitles[i]
<< ", Instructor: " << courseInstructors[i]
<< ", Capacity: " << courseCapacities[i]
<< ", Enrolled: " << courseEnrolled[i] << endl;
}
}

void assignInstructor() 
{
int id;
cout << "Enter Course ID to assign instructor: ";
cin >> id;
for (int i = 0; i < courseCount; i++) 
{
if (courseIds[i] == id) 
{
cout << "Enter new instructor name: ";
cin.ignore();
cin.getline(courseInstructors[i], 50);
saveCourses();
setColor(GREEN);
cout<< "Instructor assigned successfully!\n";
setColor(WHITE);
return;
}
}
setColor(RED);
cout<< "Course not found.\n";
setColor(WHITE);
}

void viewStudentsEnrolled() 
{
int id;
cout<< "Enter Course ID: ";
cin>> id;
setColor(CYAN);
cout<< "Students enrolled in Course ID " << id << ":\n";
setColor(WHITE);
for (int i = 0; i < studentCount; i++) 
{
if (studentCourseIds[i] == id) 
{
cout<< "ID: " << studentIds[i] << ", Name: " << studentNames[i] << endl;
}
}
}

void removeStudent() 
{
int sid;
cout<< "Enter Student ID to remove: ";
cin>> sid;
for (int i = 0; i < studentCount; i++) 
{
if (studentIds[i] == sid) 
{
// Decrease enrolled count in the course
for (int j = 0; j < courseCount; j++) 
{
if (courseIds[j] == studentCourseIds[i]) 
{
courseEnrolled[j]--;
break;
}
}
// Shift all student elements left to fill the gap
for (int j = i; j < studentCount - 1; j++) 
{
studentIds[j] = studentIds[j + 1];
customStrcpy(studentNames[j], studentNames[j + 1]);
studentCourseIds[j] = studentCourseIds[j + 1];
}
studentCount--;
saveStudents();
saveCourses();
setColor(GREEN);
cout<< "Student removed.\n";
setColor(WHITE);
return;
}
}
setColor(RED);
cout<< "Student not found.\n";
setColor(WHITE);
}

// Agent Functions
void enrollStudent() 
{
if (studentCount >= MAX_STUDENTS) 
{
setColor(RED);
cout<< "Student limit reached!\n";
setColor(WHITE);
return;
}
    
int sid, cid;
char name[50];
    
cout<< "Enter Student ID: ";
cin>> sid;
cin.ignore();
cout<< "Enter Student Name: ";
cin.getline(name, 50);
cout<< "Enter Course ID to enroll: ";
cin>> cid;
    
for (int i = 0; i < courseCount; i++) 
{
if (courseIds[i] == cid) 
{
if (courseEnrolled[i] < courseCapacities[i]) 
{
studentIds[studentCount] = sid;
customStrcpy(studentNames[studentCount], name);
studentCourseIds[studentCount] = cid;
studentCount++;
courseEnrolled[i]++;
saveStudents();
saveCourses();
setColor(GREEN);
cout<< "Student enrolled!\n";
setColor(WHITE);
return;
} else {
setColor(RED);
cout<< "Course is full!\n";
setColor(WHITE);
return;
}
}
}
setColor(RED);
cout<< "Course not found.\n";
setColor(WHITE);
}

void agentViewAvailableCourses() 
{
viewCourses();
}

void searchCourse() 
{
char keyword[50];
cout<< "Enter course keyword to search: ";
cin.ignore();
cin.getline(keyword, 50);
setColor(CYAN);
cout<< "Matching Courses:\n";
setColor(WHITE);
for (int i = 0; i < courseCount; i++) 
{
if (customStrstr(courseTitles[i], keyword)) 
{
cout<< "ID: " << courseIds[i] << ", Title: " << courseTitles[i] << endl;
}
}
}

void agentViewStudentsEnrolled() 
{
viewStudentsEnrolled();
}

void agentRemoveStudent()
{
removeStudent();
}

void updateStudentInfo() 
{
int sid;
cout<< "Enter Student ID to update: ";
cin>> sid;
for (int i = 0; i < studentCount; i++) 
{
if (studentIds[i] == sid) 
{
cout<< "Enter new name: ";
cin.ignore();
cin.getline(studentNames[i], 50);
saveStudents();
setColor(GREEN);
cout<< "Student info updated!\n";
setColor(WHITE);
return;
}
}
setColor(RED);
cout<< "Student not found.\n";
setColor(WHITE);
}

void courseAvailability() 
{
int id;
cout<< "Enter Course ID: ";
cin>> id;
for (int i = 0; i < courseCount; i++) 
{
if (courseIds[i] == id) 
{
cout<< "Course '" << courseTitles[i] << "' - ";
if (courseEnrolled[i] < courseCapacities[i]) 
{
setColor(GREEN);
cout<< "Available (" << courseCapacities[i] - courseEnrolled[i] << " seats left)\n";
setColor(WHITE);
} else {
setColor(RED);
cout<< "Full!\n";
setColor(WHITE);
}
return;
}
}
setColor(RED);
cout<< "Course not found.\n";
setColor(WHITE);
}

// Menus
void adminMenu() 
{
int choice;
do{
setColor(RED);
cout<< "\n--- Admin Menu ---\n";
setColor(YELLOW);
cout<< "1. Add Course\n2. Update Course\n3. Delete Course\n4. View Courses\n5. Assign Instructor\n";
cout<< "6. View Students Enrolled\n7. Remove Student\n8. Exit\n";
setColor(WHITE);
cout<< "Enter choice: ";
cin>> choice;
switch (choice) 
{
case 1: addCourse(); break;
case 2: updateCourse(); break;
case 3: deleteCourse(); break;
case 4: viewCourses(); break;
case 5: assignInstructor(); break;
case 6: viewStudentsEnrolled(); break;
case 7: removeStudent(); break;
case 8: return; // Return to main menu
default: 
setColor(RED);
cout<< "Invalid choice!\n";
setColor(WHITE);
}
} while (true);
}

void agentMenu() 
{
int choice;
do{
setColor(BLUE);
cout<< "\n--- Agent Menu ---\n";
setColor(MAGENTA);
cout<< "1. Enroll Student\n2. View Available Courses\n3. Search Course\n4. View Students Enrolled\n";
cout<< "5. Remove Student\n6. Update Student Info\n7. Course Availability\n8. Exit\n";
setColor(WHITE);
cout<< "Enter choice: ";
cin>> choice;
switch (choice) 
{
case 1: enrollStudent(); break;
case 2: agentViewAvailableCourses(); break;
case 3: searchCourse(); break;
case 4: agentViewStudentsEnrolled(); break;
case 5: agentRemoveStudent(); break;
case 6: updateStudentInfo(); break;
case 7: courseAvailability(); break;
case 8: return; // Return to main menu
default: 
setColor(RED);
cout<< "Invalid choice!\n";
setColor(WHITE);
}
} while (true);
}
