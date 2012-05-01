#include <Teacher.h>

Teacher::Teacher():add_easy(0),add_med(0),
	  sub_easy(0),sub_med(0),
	  place_easy(0),place_med(0),
	  add_score(0),sub_score(0),place_score(0)
{
}

Teacher::Teacher(int as, int ss, int ps,
		 int ae, int am, 
		 int se, int sm, 
		 int pe, int pm):
  add_easy(ae),add_med(am),
  sub_easy(se),sub_med(sm),
  place_easy(pe),place_med(pm),
  add_score(as),sub_score(ss),place_score(ps)
{
}
