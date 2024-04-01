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

#define _CRT_SECURE_NO_WARNINGS


// System Libraries

#include <stdio.h>

// User-Defined Libraries

#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* intptr)
{
    int val = 0;
    do
    {
        scanf("%d", &val);
        if (val < 1)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (val < 1);
    if (intptr != NULL)
    {
        *intptr = val;
    }
    return val;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* doubleptr)
{
    double val = 0;
    do
    {
        scanf("%lf", &val);
        if (val < 1)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (val < 1);
    if (doubleptr != NULL)
    {
        *doubleptr = val;
    }
    return val;
}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int numProducts)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numProducts);
    printf("NOTE: A 'serving' is %dg\n\n", GRAMS);
}

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int numProducts)
{
    printf("Cat Food Product #%d\n", numProducts + 1);
    printf("--------------------\n");
    struct CatFoodInfo newCatFoodInfo = { 0, 0.0, 0, 0.0 };
    printf("SKU           : ");
    getIntPositive(&(newCatFoodInfo.sku));
    printf("PRICE         : $");
    getDoublePositive(&(newCatFoodInfo.price));
    printf("WEIGHT (LBS)  : ");
    newCatFoodInfo.weight = getDoublePositive(NULL);
    printf("CALORIES/SERV.: ");
    getIntPositive(&(newCatFoodInfo.calPerServ));
    printf("\n");
    return newCatFoodInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(int sku, double* price, int calPerServ, double* weight)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calPerServ);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double* lbs, double* kg)
{
    double val = *lbs / LB_KG;
    if (kg != NULL)
    {
        *kg = val;
    }
    return val;
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double* lbs, int* g)
{
    int val = convertLbsKg(lbs, NULL) * 1000;
    if (g != NULL)
    {
        *g = val;
    }
    return val;
}

// 10. convert lbs: kg and g

void convertLbs(const double* lbs, double* kg, int* g)
{
    double kgVal = convertLbsKg(lbs, NULL);
    if (kg != NULL)
    {
        *kg = kgVal;
    }

    int gVal = convertLbsG(lbs, NULL);
    if (g != NULL)
    {
        *g = gVal;
    } 
}


// 11. calculate: servings based on gPerServ

double calculateServings(const int gPerServ, const int totalGrams, double* numServs)
{
    double val = (double)totalGrams / gPerServ;
    if (numServs != NULL)
    {
        *numServs = val;
    }
    return val;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double price, const double totalServs, double* costPerServ)
{
    double val = price / totalServs;
    if (costPerServ != NULL)
    {
        *costPerServ = val;
    }
    return val;
}

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* price, const double* totalCal, double* costPerCal)
{
    double val = *price / *totalCal;
    if (costPerCal != NULL)
    {
        *costPerCal = val;
    }
    return val;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo item)
{
    struct ReportData thisData = { 0 };
    thisData.sku = item.sku;
    thisData.price = item.price;
    thisData.calPerServ = item.calPerServ;
    thisData.lbs = item.weight;
    convertLbsKg(&(thisData.lbs), &(thisData.kg));
    thisData.g = convertLbsG(&(thisData.lbs), NULL);
    thisData.servings = calculateServings(GRAMS, thisData.g, NULL);
    calculateCostPerServing(thisData.price, thisData.servings, &(thisData.costPerServ));
    double totalCal = thisData.servings * thisData.calPerServ;
    calculateCostPerCal(&(thisData.price), &totalCal, &(thisData.costPerCal));
    return thisData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData thisData, const int isCheapest)
{
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", thisData.sku, thisData.price, thisData.lbs, thisData.kg, thisData.g, thisData.calPerServ, thisData.servings, thisData.costPerServ, thisData.costPerCal);
    if (isCheapest != 0)
    {
        printf(" ***");
    }
}

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo cheapest)
{
    printf("\nFinal Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n\n", cheapest.sku, cheapest.price);
    printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    struct CatFoodInfo CatFoods[MAX_PRODUCTS] = { {0, 0.0, 0, 0.0}, {0, 0.0, 0, 0.0}, {0, 0.0, 0, 0.0} };
    struct ReportData CatFoodDetails[MAX_PRODUCTS] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
    int i = 0;

    openingMessage(MAX_PRODUCTS);

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        CatFoods[i] = getCatFoodInfo(i);
        CatFoodDetails[i] = calculateReportData(CatFoods[i]);
    }

    int cheapest = 0;
    for (i = 1; i < MAX_PRODUCTS; i++)
    {
        if (CatFoodDetails[i].costPerServ < CatFoodDetails[cheapest].costPerServ)
        {
            cheapest = i;
        }
    }

    displayCatFoodHeader();

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        displayCatFoodData(CatFoods[i].sku, &(CatFoods[i].price), CatFoods[i].calPerServ, &(CatFoods[i].weight));
    }

    printf("\n");

    displayReportHeader();

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        if (i == cheapest)
        {
            displayReportData(CatFoodDetails[i], 1);
        }
        else
        {
            displayReportData(CatFoodDetails[i], 0);
        }
        printf("\n");
    }

    displayFinalAnalysis(CatFoods[cheapest]);
}
