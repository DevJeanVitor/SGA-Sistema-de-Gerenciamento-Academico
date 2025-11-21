**`v1.0.0`**

# SGA (Academic Management System)

SGA is a console system developed in C++ for managing student records. The project allows you to register, consult, and list high school and technical school students, applying Object-Oriented Programming (OOP) concepts to ensure modular, reusable, and easy-to-maintain code.

## System Demonstration

The video below presents a complete demonstration of the system's features, from registering different types of students to consulting and listing records.

<div align="center">
  <video src="https://github.com/user-attachments/assets/008d27ff-ea29-4833-8d40-243892e24813" controls="controls" style="max-width: 800px;"></video>
</div>

## About the Project

This system was created for academic data management in a console environment. It addresses both structural organization and separation of responsibilities in different modules integrated with data entry processing, ensuring a more secure and intuitive user experience.

The application uses Object-Oriented Programming (OOP) paradigms to model system entities, such as `Student` and `TechnicalStudent`, promoting cleaner and more scalable code.

## Main Features

The system offers the following operations:

1.  **High School Student Registration:** Collects name, enrollment number, and two grades.

<p align="center">
  <img src="https://github.com/user-attachments/assets/992d32da-777d-4323-b716-b50b125f94ea" alt="Cadastro de Aluno do Ensino Médio: Coleta nome, matrícula e duas notas" width="500">
</p>

2.  **Technical Education Student Registration:** Collects the same data as for high school students, plus the name of the technical course.

<p align="center">
  <img src="https://github.com/user-attachments/assets/0cb9f77e-9cea-452f-bb34-5b4f6a8434c4" alt="Cadastro de Aluno do Ensino Técnico: Coleta os mesmos dados do aluno de Ensino Médio, mais o nome do curso técnico.s" width="500">
</p>

3.  **Search by Registration Number:** Allows you to locate a specific student in any of the lists (High School or Technical School) using their registration number.

<p align="center">
  <img src="https://github.com/user-attachments/assets/764d54a2-7d4f-4085-8343-bb8162339f34" alt="Busca por Matrícula: Permite localizar um aluno específico em qualquer uma das listas (Médio ou Técnico) a partir de sua matrícula" width="500">
</p>

4.  **List of Registered Students:** Displays all registered students, separated by category, with their respective details, final average, and approval status.

<p align="center">
  <img src= "https://github.com/user-attachments/assets/1a95c732-829b-491f-a68b-dc282ccce51a" alt="Listagem de Alunos Cadastrados: Exibe todos os alunos cadastrados, separados por categoria, com seus respectivos detalhes, média final e status de aprovação." width="500">
</p>

## Data Validation

One of the pillars of the system is ensuring the integrity of the data entered by the user. Strict validations have been implemented for the following fields:

-   **Name and Course:** Uses Regular Expressions (Regex) to ensure that only valid text (letters and spaces) is accepted, rejecting numbers or special characters.
-   **Registration Number:** The entry must be a positive integer. The system prevents the registration of negative or invalid registration numbers.
-   **Grades (1 and 2):** Grades must be numerical values within the range of 0.0 to 10.0. Any value outside this range is rejected.
-   **Menu Option:** The choice in the main menu must be a numeric value. Text entries are handled to prevent the program from crashing unexpectedly.

The following video demonstrates how the system reacts to invalid entries, prompting the user to correct them.

<div align="center">
  <video src="https://github.com/user-attachments/assets/0faf7e36-b08e-45e8-9f52-726a1e41de22" controls="controls" style="max-width: 800px;"></video>
</div>

## Object-Oriented Paradigm in C++

The project was structured following OOP principles:

-   **Encapsulation:** Class attributes, such as `name`, `studentID`, and `grades` in the `Student` class, are declared as `private`. Access and manipulation of this data are controlled through public methods, such as `getName()`, `calculateResults()`, and `displayDetails()`. This protects data integrity and hides the internal complexity of objects.

- **Abstraction:** The `ApprovalStatus` class acts as an interface (pure abstract class), defining a “contract” that requires child classes to implement an `evaluateStatus()` method.

- **Inheritance:** The `Student` class inherits from `ApprovalStatus`, and the `TechnicalStudent` class inherits from `Student`, reusing attributes and methods and specializing behavior when necessary.

- **Polymorphism:** The `getExtraData()` method is declared as `virtual` in the `Student` class and overridden in the `TechnicalStudent` class. This allows the same method to behave differently depending on the object, displaying the course only for technical students.

## Project Structure

The source code has been modularized to separate responsibilities and facilitate maintenance, following the hierarchical structure below:

```
/SGA
|-- StatusAprovacao.h
|-- Estudante.h
|-- Estudante.cpp
|-- EstudanteTecnico.h
|-- EstudanteTecnico.cpp
|-- Validacao.h
|-- Validacao.cpp
|-- Sistema.h
|-- Sistema.cpp
|-- main.cpp
|-- .vscode/
|   |-- tasks.json
```

## Compilation and Execution

1 - Clone the Repository

```bash
git clone (https://github.com/DevJeanVitor/SGA-Sistema-de-Gerenciamento-Academico.git)
 ```

2 - There are two ways to compile the project:

#### Option A: Via Command Line (g++)

Navigate to the project root folder (`SGA`) via the terminal and execute the command below:

```bash
g++ main.cpp Estudante.cpp EstudanteTecnico.cpp Validacao.cpp Sistema.cpp -o sga_programa
````

After compilation, an executable file named sga_program.exe (on Windows) or sga_program (on Linux/macOS) will be created. To run it, use:

```bash
./sga_programa
````

#### Option B: Via VS Code (Automated Task)
The project already includes a tasks.json configuration file to facilitate compilation within Visual Studio Code.

1 - Open the project folder in VS Code.

2 - Check the compiler path: Open the **.vscode/tasks.json** file. Locate the “command” line and replace the example path with the actual path to your g++.exe compiler.

3 - With any .cpp file open, press the shortcut **Ctrl+Shift+B**.

4 - The compilation task will run, generating the **sga_programa.exe** file.

5 - Open the VS Code integrated terminal **(Ctrl+ ` )** and run the program with the command **./sga_programa**.

**Compilation Time Warning**

This project uses the C++ `<regex>` library to ensure name and course validation. Depending on your computer's technical specifications, the **compilation** process (when executing the `g++` command or the task in VS Code) may take a little longer than expected. This is normal behavior and does not affect the program's performance once it is running.

## Author

This project was developed by: **Jean Vítor**.

- [LinkedIn](https://www.linkedin.com/in/devjeanvitor)
- [GitHub](https://github.com/DevJeanVitor)
