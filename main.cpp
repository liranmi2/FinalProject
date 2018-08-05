
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Database.h"
#include "Query.h"

#define NAMESPACES using namespace boost::posix_time;using namespace boost::gregorian;using namespace std;using namespace sql;

NAMESPACES;
int main(int argc, const char * argv[]) {
	int selection = 21;
	string fromDate, toDate;
	int serialNumber, customerID, supplierID, sellerID;
	while (selection) {
		cout << "1. Show all books" << endl;
		cout << "2. Show all opened orders" << endl;
		cout << "3. Show all customers" << endl;
		cout << "4. Show all suppliers" << endl;
		cout << "5. Show purchases on a certain period" << endl;
		cout << "6. Show all discounted Books" << endl;
		cout << "7. Check if book is on stock (by serial number)" << endl;
		cout << "8. Show all the suppliers for a book (by serial number)" << endl;
		cout << "9. How many copies of a book sold since a certain date" << endl;
		cout << "10. How many books did a customer purchase since a certain date" << endl;
		cout << "11. Show the customer that purchased most books since a certain date" << endl;
		cout << "12. Show the most ordered supplier since a certain date" << endl;
		cout << "13. Show all supplier orders on a certain period" << endl;
		cout << "14. Show all supplier orders that ended up selling on a certain period" << endl;
		cout << "15. Total discount for a customer since a certain date" << endl;
		cout << "16. Total income for year by quarters" << endl;
		cout << "17. Number of new customers since a certain date" << endl;
		cout << "18. Total amount of orders from supplier on a certain period" << endl;
		cout << "19. Total gross sales by a sales person on a certain period" << endl;
		cout << "20. Top 10 most selling books on a certain period" << endl;
		cout << "0. EXIT" << endl;
		cin >> selection;

		switch (selection) {
		case 0:
			cout << "Goodbye :)" << endl;
			break;
		case 1:
			Query::showAllBooks();
			break;
		case 2:
			Query::showAllOpenedOrders();
			break;
		case 3:
			Query::showAllCustomers();
			break;
		case 4:
			Query::showAllSuppliers();
			break;
		case 5:
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			cout << "Please enter to date YYYY-MM-DD: ";
			cin >> toDate;
			Query::showPurchasesBetween(fromDate, toDate);
			break;
		case 6:
			Query::showAllDiscountedBooks();
			break;
		case 7:
			cout << "Please enter serial number: ";
			cin >> serialNumber;
			Query::isBookOnStock(serialNumber);
			break;
		case 8:
			cout << "Please enter serial number: ";
			cin >> serialNumber;
			Query::showSuppliersOfBook(serialNumber);
			break;
		case 9:
			cout << "Please enter serial number: ";
			cin >> serialNumber;
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			Query::howManyCopiesSoldSince(serialNumber, fromDate);
			break;
		case 10:
			cout << "Please enter customer ID: ";
			cin >> customerID;
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			Query::howManyBooksCustomerBought(customerID, fromDate);
			break;
		case 11:
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			Query::mostPurchasingCustomerSince(fromDate);
			break;
		case 12:
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			Query::mostOrderedSupplierSince(fromDate);
			break;
		case 13:
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			cout << "Please enter to date YYYY-MM-DD: ";
			cin >> toDate;
			Query::numberOfOrdersBetween(fromDate, toDate);
			break;
		case 14:
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			cout << "Please enter to date YYYY-MM-DD: ";
			cin >> toDate;
			Query::numberOfSoldOrdersBetween(fromDate, toDate);
			break;
		case 15:
			cout << "Please enter customer ID: ";
			cin >> customerID;
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			Query::totalDiscountToCustomerSince(customerID, fromDate);
			break;
		case 16:
		case 17:
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			Query::numOfNewCustomersSince(fromDate);
			break;
		case 18:
			cout << "Please enter supplier ID: ";
			cin >> supplierID;
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			cout << "Please enter to date YYYY-MM-DD: ";
			cin >> toDate;
			Query::totalOrdersBySupplierBetween(supplierID, fromDate, toDate);
			break;
		case 19:
			cout << "Please enter seller ID: ";
			cin >> sellerID;
			cout << "Please enter from date YYYY-MM-DD: ";
			cin >> fromDate;
			cout << "Please enter to date YYYY-MM-DD: ";
			cin >> toDate;
			Query::totalSalesForSellerBetween(sellerID, fromDate, toDate);
			break;
		case 20:
		default:
			cout << "Wrong input, choose again" << endl;
			break;
		}
		if (selection) {
			cout << endl << "Press any key to continue...";
			getchar();
			getchar();
			cout << endl;
		}
	}
    return 0;
}

/*
1.Query::showAllBooks();
2.Query::showAllOpenedOrders();
3.Query::showAllCustomers();
4.Query::showAllSuppliers();
5.Query::showPurchasesBetween(fromDate, toDate);
6.Query::showAllDiscountedBooks();
7.Query::isBookOnStock(serialNumber);
8.Query::showSuppliersOfBook(serialNumber);
9.Query::howManyCopiesSoldSince(serialNumber, fromDate);
10.Query::howManyBooksCustomerBought(customerID, fromDate);
11.Query::mostPurchasingCustomerSince(fromDate);
12.Query::mostOrderedSupplierSince(fromDate);
13.Query::numberOfOrdersBetween(fromDate, toDate);
14.Query::numberOfSoldOrdersBetween(fromDate, toDate);
15.Query::totalDiscountToCustomerSince(customerID, fromDate);

17.Query::numOfNewCustomersSince(fromDate);
18.Query::totalOrdersBySupplierBetween(supplierID, fromDate, toDate);
19.Query::totalSalesForSellerBetween(sellerID, fromDate, toDate);*/