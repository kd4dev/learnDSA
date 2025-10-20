#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_USERS 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 50
#define LOGIN_FILE "login.txt"

#define MAX_COINS 100
#define NAME_LEN 50
#define SYMBOL_LEN 10
#define HISTORY 5
#define FILENAME "portfolio.dat"
#define EXPORT_FILE "portfolio_export.txt"

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define CLEAR "cls"
#define SLEEP(seconds) Sleep((seconds)*1000)
#else
#include <termios.h>
#include <unistd.h>
#define CLEAR "clear"
#define SLEEP(seconds) sleep(seconds)
#endif

// Modern color definitions
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"
#ifdef _WIN32
    #define strcasecmp _stricmp
#endif

typedef struct {
    char name[NAME_LEN];
    char symbol[SYMBOL_LEN];
    float quantity;
    float price;
    float history[HISTORY];
    int historyCount;
} Coin;

Coin portfolio[MAX_COINS];
int coinCount = 0;
char currentUser[USERNAME_LEN];

// Function prototypes
void clearScreen();
void showHeader();
void addCoin();
void viewPortfolio();
void updatePrices();
void calculateTotalValue();
void savePortfolio();
void loadPortfolio();
void exportPortfolio();
void searchCoin();
void simulatePrices();
void deleteCoin();
void viewGraph();
void updateQuantity();
void about();
void registerUser();
int login();
void printCentered(const char* text);
void printMenuOption(int num, const char* option);
void drawHorizontalLine(int length);
void getPassword(char* password);
void printSuccess(const char* message);
void printError(const char* message);
void printWarning(const char* message);
void printInfo(const char* message);

// Utility functions
void clearScreen() {
    system(CLEAR);
}

void drawHorizontalLine(int length) {
    printf(BOLD BLUE);
    for(int i = 0; i < length; i++) printf("─");
    printf(RESET "\n");
}

void printCentered(const char* text) {
    int terminalWidth = 80; // Default width
    printf("%*s%s%*s\n", (terminalWidth - strlen(text)) / 2, "", text, (terminalWidth - strlen(text)) / 2, "");
}

void printMenuOption(int num, const char* option) {
    printf(BOLD " %2d. " RESET "%s\n", num, option);
}

void printSuccess(const char* message) {
    printf(BOLD GREEN "✓ %s" RESET "\n", message);
}

void printError(const char* message) {
    printf(BOLD RED "✗ %s" RESET "\n", message);
}

void printWarning(const char* message) {
    printf(BOLD YELLOW "⚠ %s" RESET "\n", message);
}

void printInfo(const char* message) {
    printf(BOLD CYAN "ℹ %s" RESET "\n", message);
}

void getPassword(char* password) {
    #ifdef _WIN32
    char ch;
    int i = 0;
    while ((ch = _getch()) != 13) { // 13 is Enter
        if (ch == 8) { // Backspace
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
    printf("\n");
    #else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    scanf("%s", password);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
    #endif
}

void showHeader() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    clearScreen();
    printf(BOLD BLUE);
    drawHorizontalLine(80);
    printCentered("░█████╗░██████╗░██╗░░░██╗██████╗░████████╗░█████╗░░█████╗░██╗░░██╗███████╗██████╗░");
    printCentered("██╔══██╗██╔══██╗╚██╗░██╔╝██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗██║░██╔╝██╔════╝██╔══██╗");
    printCentered("██║░░╚═╝██████╔╝░╚████╔╝░██████╔╝░░░██║░░░██║░░██║██║░░╚═╝█████═╝░█████╗░░██████╔╝");
    printCentered("██║░░██╗██╔══██╗░░╚██╔╝░░██╔═══╝░░░░██║░░░██║░░██║██║░░██╗██╔═██╗░██╔══╝░░██╔══██╗");
    printCentered("╚█████╔╝██║░░██║░░░██║░░░██║░░░░░░░░██║░░░╚█████╔╝╚█████╔╝██║░╚██╗███████╗██║░░██║");
    printCentered("░╚════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░░░░░░░╚═╝░░░░╚════╝░░╚════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝");
    printf(BOLD WHITE);
    printCentered("Your Personal Cryptocurrency Portfolio Tracker");
    printf(BOLD MAGENTA);
    printf("%*sLogged in as: %s\n", 60, "", currentUser);
    printf(BOLD YELLOW);
    printf("%*sDate: %04d-%02d-%02d %02d:%02d:%02d\n", 60, "",
           tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
           tm.tm_hour, tm.tm_min, tm.tm_sec);
    drawHorizontalLine(80);
    printf(RESET);
}

// Core functions
int login() {
    char username[USERNAME_LEN], password[PASSWORD_LEN];
    char storedUsername[USERNAME_LEN], storedPassword[PASSWORD_LEN];

    FILE *fp = fopen(LOGIN_FILE, "r");
    if (!fp) {
        printError("Could not open login database");
        return 0;
    }

    clearScreen();
    printf(BOLD BLUE);
    printCentered("╔════════════════════════════╗");
    printCentered("║      USER LOGIN PORTAL     ║");
    printCentered("╚════════════════════════════╝");
    printf(RESET);
    
    printf("\n" BOLD "Username: " RESET);
    scanf("%s", username);
    printf(BOLD "Password: " RESET);
    getPassword(password);

    int success = 0;
    while (fscanf(fp, "%s %s", storedUsername, storedPassword) == 2) {
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            strcpy(currentUser, username);
            success = 1;
            break;
        }
    }
    fclose(fp);

    if (success) {
        printSuccess("Login successful! Loading your portfolio...");
        SLEEP(2);
        return 1;
    } else {
        printError("Invalid credentials. Access denied.");
        SLEEP(1);
        return 0;
    }
}

