#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include "raygui.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <string>
using namespace std;

const int MAX_QUESTIONS = 5;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 50;
const int FIRST_BUTTON_Y = 160;
const int BUTTON_SPACING = 70;

Color titleBlue = {0, 150, 255};
Color dividerPurple = {106, 5, 114};
Color darkGray = {50, 50, 50};

class QuizQuestion
{
private:
    string question;
    string options[4];
    char correct_answer;

public:
    QuizQuestion() {}

    void setQuestion(const string &q)
    {
        question = q;
    }

    void setOption(int index, const string &opt)
    {
        if (index >= 0 && index < 4)
        {
            options[index] = opt;
        }
    }

    void setCorrectAnswer(char ans)
    {
        correct_answer = ans;
    }

    string getQuestion() const
    {
        return question;
    }

    string getOption(int index) const
    {
        if (index >= 0 && index < 4)
        {
            return options[index];
        }
        return "";
    }

    char getCorrectAnswer() const
    {
        return correct_answer;
    }

    void writeToFile(ofstream &file) const
    {
        file << question << endl;
        for (int i = 0; i < 4; i++)
        {
            file << options[i] << endl;
        }
        file << correct_answer << endl;
    }

    void displayQuestion() const
    {
        cout << endl
             << question << endl;

        for (int i = 0; i < 4; ++i)
        {
            cout << (char)('a' + i) << ") " << options[i] << endl;
        }
    }
};

class Subject
{
protected:
    string filename;

public:
    Subject(string fname)
    {
        filename = fname;
    }

    void loadQuestionsFromFile(QuizQuestion quiz[]) const
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            DrawText("ERROR 404!! Not Found. Failed to load questions!! Failed to load questions!!", 300, 200, 30, RED);
            return;
        }

        string buffer;
        for (int i = 0; i < MAX_QUESTIONS; i++)
        {
            if (!getline(file, buffer))
                break;
            quiz[i].setQuestion(buffer);

            for (int j = 0; j < 4; j++)
            {
                if (!getline(file, buffer))
                    break;
                quiz[i].setOption(j, buffer);
            }

            if (!getline(file, buffer) || buffer.empty())
            {
                quiz[i].setCorrectAnswer('a'); 
            }
            else
            {
                quiz[i].setCorrectAnswer(buffer[0]);
            }
        }
        file.close();
    }

    virtual void writeQuestionsToFile() = 0;
};

class OOPSubject : public Subject
{
public:
    OOPSubject() : Subject("OOP_Questions.txt") {}

    void writeQuestionsToFile()
    {
        QuizQuestion questions[MAX_QUESTIONS];

        questions[0].setQuestion("What is encapsulation in OOP?");
        questions[0].setOption(0, "Hiding data implementation");
        questions[0].setOption(1, "Using public variables");
        questions[0].setOption(2, "Multiple inheritance");
        questions[0].setOption(3, "Overriding functions");
        questions[0].setCorrectAnswer('a');

        questions[1].setQuestion("Which keyword is used to create a class object?");
        questions[1].setOption(0, "object");
        questions[1].setOption(1, "new");
        questions[1].setOption(2, "class");
        questions[1].setOption(3, "struct");
        questions[1].setCorrectAnswer('b');

        questions[2].setQuestion("Which concept allows function overloading?");
        questions[2].setOption(0, "Encapsulation");
        questions[2].setOption(1, "Polymorphism");
        questions[2].setOption(2, "Abstraction");
        questions[2].setOption(3, "Inheritance");
        questions[2].setCorrectAnswer('b');

        questions[3].setQuestion("What is a constructor?");
        questions[3].setOption(0, "A function that destroys objects");
        questions[3].setOption(1, "A function called when object is created");
        questions[3].setOption(2, "A function with return type int");
        questions[3].setOption(3, "A virtual function");
        questions[3].setCorrectAnswer('b');

        questions[4].setQuestion("Which of the following is not an OOP principle?");
        questions[4].setOption(0, "Encapsulation");
        questions[4].setOption(1, "Inheritance");
        questions[4].setOption(2, "Compilation");
        questions[4].setOption(3, "Polymorphism");
        questions[4].setCorrectAnswer('c');

        ofstream file(filename);

        if (!file)
        {

            DrawText("ERROR 404!! Not Found. Failed to load questions!!", 300, 200, 30, RED);
            return;
        }

        for (int i = 0; i < MAX_QUESTIONS; i++)
        {
            questions[i].writeToFile(file);
        }

        file.close();
    }
};

