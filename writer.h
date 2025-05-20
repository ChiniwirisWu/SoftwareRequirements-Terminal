#ifndef WRITER_H
#define WRITER_H
#include "project.h"
#include "currentTime.h"
#include <fstream>
#include <iostream>
#include <vector>


class Writer{
private:
  std::ofstream m_myFile { "summary.txt" }; // opens and creates a .txt file.
  
  void writeEntry(std::string_view label, std::string& content){
    //security check
    if(!m_myFile.is_open()){
      std::cerr << "It was unable to open the file." << std::endl;
      return;
    }
    //then run
    m_myFile << label << ":" << std::endl;
    m_myFile << content << "\n\n"; 
  }

  void writeMultipleEntries(std::string_view label, std::vector<std::string>& entries){
    //security check
    if(!m_myFile.is_open()){
      std::cerr << "It was unable to open the file." << std::endl;
      return;
    } 
    //then run
    m_myFile << label << ":" << std::endl;
    for(int i = 0; i < entries.size(); i++){
      m_myFile << (i + 1) << ") " << entries[i] << std::endl;      
    }
    m_myFile << "\n\n";
  }
public:
  void writeTitle(Project& project){
    writeEntry("Title", project.getTitle());
  }

  void writeDescription(Project& project){
    writeEntry("Description", project.getDescription());
  }

  void writeFunctionalObjectives(Project& project){
    writeMultipleEntries("Functional Objectives", project.getFunctionalObjectives());
  }

  void writeTechnicalObjectives(Project& project){
    writeMultipleEntries("Technical Objectives", project.getTechnicalObjectives());
  }

  void writeIssues(Project& project){
    writeMultipleEntries("Issues", project.getIssues());
  }

  void writeCurrentTime(){
    //security check
    if(!m_myFile.is_open()){
      std::cerr << "It was unable to open the file." << std::endl;
      return;
    }
    //then run
    m_myFile << "Created date" << std::endl;
    m_myFile << CurrentTime::getCurrentTime() << "\n\n";
  }

  void closeFile(){
    m_myFile.close();
    system("clear");
    std::cout << "File updated successfuly" << std::endl;
  }
};

#endif
