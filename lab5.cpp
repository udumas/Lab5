#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


const int MAX=100;
const int ELEMENTS=3;
const int YEAR=0;
const int COURSE=1;
const int STUDENTS=2;

/**
 * Program takes a series of values of the form
 * YEAR COURSE NUMBEROFSTUDENTS
 * and saves these values into three arrays 
 * YEAR[] COURSE[] AND STUDENTS[]
 *
 * 
 *  
 */


/**
 * function: getData()
 * takes a series of values of the form
 * YEAR COURSE NUMBEROFSTUDENTS
 * and saves these values into three arrays 
 * YEAR[] COURSE[] AND STUDENTS[]
 * if the first value of a string of values is  
 * program stops inputing data.
 *  PRECONDITION: expects to find a file formatted as
 *  YEAR   COURSENAME   NUMBER_OF_STUDENTS
 */
void getData(int list[][ELEMENTS], string courses[], int& size, int& coursesSize);

/**
 * function: graph()
 *
 * 
 *	 Precondition: list[] contains integers representing YEAR COURSENUMBER and NUMBER_OF_STUDENTS
 *					courses[] contains exactly one copy of each course name. 
 *					size and course size are the number of elements in each array respectively
 *
 *	 PostCondition: returns String representing graph of data for classes.
 */
string graph(const int list[][ELEMENTS], const string courses[], int& size, int& coursesSize);



/**
 * function: rangeOfYears()
 *  determines minimumYear and maximumYear
 * precondition: list containing year, courseid and numberOfStudents
 * postCondition: String "Statistics for the years" minYear "-" maxYear
 */
string rangeOfYears(const int list[][ELEMENTS], int& size);

/**
 * Function totalPerCourse
 *	PRECONDITION: list[] contains year, course number and number of students for a list of classes
 *				  course[] contains a list of courses offered with no duplicate values
 * 	
 *  PostCondition returns a string containing representing the range of years
 */
string totalPerCourse(int list[][ELEMENTS], string courses[], int& size, int& courseSize);
/**
 *  function: minNumberOfStudents(String course[], int list[], int& courseSize, int& listSize)
 * 	loop through the student[] 
 *			IF student[i]<minStudents
 *			THEN minstudents==student[i]
 * PRECONDITION: requires a list Array with YEAR, COURSE NUMBER, NUMBER OF STUDENTS
 * POSTCONDITION: returns a string stating which course had the lowest student enrollment over the 
 *  range of years.
 *	
 */
string minNumberOfStudents(string courses[], int list[][ELEMENTS], int& courseSize, int& listSize);

 /*
  * function: maxPerYears(list[], &size)
  * PRECONDITION: 2d array containing [1] Year [2] integer representing course and [3] NumberofStudents and 1d array containing
  * course names.
  * functions maxYear() and minYear()
  *	POSTCONDITION: returns a string stating which course had the maximum number of students for each year  
  */	
string maxPerYears(int list[][ELEMENTS], string course[], int& size, int& courseSize);

/**
 *Function createInt
 * searches through the courses[] to see if the course name input exists. 
 * if the course name exists in the array it returns the index of the location of the course name
 * if the course name doues not yet exist it stores the course name into the array at the next 
 * empty location, and returns theb index of the location
 *
 * PRECONDITION: requires a course[] containing a list of course names.
 * POSTCONDITION: returns an integer describing where to find the course name.
 *
 **/
int createInt(string course, string courses[], int& size);


/**
 * set all values of array to zero
 */
void initialize(int list[][ELEMENTS]);

/**
 * set all values of array to zero
 */
void initial(string courses[]);

/**
 *  int MIN=0
 *  int MAX=list[0][ELEMENTS]
 *   
 *  FOREACH i in LIST[][ELEMENTS]
 *    IF:
 *      LIST[i][YEAR]>MAX
 *    THEN:
 *      MAX = LIST[i][YEAR]
 *    ENDIF
 *    IF:
 *      LIST[i][ELEMENTS]< MIN
 *    THEN:
 *      MIN=list[i][ELEMENTS]
 *
 *  PRECONDITION: LIST[][COURSE]
 *  POSTCONDITION: smallest value in LIST[][COURSE] 
 */
 int minYear(const int list[][ELEMENTS], int& size);

/**
 *  int MAX=list[0][ELEMENTS]
 *   
 *  FOREACH i in LIST[][ELEMENTS]
 *    IF:
 *      LIST[i][YEAR]>MAX
 *    THEN:
 *      MAX = LIST[i][YEAR]
 *    ENDIF
 *  PRECONDITION: LIST[][COURSE]
 *  POSTCONDITION: LARGEST value in LIST[][COURSE] 
 */
  int maxYear(const int list[][ELEMENTS], int& size);

