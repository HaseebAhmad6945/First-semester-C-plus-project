# 🎓 Course Management System

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)](https://www.microsoft.com/windows)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

A comprehensive C++ console application designed to streamline course administration and student enrollment processes. This system features a **dual-access architecture** with separate Admin and Agent interfaces, providing role-based functionality for educational institutions.

---

## 🌟 Key Features

### 👨‍💼 Admin Capabilities
- ➕ **Add Courses** - Create new courses with capacity limits
- ✏️ **Update Courses** - Modify existing course details
- 🗑️ **Delete Courses** - Remove courses from the system
- 👨‍🏫 **Assign Instructors** - Manage course instructors
- 📊 **View Course Listings** - Comprehensive course overview
- 👥 **Monitor Enrollments** - Track student registrations
- ❌ **Remove Students** - Manage student withdrawals

### 👨‍💻 Agent Capabilities
- 📝 **Enroll Students** - Register students in available courses
- 🔍 **Search Courses** - Find courses by keywords
- 📈 **View Availability** - Check course capacity and enrollment status
- 👤 **Update Student Info** - Modify student details
- 📋 **View Enrollments** - Access student enrollment lists
- ❌ **Remove Students** - Process student removals

---

## 🛠️ Technical Highlights

### 🏗️ **Custom Implementation**
- **No Advanced Libraries**: Built using only basic C++ libraries
- **Custom String Functions**: Hand-implemented `strlen`, `strcpy`, `strcmp`, and `strstr`
- **Array-Based Architecture**: Efficient memory management without vectors or STL containers

### 💾 **Data Management**
- **File-Based Persistence**: Robust text file storage system
- **Dual File Structure**: Separate files for courses (`courses.txt`) and students (`students.txt`)
- **Data Integrity**: Automatic file handling with error checking

### 🔐 **Security & Access Control**
- **Role-Based Authentication**: Secure login for Admin and Agent roles
- **Credential Management**: 
  - **Admin**: Username: `haseeb` | Password: `haseebahmad`
  - **Agent**: Username: `agent` | Password: `123`

### 🎨 **User Interface**
- **Colorized Console**: Windows console colors for enhanced UX
- **Intuitive Menus**: Clear navigation and option selection
- **Error Handling**: Comprehensive input validation and error messages

---

## 📊 System Specifications

| Feature | Specification |
|---------|--------------|
| **Maximum Courses** | 50 |
| **Maximum Students** | 200 |
| **Data Storage** | Text Files (.txt) |
| **Platform** | Windows (Console Colors) |
| **Memory Usage** | Static Arrays |
| **File Dependencies** | courses.txt, students.txt |

---

## 🚀 Getting Started

### Prerequisites
- C++ Compiler (GCC, MSVC, or equivalent)
- Windows OS (for console color support)
- Basic C++ runtime environment

### Installation & Compilation

1. **Clone or Download** the source code
```bash
# Save the code as course_management.cpp
```

2. **Compile the Program**
```bash
g++ -o course_management course_management.cpp
# or
cl course_management.cpp
```

3. **Run the Application**
```bash
./course_management
# or
course_management.exe
```

---

## 💻 Usage Guide

### First Time Setup
1. Launch the application
2. Choose user type (Admin/Agent)
3. Enter credentials
4. Navigate through the menu options

### Admin Workflow
```
Login → Admin Menu → Select Operation → Perform Task → Save Data
```

### Agent Workflow
```
Login → Agent Menu → Select Operation → Manage Students → Update Records
```

---

## 🏗️ System Architecture

### Data Structures
```cpp
// Course Management
int courseIds[MAX_COURSES];
char courseTitles[MAX_COURSES][50];
char courseInstructors[MAX_COURSES][50];
int courseCapacities[MAX_COURSES];
int courseEnrolled[MAX_COURSES];

// Student Management
int studentIds[MAX_STUDENTS];
char studentNames[MAX_STUDENTS][50];
int studentCourseIds[MAX_STUDENTS];
```

### File Format
**courses.txt**
```
CourseID
Course Title
Instructor Name
Capacity EnrolledCount
```

**students.txt**
```
StudentID
Student Name
CourseID
```

---

## 🎯 Perfect For

- 🏫 **Educational Institutions** seeking lightweight course management
- 👨‍🎓 **Computer Science Students** learning file handling and data structures
- 🏢 **Small Training Centers** requiring basic enrollment tracking
- 📚 **Academic Projects** demonstrating console application development

---

## 🔧 Key Benefits

✅ **Lightweight**: No database dependencies  
✅ **Portable**: Single executable file  
✅ **Educational**: Perfect for learning C++ fundamentals  
✅ **Customizable**: Easy to modify and extend  
✅ **Efficient**: Fast performance with minimal resource usage  

---

## 📝 Future Enhancements

- [ ] Cross-platform color support
- [ ] Database integration
- [ ] GUI interface
- [ ] Report generation
- [ ] Backup and restore functionality
- [ ] Multi-course enrollment per student

---

## 🤝 Contributing

Contributions are welcome! Please feel free to submit issues, feature requests, or pull requests to improve the system.

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Developer

**Haseeb Ahmad**  
*First Semester C++ Project*

---

<div align="center">

**⭐ Star this repository if you find it helpful!**

</div>