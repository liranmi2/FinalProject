#include <iostream>
#include "Database.h"

using namespace std;

class Query {

public:
	//qeury 1
	static void showAllBooks();
	//qeury 2
	static void showAllOpenedOrders();
	//qeury 3
	static void showAllCustomers();
	//qeury 4
	static void showAllSuppliers();
	//qeury 5
	static void showPurchasesBetween(string fromDate, string toDate);
	//qeury 6
	static void showAllDiscountedBooks();
	//qeury 7
	static void isBookOnStock(int serialNumber);
	//qeury 8
	static void showSuppliersOfBook(int serialNumber);
	//qeury 9
	static void howManyCopiesSoldSince(int serialNumber, string fromDate);
	//qeury 10
	static void howManyBooksCustomerBought(int customerID, string fromDate);
	//qeury 11
	static void mostPurchasingCustomerSince(string fromaDate);
	//qeury 12
	static void mostOrderedSupplierSince(string fromDate);
	//qeury 13
	static void numberOfOrdersBetween(string fromDate, string toDate);
	//qeury 14
	static void numberOfSoldOrdersBetween(string fromDate, string toDate);
	//qeury 15
	static void totalDiscountToCustomerSince(int customerID, string fromDate);
	//qeury 16
	static void totalIncomeForYearByQuarters(int year);
	//qeury 17
	static void numOfNewCustomersSince(string fromDate);
	//qeury 18
	static void totalOrdersBySupplierBetween(int supplierID, string fromDate, string toDate);
	//qeury 19
	static void totalSalesForSellerBetween(int sellerID, string fromDate, string toDate);
	//qeury 20
	static void tenMostSoldBooksBetween(string fromDate, string toDate);
};