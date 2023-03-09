#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds
{


    //fully provided for students to display details of a project
    void display(const Project& project) //& means pass by reference, does not pass an copy of the object
    {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department)
    {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
            << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++)
        {
            display(temp[i]);
        }
    }

    //lab functions
     //create a variable to nullptr

    /*If the provided name is valid (exists and is not empty), this function will set the name of the department.
    If the department is already set, it will deallocate the name. It will create enough memory for the name of the
    department to match the new name and then copies the data of the new name. If the new name is not valid, the
    department's current name will not change.
    */

    void Department::updateName(const char* newname)
    {
        //redo





        /*
        char* department_name = nullptr;
        //if newname is not null and is greater than 0 and less than 25
        if (newname != nullptr && strlen(newname) > 0 && strlen(newname) <= 25)
        {   //should else be included as well   //no need
            if (department_name != nullptr)
            {
                delete[] department_name;       //if department name is not empty, delete old, will this work or do I need to delete via class?
            }
            //set length to length of string for dynamic
            int length = strlen(newname);

            if (length > MAX_TOPIC_LENGTH)
            {    //confusion starts, if length is greater than 25, set to 25?
                length = MAX_TOPIC_LENGTH;
            }

            department_name = new char[length + 1];
            strncpy(department_name, newname, length);
            department_name[length] = '\0';
            //return department_name as new department name?
        }*/
    }
    //function to update the budget 
    //This function will update the budget of the department by adding a new change to it.
    void Department::updateBudget(double change)
    {
        Department::departmentBudget += change;  //I think? Says adding a change, do we add new budget to old or replace?
    }

    /*
    -add a new project so long as total cost does not exceed total budget
    -if new project cost + current project !> total budget, this function will work by doing:

    1.  If no new projects currently in progress,
            create new project and save data inside it
    2.  If there are new projects in progress,

    if there are no projects currently in progress:

    creates a new Project and saves the data inside it

if there are projects currently in progress:

    allocates a temp array of projects with new size = old size + 1.
    copy all projects from the old array to the new one
    add new data to the last position of the temp array
    wipe out the old array
    increase the number of the project by one
    allocate projects with the new size
    copy all projects from the temp array to projects
    wipe out the temp array

This function will eventually return true if a project was added to the department, and false otherwise
    */



    bool Department::addProject(Project& newProject)
    {
        double totalCost = departmentBudget;
        //double totalCost = remainingBudget();
        for (int i = 0; i < numofProjects; i++)
        {
            totalCost += projectName[i].projectCost;    //where are we getting new project cost from?
        }

        if (totalCost + newProject.projectCost <= departmentBudget)
        {
            if (numofProjects == 0)
            {
                projectName = new Project;
                *projectName = newProject;
            }
            else
            {
                Project* tempArray = new Project[numofProjects + 1];
                for (int i = 0; i < numofProjects; i++)
                {
                    tempArray[i] = projectName[i];
                }
                tempArray[numofProjects] = newProject;
                numofProjects++;
                delete[] projectName;
                projectName = new Project[numofProjects];
                for (int i = 0; i < numofProjects; i++)
                {
                    projectName[i] = tempArray[i];
                }
                delete[] tempArray;
            }
            return true;
        }
        return false;
    }

    //create a new deparment 
    void createDepartment(const char* newname, Project& newproject, double change)
    {
        //This function will use functions updateName, addProject and updateBudget to set the name of the department, add a project to it and update its budget.
        updateName(newname);
        Department::addProject(newproject); //why am I getting these errors?
        Department::updateBudget(change);   
    };




    //This function will return the list of projects a deparment is currently working on
    Project* fetchProjects() const //syntax error not sure what it was supposed to be?
    {
        return Department::projectName;
    }

    int Department::fetchNumProjects() const; //This function will return the number of projects a department is currently working on.
    {

    }


    double Department::fetchBudget() const
    {
        //double budget = 0;
        //budget = departmentBudget;
        //Department obj;
        //double budget = 0;
        //budget = obj.DepartmentdepartmentBudget;                      //? is this correct? only use :: when 
        return departmentBudget;
    }

    //This function will return the name of a department.
    char* Department::fetchName() const
    {
        //Department obj;
        //char deptName[] = {0};
        //deptName[25] = obj.deparmentName;

        return this->deparmentName;
    }


    //This function will calculate and return the expenses of a department. The total expenses of a department is the total cost of all its current projects.
    double Department::totalexpenses()
    {
        int i = 0;
        double totalExpenses = 0;
        for (i = 0; i < ; i++)
        {
            //add array of expenses
            totalExpenses = ;       //getting lost

        }

        return totalExpenses;
    }

    //This function will calculate and return the remaining budget of a department by subtracting the total expenses from the budget.
    //
    double remainingBudget()
    {

    }

    //This function will clear all the dynamic memory allocation in a department.
    void clearDepartment()
    {

    }



}


