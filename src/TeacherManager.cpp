#include <LoginManager.h>
#include <TeacherManager.h>
#include <Teacher.h>
#include <Util.h>

Teacher TeacherManager::getTeacher(int uID)
{
  	MYSQL *connect;
	connect = mysql_init(NULL);
	if(!connect){
		cout << "Failed to start!" << endl;
		return Teacher();
	}

	connect = mysql_real_connect(connect,DB_SR,DB_UN,DB_PW,DB_DB,0,NULL,0);
	if(!connect)
	  return Teacher();
	
	MYSQL_RES *my_res;
	string query = "SELECT Teachers.Addition_Score,Teachers.Subtraction_Score,Teachers.Placement_Score,Teachers.Addition_Easy_Threshold,Teachers.Addition_Medium_Threshold,Teachers.Subtraction_Easy_Threshold,Teachers.Subtraction_Medium_Threshold,Teachers.Placement_Easy_Threshold,Teachers.Placement_Medium_Threshold FROM Students,Teachers WHERE Students.uID = '"+to_string(uID)+"' AND Students.teacher_id = Teachers.uID" ;
	////////////
	mysql_query(connect,query.c_str());
	cout << mysql_error(connect) << endl;
	my_ulonglong num_rows = 0;
	my_res = mysql_store_result(connect);

	num_rows = mysql_num_rows(my_res);
	MYSQL_ROW row = mysql_fetch_row(my_res);
	return Teacher(to_int(row[0]),to_int(row[1]),to_int(row[2]),
		       to_int(row[3]),to_int(row[4]),
		       to_int(row[5]),to_int(row[6]),
		       to_int(row[6]),to_int(row[7]));
	//return Teacher(200,200,200,50, 125,50, 125,50, 125);
}