class DLDSubject : public Subject
{
public:
    DLDSubject() : Subject("DLD_Questions.txt") {}

    void writeQuestionsToFile()
    {
        QuizQuestion questions[MAX_QUESTIONS];

        questions[0].setQuestion("What does a decoder do in digital circuits?");
        questions[0].setOption(0, "Converts binary to decimal");
        questions[0].setOption(1, "Converts decimal to binary");
        questions[0].setOption(2, "Stores data");
        questions[0].setOption(3, "Adds binary numbers");
        questions[0].setCorrectAnswer('a');

        questions[1].setQuestion("What is the output of a 2-to-4 line decoder?");
        questions[1].setOption(0, "2 output lines");
        questions[1].setOption(1, "4 output lines");
        questions[1].setOption(2, "8 output lines");
        questions[1].setOption(3, "1 output line");
        questions[1].setCorrectAnswer('b');

        questions[2].setQuestion("What is the function of a multiplexer?");
        questions[2].setOption(0, "Distributes input to many outputs");
        questions[2].setOption(1, "Selects one input from many");
        questions[2].setOption(2, "Stores data permanently");
        questions[2].setOption(3, "Generates clock pulses");
        questions[2].setCorrectAnswer('b');

        questions[3].setQuestion("How many output lines does a 3-to-8 decoder have?");
        questions[3].setOption(0, "3");
        questions[3].setOption(1, "8");
        questions[3].setOption(2, "6");
        questions[3].setOption(3, "4");
        questions[3].setCorrectAnswer('b');

        questions[4].setQuestion("Which gate is known as the universal gate?");
        questions[4].setOption(0, "OR");
        questions[4].setOption(1, "AND");
        questions[4].setOption(2, "NAND");
        questions[4].setOption(3, "XOR");
        questions[4].setCorrectAnswer('c');

        ofstream file(filename);

        if (!file)
        {

            DrawText("ERROR 404!! Not Found. Failed to load questions!!", 300, 200, 30, RED);
            return;
        }

        for (int i = 0; i < MAX_QUESTIONS; i++)
        {
            questions[i].writeToFile(file);
        }

        file.close();
    }
};

class MVCSubject : public Subject
{
public:
    MVCSubject() : Subject("MVC_Questions.txt") {}

    void writeQuestionsToFile()
    {
        QuizQuestion questions[MAX_QUESTIONS];

        questions[0].setQuestion("What is a partial derivative?");
        questions[0].setOption(0, "Derivative w.r.t. one variable while fixing others");
        questions[0].setOption(1, "Total derivative");
        questions[0].setOption(2, "Double integral");
        questions[0].setOption(3, "None of these");
        questions[0].setCorrectAnswer('a');

        questions[1].setQuestion("What is a gradient vector?");
        questions[1].setOption(0, "Vector of function values");
        questions[1].setOption(1, "Vector of second derivatives");
        questions[1].setOption(2, "Vector of partial derivatives");
        questions[1].setOption(3, "A constant vector");
        questions[1].setCorrectAnswer('c');

        questions[2].setQuestion("What does a double integral represent?");
        questions[2].setOption(0, "Area under curve");
        questions[2].setOption(1, "Volume under surface");
        questions[2].setOption(2, "Length of curve");
        questions[2].setOption(3, "Slope of tangent");
        questions[2].setCorrectAnswer('b');

        questions[3].setQuestion("In which coordinate system is r^2 = x^2 + y^2 used?");
        questions[3].setOption(0, "Spherical");
        questions[3].setOption(1, "Polar");
        questions[3].setOption(2, "Cylindrical");
        questions[3].setOption(3, "Cartesian");
        questions[3].setCorrectAnswer('b');

        questions[4].setQuestion("What is the Jacobian used for?");
        questions[4].setOption(0, "To calculate limits");
        questions[4].setOption(1, "To transform variables in multiple integrals");
        questions[4].setOption(2, "To find extrema");
        questions[4].setOption(3, "To integrate simple functions");
        questions[4].setCorrectAnswer('b');

        ofstream file(filename);

        if (!file)
        {

            DrawText("ERROR 404!! Not Found. Failed to load questions!!", 300, 200, 30, RED);
            return;
        }

        for (int i = 0; i < MAX_QUESTIONS; i++)
        {
            questions[i].writeToFile(file);
        }

        file.close();
    }
};

