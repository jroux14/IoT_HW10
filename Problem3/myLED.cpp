#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include "GPIO.h"
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#define LED_GPIO "/sys/class/gpio/gpio60/"
using namespace std;
using namespace exploringBB;
using namespace cgicc;

int main(){
   Cgicc form;
   string cmd;
   GPIO outGPIO(28);
   
   bool isStatus = form.queryCheckbox("status");
   form_iterator it = form.getElement("cmd");
   if (it == form.getElements().end() || it->getValue()==""){
      cmd = "off";
   }
   else { cmd = it->getValue(); }
   char *value = getenv("REMOTE_ADDR");
 
   cout << HTTPHTMLHeader() << endl;
   cout << html() << head() << title("LED Example") << head() << endl;
   cout << body() << h1("Exploring BB POST LED Example") << endl;;
   cout << "<form action=\"/cgi-bin/led.cgi\" method=\"POST\">\n";
   cout << "<div>Set LED: <input type=\"radio\" name=\"cmd\" value=\"on\""
        << ( cmd=="on" ? "checked":"") << "/> On ";
   cout << "<input type=\"radio\" name=\"cmd\" value=\"off\""
        << ( cmd=="off" ? "checked":"") << "/> Off ";
   cout << "<input type=\"submit\" value=\"Set LED\" />";
   cout << "</div></form>";
 
   if (cmd=="on") outGPIO.setValue(HIGH);
   else if (cmd=="off") outGPIO.setValue(LOW);
   else cout << "<div> Invalid command! </div>";
   cout << body() << html();
   return 0;
}
