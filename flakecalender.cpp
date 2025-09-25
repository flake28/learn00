#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

enum class AppState {
    MAIN_MENU,
    YEAR_SELECT,
    MONTH_SELECT,
    DAY_SELECT,
    DAY_VIEW
};

struct Event {
    std::string text;
    std::string color;
    Event() : text(""), color("BLUE") {}
    Event(const std::string& t, const std::string& c) : text(t), color(c) {}
};

class Calendar {
private:
    AppState currentState;
    int selectedYear;
    int selectedMonth;
    int selectedDay;
    
    // Event storage: [year][month][day][hour] = Event
    std::map<int, std::map<int, std::map<int, std::map<int, Event>>>> events;
    
    std::vector<std::string> colorOptions = {
        "BLUE", "PURPLE", "CYAN", "GREEN", "YELLOW", "MAGENTA", "RED", "WHITE"
    };
    
    std::vector<std::string> monthNames = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

public:
    Calendar() : currentState(AppState::MAIN_MENU), selectedYear(2025), selectedMonth(1), selectedDay(1) {}
    
    void run() {
        while (true) {
            clearScreen();
            switch (currentState) {
                case AppState::MAIN_MENU:
                    showMainMenu();
                    break;
                case AppState::YEAR_SELECT:
                    showYearSelect();
                    break;
                case AppState::MONTH_SELECT:
                    showMonthSelect();
                    break;
                case AppState::DAY_SELECT:
                    showDaySelect();
                    break;
                case AppState::DAY_VIEW:
                    showDayView();
                    break;
            }
        }
    }

private:
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    
    void setColor(const std::string& color) {
        #ifdef _WIN32
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int colorCode = 7; // Default white
            if (color == "BLUE") colorCode = 9;
            else if (color == "PURPLE") colorCode = 13;
            else if (color == "CYAN") colorCode = 11;
            else if (color == "GREEN") colorCode = 10;
            else if (color == "YELLOW") colorCode = 14;
            else if (color == "MAGENTA") colorCode = 13;
            else if (color == "RED") colorCode = 12;
            else if (color == "WHITE") colorCode = 15;
            SetConsoleTextAttribute(hConsole, colorCode);
        #else
            // ANSI color codes for Unix/Linux/Mac
            if (color == "BLUE") std::cout << "\033[94m";
            else if (color == "PURPLE") std::cout << "\033[95m";
            else if (color == "CYAN") std::cout << "\033[96m";
            else if (color == "GREEN") std::cout << "\033[92m";
            else if (color == "YELLOW") std::cout << "\033[93m";
            else if (color == "MAGENTA") std::cout << "\033[95m";
            else if (color == "RED") std::cout << "\033[91m";
            else if (color == "WHITE") std::cout << "\033[97m";
        #endif
    }
    