void registerUser() {
    char username[USERNAME_LEN], password[PASSWORD_LEN], confirm[PASSWORD_LEN];

    clearScreen();
    printf(BOLD BLUE);
    printCentered("╔════════════════════════════╗");
    printCentered("║     USER REGISTRATION      ║");
    printCentered("╚════════════════════════════╝");
    printf(RESET);
    
    printf("\n" BOLD "Choose a Username: " RESET);
    scanf("%s", username);
    
    if(strlen(username) < 4) {
        printError("Username must be at least 4 characters");
        return;
    }
    
    char existingUsername[USERNAME_LEN], existingPassword[PASSWORD_LEN];
    FILE *fp = fopen(LOGIN_FILE, "r");
    if (fp) {
        while (fscanf(fp, "%s %s", existingUsername, existingPassword) != EOF) {
            if (strcmp(existingUsername, username) == 0) {
                fclose(fp);
                printError("Username already exists. Try a different one.");
                return;
            }
        }
        fclose(fp);
    }

    printf(BOLD "Choose a Password: " RESET);
    getPassword(password);
    
    if(strlen(password) < 6) {
        printError("Password must be at least 6 characters");
        return;
    }
    
    printf(BOLD "Confirm Password: " RESET);
    getPassword(confirm);
    
    if(strcmp(password, confirm) != 0) {
        printError("Passwords do not match!");
        return;
    }

    fp = fopen(LOGIN_FILE, "a");
    if (!fp) {
        printError("Could not open login database");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);
    printSuccess("Registration successful! You can now log in.");
    SLEEP(2);
}

void loadPortfolio() {
    char filename[100];
    sprintf(filename, "%s_portfolio.dat", currentUser);

    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    coinCount = 0;
    Coin c;
    while (fscanf(fp, "%s %s %f %f %d",
                  c.name, c.symbol, &c.quantity, &c.price, &c.historyCount) == 5) {
        for (int j = 0; j < c.historyCount; j++)
            fscanf(fp, "%f", &c.history[j]);
        portfolio[coinCount++] = c;
    }
    fclose(fp);
}

void savePortfolio() {
    char filename[100];
    sprintf(filename, "%s_portfolio.dat", currentUser);

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printError("Could not save portfolio");
        return;
    }

    for (int i = 0; i < coinCount; i++) {
        fprintf(fp, "%s %s %f %f %d ",
                portfolio[i].name, portfolio[i].symbol,
                portfolio[i].quantity, portfolio[i].price,
                portfolio[i].historyCount);
        for (int j = 0; j < portfolio[i].historyCount; j++)
            fprintf(fp, "%f ", portfolio[i].history[j]);
        fprintf(fp, "\n");
    }

    fclose(fp);
    printSuccess("Portfolio saved successfully");
}

void addCoin() {
    if (coinCount >= MAX_COINS) {
        printError("Portfolio is full");
        return;
    }

    Coin c;
    printf(BOLD BLUE "\n[ Add New Coin ]\n\n" RESET);
    printf("Coin Name    : ");
    scanf("%s", c.name);
    printf("Coin Symbol  : ");
    scanf("%s", c.symbol);

    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(portfolio[i].name, c.name) == 0 || strcasecmp(portfolio[i].symbol, c.symbol) == 0) {
            printError("A coin with this name or symbol already exists");
            return;
        }
    }

    printf("Quantity     : ");
    scanf("%f", &c.quantity);
    c.price = 0.0;
    c.historyCount = 0;
    portfolio[coinCount++] = c;
    printSuccess("Coin added successfully");
}

