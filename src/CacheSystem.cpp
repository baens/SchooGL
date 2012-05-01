#ifdef _WIN32
#include <windows.h>
#endif

#include <CacheSystem.h>
#include <Util.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

bool CacheSystem::tryCacheLogin(string username, string password)
{
  string line;
  vector<string> tokens;
  fstream file_op("cache",ios::in);
  while(file_op.good()){
    getline(file_op,line);
    istringstream string_line(line);
    string type;
    string_line >> type;
	transform(type.begin(),type.end(),type.begin(),::tolower);
    if(type == "username"){
      string username_file;
      string password_file;
      string_line >> username_file >> password_file;
      if(username == username_file && password == password_file){
	return true;
      }
    }
}
  return false;
}

void CacheSystem::cacheLogin(string username, string password, int id){
  ifstream infile("cache");
  vector<string> lines;
  string input;
  while(getline(infile,input))
    lines.push_back(input);
  
  infile.close();
  bool handledWrite = false;
  ofstream outfile("cache",ios_base::trunc);
  vector<string>::const_iterator it = lines.begin();
  while(it != lines.end()){
    istringstream string_line(*it);
    string type;
    string_line >> type;
    transform(type.begin(),type.end(),type.begin(),::tolower);
    if(type == "username"){
      string username_file;
      string_line >> username_file;
      if(username == username_file){
	outfile << "username "+username+" "+password+" "+to_string(id) << endl;
	handledWrite = true;
      }
      else
	outfile << *it << endl;
    }
    else
      outfile << *it << endl;
    it++;
  }
  if(!handledWrite)
    outfile << "username "+username+" "+password+" "+to_string(id) << endl;

  outfile.close();
}
bool CacheSystem::cacheQuestion(Question* q,Subject s, Difficulty d)
{
  if(q == NULL)
    return false;
  ofstream outfile("cache",ios_base::app);
  outfile << "question "+to_string(s)+" "+to_string(d)+" "+q->getQuestion()+" "+q->getAnswer() << endl;
  return true;
}

Question* CacheSystem::getQuestionFromCache(Subject s, Difficulty d)
{
  ifstream infile("cache");
  string line;
  while(!infile.eof()){
    getline(infile,line);
    istringstream string_line(line);
    string type;
    string_line >> type;
    transform(type.begin(),type.end(),type.begin(),::tolower);
    if(type == "question"){
      string subject;
      string difficulty;
      string_line >> subject >> difficulty;
      if(subject == to_string(s) && difficulty == to_string(d)){
	string question;
	string answer;
	string_line >> question >> answer;
	return new Question(question,answer);	
      }
    }
  }
}

void CacheSystem::startQuestionCachingThread()
{
}

void CacheSystem::cacheProfile(string username, Profile p){
    ifstream infile("cache");
  vector<string> lines;
  string input;
  while(getline(infile,input))
    lines.push_back(input);
  
  infile.close();
  bool handledWrite = false;
  ofstream outfile("cache",ios_base::trunc);
  vector<string>::const_iterator it = lines.begin();
  while(it != lines.end()){
    istringstream string_line(*it);
    string type;
    string_line >> type;
    transform(type.begin(),type.end(),type.begin(),::tolower);
    if(type == "profile"){
      string username_file;
      string_line >> username_file;
      if(username == username_file){
	outfile << "profile "+username+" "+p.getNick()+" "+to_string(p.getColor().getRed())+" "+to_string(p.getColor().getGreen())+" "+to_string(p.getColor().getBlue()) << endl;
	handledWrite = true;
      }
      else
	outfile << *it << endl;
    }
    else
      outfile << *it << endl;
    it++;
  }
  if(!handledWrite)
    outfile << "profile "+username+" "+p.getNick()+" "+to_string(p.getColor().getRed())+" "+to_string(p.getColor().getGreen())+" "+to_string(p.getColor().getBlue()) << endl;

  outfile.close();
}

Profile* CacheSystem::getProfile(string un){
  ifstream infile("cache");
  string line;
  while(!infile.eof()){
    getline(infile,line);
    istringstream string_line(line);
    string type;
    string_line >> type;
    transform(type.begin(),type.end(),type.begin(),::tolower);
    if(type == "profile"){
      string username;
      string nick;
      string r,g,b;
      string_line >> username;
      if(un == username){
        string_line >> nick >> r >> g >> b;
	return new Profile(nick,Color(to_double(r),to_double(g),to_double(b)));
      }
    }
  }
  return NULL;
}

bool CacheSystem::isOffLine()
{
  return false;
}

int CacheSystem::getUserID(string username){
  string line;
  vector<string> tokens;
  fstream file_op("cache",ios::in);
  while(file_op.good()){
    getline(file_op,line);
    istringstream string_line(line);
    string type;
    string_line >> type;
    transform(type.begin(),type.end(),type.begin(),::tolower);
    if(type == "username"){
      string username_file;
      string password_file;
      string_line >> username_file >> password_file;
      if(username == username_file){
	string id;
	string_line >> id;
	return to_int(id);
      }
    }
  }
  return -1;
}
