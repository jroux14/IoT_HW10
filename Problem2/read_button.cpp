#include<iostream>
#include<unistd.h>
#include <cgicc/Cgicc.h>
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include"GPIO.h"
using namespace cgicc;
using namespace exploringBB;
using namespace std;

int main(){
   Cgicc form;
   std::string buttonState = "";
   GPIO inGPIO(46); 
   inGPIO.setDirection(INPUT);
   GPIO_VALUE buttonStatus = inGPIO.getValue();

   cout << HTTPHTMLHeader() << endl;
   cout << html() << body() << endl;
   cout << h1("Reading Pushbutton From Beaglebone Black") << "<br>" << h2("Reading GPIO46") << endl;
   cout << "<form action=\"/cgi-bin/read_button.cpp\" method=\"GET\">" << endl;
   cout << "<input type=\"submit\" value=\"Read Button\" name=\"read\" />" << endl;
  
   form_iterator fsubmit = form.getElement("read");
   if( !fsubmit->isEmpty() && fsubmit != (*form).end()) {
      buttonStatus = inGPIO.getValue();
      if(buttonStatus == LOW){
	 buttonState = "Off"; 
      }else{
         buttonState = "On";
      }
      cout << "<div> Button State: " << buttonState << "</div>" << endl;
   }    
   
   cout << body() << html() << endl;

   return 0;
}