void viewPortfolio() {
    if (coinCount == 0) {
        printInfo("Your portfolio is empty");
        return;
    }
    
    printf(BOLD BLUE "\n[ Your Portfolio ]\n\n" RESET);
    printf(BOLD "%-20s %-10s %-12s %-12s %-12s\n" RESET, 
           "Coin Name", "Symbol", "Quantity", "Price", "Value");
    drawHorizontalLine(80);
    
    float totalValue = 0;
    for (int i = 0; i < coinCount; i++) {
        float value = portfolio[i].quantity * portfolio[i].price;
        totalValue += value;
        
        const char* color = value > 1000 ? GREEN : (value > 100 ? YELLOW : RED);
        
        printf("%-20s %-10s %-12.2f " BOLD "%s$%-12.2f%s $%-12.2f\n" RESET,
               portfolio[i].name,
               portfolio[i].symbol,
               portfolio[i].quantity,
               color,
               portfolio[i].price,
               RESET,
               value);
    }
    
    drawHorizontalLine(80);
    printf(BOLD "Total Portfolio Value: " GREEN "$%.2f\n" RESET, totalValue);
}

void updatePrices() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char input[NAME_LEN];
    printf(BOLD BLUE "\n[ Update Coin Prices ]\n\n" RESET);
    printf("Enter coin name/symbol (or 'done' to finish):\n");

    while (1) {
        printf("Coin: ");
        scanf("%s", input);

        if (strcasecmp(input, "done") == 0) break;

        int found = 0;
        for (int i = 0; i < coinCount; i++) {
            if (strcasecmp(input, portfolio[i].symbol) == 0 || strcasecmp(input, portfolio[i].name) == 0) {
                printf("New price for %s (%s): $", portfolio[i].name, portfolio[i].symbol);
                scanf("%f", &portfolio[i].price);

                if (portfolio[i].historyCount < HISTORY)
                    portfolio[i].history[portfolio[i].historyCount++] = portfolio[i].price;
                else {
                    for (int j = 1; j < HISTORY; j++)
                        portfolio[i].history[j - 1] = portfolio[i].history[j];
                    portfolio[i].history[HISTORY - 1] = portfolio[i].price;
                }

                printSuccess("Price updated");
                found = 1;
                break;
            }
        }

        if (!found) printError("Coin not found");
    }
}

void calculateTotalValue() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    float total = 0.0;
    printf(BOLD BLUE "\n[ Portfolio Value ]\n\n" RESET);
    for (int i = 0; i < coinCount; i++) {
        float value = portfolio[i].quantity * portfolio[i].price;
        printf("%-20s (%s): $%.2f\n", portfolio[i].name, portfolio[i].symbol, value);
        total += value;
    }
    printf(BOLD "\nTotal Value: " GREEN "$%.2f\n" RESET, total);
}

void exportPortfolio() {
    FILE *fp = fopen(EXPORT_FILE, "w");
    if (!fp) {
        printError("Could not export portfolio");
        return;
    }
    
    fprintf(fp, "CryptoTracker Portfolio Export\n\n");
    for (int i = 0; i < coinCount; i++) {
        float value = portfolio[i].quantity * portfolio[i].price;
        fprintf(fp, "%s (%s): %.2f units @ $%.2f = $%.2f\n",
                portfolio[i].name, portfolio[i].symbol,
                portfolio[i].quantity, portfolio[i].price, value);
    }
    fclose(fp);
    printSuccess("Portfolio exported to 'portfolio_export.txt'");
}

void searchCoin() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char query[NAME_LEN];
    printf(BOLD BLUE "\n[ Search Coin ]\n\n" RESET);
    printf("Enter coin name/symbol: ");
    scanf("%s", query);
    
    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(query, portfolio[i].name) == 0 || strcasecmp(query, portfolio[i].symbol) == 0) {
            float value = portfolio[i].quantity * portfolio[i].price;
            printf("\nFound: %s (%s)\n", portfolio[i].name, portfolio[i].symbol);
            printf("Quantity: %.2f\n", portfolio[i].quantity);
            printf("Price: $%.2f\n", portfolio[i].price);
            printf("Value: $%.2f\n", value);
            return;
        }
    }
    printError("Coin not found");
}

void simulatePrices() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    srand(time(NULL));
    printf(BOLD BLUE "\n[ Simulate Price Changes ]\n\n" RESET);
    for (int i = 0; i < coinCount; i++) {
        float change = ((rand() % 2001) - 1000) / 100.0f; // -10% to +10%
        float oldPrice = portfolio[i].price;
        portfolio[i].price += (portfolio[i].price * (change / 100));

        if (portfolio[i].historyCount < HISTORY)
            portfolio[i].history[portfolio[i].historyCount++] = portfolio[i].price;
        else {
            for (int j = 1; j < HISTORY; j++)
                portfolio[i].history[j - 1] = portfolio[i].history[j];
            portfolio[i].history[HISTORY - 1] = portfolio[i].price;
        }

        const char* color = change > 0 ? GREEN : RED;
        printf("%s (%s): $%.2f → " BOLD "%s$%.2f (%.2f%%)\n" RESET,
               portfolio[i].name,
               portfolio[i].symbol,
               oldPrice,
               color,
               portfolio[i].price,
               change);
    }
}

