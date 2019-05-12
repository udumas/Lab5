#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


const int MAX=100;
const int ELEMENTS=3;
const int YEAR=0;
const int COURSE=1;
const int STUDENTS=2;


    ifstream fin;
    ofstream fout;


/**
 * Program takes a series of values of the form
 * YEAR COURSE NUMBEROFSTUDENTS
 * and saves these values into three arrays 
 * YEAR[] COURSE[] AND STUDENTS[]
 * if the first value of a string of values is -1 
 * program stops inputing data.
 *
 * once all data is input then
 * print Title of Course
 	print "        |" three times
 * for each value in the COURSE[] check the valuesGraphed[] 
 * if the value is in the valuesaGraphed[] do nothing
 * if value not in valuesGraphed[] 
 *     year=YEAR[i] "|" for "k= 1 to STUDENTS[i] print *"
 * for j=i to size j++ 
 * 		if COURSE[j]==COURSE[i]  
 *     year=YEAR[j] "|" for "k= 1 to STUDENTS[j] print *"
 * 
 *  
 */


/**
 * function: getData()
 * takes a series of values of the form
 * YEAR COURSE NUMBEROFSTUDENTS
 * and saves these values into three arrays 
 * YEAR[] COURSE[] AND STUDENTS[]
 * if the first value of a string of values is -1 
 * program stops inputing data.
 *
 */
void getData(int list[][ELEMENTS], string courses[], int& size, int& coursesSize);

/**
 * function: graph()
 *
 * 
 * FOREACH i in the courses[] 
 *		print Title of Course
 * 		print "        |\n" 2 times
 *  	FOREACH j in list[][]
 *			IF list[j][STUDENTS]==courses[j]
 *			year=list[j][COURSE] "|" 
 *			for "k= 1 to list[j][3] print *"
 *		print "        |\n"
 *		FOREACH j in 50
 *			IF (j%5==0)
 *				PRINT j
 *			ELSE 
 *				print "*"
 *	 Precondition: list[] contains integers representing year course and number of students
 *					courses[] contains exactly one copy of each course name. 
 *					size and course size are the number of elements in each array respectively
 *
 *	 PostCondition: void sends a graph of number of students in each course by year to the screen.
 */
void graph(const int list[][ELEMENTS], const string courses[], int& size, int& coursesSize);



/**
 * function: rangeOfYears()
 *  determines minimumYear and maximumYear
 * prints: "Statistics for the years " << minYear << "-" << maxYear
 * FOR EACH i in list[][COURSE]
 * if list[i][COURSE]<minYear
 *	minYear=list[i][COURSE]
 * if list[i][COURSE]>maxYear
 * 	maxYear=list[i][COURSE]
 * precondition: list containing year, courseid and numberOfStudents
 * postCondition: String "Statistics for the years" minYear "-" maxYear
 */
void rangeOfYears(const int list[][ELEMENTS], int& size);

/**
 * function: totalPerCourse()
 * INT[courseSize]  = total[]
 * FOREACH i in Courses[][STUDENTS]
 *		FOREACH j in list[]
 * 			IF list[j][STUDENTS]==i
 *			THEN total[i]+=list[j][3]
 *  
 * PRINT 
 * 		"Number of students per course\n"
 *		for each i in course[i][]
 *			"		" << course[i] << " has " << total[i] << " Students "
 *
 *	PRECONDITION: list[] contains year, course number and number of students for a list of classes
 *				  course[] contains a list of courses offered with no duplicate values
 * 	
 */
void totalPerCourse(int list[][ELEMENTS], string courses[], int& size, int& courseSize);
/**
 *  function: minNumberOfStudents(String course[], int list[], int& courseSize, int& listSize)
 * 	loop through the student[] 
 *			IF student[i]<minStudents
 *			THEN minstudents==student[i]
 * PRECONDITION: requires a list Array with YEAR, COURSE NUMBER, NUMBER OF STUDENTS
 * POSTCONDITION: returns the index of the course with the least students in the list[]
 *	
 */
void minNumberOfStudents(string courses[], int list[][ELEMENTS], int& courseSize, int& listSize);

 /*
  * function: maxPerYears(list[], &size)
  *	
  * create an array YEARS[50]
  * create integer LOCATION=-1
  *	create integer YEARSIZE=0
  *	FOREACH i in LIST[][COURSE] 
  *		FOREACH j in YEARS[]
  *			IF 
  *				LIST[i][COURSE]==YEARS[j][COURSE]
  *			THEN 				
  *				LOCATION=j
  *				IF 
  *					YEARS[j][STUDENTS] < LIST[i][3]
  *				THEN
  *					YEARS[j][STUDENTS] = LIST[i][3]
  *				ENDIF
  *			ENDIF
  *		END FOR
  *		IF 
  *			LOCATION = -1
  *		THEN
  *			
  *			YEARSIZE = YEARSIZE + 1
  *			
  */	
