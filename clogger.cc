#include <node.h>
#include <v8.h>
#include <ctime>
#include <iostream>
#include <sstream>

using namespace v8;
using namespace std;

string PrintDate() {
	time_t       now = time(0);
	tm           *ltm = localtime(&now);
	stringstream ss (stringstream::in | stringstream::out);

  ss << "[" << 1900 + ltm->tm_year << "-";
  
  ++ltm->tm_mon;

  if (ltm->tm_mon < 10) {
    ss << "0";
  }

  ss << ltm->tm_mon << "-";
  ss << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "] ";
	return ss.str();
}

// colore rosso
char red[]   = "\033[31m";

// colore verde
char green[] = "\033[32m";

// colore blue
char blue[]  = "\033[34m";

// riporta al colore di default
char reset[] = "\033[0m";

char greenstring[] = "green";
char redstring[]   = "red";
char bluestring[]  = "blue";

Handle<String> path = String::New("");

Handle<Value> GetPath(Local<String> property, const AccessorInfo& info){
    return path;
}

void Set(Local<String> property, Local<Value> value, const AccessorInfo& info){
    String::AsciiValue pvalue(property);
    String::AsciiValue ppath(String::New("path"));
    String::AsciiValue pcolor(String::New("color"));
    if (strcmp(*pvalue, *ppath) == 0) {
        path = value->ToString();
    }
   
}

Handle<Value> Log(const Arguments& args) {
  HandleScope scope;
  char *color;
  bool level = false;
  bool category = false;

  String::AsciiValue asciipath(path);
  
  /*if (path == String::New("")) {
      return ThrowException(
          Exception::TypeError(String::New("Devi specificare il percorso in cui si trova il file di log"))
      );     
  }*/

    // se non viene passato il testo del messaggio
    // usciamo in silenzio senza scrivere nulla
    if (!args[0]->IsString() || args[0]->ToString()->Length() == 0) {
        return scope.Close(Undefined());
    }    
    
    if (args[1]->IsString() && args[1]->ToString()->Length() > 0) {
        level = true;
    }

    if (args[2]->IsString() && args[2]->ToString()->Length() > 0) {
        category = true;
    }

    if (args[3]->IsString() && args[3]->ToString()->Length() > 0) {
        String::AsciiValue colorparam(args[3]->ToString());
        if (strcmp(*colorparam, greenstring) == 0) {
            color = green;
        } else if (strcmp(*colorparam, redstring) == 0) {
            color = red;
        } else if (strcmp(*colorparam, bluestring) == 0) {
            color = blue;
        } 
    } else {
      color = reset;
    }

    printf("%s", color);

    cout << PrintDate();

    String::AsciiValue asciitext(args[0]->ToString());
    if (level) {
      String::AsciiValue leveltext(args[1]->ToString());
      printf("[%s] ", *leveltext);
    }
    if (category) {
      String::AsciiValue categorytext(args[2]->ToString());
      printf("[%s] ", *categorytext);
    }
    printf("%s\n", *asciitext);
    cout << reset;
    return scope.Close(Undefined());
}

void init(Handle<Object> target) {
  target->Set(String::NewSymbol("log"), FunctionTemplate::New(Log)->GetFunction());
  target->SetAccessor(String::New("path"), GetPath, Set);
}

NODE_MODULE(clogger, init);