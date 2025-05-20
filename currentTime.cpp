#include <ctime>
#include <string>
#include <iostream>


namespace CurrentTime{

  std::string getCurrentTime(){
    time_t now;
    time(&now);
    char* df = ctime(&now);
    std::string date {df};
    return date;
  }
}