    void resetColor() {
        #ifdef _WIN32
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 7);
        #else
            std::cout << "\033[0m";
        #endif
    }
    
    void showMainMenu() {
        setColor("PURPLE");
        std::cout << "\n\n";
        std::cout << "  ███████╗██╗      █████╗ ██╗  ██╗███████╗██╗███████╗\n";
        std::cout << "  ██╔════╝██║     ██╔══██╗██║ ██╔╝██╔════╝██║██╔════╝\n";
        std::cout << "  █████╗  ██║     ███████║█████╔╝ █████╗  ██║███████╗\n";
        std::cout << "  ██╔══╝  ██║     ██╔══██║██╔═██╗ ██╔══╝  ██║╚════██║\n";
        std::cout << "  ██║     ███████╗██║  ██║██║  ██╗███████╗██║███████║\n";
        std::cout << "  ╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝╚══════╝\n";
        resetColor();
        
        setColor("CYAN");
        std::cout << "\n           ██████╗ █████╗ ██╗     ███████╗███╗   ██╗██████╗  █████╗ ██████╗ \n";
        std::cout << "          ██╔════╝██╔══██╗██║     ██╔════╝████╗  ██║██╔══██╗██╔══██╗██╔══██╗\n";
        std::cout << "          ██║     ███████║██║     █████╗  ██╔██╗ ██║██║  ██║███████║██████╔╝\n";
        std::cout << "          ██║     ██╔══██║██║     ██╔══╝  ██║╚██╗██║██║  ██║██╔══██║██╔══██╗\n";
        std::cout << "          ╚██████╗██║  ██║███████╗███████╗██║ ╚████║██████╔╝██║  ██║██║  ██║\n";
        std::cout << "           ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝\n";
        resetColor();
        
        std::cout << "\n\n";
        setColor("WHITE");
        std::cout << "                                Welcome to Flake's Calendar!\n";
        std::cout << "                              Your personal scheduling companion\n\n";
        resetColor();
        
        setColor("BLUE");
        std::cout << "                                    [1] Enter Calendar\n";
        std::cout << "                                    [0] Exit\n\n";
        resetColor();
        
        std::cout << "                                    Choose an option: ";
        
        int choice;
        std::cin >> choice;
        
        if (choice == 1) {
            currentState = AppState::YEAR_SELECT;
        } else if (choice == 0) {
            exit(0);
        }
    }
    
    void showYearSelect() {
        setColor("PURPLE");
        std::cout << "\n                               ╔═══════════════════════════╗\n";
        std::cout << "                               ║      SELECT YEAR          ║\n";
        std::cout << "                               ╚═══════════════════════════╝\n\n";
        resetColor();
        
        setColor("CYAN");
        std::cout << "                                     Current Year: " << selectedYear << "\n\n";
        resetColor();
        
        setColor("BLUE");
        std::cout << "                                  [1] Continue with 2025\n";
        std::cout << "                                  [2] Change Year\n";
        std::cout << "                                  [0] Back to Main Menu\n\n";
        resetColor();
        
        std::cout << "                                  Choose an option: ";
        
        int choice;
        std::cin >> choice;
        
        if (choice == 1) {
            currentState = AppState::MONTH_SELECT;
        } else if (choice == 2) {
            std::cout << "\n                                  Enter year: ";
            std::cin >> selectedYear;
            currentState = AppState::MONTH_SELECT;
        } else if (choice == 0) {
            currentState = AppState::MAIN_MENU;
        }
    }
    
    void showMonthSelect() {
        setColor("PURPLE");
        std::cout << "\n                               ╔═══════════════════════════╗\n";
        std::cout << "                               ║     SELECT MONTH " << selectedYear << "      ║\n";
        std::cout << "                               ╚═══════════════════════════╝\n\n";
        resetColor();
        
        // Display months in a 4x3 grid
        for (int i = 1; i <= 12; i++) {
            if ((i - 1) % 4 == 0) std::cout << "        ";
            
            setColor("BLUE");
            std::cout << "[" << std::setw(2) << i << "] " << std::setw(12) << std::left << monthNames[i];
            resetColor();
            
            if (i % 4 == 0) std::cout << "\n";
        }
        
        std::cout << "\n\n";
        setColor("CYAN");
        std::cout << "                                  [0] Back to Year Selection\n\n";
        resetColor();
        
        std::cout << "                                  Choose month (1-12): ";
        
        int choice;
        std::cin >> choice;
        
        if (choice >= 1 && choice <= 12) {
            selectedMonth = choice;
            currentState = AppState::DAY_SELECT;
        } else if (choice == 0) {
            currentState = AppState::YEAR_SELECT;
        }
    }
    
    void showDaySelect() {
        setColor("PURPLE");
        std::cout << "\n                        ╔════════════════════════════════════════╗\n";
        std::cout << "                        ║    " << monthNames[selectedMonth] << " " << selectedYear << " - SELECT DAY        ║\n";
        std::cout << "                        ╚════════════════════════════════════════╝\n\n";
        resetColor();
        
        int daysInMonth = getDaysInMonth(selectedMonth, selectedYear);
        
        // Display days in a 7-day week format
        std::cout << "        Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
        std::cout << "        ─────────────────────────────────────\n";
        
        int startDay = 1; // Simplified - you could calculate actual day of week
        int currentDay = 1;
        
        // Print calendar grid
        for (int week = 0; week < 6 && currentDay <= daysInMonth; week++) {
            std::cout << "        ";
            for (int day = 0; day < 7 && currentDay <= daysInMonth; day++) {
                if (hasEventsOnDay(currentDay)) {
                    setColor("YELLOW");
                    std::cout << "[" << std::setw(2) << currentDay << "]";
                    resetColor();
                } else {
                    setColor("CYAN");
                    std::cout << " " << std::setw(2) << currentDay << " ";
                    resetColor();
                }
                std::cout << " ";
                currentDay++;
            }
            std::cout << "\n";
        }
        
        std::cout << "\n";
        setColor("YELLOW");
        std::cout << "        [##] = Days with events\n\n";
        resetColor();
        
        setColor("BLUE");
        std::cout << "                                  [0] Back to Month Selection\n\n";
        resetColor();
        
        std::cout << "                                  Choose day (1-" << daysInMonth << "): ";
        
        int choice;
        std::cin >> choice;
        
        if (choice >= 1 && choice <= daysInMonth) {
            selectedDay = choice;
            currentState = AppState::DAY_VIEW;
        } else if (choice == 0) {
            currentState = AppState::MONTH_SELECT;
        }
    }
    
    void showDayView() {
        setColor("PURPLE");
        std::cout << "\n              ╔══════════════════════════════════════════════════════════╗\n";
        std::cout << "              ║         " << monthNames[selectedMonth] << " " << selectedDay << ", " << selectedYear << " - DAILY SCHEDULE           ║\n";
        std::cout << "              ╚══════════════════════════════════════════════════════════╝\n\n";
        resetColor();
        
        // Display 24-hour schedule
        for (int hour = 0; hour < 24; hour++) {
            std::cout << "   ";
            setColor("CYAN");
            std::cout << std::setw(2) << std::setfill('0') << hour << ":00";
            resetColor();
            std::cout << " │ ";
            
            Event& event = events[selectedYear][selectedMonth][selectedDay][hour];
            if (!event.text.empty()) {
                setColor(event.color);
                std::cout << event.text;
                resetColor();
            } else {
                setColor("WHITE");
                std::cout << "(empty)";
                resetColor();
            }
            std::cout << "\n";
        }
        
        std::cout << "\n";
        setColor("BLUE");
        std::cout << "                           [1] Add/Edit Event for Specific Hour\n";
        std::cout << "                           [2] Delete Event\n";
        std::cout << "                           [0] Back to Day Selection\n\n";
        resetColor();
        
        std::cout << "                           Choose option: ";
        
        int choice;
        std::cin >> choice;
        
        if (choice == 1) {
            addEditEvent();
        } else if (choice == 2) {
            deleteEvent();
        } else if (choice == 0) {
            currentState = AppState::DAY_SELECT;
        }
    }
    
    void addEditEvent() {
        std::cout << "\nEnter hour (0-23): ";
        int hour;
        std::cin >> hour;
        
        if (hour < 0 || hour > 23) {
            std::cout << "Invalid hour! Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            return;
        }
        
        std::cin.ignore(); // Clear input buffer
        
        std::cout << "Enter event text: ";
        std::string eventText;
        std::getline(std::cin, eventText);
        
        std::cout << "\nChoose color:\n";
        for (size_t i = 0; i < colorOptions.size(); i++) {
            setColor(colorOptions[i]);
            std::cout << "[" << (i + 1) << "] " << colorOptions[i] << "  ";
            resetColor();
            if ((i + 1) % 4 == 0) std::cout << "\n";
        }
        
        std::cout << "\nChoose color (1-" << colorOptions.size() << "): ";
        int colorChoice;
        std::cin >> colorChoice;
        
        if (colorChoice >= 1 && colorChoice <= (int)colorOptions.size()) {
            events[selectedYear][selectedMonth][selectedDay][hour] = Event(eventText, colorOptions[colorChoice - 1]);
            std::cout << "\nEvent saved! Press any key to continue...";
        } else {
            std::cout << "\nInvalid color choice! Press any key to continue...";
        }
        
        std::cin.ignore();
        std::cin.get();
    }
    
    void deleteEvent() {
        std::cout << "\nEnter hour to delete (0-23): ";
        int hour;
        std::cin >> hour;
        
        if (hour >= 0 && hour <= 23) {
            events[selectedYear][selectedMonth][selectedDay][hour] = Event();
            std::cout << "\nEvent deleted! Press any key to continue...";
        } else {
            std::cout << "\nInvalid hour! Press any key to continue...";
        }
        
        std::cin.ignore();
        std::cin.get();
    }
    
    bool hasEventsOnDay(int day) {
        for (int hour = 0; hour < 24; hour++) {
            if (!events[selectedYear][selectedMonth][day][hour].text.empty()) {
                return true;
            }
        }
        return false;
    }
    
    int getDaysInMonth(int month, int year) {
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear(year)) {
            return 29;
        }
        return daysInMonth[month - 1];
    }
    
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main() {
    std::cout << "Loading Flake's Calendar...\n";
    std::cout << "Please ensure your terminal supports colors for the best experience!\n";
    std::cout << "Press any key to start...";
    std::cin.get();
    
    Calendar app;
    app.run();
    
    return 0;
}