void maxPerYears(int list[][ELEMENTS], string course[], int& size, int& courseSize);

/**
 * Function createInt(String list[], &size )
 * i=-1
 * 
 * FOREACH i list[][COURSE]
 *
 * 	IF course=course[i][COURSE]
 *	
 * END FOR
 * IF i==-1
 * THEN 
 *  courseNumber=size+1
 * 	course[courseNumber][COURSE] = course;
 *
 **/
int createInt(string course, string courses[], int& size);


/**
 *
 */
void initialize(int list[][ELEMENTS]);

/**
 *
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



 	  int list[MAX][3];
    int size=0;
    string courses[MAX];
    int courseSize=0;




    
    fout.open("output.txt");
    
    initial(courses);
    initialize(list);
  
    getData(list,courses,size, courseSize);
    fout << "\n";
  

    
   
    graph(list, courses, size, courseSize);
    rangeOfYears(list, size);
    totalPerCourse(list, courses, size, courseSize);
    minNumberOfStudents(courses, list, courseSize, size);
    maxPerYears(list, courses, size, courseSize);

    fout.close();
    fin.close();

 }




/**
 *
 */
void initial(string courses[]){
  for(int i=0;i<MAX;i++){
      courses[i]="0";
  }
}



/**
 *
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
 * if the first value of a string of values is -1 
 * program stops inputing data.
 *
 */

 	 	void getData(int list[][ELEMENTS], string courses[], int& size, int& coursesSize){
		
    int year=0;
    int students = 0;
    int stop=-1;
    string course;
    ifstream fin;
		// fout << "Enter the year (four digit for eg. 2002,\n";
		// fout << "Course Identifier (formatted as \"Dept\"\"number\" eg. CSC101\n";
		// fout << "and number of Students on one line.\n";

    fin.open("input.txt");

    
		fin >> year >> course >> students;
  
    while(year!=stop){

  		  list[size][YEAR]=year;
		    list[size][COURSE]=createInt(course, courses, coursesSize);
        list[size][STUDENTS]=students;
        fout << list[size][YEAR] << " " << courses[list[size][COURSE]] << " " <<list[size][STUDENTS] << "\n next Course \n";
        size++;
        
        fin >> year >> course >> students;

      }
		}
		

/**
 * function: graph()
 *
 * 
 * FOREACH i in the courses[] 
 *		print Title of Course
 * 		print "        |\n" 2 times
 *  	FOREACH j in list[][]
 *			IF list[j][STUDENTS]==courses[i]
 *			year=list[j][COURSE] "|" 
 *			for "k= 1 to list[j][3] print *"
 *		print "        |\n"
 *		FOREACH j in 50
 *			IF (j%5==0)
 *				PRINT j
 *			ELSE 
 *				print "*"
 *	 Precondition: list[] contains integers representing year course and number of students
 *					courses[] contains exactly one copy of each course name. 
 *					size and course size are the number of elements in each array respectively
 *
 *	 PostCondition: void sends a graph of number of students in each course by year to the screen.
 */
void graph(const int list[][ELEMENTS], const string courses[], int& size, int& courseSize){
    for(int i=0; i<courseSize;i++){
      fout << courses[i];
      fout << "\n" << "      |\n";
      fout << "\n" << "      |\n";
      for(int j=0;j<=size;j++){
        if(list[j][COURSE]==i){
          fout << "  " << list[j][YEAR] << "|";
          for(int k=1;k<list[j][STUDENTS];k++){
            fout << "*";
          }
          fout << "\n";
        }
      }
      fout << "      |";
      for (int j = 0; j < 50; ++j){
        if(j%5==0)
          fout << j;
        else
          fout << "*";
      }
      fout << "\n" << "\n" <<  "\n";

    }

}



/**
 * function: rangeOfYears()
 *  determines minimumYear and maximumYear
 * prints: "Statistics for the years " << minYear << "-" << maxYear
 * FOR EACH i in list[][COURSE]
 * if list[i][COURSE]<minYear
 *	minYear=list[i][COURSE]
 * if list[i][COURSE]>maxYear
 * 	maxYear=list[i][COURSE]
 * precondition: list containing year, courseid and numberOfStudents
 * postCondition: String "Statistics for the years" minYear "-" maxYear
 */
