# Object-Oriented Quiz Game in C++

## Team Members

- *Samiya Khan* – 24K-0768  
- *Iqra Ashraf* – 24K-0952  
- *Aseelah Masood Khan* – 24K-0881  

*Submission Week:* 17  
*Report Submission Date:* 12th May 2025  

---

## Executive Summary

### Overview
This project involved the design and implementation of a UI-based quiz game using C++ and core Object-Oriented Programming (OOP) principles. The application allows users to select a subject, answer multiple-choice questions (MCQs), receive real-time feedback, and view their scores through a graphical interface.

### Key Findings
- Effective use of OOP concepts: encapsulation, abstraction, inheritance, and polymorphism.
- Seamless integration of file handling for dynamic data loading.
- Modular design allows parallel development and easy maintenance.
- GUI implementation enhanced user interactivity and visual appeal.

---

## Introduction

### Background
Interactive educational games improve knowledge retention. By developing a quiz game in C++, we practiced applying OOP concepts in a practical, user-centric application.

### Objectives
- Develop an educational quiz game using C++.
- Apply and demonstrate core OOP principles.
- Incorporate file handling for dynamic content.
- Build a user-friendly interface using GUI components.
- Implement score tracking for feedback and progress analysis.

---

## Project Description

### Scope

#### Included Features
- Subject selection  
- MCQ format with four options  
- Feedback after each question  
- Randomized question selection  
- Session-based and cumulative scoreboards  
- Full GUI interface using Raylib and RayGUI  

#### Excluded Features
- Online multiplayer or persistent user accounts  
- Question creation/editing interface  
- Adaptive difficulty scaling  

---

## Technical Overview

- *Language:* C++  
- *Tools:* Visual Studio / VS Code  
- *Libraries:* Raylib, RayGUI  
- *Data Handling:* Text files for questions, answers, and scores  

---

## Methodology

### Approach
We followed a collaborative and iterative development approach:
- Weekly planning and review meetings  
- Prototyping of CLI logic before GUI integration  
- Division of work by class responsibility and GUI screens  
- Constant collaboration across all phases, especially during GUI integration  

### Role Distribution (Actual Implementation)

#### Iqra Ashraf
*Code:*
- Imported libraries and constants  
- Developed QuizQuestion and Subject classes (handling OOP, DLD, MVC subjects)  
- Logic for MENU, SUBJECTSELECT, and FINALSCORE cases  

*GUI:*
- Menu Screen  
- Subject Selection Screen  
- Final Score Screen  

#### Samiya Khan
*Code:*
- Player and QuizGame classes  
- Logic for NAMEENTRY, QUIZ, RESULT, and EXIT  

*GUI:*
- Name Entry Screen  
- Quiz Display Screen  
- Result Screen (reviewing all answers and highlighting incorrect ones with correct answers)  

#### Aseelah Masood Khan
*Code:*
- ScoreManager class  
- Logic for HIGHSCORE and SCOREBOARD cases  

*GUI:*
- High Score Screen  
- Scoreboard Screen  

---

## Project Implementation

### Design Structure
- *Subject*: Stores subject-specific questions  
- *QuizQuestion*: Manages question text, options, and correct answer  
- *QuizGame*: Core engine managing gameplay logic  
- *Player*: Stores player-specific data  
- *ScoreManager*: Handles high scores and scoreboard logic  

### Functionalities Implemented
- Menu navigation and subject selection  
- Name input and dynamic question display  
- Real-time answer feedback and score calculation  
- Session summary with answer review  
- High score comparison and scoreboard display  

---

## Challenges Faced

| *Challenge* | *Solution* |
|---------------|--------------|
| File parsing and formatting | Custom parser for structured text files using delimiters and newline support |
| Randomizing questions without repeat | Indexed shuffling with a tracking mechanism to avoid repetition |
| GUI synchronization with logic flow | Close team collaboration to align back-end logic with GUI transitions |
| Integration deviations | Adaptive task handling while maintaining role-based modular contributions |

---

## Results

### Outcomes
- Fully functional and GUI-based quiz game  
- Solid demonstration of OOP and file handling  
- User-friendly experience with visual feedback and session tracking  

### Testing
- Manual testing of all features  
- Repeated randomization trials  
- Edge case handling: empty input, invalid options, score overflow  

### Screenshots

![Image](https://github.com/user-attachments/assets/b8cc6b2e-e941-4b9f-a52c-2c3e8ae218a2)

![Image](https://github.com/user-attachments/assets/496a58a8-9a94-4c23-a3a7-3891e2a19941)

![Image](https://github.com/user-attachments/assets/c817a1f6-9acd-4504-84e9-d61463391b67)

![Image](https://github.com/user-attachments/assets/35378f95-3dd4-49ef-bed0-1c21efb55ca1)

![Image](https://github.com/user-attachments/assets/59fcc8f0-e6c9-41f8-bbd3-6ec637cf51e7)

![Image](https://github.com/user-attachments/assets/05c3a0bf-3b11-4b6c-8fb8-877e9a4e86b8)

![Image](https://github.com/user-attachments/assets/a2088e2c-62dc-4f84-bc02-3f57daf44bcb)

---

## Conclusion

### Findings
The quiz game achieved its educational goals while successfully showcasing C++ and OOP. The collaboration across screens, file handling, and game logic contributed to a robust and scalable application.

### Final Remarks
This project highlighted the importance of modular code structure, GUI integration, and team collaboration. It laid the foundation for potential future extensions like database-backed user accounts or mobile versions.
