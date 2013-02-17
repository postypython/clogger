#include <node.h>
#include <v8.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cstring>
#include "colors.cc"

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
  string color;
  string logmessage;
  BashColors bashcolors;

  String::AsciiValue asciipath(path);
  
  /*if (path == String::New("")) {
      return ThrowException(
          Exception::TypeError(String::New("Devi specificare il percorso in cui si trova il file di log"))
      );     
  }*/
    if (!args[0]->IsString() || args[0]->ToString()->Length() == 0) {
        return scope.Close(Undefined());
    } 

    if (args[3]->IsString() && args[3]->ToString()->Length() > 0) {
        String::AsciiValue colorname(args[3]->ToString());
        color = bashcolors.GetColorFromName(*colorname);
    } else {
        color = bashcolors.GetColorFromName("reset");
    }

    // sets up color and timestamp
    logmessage += color + PrintDate();
    
    if (args[1]->IsString() && args[1]->ToString()->Length() > 0) {
        String::AsciiValue leveltext(args[1]->ToString());
        
        // adss level
        logmessage += "[" + string(*leveltext) + "] ";
    }

    if (args[2]->IsString() && args[2]->ToString()->Length() > 0) {
        String::AsciiValue categorytext(args[2]->ToString());
        
        // adds category
        logmessage += "[" + string(*categorytext) + "] ";
    }

    String::AsciiValue asciitext(args[0]->ToString());

    // adds message
    logmessage += string(*asciitext) + bashcolors.GetColorFromName("reset");

    // outputs message
    cout << logmessage << endl;

    return scope.Close(Undefined());
}

void init(Handle<Object> target) {
  target->Set(String::NewSymbol("log"), FunctionTemplate::New(Log)->GetFunction());
  target->SetAccessor(String::New("path"), GetPath, Set);
}

NODE_MODULE(clogger, init);