void rangeOfYears(const int list[][ELEMENTS], int& size){
//  int minimumYear=minYear(list, size);
//  int maximumYear=maxYear(list, size);
  fout << "Statistics for the years " <<  minYear(list, size) << "-" <<  maxYear(list, size) << "\n";

}

/**
 * function: totalPerCourse()
 * INT[courseSize]  = total[]
 * FOREACH i in Courses[][STUDENTS]
 *		FOREACH j in list[]
 * 			IF list[j][STUDENTS]==i
 *			THEN total[i]+=list[j][3]
 *  
 * PRINT 
 *    
 * 		"Number of students per course\n"
 *		for each i in course[i][]
 *			"		" << course[i] << " has " << total[i] << " Students "
 *
 *	PRECONDITION: list[] contains year, course number and number of students for a list of classes
 *				  course[] contains a list of courses offered with no duplicate values
 * 	
 */
 void totalPerCourse(int list[][ELEMENTS], string courses[], int& size, int& courseSize){
    fout << "The Number of Students per Course:\n";
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
      fout << "                   " << courses[i] << " had " << total[i] << "\n";
    }
 }

/**
 *  function: minNumberOfStudents(String course[], int list[], int& courseSize, int& listSize)
 * 	loop through the student[] 
 *			IF student[i]<minStudents
 *			THEN minstudents==student[i]
 * PRECONDITION: requires a list Array with YEAR, COURSE NUMBER, NUMBER OF STUDENTS
 * POSTCONDITION: returns the index of the course with the least students in the list[]
 *	
 */
void minNumberOfStudents(string course[], int list[][ELEMENTS], int& courseSize, int& size){
  int minStudents=1000;
  int location = -1;
  for(int i=0;i<size;i++){
    if(list[i][STUDENTS]<minStudents){
      minStudents=list[i][STUDENTS];
      location=i;
    }
  }
  fout << "* The course with the MINIMUM numer of students was in " << list[location][YEAR] << " " 
       << course[list[location][COURSE]] << " with " << list[location][STUDENTS] << " students.\n";
}

 /*
  * function: maxPerYears(list[], &size)
  *	
  * create an array YEARS[50]
  * create integer LOCATION=-1
  *	create integer YEARSIZE=0
  *	FOREACH i in LIST[][COURSE] 
  *		FOREACH j in YEARS[]
  *			IF 
  *				LIST[i][COURSE]==YEARS[j][COURSE]
  *			THEN 				
  *				LOCATION=j
  *				IF 
  *					YEARS[j][STUDENTS] < LIST[i][3]
  *				THEN
  *					YEARS[j][STUDENTS] = LIST[i][3]
  *				ENDIF
  *			ENDIF
  *		END FOR
  *		IF 
  *			LOCATION = -1
  *		THEN
  *			
  *			YEARSIZE = YEARSIZE + 1
  *			The max number of students in 2012 is MTH 223 with 30 students
  */	
void maxPerYears(int list[][ELEMENTS], string course[], int& size, int& courseSize){
  int max=maxYear(list, size);
  int min=minYear(list, size);
  int largest=0;

  fout << "* The courses that had the MAXIMUM number of students per year\n";
  for(int i=min;i<=max;i++){
    largest=-1;
    for(int j=0;j<size;j++){

      if(list[j][YEAR]==i){
        if(list[j][STUDENTS]>list[largest][STUDENTS]){
            largest=j;
            
        }
      }
    }
    
    fout << "                    in " << i << "the maximum number of students is in " << course[list[largest][COURSE]] << " with " 
         << list[largest][STUDENTS] << " students. \n";
  }

}

/**
 * Function createInt(String list[], &size )
 * i=-1
 * 
 * FOREACH i list[][COURSE]
 *
 * 	IF course=course[i][COURSE]
 *	
 * END FOR
 * IF i==-1
 * THEN 
 *  courseNumber=size+1
 * 	course[courseNumber][COURSE] = course;
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
 *  int MIN=LIST[i][YEAR]
 *   
 *  FOREACH i in LIST[][ELEMENTS]
 *    IF:
 *      LIST[i][ELEMENTS]< MIN
 *    THEN:
 *      MIN=list[i][ELEMENTS]
 *
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
  int maxYear(const int list[][ELEMENTS], int& size){
    int max = 0;
    for(int i=0;i<size;i++){
      if(list[i][YEAR]>max){
        max=list[i][YEAR];
		fout << list[i][YEAR] << "\n";
      }
      }
      return max;
    }
  