void viewGraph() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char query[SYMBOL_LEN];
    printf(BOLD BLUE "\n[ View Price Graph ]\n\n" RESET);
    printf("Enter coin symbol: ");
    scanf("%s", query);
    
    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(query, portfolio[i].symbol) == 0) {
            printf("\n%s (%s) - Price History\n", portfolio[i].name, portfolio[i].symbol);
            for (int j = 0; j < portfolio[i].historyCount; j++) {
                printf("$%-6.2f | ", portfolio[i].history[j]);
                int bars = (int)(portfolio[i].history[j] / 10);
                for (int k = 0; k < bars; k++) printf("█");
                printf("\n");
            }
            return;
        }
    }
    printError("Coin not found");
}

void updateQuantity() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char symbol[SYMBOL_LEN];
    printf(BOLD BLUE "\n[ Update Quantity ]\n\n" RESET);
    printf("Enter coin symbol: ");
    scanf("%s", symbol);

    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(symbol, portfolio[i].symbol) == 0) {
            float newQty;
            printf("Current quantity of %s (%s): %.2f\n",
                   portfolio[i].name, portfolio[i].symbol, portfolio[i].quantity);
            printf("Enter new quantity: ");
            scanf("%f", &newQty);

            portfolio[i].quantity = newQty;
            printSuccess("Quantity updated");
            return;
        }
    }
    printError("Coin not found");
}

void deleteCoin() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char target[NAME_LEN];
    printf(BOLD BLUE "\n[ Delete Coin ]\n\n" RESET);
    printf("Enter coin name/symbol: ");
    scanf("%s", target);

    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(target, portfolio[i].name) == 0 || strcasecmp(target, portfolio[i].symbol) == 0) {
            for (int j = i; j < coinCount - 1; j++) {
                portfolio[j] = portfolio[j + 1];
            }
            coinCount--;
            printSuccess("Coin deleted");
            return;
        }
    }
    printError("Coin not found");
}

void about() {
    printf(BOLD BLUE "\n[ About CryptoTracker ]\n\n" RESET);
    printf("CryptoTracker is a terminal-based cryptocurrency portfolio manager\n");
    printf("Features include:\n");
    printf("- Track multiple cryptocurrencies\n");
    printf("- View price history graphs\n");
    printf("- Simulate market changes\n");
    printf("- Export your portfolio data\n");
    printf("\nVersion: 3.0\n");
}

// Main function
int main() {
    int choice;
    
    while (1) {
        clearScreen();
        printf(BOLD BLUE);
        printCentered("╔════════════════════════════╗");
        printCentered("║    CRYPTOTRACKER v3.0     ║");
        printCentered("╚════════════════════════════╝");
        printf(RESET);
        
        printf("\n");
        printMenuOption(1, "Login");
        printMenuOption(2, "Register");
        printMenuOption(3, "Exit");
        
        printf("\n" BOLD "Enter your choice: " RESET);
        scanf("%d", &choice);

        if (choice == 1) {
            if (login()) break;
        } else if (choice == 2) {
            registerUser();
        } else if (choice == 3) {
            printf(BOLD "\nThank you for using CryptoTracker!\n" RESET);
            exit(0);
        } else {
            printError("Invalid choice");
            SLEEP(1);
        }
    }

    loadPortfolio();

    while (1) {
        showHeader();
        
        printf("\n" BOLD BLUE "MAIN MENU\n" RESET);
        printMenuOption(1, "Add Cryptocurrency");
        printMenuOption(2, "View Portfolio");
        printMenuOption(3, "Update Prices");
        printMenuOption(4, "Calculate Total Value");
        printMenuOption(5, "Search Coin");
        printMenuOption(6, "Simulate Price Changes");
        printMenuOption(7, "Export Portfolio");
        printMenuOption(8, "View Price Graph");
        printMenuOption(9, "Update Quantity");
        printMenuOption(10, "Delete Coin");
        printMenuOption(11, "About");
        printMenuOption(12, "Save & Exit");
        
        printf("\n" BOLD "Enter your choice: " RESET);
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addCoin(); break;
            case 2: viewPortfolio(); break;
            case 3: updatePrices(); break;
            case 4: calculateTotalValue(); break;
            case 5: searchCoin(); break;
            case 6: simulatePrices(); break;
            case 7: exportPortfolio(); break;
            case 8: viewGraph(); break;
            case 9: updateQuantity(); break;
            case 10: deleteCoin(); break;
            case 11: about(); break;
            case 12: savePortfolio(); 
                    printSuccess("Goodbye!");
                    exit(0);
            default: printError("Invalid choice");
        }
        
        printf("\nPress Enter to continue...");
        getchar(); getchar();
    }

    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_USERS 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 50