int main(){

    ifstream fin;
    ofstream fout;
 	  int list[MAX][3];
    int size=0;
    string courses[MAX];
    int courseSize=0;
    
    
    initial(courses);
    initialize(list);
  
    getData(list,courses,size, courseSize);

    

    fout.open("output.txt");
   
    fout << graph(list, courses, size, courseSize);
    fout << rangeOfYears(list, size);
    fout << totalPerCourse(list, courses, size, courseSize);
    fout << minNumberOfStudents(courses, list, courseSize, size);
    fout << maxPerYears(list, courses, size, courseSize);

    fout.close();
    fin.close();

 }




/*
 * sets all values in a single dimensional array to zero
 */

void initial(string courses[]){
  for(int i=0;i<MAX;i++){
      courses[i]="0";
  }
}



/**
 *sets all values of 2d array to zero
 */
void initialize(int list[][ELEMENTS]){
  for(int i=0;i<MAX;i++){
    for(int j=0;j<=ELEMENTS;j++){
      list[i][j]=-1;
    }
  }
}


/**
 * function: getData()
 * takes a series of values of the form
 * YEAR COURSE NUMBEROFSTUDENTS
 * and saves these values into three arrays 
 * YEAR[] COURSE[] AND STUDENTS[]
 * if the first value of a string of values is  
 * program stops inputing data.
 *  PRECONDITION: expects to find a file formatted as
 *  YEAR   COURSENAME   NUMBER_OF_STUDENTS
 */
 	 	void getData(int list[][ELEMENTS], string courses[], int& size, int& coursesSize){

    ifstream fin;
    int year=0;
    int students = 0;
    int stop=-1;
    string course;
    char years[100];
		// fout << "Enter the year (four digit for eg. 2002,\n";
		// fout << "Course Identifier (formatted as \"Dept\"\"number\" eg. CSC101\n";
		// fout << "and number of Students on one line.\n";

    fin.open("input.txt");

    
		fin >> year >> course >> students;
  
    while(!fin.eof()){

  		  list[size][YEAR]=year;

		    list[size][COURSE]=createInt(course, courses, coursesSize);
        list[size][STUDENTS]=students;
        size++;
        
        fin >> year >> course >> students;


      }
      fin.close();

		}
		

/**
 * function: graph()
 *
 * 
 *   Precondition: list[] contains integers representing YEAR COURSENUMBER and NUMBER_OF_STUDENTS
 *          courses[] contains exactly one copy of each course name. 
 *          size and course size are the number of elements in each array respectively
 *
 *   PostCondition: returns String representing graph of data for classes.
 */
string graph(const int list[][ELEMENTS], const string courses[], int& size, int& courseSize){
    using std::stringstream;

    stringstream ss;
    string returnString = " ";
    ss.str("");


    ss <<    "\n";
    for(int i=0; i<courseSize;i++){
      ss << courses[i] << " ";
//      ss << courses[i];
      ss << "\n" << "      |\n";
      ss << "\n" << "      |\n";
       for(int l=minYear(list, size);l<=maxYear(list,size);l++){ 
        
        for(int j=0;j<=size;j++){
          if((list[j][COURSE]==i)&&(list[j][YEAR]==l)){
            ss <<    "  " << list[j][YEAR] << "|";
            for(int k=1;k<list[j][STUDENTS];k++){
              ss <<    "*";
            }
            ss <<    "\n";
          }
        }
      }

      ss <<    "      |";
      for (int j = 0; j < 50; ++j){
        if(j%5==0)
          ss <<    j;
        else
          ss <<    "*";
      }
      ss <<    "\n" << "\n" <<  "\n";
      returnString=ss.str();

    }
    return returnString;
  }



/**
 * function: rangeOfYears()
 *  determines minimumYear and maximumYear
 * precondition: list containing year, courseid and numberOfStudents
 * postCondition: String "Statistics for the years" minYear "-" maxYear
 */
string rangeOfYears(const int list[][ELEMENTS], int& size){
//  int minimumYear=minYear(list, size);
//  int maximumYear=maxYear(list, size);

using std::stringstream;
  stringstream ss;
  string returnString = " ";
  ss.str("");
  
  

  ss <<    "Statistics for the years " <<  minYear(list, size) << "-" <<  maxYear(list, size) << "\n";
  returnString = ss.str();
  return returnString;
}