class Player
{
private:
    string name;
    int score;

public:
    Player()
    {
        score = 0;
        name = "";
    }

    void setName(const string n)
    {
        name = n;
    }

    string getName() const
    {
        return name;
    }

    void setScore(const int s)
    {
        score = s;
    }

    int getScore() const
    {
        return score;
    }

    void saveToFile(const char *filename) const
    {
        ofstream file(filename, ios::app);
        if (file)
        {
            file << name << " " << score << endl;
            file.close();
        }
    }
};

class ScoreManager
{
public:
    static int getHighestScore(const char *filename)
    {
        ifstream file(filename);
        int highestScore = 0;

        if (!file)
        {
            DrawText("Error 404!! Not Found. Failed to load questions!!", 300, 200, 30, RED);
            return 0; // Error may be cause of this so just remove this
        }

        file >> highestScore;
        file.close();

        return highestScore;
    }

    static void updateHighestScore(const char *filename, int newHighScore)
    {
        ofstream file(filename);
        if (!file)
        {
            DrawText("Error 404!! Not Found. Failed to load questions!!", 300, 200, 30, RED);
            return;
        }

        file << newHighScore;
        file.close();
    }
};

class QuizGame
{
private:
    QuizQuestion quiz[MAX_QUESTIONS];
    Player currentPlayer;
    int questionOrder[MAX_QUESTIONS];
    char userAnswers[MAX_QUESTIONS];
    int currentQuestionIndex;
    bool questionsLoaded = false;
    bool quizSubmitted = false;
    bool scoreSaved = false;

public:
    QuizGame() {}

    void StartQuiz(Subject *subject, const string &playerName)
    {
        if (!subject)
        {
            return;
        }

        currentQuestionIndex = 0;
        currentPlayer.setName(playerName);

        if (!questionsLoaded)
        {
            subject->loadQuestionsFromFile(quiz);

            for (int i = 0; i < MAX_QUESTIONS; i++)
            {
                questionOrder[i] = i;
            }

            for (int i = MAX_QUESTIONS - 1; i > 0; i--)
            {
                int j = rand() % (i + 1);
                int temp = questionOrder[i];
                questionOrder[i] = questionOrder[j];
                questionOrder[j] = temp;
            }
            questionsLoaded = true;
        }
    }

    QuizQuestion GetQuestionAtIndex(int index)
    {
        return quiz[questionOrder[index]];
    }

    QuizQuestion GetCurrentQuestion() const
    {
        return quiz[questionOrder[currentQuestionIndex]];
    }

    bool AdvanceToNextQuestion()
    {
        if (currentQuestionIndex < MAX_QUESTIONS - 1)
        {
            currentQuestionIndex++;
            return true;
        }

        return false;
    }

    void RecordAnswer(char answer)
    {
        userAnswers[currentQuestionIndex] = answer;
    }

    void SubmitQuiz()
    {
        quizSubmitted = true;
    }

    bool IsSubmitted() const
    {
        return quizSubmitted;
    }

    int GetCurrentQuestionIndex() const
    {
        return currentQuestionIndex;
    }

    int GetScore()
    {
        int score = 0;
        for (int i = 0; i < MAX_QUESTIONS; i++)
        {
            if (userAnswers[i] == quiz[questionOrder[i]].getCorrectAnswer())
            {
                score++;
            }
        }
        currentPlayer.setScore(score);
        return score;
    }

    char getUserAnswer(int index) const
    {
        return userAnswers[index];
    }