#define LOGIN_FILE "login.txt"

#define MAX_COINS 100
#define NAME_LEN 50
#define SYMBOL_LEN 10
#define HISTORY 5
#define FILENAME "portfolio.dat"
#define EXPORT_FILE "portfolio_export.txt"

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define CLEAR "cls"
#define SLEEP(seconds) Sleep((seconds)*1000)
#else
#include <termios.h>
#include <unistd.h>
#define CLEAR "clear"
#define SLEEP(seconds) sleep(seconds)
#endif

// Modern color definitions
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

typedef struct {
    char name[NAME_LEN];
    char symbol[SYMBOL_LEN];
    float quantity;
    float price;
    float history[HISTORY];
    int historyCount;
} Coin;

Coin portfolio[MAX_COINS];
int coinCount = 0;
char currentUser[USERNAME_LEN];

// Function prototypes
void clearScreen();
void showHeader();
void addCoin();
void viewPortfolio();
void updatePrices();
void calculateTotalValue();
void savePortfolio();
void loadPortfolio();
void exportPortfolio();
void searchCoin();
void simulatePrices();
void deleteCoin();
void viewGraph();
void updateQuantity();
void about();
void registerUser();
int login();
void printCentered(const char* text);
void printMenuOption(int num, const char* option);
void drawHorizontalLine(int length);
void getPassword(char* password);
void printSuccess(const char* message);
void printError(const char* message);
void printWarning(const char* message);
void printInfo(const char* message);

// Utility functions
void clearScreen() {
    system(CLEAR);
}

void drawHorizontalLine(int length) {
    printf(BOLD BLUE);
    for(int i = 0; i < length; i++) printf("─");
    printf(RESET "\n");
}

void printCentered(const char* text) {
    int terminalWidth = 80; // Default width
    printf("%*s%s%*s\n", (terminalWidth - strlen(text)) / 2, "", text, (terminalWidth - strlen(text)) / 2, "");
}

void printMenuOption(int num, const char* option) {
    printf(BOLD " %2d. " RESET "%s\n", num, option);
}

void printSuccess(const char* message) {
    printf(BOLD GREEN "✓ %s" RESET "\n", message);
}

void printError(const char* message) {
    printf(BOLD RED "✗ %s" RESET "\n", message);
}

void printWarning(const char* message) {
    printf(BOLD YELLOW "⚠ %s" RESET "\n", message);
}

void printInfo(const char* message) {
    printf(BOLD CYAN "ℹ %s" RESET "\n", message);
}

void getPassword(char* password) {
    #ifdef _WIN32
    char ch;
    int i = 0;
    while ((ch = _getch()) != 13) { // 13 is Enter
        if (ch == 8) { // Backspace
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
    printf("\n");
    #else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    scanf("%s", password);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
    #endif
}

void showHeader() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    clearScreen();
    printf(BOLD BLUE);
    drawHorizontalLine(80);
    printCentered("░█████╗░██████╗░██╗░░░██╗██████╗░████████╗░█████╗░░█████╗░██╗░░██╗███████╗██████╗░");
    printCentered("██╔══██╗██╔══██╗╚██╗░██╔╝██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗██║░██╔╝██╔════╝██╔══██╗");
    printCentered("██║░░╚═╝██████╔╝░╚████╔╝░██████╔╝░░░██║░░░██║░░██║██║░░╚═╝█████═╝░█████╗░░██████╔╝");
    printCentered("██║░░██╗██╔══██╗░░╚██╔╝░░██╔═══╝░░░░██║░░░██║░░██║██║░░██╗██╔═██╗░██╔══╝░░██╔══██╗");
    printCentered("╚█████╔╝██║░░██║░░░██║░░░██║░░░░░░░░██║░░░╚█████╔╝╚█████╔╝██║░╚██╗███████╗██║░░██║");
    printCentered("░╚════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░░░░░░░╚═╝░░░░╚════╝░░╚════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝");
    printf(BOLD WHITE);
    printCentered("Your Personal Cryptocurrency Portfolio Tracker");
    printf(BOLD MAGENTA);
    printf("%*sLogged in as: %s\n", 60, "", currentUser);
    printf(BOLD YELLOW);
    printf("%*sDate: %04d-%02d-%02d %02d:%02d:%02d\n", 60, "",
           tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
           tm.tm_hour, tm.tm_min, tm.tm_sec);
    drawHorizontalLine(80);
    printf(RESET);
}

// Core functions
int login() {
    char username[USERNAME_LEN], password[PASSWORD_LEN];
    char storedUsername[USERNAME_LEN], storedPassword[PASSWORD_LEN];

    FILE *fp = fopen(LOGIN_FILE, "r");
    if (!fp) {
        printError("Could not open login database");
        return 0;
    }

    clearScreen();
    printf(BOLD BLUE);
    printCentered("╔════════════════════════════╗");
    printCentered("║      USER LOGIN PORTAL     ║");
    printCentered("╚════════════════════════════╝");
    printf(RESET);
    
    printf("\n" BOLD "Username: " RESET);
    scanf("%s", username);
    printf(BOLD "Password: " RESET);
    getPassword(password);

    int success = 0;
    while (fscanf(fp, "%s %s", storedUsername, storedPassword) == 2) {
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            strcpy(currentUser, username);
            success = 1;
            break;
        }
    }
    fclose(fp);

    if (success) {
        printSuccess("Login successful! Loading your portfolio...");
        SLEEP(2);
        return 1;
    } else {
        printError("Invalid credentials. Access denied.");
        SLEEP(1);
        return 0;
    }
}

