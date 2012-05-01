#ifndef QUESTION_H
#define QUESTION_H 1
#include <string>
#include "Point.h"
#include "Color.h"
#include "Rectangle1.h"

using namespace std;

class Question{
 public:
	 /*
	 * a default question
	 */
	Question();
	 /*
	 * a question with a point
	 * 
	 * @param p a point where the question is
	 */
	Question(Point p, Color c, string question, string answer[4], int correct);
	Question(Point p, Color c, string question, string answer[4], int correct, double ansOffset);
	Question(string question, string answer);
	
	 /*
	 * a copy of a question
	 * 
	 * @param rhs a questionto copy
	 */
	Question(Question& rhs);
	 /*
	 * gets the question
	 * 
	 * @return string the question
	 */
	string getQuestion(){return question;}
	 /*
	 * sets the question
	 * 
	 * @param q a string that represents the question
	 */
	//void setQuestion(string q);
	 /*
	 * gets the answer
	 * 
	 * @return string the answer
	 */
	string getAnswer(){return answers[correctAnswer];}
	 /*
	 * sets the answer
	 * 
	 * @param a a string that represents the answer
	 */
	//void setAnswer(string a);
	 /*
	 * set the incorrect answers
	 * 
	 * @param inc an array of strings
	 * @param size size of array
	 */
	//void setinCorrectAnswers();//string inc[], int size);
	 /*
	 * draws the question
	 */
	void drawQuestion();
	 /*
	 * draws the answer
	 * 
	 * @param p point where the answer is
	 * @param answer answer string to be printed
	 */
	void drawAnswer(Rectangle1 r, string answer);
	/**
	 * attempts to handle a left mouse down
	 * @param p The point where the action occured
	 *
	 *@return will return true if handled, else false
	 */
	bool handleLeftMouseDown(Point p);
	/**
	 * attempts to handle a right mouse down
	 * @param p The point where teh action occured
	 *
	 *@return will return true if handled, else false
	 */
	bool handleLeftMouseUp(Point p);

	bool isAnswerCorrect(){return correct;}
	
	void setCorrectColor(Color c){answerRec[correctAnswer]->setColor(c);}

	bool hasAnswered() {return answered;}
 private:
	Point point;
	Point* points[4];
	string question;
	string answers[4];
	int correctAnswer;
	Color color;
	Rectangle1* answerRec[4];
	int random;
	bool correct;
	bool answered;
};
#endif //QUESTION_H
