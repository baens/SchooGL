#ifndef TEACHER_H
#define TEACHER_H
class Teacher{
 public:
  Teacher();
  Teacher(int as, int ss, int ps,int ae, int am, int se, int sm, int pe, int pm);

  void setAddEasy(int s){add_easy = s;}
  void setAddMed(int s){add_med = s;}
  void setSubEasy(int s){sub_easy = s;}
  void setSubMed(int s){sub_med = s;}
  void setPlaceEasy(int s){place_easy = s;}
  void setPlaceMed(int s){place_med = s;}
  void setAddScore(int s){add_score = s;}
  void setSubScore(int s){sub_score = s;}
  void setPlaceScore(int s){place_score = s;};

  int getAddEasy(){return add_easy;}
  int getAddMed(){return add_med;}
  int getSubEasy(){return sub_easy;}
  int getSubMed(){return sub_med;}
  int getPlaceEasy(){return place_easy;}
  int getPlaceMed(){return place_med;}
  int getAddScore(){return add_score;}
  int getSubScore(){return sub_score;}
  int getPlaceScore(){return place_score;};


 private:
  int add_easy;
  int add_med;
  int sub_easy;
  int sub_med;
  int place_easy;
  int place_med;
  int add_score;
  int sub_score;
  int place_score;

};
#endif