void registerUser() {
    char username[USERNAME_LEN], password[PASSWORD_LEN], confirm[PASSWORD_LEN];

    clearScreen();
    printf(BOLD BLUE);
    printCentered("╔════════════════════════════╗");
    printCentered("║     USER REGISTRATION      ║");
    printCentered("╚════════════════════════════╝");
    printf(RESET);
    
    printf("\n" BOLD "Choose a Username: " RESET);
    scanf("%s", username);
    
    if(strlen(username) < 4) {
        printError("Username must be at least 4 characters");
        return;
    }
    
    char existingUsername[USERNAME_LEN], existingPassword[PASSWORD_LEN];
    FILE *fp = fopen(LOGIN_FILE, "r");
    if (fp) {
        while (fscanf(fp, "%s %s", existingUsername, existingPassword) != EOF) {
            if (strcmp(existingUsername, username) == 0) {
                fclose(fp);
                printError("Username already exists. Try a different one.");
                return;
            }
        }
        fclose(fp);
    }

    printf(BOLD "Choose a Password: " RESET);
    getPassword(password);
    
    if(strlen(password) < 6) {
        printError("Password must be at least 6 characters");
        return;
    }
    
    printf(BOLD "Confirm Password: " RESET);
    getPassword(confirm);
    
    if(strcmp(password, confirm) != 0) {
        printError("Passwords do not match!");
        return;
    }

    fp = fopen(LOGIN_FILE, "a");
    if (!fp) {
        printError("Could not open login database");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);
    printSuccess("Registration successful! You can now log in.");
    SLEEP(2);
}

void loadPortfolio() {
    char filename[100];
    sprintf(filename, "%s_portfolio.dat", currentUser);

    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    coinCount = 0;
    Coin c;
    while (fscanf(fp, "%s %s %f %f %d",
                  c.name, c.symbol, &c.quantity, &c.price, &c.historyCount) == 5) {
        for (int j = 0; j < c.historyCount; j++)
            fscanf(fp, "%f", &c.history[j]);
        portfolio[coinCount++] = c;
    }
    fclose(fp);
}

void savePortfolio() {
    char filename[100];
    sprintf(filename, "%s_portfolio.dat", currentUser);

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printError("Could not save portfolio");
        return;
    }

    for (int i = 0; i < coinCount; i++) {
        fprintf(fp, "%s %s %f %f %d ",
                portfolio[i].name, portfolio[i].symbol,
                portfolio[i].quantity, portfolio[i].price,
                portfolio[i].historyCount);
        for (int j = 0; j < portfolio[i].historyCount; j++)
            fprintf(fp, "%f ", portfolio[i].history[j]);
        fprintf(fp, "\n");
    }

    fclose(fp);
    printSuccess("Portfolio saved successfully");
}

void addCoin() {
    if (coinCount >= MAX_COINS) {
        printError("Portfolio is full");
        return;
    }

    Coin c;
    printf(BOLD BLUE "\n[ Add New Coin ]\n\n" RESET);
    printf("Coin Name    : ");
    scanf("%s", c.name);
    printf("Coin Symbol  : ");
    scanf("%s", c.symbol);

    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(portfolio[i].name, c.name) == 0 || strcasecmp(portfolio[i].symbol, c.symbol) == 0) {
            printError("A coin with this name or symbol already exists");
            return;
        }
    }

    printf("Quantity     : ");
    scanf("%f", &c.quantity);
    c.price = 0.0;
    c.historyCount = 0;
    portfolio[coinCount++] = c;
    printSuccess("Coin added successfully");
}