/**
 * Function totalPerCourse
 *  PRECONDITION: list[] contains year, course number and number of students for a list of classes
 *          course[] contains a list of courses offered with no duplicate values
 *  
 *  PostCondition returns a string containing representing the range of years
 */
 string totalPerCourse(int list[][ELEMENTS], string courses[], int& size, int& courseSize){
    using std::stringstream;

    stringstream ss;
    string returnString = " ";
    ss.str("");


    ss << "\n";
    
    
    ss << "* The Number of Students per Course:\n";
    int total[1000];
    int thisTotal = 0;
    for(int i=0;i<courseSize;i++){
      thisTotal=0;
      for(int j=0;j<size;j++){
        if(i==list[j][COURSE]){
          thisTotal=thisTotal+list[j][STUDENTS];
        }
      }
      total[i]=thisTotal;
      ss << "                   " << courses[i] << " had " << total[i] << "\n";
    }
  returnString = ss.str();
  return returnString;
 }

/**
 *  function: minNumberOfStudents(String course[], int list[], int& courseSize, int& listSize)
 *  loop through the student[] 
 *      IF student[i]<minStudents
 *      THEN minstudents==student[i]
 * PRECONDITION: requires a list Array with YEAR, COURSE NUMBER, NUMBER OF STUDENTS
 * POSTCONDITION: returns a string stating which course had the lowest student enrollment over the 
 *  range of years.
 *  
 */
string minNumberOfStudents(string course[], int list[][ELEMENTS], int& courseSize, int& size){
  using std::stringstream;
  stringstream ss;
  string returnString = " ";
  ss.str("");
  ss << "\n";
  
  int minStudents=1000;
  int location = -1;
  ofstream fout;
  fout.open("output.txt", ios::app);
  

  for(int i=0;i<size;i++){
    if(list[i][STUDENTS]<minStudents){
      minStudents=list[i][STUDENTS];
      location=i;
    }
  }
  ss << "* The Course with the MINIMUM numer of students was in " << list[location][YEAR] << " " 
       << course[list[location][COURSE]] << " with " << list[location][STUDENTS] << " students.\n"; 

  returnString = ss.str();
  return returnString;
}

/*
  * function: maxPerYears(list[], &size)
  * PRECONDITION: 2d array containing [1] Year [2] integer representing course and [3] NumberofStudents and 1d array containing
  * course names.
  * functions maxYear() and minYear()
  * POSTCONDITION: returns a string stating which course had the maximum number of students for each year  
  */
string maxPerYears(int list[][ELEMENTS], string course[], int& size, int& courseSize){
using std::stringstream;
stringstream ss;
string returnString = " ";
ss.str("");
ss << "\n";
  int max=maxYear(list, size);
  int min=minYear(list, size);
  int largest=0;
  ofstream fout;

  ss << "* The Courses that had the MAXIMUM number of students per year\n";
  for(int i=min;i<=max;i++){
    largest=-1;
    for(int j=0;j<size;j++){

      if(list[j][YEAR]==i){
        if(list[j][STUDENTS]>list[largest][STUDENTS]){
            largest=j;
            
        }
      }
    }
    
    ss << "                    in " << i << " the maximum number of students is in " << course[list[largest][COURSE]] << " with " 
         << list[largest][STUDENTS] << " students. \n";
  }
  returnString = ss.str();
  return returnString;
}

/**
 *Function createInt
 * searches through the courses[] to see if the course name input exists. 
 * if the course name exists in the array it returns the index of the location of the course name
 * if the course name doues not yet exist it stores the course name into the array at the next 
 * empty location, and returns theb index of the location
 *
 * PRECONDITION: requires a course[] containing a list of course names.
 * POSTCONDITION: returns an integer describing where to find the course name.
 *
 **/
int createInt(string course, string courses[], int& courseSize){
  int found = -1;

    for(int i =0; i<=courseSize;i++){
     if(course==courses[i]){
        found=i;
    }
    
     
    }
    if(found==-1){
     courses[courseSize]=course;
     found=courseSize++;
  }
  
  return found;
}


/**
 *  function minYear
 *  PRECONDITION: LIST[][COURSE]
 *  POSTCONDITION: smallest value in LIST[][COURSE] 
 */
 int minYear(const int list[][ELEMENTS], int& size){
    int min=list[0][YEAR];
    for(int i=0;i<size;i++){
      if(list[i][YEAR]<min){
        min=list[i][YEAR];
      }
    }
    return min;
 }

/**
 *  Function maxYear
 *  PRECONDITION: LIST[][COURSE]
 *  POSTCONDITION: LARGEST value in LIST[][COURSE] 
 */
  int maxYear(const int list[][ELEMENTS], int& size){
    ofstream fout;
    fout.open("output.txt", ios::app);
    
    int max = 0;
    for(int i=0;i<size;i++){
      if(list[i][YEAR]>max){
        max=list[i][YEAR];
		fout << list[i][YEAR] << "\n";
      }
      }
    fout.close();
      return max;
    }
  

