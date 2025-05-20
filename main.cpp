//crear un programa que haga un registro de una To Do List para proyectos de programacion. Ha de incluir el titulo, la fecha de cuando se pretende crear el proyecto, los objetivos funcionales (ilimitados), los objetivos tecnicos (ilimitados)

/*
Objetivos funcionales 
Modifique un .txt con el resumen de los detalles del proyecto de programacion.
Pida el titulo, descripcion, objetivos funcionales, y objetivos tecnicos.
 * */


#include "project.h"
#include "writer.h"

void setProjectInfo(Project& project){
  project.setIssues();
  project.setDescription();
  project.setFunctionalObjectives();
  project.setTechnicalObjectives();
  project.setTitle();
}

void writeProjectInfo(Project& project, Writer& writer){
  writer.writeTitle(project);
  writer.writeDescription(project);
  writer.writeFunctionalObjectives(project);
  writer.writeTechnicalObjectives(project);
  writer.writeIssues(project);
  writer.writeCurrentTime();
  writer.closeFile();
}

int main(){
  Project project {};
  Writer writer {};

  setProjectInfo(project);
  writeProjectInfo(project, writer);
}
