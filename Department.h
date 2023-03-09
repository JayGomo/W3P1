#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds
{

	const int MAX_TOPIC_LENGTH = 25;

	struct Project
	{
		char m_topic[MAX_TOPIC_LENGTH + 1];
		double m_cost;
		double projectCost;
	};

	//class Department does here
	/*The Department class must keep the following information:

	The departments' name: that is held dynamically in a C string. (char *)
	The departments' projects: that is held dynamically by a Project pointer. (Project *)
	Number of Current Projects: that are all held in an integer. (int)
	Budget of the Department: that is held in a double (double). Should have an initial value of 15345.99.
	*/
	class Department
	{


	public:
		char* deparmentName;
		struct Project* projectName;
		int numofProjects;
		double departmentBudget = 15345.99;

		//functions
		void updateName(const char* newname);
		void updateBudget(double change);
		bool addProject(Project& newproject);


		void createDepartment(const char* newname,			//what is difference between * and &
			Project& newproject,
			double change);


		Project* fetchProjects() const;					//why is the const outside of the input arg //does not modify the member of the class when called.
		int fetchNumProjects() const;
		double fetchBudget() const;
		char* fetchName() const;
		double totalexpenses();
		double remainingBudget();
		void clearDepartment();

	};



	//helper functions - do not belong inside the class
	void display(const Project& project);
	void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_