void viewPortfolio() {
    if (coinCount == 0) {
        printInfo("Your portfolio is empty");
        return;
    }
    
    printf(BOLD BLUE "\n[ Your Portfolio ]\n\n" RESET);
    printf(BOLD "%-20s %-10s %-12s %-12s %-12s\n" RESET, 
           "Coin Name", "Symbol", "Quantity", "Price", "Value");
    drawHorizontalLine(80);
    
    float totalValue = 0;
    for (int i = 0; i < coinCount; i++) {
        float value = portfolio[i].quantity * portfolio[i].price;
        totalValue += value;
        
        const char* color = value > 1000 ? GREEN : (value > 100 ? YELLOW : RED);
        
        printf("%-20s %-10s %-12.2f " BOLD "%s$%-12.2f%s $%-12.2f\n" RESET,
               portfolio[i].name,
               portfolio[i].symbol,
               portfolio[i].quantity,
               color,
               portfolio[i].price,
               RESET,
               value);
    }
    
    drawHorizontalLine(80);
    printf(BOLD "Total Portfolio Value: " GREEN "$%.2f\n" RESET, totalValue);
}

void updatePrices() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char input[NAME_LEN];
    printf(BOLD BLUE "\n[ Update Coin Prices ]\n\n" RESET);
    printf("Enter coin name/symbol (or 'done' to finish):\n");

    while (1) {
        printf("Coin: ");
        scanf("%s", input);

        if (strcasecmp(input, "done") == 0) break;

        int found = 0;
        for (int i = 0; i < coinCount; i++) {
            if (strcasecmp(input, portfolio[i].symbol) == 0 || strcasecmp(input, portfolio[i].name) == 0) {
                printf("New price for %s (%s): $", portfolio[i].name, portfolio[i].symbol);
                scanf("%f", &portfolio[i].price);

                if (portfolio[i].historyCount < HISTORY)
                    portfolio[i].history[portfolio[i].historyCount++] = portfolio[i].price;
                else {
                    for (int j = 1; j < HISTORY; j++)
                        portfolio[i].history[j - 1] = portfolio[i].history[j];
                    portfolio[i].history[HISTORY - 1] = portfolio[i].price;
                }

                printSuccess("Price updated");
                found = 1;
                break;
            }
        }

        if (!found) printError("Coin not found");
    }
}

void calculateTotalValue() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    float total = 0.0;
    printf(BOLD BLUE "\n[ Portfolio Value ]\n\n" RESET);
    for (int i = 0; i < coinCount; i++) {
        float value = portfolio[i].quantity * portfolio[i].price;
        printf("%-20s (%s): $%.2f\n", portfolio[i].name, portfolio[i].symbol, value);
        total += value;
    }
    printf(BOLD "\nTotal Value: " GREEN "$%.2f\n" RESET, total);
}

void exportPortfolio() {
    FILE *fp = fopen(EXPORT_FILE, "w");
    if (!fp) {
        printError("Could not export portfolio");
        return;
    }
    
    fprintf(fp, "CryptoTracker Portfolio Export\n\n");
    for (int i = 0; i < coinCount; i++) {
        float value = portfolio[i].quantity * portfolio[i].price;
        fprintf(fp, "%s (%s): %.2f units @ $%.2f = $%.2f\n",
                portfolio[i].name, portfolio[i].symbol,
                portfolio[i].quantity, portfolio[i].price, value);
    }
    fclose(fp);
    printSuccess("Portfolio exported to 'portfolio_export.txt'");
}

void searchCoin() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char query[NAME_LEN];
    printf(BOLD BLUE "\n[ Search Coin ]\n\n" RESET);
    printf("Enter coin name/symbol: ");
    scanf("%s", query);
    
    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(query, portfolio[i].name) == 0 || strcasecmp(query, portfolio[i].symbol) == 0) {
            float value = portfolio[i].quantity * portfolio[i].price;
            printf("\nFound: %s (%s)\n", portfolio[i].name, portfolio[i].symbol);
            printf("Quantity: %.2f\n", portfolio[i].quantity);
            printf("Price: $%.2f\n", portfolio[i].price);
            printf("Value: $%.2f\n", value);
            return;
        }
    }
    printError("Coin not found");
}

void simulatePrices() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    srand(time(NULL));
    printf(BOLD BLUE "\n[ Simulate Price Changes ]\n\n" RESET);
    for (int i = 0; i < coinCount; i++) {
        float change = ((rand() % 2001) - 1000) / 100.0f; // -10% to +10%
        float oldPrice = portfolio[i].price;
        portfolio[i].price += (portfolio[i].price * (change / 100));

        if (portfolio[i].historyCount < HISTORY)
            portfolio[i].history[portfolio[i].historyCount++] = portfolio[i].price;
        else {
            for (int j = 1; j < HISTORY; j++)
                portfolio[i].history[j - 1] = portfolio[i].history[j];
            portfolio[i].history[HISTORY - 1] = portfolio[i].price;
        }

        const char* color = change > 0 ? GREEN : RED;
        printf("%s (%s): $%.2f → " BOLD "%s$%.2f (%.2f%%)\n" RESET,
               portfolio[i].name,
               portfolio[i].symbol,
               oldPrice,
               color,
               portfolio[i].price,
               change);
    }
}

