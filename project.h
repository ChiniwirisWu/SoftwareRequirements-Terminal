#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include "C-essentials/input.h"
#include <iostream>
#include <cstdlib>
#include <string_view>
class Project{
private:
  std::string m_title {}; 
  std::string m_description {};
  std::vector<std::string> m_functionalObjectives {};
  std::vector<std::string> m_technicalObjectives {};
  std::vector<std::string> m_issues {};

  void setMember(std::string_view label, std::string& member){
    while(true){
      // display
      system("clear");
      std::cout << label << std::endl;
      member = getInput<std::string>();
      // only continue if the input is valid.
      if(member == ""){
        clearInput();
        std::cerr << "Invalid input, press any key to try again..." << std::endl;
        std::cin.get();
        continue;
      } else {
        clearInput();
        system("clear");
        std::cout << label << " saved" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.get();
        return;
      }
    }
  }

  void setMultipleMembers(std::string_view label, std::vector<std::string>& memberVector){
    std::string value {};
    while(true){
      system("clear");
      std::cout << label << "(insert \"0\" to get to the following)" << std::endl;
      value = getInput<std::string>();
      // when the user inputs "", it means that he/her will not insert more values. 
      if(value == "0"){
        return;
      }
      memberVector.push_back(value);
      clearInput();
      system("clear");
      std::cout << label << " saved" << std::endl;
      std::cout << "Press any key to continue..." << std::endl;
      std::cin.get();
    }
  }

public:
  Project() = default;

  void setTitle(){
    setMember("Title", m_title);
  }
  void setDescription(){
    setMember("Description", m_description);
  }
  void setIssues(){
    setMultipleMembers("Issues", m_issues);
  }
  void setFunctionalObjectives(){
    setMultipleMembers("Functional Objectives", m_functionalObjectives);
  }
  void setTechnicalObjectives(){
    setMultipleMembers("Technical Objectives", m_technicalObjectives);
  }

  std::string& getTitle () {
    return m_title;
  }

  std::string& getDescription () {
    return m_description;
  }

  std::vector<std::string>& getFunctionalObjectives(){
    return m_functionalObjectives;
  }

  std::vector<std::string>& getTechnicalObjectives(){
    return m_technicalObjectives;

  }
  std::vector<std::string>& getIssues(){
    return m_issues;
  }

};

#endif
