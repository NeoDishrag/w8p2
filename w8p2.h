/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Man Yan Li
Student ID#: 143175230
Email      : myli7@myseneca.ca
Section    : ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros

#define MAX_PRODUCTS 3
#define GRAMS 64
#define LB_KG 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo {

    int sku;
    double price;
    int calPerServ;
    double weight;
};

struct ReportData
{
    int sku;
    double price;
    int calPerServ;
    double lbs;
    double kg;
    int g;
    double servings;
    double costPerServ;
    double costPerCal;
};


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* intptr);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* doubleptr);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int numProducts);

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int numSequence);

// 5. Display the formatted table header

void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(int sku, double* price, int calPerServ, double* weight);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg

double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g

int convertLbsG(const double* lbs, int* grams);

// 10. convert lbs: kg / g

void convertLbs(const double* lbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ

double calculateServings(const int gPerServ, const int totalGrams, double* numServs);

// 12. calculate: cost per serving

double calculateCostPerServing(const double price, const double totalServs, double* costPerServ);

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* price, const double* totalCal, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo item);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData thisData, const int isCheapest);

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo cheapest);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start();

