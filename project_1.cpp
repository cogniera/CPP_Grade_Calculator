#include <iostream>
#include <cmath>

//declare main function 
int main();

//declare grade function 
double average_calculator(double recieved_grade , double max_grade);

//declare input function 
void input_grade_prompt(double& grade, std::string name );

//declare input function 
void input_grade_recieved(double& grade, std::string name, double& max_grade );

//declare comparison function
double final_exam_comparison(double average , double final_exam_averge);

//define main function 
int main(){

    //declare maximum grade variables 
    double final_exam_max{0};
    double midterm_max{0};
    double project1_max{0};
    double project2_max{0};
    double project3_max{0};
    double project4_max{0};
    double project5_max{0};

    //declare recieved grade variables 
    double final_exam_grade{0};
    double midterm_grade{0};
    double project1_grade{0};
    double project2_grade{0};
    double project3_grade{0};
    double project4_grade{0};
    double project5_grade{0};

    //declare average variables 
    double final_exam_average{0};
    double midterm_average{0};
    double project1_average{0};
    double project2_average{0};
    double project3_average{0};
    double project4_average{0};
    double project5_average{0};

    //declare variables for averages 
    double project_average{0};
    double exams_average{0};
    double final_average{0};
    int final_average_asint{0};

    //starting by making a menu 

    std::cout << "============================" << std::endl;
    std::cout << "FINAL GRADE CALCULATOR" << std::endl;
    std::cout << "============================" << std::endl; 
    std::cout << std::endl;

    input_grade_prompt(final_exam_max, "final exam");
    
    input_grade_recieved(final_exam_grade, "final exam", final_exam_max);
    
    input_grade_prompt(midterm_max, "midterm");
    
    input_grade_recieved(midterm_grade, "midterm", midterm_max);
    
    input_grade_prompt(project1_max, "project 1");
    
    input_grade_recieved(project1_grade, "project 1", project1_max);
    
    input_grade_prompt(project2_max, "project 2");

    input_grade_recieved(project2_grade, "project 2", project2_max);
    
    input_grade_prompt(project3_max, "project 3");
    
    input_grade_recieved(project3_grade, "project 3", project3_max);
    
    input_grade_prompt(project4_max, "project 4");
    
    input_grade_recieved(project4_grade, "project 4", project4_max);
    
    input_grade_prompt(project5_max, "project 5");
    
    input_grade_recieved(project5_grade, "project 5", project5_max);

    //calculate the averages
    final_exam_average = average_calculator(final_exam_grade, final_exam_max);
    
    midterm_average = average_calculator(midterm_grade, midterm_max);
    
    project1_average = average_calculator(project1_grade, project1_max);
    
    project2_average = average_calculator(project2_grade, project2_max);
    
    project3_average = average_calculator(project3_grade, project3_max);
    
    project4_average = average_calculator(project4_grade, project4_max);
    
    project5_average = average_calculator(project5_grade, project5_max);

    midterm_average = final_exam_comparison(midterm_average, final_exam_average);
    project1_average = final_exam_comparison(project1_average, final_exam_average);
    project2_average = final_exam_comparison(project2_average, final_exam_average);
    project3_average = final_exam_comparison(project3_average, final_exam_average);
    project4_average = final_exam_comparison(project4_average, final_exam_average);
    project5_average = final_exam_comparison(project5_average, final_exam_average);

    exams_average = (3.0/4.0)*(final_exam_average) + (1.0/4.0)*(midterm_average);

    project_average = (project1_average+project2_average+project3_average+project4_average+project5_average)/5.0;

    if(exams_average <= 40.0){
        final_average = exams_average;
    }
    else if(exams_average >= 60.0){
        final_average =(2.0/3.0)*(exams_average) + (1.0/3.0)*(project_average);
    }
    else{
        final_average = (project_average)*(1.0/3.0)*((exams_average-40.0)/20.0) + (exams_average)*(1.0-((1.0/3.0)*((exams_average-40.0)/20.0)));
    }

    final_average = std::round(final_average + 1e-12) ;

    final_average_asint = static_cast<int>(final_average);

    std::cout << "Final Grade: " << final_average_asint << std::endl;

    //exit 
    return 0 ; 
}

//define the function for inputing the grade 
void input_grade_prompt(double& grade , std::string name){
    
    while (grade <= 0)
    {
        //prompt for the max grade
        std::cout << "Enter the maximum grade for " << name << " :" << std::endl;
        std::cin >> grade;

        //check for an integer
        if ( grade == std::round( grade ) && grade > 0) {
            break;
        }else {
            //reset, prompt the user and ask again 
            grade = 0;
            continue;
        }
    }
}

void input_grade_recieved(double& grade , std::string name, double& max_grade){
    
    while (grade <= 0)
    {
        //prompt for the recieved grade
        std::cout << "Enter the revieved grade for " << name << " :"<< std::endl;
        std::cin >> grade;

        //check for an conditions
        if ( grade >= 0 && grade <= max_grade) {
            break;
        }else {
            //reset, prompt the user and ask again 
            grade = 0;
            continue;
        }
    }
}

//define function for average calculation
double average_calculator(double recieved_grade , double max_grade){
    
    //define the final average
    double final_average;

    //calculate the final average
    final_average = 100.0*(recieved_grade/max_grade);
    
    //return the final average
    return final_average;
}

//define function to compare the final exam average 
double final_exam_comparison(double average , double final_exam_average){

    //compare the final exam average
    if(average < final_exam_average){
        average = final_exam_average;
    }

    return average;
}