void viewGraph() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char query[SYMBOL_LEN];
    printf(BOLD BLUE "\n[ View Price Graph ]\n\n" RESET);
    printf("Enter coin symbol: ");
    scanf("%s", query);
    
    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(query, portfolio[i].symbol) == 0) {
            printf("\n%s (%s) - Price History\n", portfolio[i].name, portfolio[i].symbol);
            for (int j = 0; j < portfolio[i].historyCount; j++) {
                printf("$%-6.2f | ", portfolio[i].history[j]);
                int bars = (int)(portfolio[i].history[j] / 10);
                for (int k = 0; k < bars; k++) printf("█");
                printf("\n");
            }
            return;
        }
    }
    printError("Coin not found");
}

void updateQuantity() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char symbol[SYMBOL_LEN];
    printf(BOLD BLUE "\n[ Update Quantity ]\n\n" RESET);
    printf("Enter coin symbol: ");
    scanf("%s", symbol);

    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(symbol, portfolio[i].symbol) == 0) {
            float newQty;
            printf("Current quantity of %s (%s): %.2f\n",
                   portfolio[i].name, portfolio[i].symbol, portfolio[i].quantity);
            printf("Enter new quantity: ");
            scanf("%f", &newQty);

            portfolio[i].quantity = newQty;
            printSuccess("Quantity updated");
            return;
        }
    }
    printError("Coin not found");
}

void deleteCoin() {
    if (coinCount == 0) {
        printError("Portfolio is empty");
        return;
    }

    char target[NAME_LEN];
    printf(BOLD BLUE "\n[ Delete Coin ]\n\n" RESET);
    printf("Enter coin name/symbol: ");
    scanf("%s", target);

    for (int i = 0; i < coinCount; i++) {
        if (strcasecmp(target, portfolio[i].name) == 0 || strcasecmp(target, portfolio[i].symbol) == 0) {
            for (int j = i; j < coinCount - 1; j++) {
                portfolio[j] = portfolio[j + 1];
            }
            coinCount--;
            printSuccess("Coin deleted");
            return;
        }
    }
    printError("Coin not found");
}

void about() {
    printf(BOLD BLUE "\n[ About CryptoTracker ]\n\n" RESET);
    printf("CryptoTracker is a terminal-based cryptocurrency portfolio manager\n");
    printf("Features include:\n");
    printf("- Track multiple cryptocurrencies\n");
    printf("- View price history graphs\n");
    printf("- Simulate market changes\n");
    printf("- Export your portfolio data\n");
    printf("\nVersion: 3.0\n");
}

// Main function
int main() {
    int choice;
    
    while (1) {
        clearScreen();
        printf(BOLD BLUE);
        printCentered("╔════════════════════════════╗");
        printCentered("║    CRYPTOTRACKER v3.0     ║");
        printCentered("╚════════════════════════════╝");
        printf(RESET);
        
        printf("\n");
        printMenuOption(1, "Login");
        printMenuOption(2, "Register");
        printMenuOption(3, "Exit");
        
        printf("\n" BOLD "Enter your choice: " RESET);
        scanf("%d", &choice);

        if (choice == 1) {
            if (login()) break;
        } else if (choice == 2) {
            registerUser();
        } else if (choice == 3) {
            printf(BOLD "\nThank you for using CryptoTracker!\n" RESET);
            exit(0);
        } else {
            printError("Invalid choice");
            SLEEP(1);
        }
    }

    loadPortfolio();

    while (1) {
        showHeader();
        
        printf("\n" BOLD BLUE "MAIN MENU\n" RESET);
        printMenuOption(1, "Add Cryptocurrency");
        printMenuOption(2, "View Portfolio");
        printMenuOption(3, "Update Prices");
        printMenuOption(4, "Calculate Total Value");
        printMenuOption(5, "Search Coin");
        printMenuOption(6, "Simulate Price Changes");
        printMenuOption(7, "Export Portfolio");
        printMenuOption(8, "View Price Graph");
        printMenuOption(9, "Update Quantity");
        printMenuOption(10, "Delete Coin");
        printMenuOption(11, "About");
        printMenuOption(12, "Save & Exit");
        
        printf("\n" BOLD "Enter your choice: " RESET);
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addCoin(); break;
            case 2: viewPortfolio(); break;
            case 3: updatePrices(); break;
            case 4: calculateTotalValue(); break;
            case 5: searchCoin(); break;
            case 6: simulatePrices(); break;
            case 7: exportPortfolio(); break;
            case 8: viewGraph(); break;
            case 9: updateQuantity(); break;
            case 10: deleteCoin(); break;
            case 11: about(); break;
            case 12: savePortfolio(); 
                    printSuccess("Goodbye!");
                    exit(0);
            default: printError("Invalid choice");
        }
        
        printf("\nPress Enter to continue...");
        getchar(); getchar();
    }

    return 0;
}