    void saveScoreboard(const char *filename)
    {
        if (!scoreSaved)
        {
            currentPlayer.saveToFile(filename);
            scoreSaved = true;
        }
    }
    void ResetQuizState()
    {
        currentQuestionIndex = 0;
        questionsLoaded = false;
        quizSubmitted = false;
        scoreSaved = false; 
        memset(userAnswers, 0, sizeof(userAnswers));
    }
};

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Quiz Game");
    SetTargetFPS(60);

    OOPSubject o1;
    o1.writeQuestionsToFile();

    DLDSubject d1;
    d1.writeQuestionsToFile();

    MVCSubject m1;
    m1.writeQuestionsToFile();

    QuizGame game;
    Subject *selectedSubject;

    enum GameState
    {
        NAMEENTRY,
        MENU,
        SUBJECTSELECT,
        QUIZ,
        RESULT,
        FINALSCORE,
        HIGHSCORE,
        SCOREBOARD,
        EXIT
    };

    GameState gameState = NAMEENTRY;

    char nameInput[256] = "";
    string playerName = "";

    while (!WindowShouldClose() && gameState != EXIT)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (gameState)
        {

        case NAMEENTRY:
        {
            Rectangle textBoxRect = {200, 150, 400, 50};
            GuiTextBox(textBoxRect, nameInput, 255, true);

            Rectangle continueBtnRect = {300, 220, 200, 50};
            if (GuiButton(continueBtnRect, "CONTINUE") && nameInput[0] != '\0')
            {
                playerName = nameInput;
                gameState = MENU;
            }

            break;
        }

        case MENU:
        {
            float buttonWidth = 300;
            float buttonHeight = 45;
            float startX = 250;
            float startY = 150;
            float gap = 55;

            Rectangle btnPlay = {startX, startY + gap * 0, buttonWidth, buttonHeight};
            if (GuiButton(btnPlay, "1. Play the Quiz Game!!"))
            {
                gameState = SUBJECTSELECT;
            }

            Rectangle btnHighScore = {startX, startY + gap * 1, buttonWidth, buttonHeight};
            if (GuiButton(btnHighScore, "2. View the Highest Score!"))
            {
                gameState = HIGHSCORE;
            }

            Rectangle btnScoreboard = {startX, startY + gap * 2, buttonWidth, buttonHeight};
            if (GuiButton(btnScoreboard, "3. View the Scoreboard!"))
            {
                gameState = SCOREBOARD;
            }

            Rectangle btnExit = {startX, startY + gap * 3, buttonWidth, buttonHeight};
            if (GuiButton(btnExit, "4. Exit the Game!!"))
            {
                gameState = EXIT;
            }

            break;
        }

        case SUBJECTSELECT:
        {
            Rectangle btnOOP = {250, 160, 300, 40};
            if (GuiButton(btnOOP, "1. Object-Oriented Programming (OOP)"))
            {
                selectedSubject = &o1;
                game.StartQuiz(selectedSubject, playerName);
                gameState = QUIZ;
            }

            Rectangle btnDLD = {250, 220, 300, 40};
            if (GuiButton(btnDLD, "2. Digital Logic Design (DLD)"))
            {
                selectedSubject = &d1;
                game.StartQuiz(selectedSubject, playerName);
                gameState = QUIZ;
            }

            Rectangle btnMVC = {250, 280, 300, 40};
            if (GuiButton(btnMVC, "3. Multivariable Calculus (MVC)"))
            {
                selectedSubject = &m1;
                game.StartQuiz(selectedSubject, playerName);
                gameState = QUIZ;
            }

            Rectangle btnBack = {SCREEN_WIDTH / 2 - 100, 400, 200, 50};
            if (GuiButton(btnBack, "BACK"))
            {
                gameState = MENU;
            }

            break;
        }

        case QUIZ:
        {
            QuizQuestion current = game.GetCurrentQuestion();

            DrawRectangle(645, 25, 150, 30, LIGHTGRAY);
            DrawText(TextFormat("Question %d/%d", game.GetCurrentQuestionIndex() + 1, MAX_QUESTIONS), 650, 30, 20, BLACK);

            DrawText(current.getQuestion().c_str(), 50, 80, 24, BLACK);

            for (int i = 0; i < 4; i++)
            {
                char optionChar = 'a' + i;
                string optionText = string(1, optionChar) + ") " + current.getOption(i);

                Rectangle optionRect = {100, 180 + i * 70, 600, 50};
                if (GuiButton(optionRect, optionText.c_str()))
                {
                    game.RecordAnswer(optionChar);
                    if (!game.AdvanceToNextQuestion())
                    {
                        game.SubmitQuiz();
                        gameState = RESULT;
                    }
                }
            }
            break;
        }

        case RESULT:
        {
            int yPos = 120;
            int correctCount = 0;
            for (int i = 0; i < MAX_QUESTIONS; i++)
            {
                QuizQuestion q = game.GetQuestionAtIndex(i);
                char correctAns = q.getCorrectAnswer();
                char userAns = game.getUserAnswer(i);
                bool isCorrect = (userAns == correctAns);

                if (isCorrect)
                {
                    correctCount++;
                }

                DrawText(TextFormat("Q%d: %s", i + 1, q.getQuestion().c_str()), 50, yPos, 20, BLACK);
                yPos += 30;

                DrawText(TextFormat("Your answer: %c", userAns), 70, yPos, 20, isCorrect ? GREEN : RED);
                if (!isCorrect)
                {
                    DrawText(TextFormat("Correct: %c", correctAns), 250, yPos, 20, GREEN);
                }
                yPos += 40;

                if (i < MAX_QUESTIONS - 1)
                {
                    DrawLine(50, yPos, 750, yPos, LIGHTGRAY);
                    yPos += 20;
                }
            }

            Rectangle continueBtn = {SCREEN_WIDTH / 2 - 100, yPos + 20, 200, 40};
            if (GuiButton(continueBtn, "CONTINUE"))
            {
                gameState = FINALSCORE;
            }

            break;
        }

        case FINALSCORE:
        {
            int highestScore = ScoreManager::getHighestScore("Highestscore.txt");
            int userScore = game.GetScore();
            bool isNewHighScore = (userScore > highestScore);
            game.saveScoreboard("Scoreboard.txt");

            const char *scoreText = TextFormat("SCORE: %d/%d", userScore, MAX_QUESTIONS);
            int scoreWidth = MeasureText(scoreText, 30);
            DrawText(scoreText, SCREEN_WIDTH / 2 - scoreWidth / 2, 100, 30, BLACK);

            const char *feedback;
            if (userScore == MAX_QUESTIONS)
                feedback = "CONGRATULATIONS!! Mastered the subject!!";
            
            else if (userScore > MAX_QUESTIONS / 2)
                feedback = "Almost there!! You can do it!!";
            
            else
                feedback = "No time to waste!! Work harder!!";

        
            int feedbackWidth = MeasureText(feedback, 25);
            DrawText(feedback, SCREEN_WIDTH / 2 - feedbackWidth / 2, 150, 25, (userScore == MAX_QUESTIONS) ? GREEN : BLACK);

            int yPos = 200;

            if (isNewHighScore)
            {
                const char *newHigh = "CONGRATULATIONS!! You have set a new highscore!!";
                int newHighWidth = MeasureText(newHigh, 30);
                DrawText(newHigh, SCREEN_WIDTH / 2 - newHighWidth / 2, yPos, 30, GOLD);
                ScoreManager::updateHighestScore("Highestscore.txt", userScore);
                yPos += 50;
            }

            else if (highestScore == 0 && userScore == 0)
            {
                const char *noHigh = "No high score yet!! Try again!!";
                int noHighWidth = MeasureText(noHigh, 25);
                DrawText(noHigh, SCREEN_WIDTH / 2 - noHighWidth / 2, yPos, 25, GRAY);
                yPos += 40;
            }

            else if (userScore == 0)
            {
                const char *zeroScore = "Oops! You scored 0. Don't worry — keep practicing!";
                int zeroWidth = MeasureText(zeroScore, 25);
                DrawText(zeroScore, SCREEN_WIDTH / 2 - zeroWidth / 2, yPos, 25, GRAY);
                yPos += 40;
            }

            else if (userScore == highestScore)
            {
                const char *matched = TextFormat("Matched the current high score: %d", highestScore);
                int matchedWidth = MeasureText(matched, 25);
                DrawText(matched, SCREEN_WIDTH / 2 - matchedWidth / 2, yPos, 25, GREEN);
                yPos += 40;
            }

            else
            {
                const char *remain = TextFormat("The highest score remains: %d", highestScore);
                int remainWidth = MeasureText(remain, 25);
                DrawText(remain, SCREEN_WIDTH / 2 - remainWidth / 2, yPos, 25, GRAY);
                yPos += 40;
            }

            float buttonWidth = 200;
            float buttonHeight = 50;
            float buttonX = SCREEN_WIDTH / 2 - buttonWidth / 2;
            float backY = SCREEN_HEIGHT - 150;
            float gap = 10;

            Rectangle scoreboardBtn = {buttonX, backY - buttonHeight - gap, buttonWidth, buttonHeight};
            if (GuiButton(scoreboardBtn, "SCOREBOARD"))
            {
                gameState = SCOREBOARD;
            }

            Rectangle backBtn = {buttonX, backY, buttonWidth, buttonHeight};
            if (GuiButton(backBtn, "BACK"))
            {
                game.ResetQuizState();
                gameState = MENU;
            }

            break;
        }

        case SCOREBOARD:
        {
            ifstream file("Scoreboard.txt");
            if (!file)
            {
                const char *errorMsg = "Error 404!! Not Found. Failed to load scores!!";
                int errorWidth = MeasureText(errorMsg, 30);
                DrawText(errorMsg, SCREEN_WIDTH / 2 - errorWidth / 2, 200, 30, RED);

                Rectangle btnMainMenu = {SCREEN_WIDTH / 2 - 75, 350, 150, 50};
                if (GuiButton(btnMainMenu, "MAIN MENU"))
                {
                    gameState = MENU;
                }
                break;
            }

            int yPos = 150;
            int score, count = 0;
            string name;

            while (file >> name >> score)
            {
                DrawText(name.c_str(), SCREEN_WIDTH / 2 - 200, yPos, 20, BLACK);

                const char *scoreText = TextFormat("%d", score);
                int scoreWidth = MeasureText(scoreText, 20);
                DrawText(scoreText, SCREEN_WIDTH / 2 + 200 - scoreWidth, yPos, 20, BLACK);

                DrawRectangle(SCREEN_WIDTH / 2 - 250, yPos + 30, 500, 2, dividerPurple);
                yPos += 40;
                count++;
            }

            file.close();

            if (count > 0)
            {
                const char *footer = TextFormat("Total players: %d", count);
                int footerWidth = MeasureText(footer, 25);
                DrawText(footer, SCREEN_WIDTH / 2 - footerWidth / 2, yPos + 30, 25, BLACK);
            }
            else
            {
                const char *noScores = "No scores recorded yet!!";
                int noScoresWidth = MeasureText(noScores, 30);
                DrawText(noScores, SCREEN_WIDTH / 2 - noScoresWidth / 2, 200, 30, GRAY);
            }

            float btnY = max(yPos + 80, SCREEN_HEIGHT - 100);
            Rectangle btnBack = {SCREEN_WIDTH / 2 - 100, btnY, 200, 50};

            if (GuiButton(btnBack, "BACK"))
            {
                gameState = MENU;
            }

            break;
        }

        case HIGHSCORE:
        {
            int highestScore = ScoreManager::getHighestScore("Highestscore.txt");
            bool scoreExists = (highestScore > 0);

            int yPos = 200;
            if (!scoreExists)
            {
                const char *noScore1 = "No high scores yet!!";
                const char *noScore2 = "Play a quiz to set one!!";

                int width1 = MeasureText(noScore1, 30);
                int width2 = MeasureText(noScore2, 25);

                DrawText(noScore1, SCREEN_WIDTH / 2 - width1 / 2, 200, 30, GRAY);
                DrawText(noScore2, SCREEN_WIDTH / 2 - width2 / 2, 240, 25, LIGHTGRAY);
            }

            else
            {
                const char *scoreText = TextFormat("%d POINTS", highestScore);
                int scoreWidth = MeasureText(scoreText, 40);
                DrawText(scoreText, SCREEN_WIDTH / 2 - scoreWidth / 2, 200, 40, BLACK);

                if (highestScore == MAX_QUESTIONS)
                {
                    const char *perfect = "PERFECT SCORE!!";
                    int perfectWidth = MeasureText(perfect, 30);
                    DrawText(perfect, SCREEN_WIDTH / 2 - perfectWidth / 2, 260, 30, GOLD);
                }
            }

            float btnY = max(yPos + 80, SCREEN_HEIGHT - 100);
            Rectangle btnBack = {SCREEN_WIDTH / 2 - 100, btnY, 200, 50};
            
            if (GuiButton(btnBack, "BACK"))
            {
                gameState = MENU;
            }

            break;
        }

        case EXIT:
        {
            CloseWindow();
            return 0;
            break;
        }
        }

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
