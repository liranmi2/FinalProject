#include "Query.h"

//qeury 1
void Query::Query::showAllBooks() {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Books WHERE onStock = 1");
		ResultSet * rset = pstmt->executeQuery();
		rset->beforeFirst();
		cout << "sernum  :  title  :  author  :  genre  :  price  :  discount" << endl;
		while (rset->next()) {
			cout << rset->getInt("sernum") << " : " << rset->getString("title") << " : "
				 << rset->getString("author") << " : " << rset->getString("genre") << " : "
				 << rset->getInt("price") << "  : " << rset->getInt("discount")<< endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 2
 void Query::showAllOpenedOrders() {
	 CON;
	 if (con) {
		 PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Orders");
		 ResultSet * rset = pstmt->executeQuery();
		 rset->beforeFirst();
		 while (rset->next()) {
			 cout << rset->getInt("suppid") << " : " << rset->getInt("sernum") << " : "
				 << rset->getInt("price")<< " : " << rset->getString("ostatus") << " : "
				 << rset->getString("odate") << endl;
		 }
		 delete rset;
		 delete pstmt;
		 delete con;
	 }
}
//qeury 3
 void Query::showAllCustomers() {
	 CON;
	 if (con) {
		 PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Customers");
		 ResultSet * rset = pstmt->executeQuery();
		 rset->beforeFirst();
		 while (rset->next()) {
			 cout << rset->getInt("id") << "  " << rset->getString("fname") << "  "
				 << rset->getString("lname") << "  " << rset->getString("bdate") << "  "
				 << rset->getInt("phonenum") << "  " << rset->getString("address")<< endl;
		 }
		 delete rset;
		 delete pstmt;
		 delete con;
	 }
}
//qeury 4
void Query::showAllSuppliers() {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Suppliers");
		ResultSet * rset = pstmt->executeQuery();
		rset->beforeFirst();
		while(rset->next()) {
			cout << rset->getInt("suppid") << "  " << rset->getString("suppname") << "  "
				<< rset->getString("address") << "  " << rset->getInt("phonenum") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 5
void Query::showPurchasesBetween(string fromDate, string toDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Purchases WHERE pdate between ? and ?");
		pstmt->setString(1, fromDate);
		pstmt->setString(2, toDate);
		ResultSet * rset = pstmt->executeQuery();
		rset->beforeFirst();
		while (rset->next()) {
			cout << rset->getInt("cusid") << " : " << rset->getInt("sernum") << " : "
				<< rset->getInt("sellid") << " : " << rset->getInt("price") << " : "
				<< rset->getString("pstatus") << "  : " << rset->getString("pdate") 
				<< "  : " << rset->getInt("discount") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 6
void Query::showAllDiscountedBooks() {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Books WHERE discount <> 0");
		ResultSet * rset = pstmt->executeQuery();
		rset->beforeFirst();
		cout << "sernum  :  title  :  author  :  genre  :  price  :  discount" << endl;
		while (rset->next()) {
			cout << rset->getInt("sernum") << " : " << rset->getString("title") << " : "
				<< rset->getString("author") << " : " << rset->getString("genre") << " : "
				<< rset->getInt("price") << "  : " << rset->getInt("discount") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 7
void Query::isBookOnStock(int serialNumber) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Books WHERE sernum = ?");
		pstmt->setInt(1, serialNumber);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 1) {
			rset->first();
			cout << "The book "<< rset->getString("title") << " is ";
			if (rset->getInt("onstock") == 0)
				cout << "not ";
			cout << "on stock" << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 8
void Query::showSuppliersOfBook(int serialNumber) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT suppid FROM Orders WHERE sernum = ?");
		pstmt->setInt(1, serialNumber);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 0)
			return;
		rset->beforeFirst();
		while (rset->next()) {
			cout << rset->getInt("suppid") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 9
void Query::howManyCopiesSoldSince(int serialNumber, string fromDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT sernum, count(sernum) as total FROM Purchases"
														 "WHERE sernum = ? AND pdate >= ?");
		pstmt->setInt(1, serialNumber);
		pstmt->setString(2, fromDate);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount()) {
			rset->first();
			cout << "Total purchases for book " << rset->getInt("sernum") 
				 << " : " << rset->getInt("total") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 10
void Query::howManyBooksCustomerBought(int customerID, string fromDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT cusid, count(cusid) as total FROM Purchases"
														 "WHERE cusid = ? AND pdate >= ?");
		pstmt->setInt(1, customerID);
		pstmt->setString(2, fromDate);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 1) {
			rset->first();
			cout << "Total purchases for customer " << rset->getInt("cusid")
				<< " : " << rset->getInt("total") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}

//qeury 11
void Query::mostPurchasingCustomerSince(string fromDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Customers c INNER JOIN"
			"(SELECT cusid, COUNT(cusid) as most FROM Purchases"
			"WHERE pdate > ? ) y"
			"ON c.id = y.cusid"
			"GROUP BY cusid ORDER BY most DESC LIMIT 1");
		pstmt->setString(1, fromDate);
		ResultSet * rset = pstmt->executeQuery();
		if(rset->rowsCount() == 1) {
			cout << "Most purchasing customer since " << fromDate << " is:" << endl;
			rset->first();
			cout << rset->getInt("id") << "  " << rset->getString("fname") << "  "
				<< rset->getString("lname") << "  " << rset->getString("bdate") << "  "
				<< rset->getInt("phonenum") << "  " << rset->getString("address") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 12
void Query::mostOrderedSupplierSince(string fromDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM suppliers s INNER JOIN"
			"(SELECT suppid, COUNT(suppid) as most FROM Orders"
			"WHERE odate > ?) y"
			"ON s.suppid = y.suppid"
			"GROUP BY y.suppid"
			"ORDER BY most DESC LIMIT 1");
		pstmt->setString(1, fromDate);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 1) {
			cout << "Most ordered supplier since " << fromDate << " is:" << endl;
			rset->first();
			cout << rset->getInt("suppid") << "  " << rset->getString("suppname") << "  "
				<< rset->getString("address") << "  " << rset->getInt("phonenum") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 13
void Query::numberOfOrdersBetween(string fromDate, string toDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT COUNT(oid) as numOfOrders FROM Orders WHERE odate BETWEEN ? AND ? ");
		pstmt->setString(1, fromDate);
		pstmt->setString(2, toDate);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 1) {
			cout << "Number of orders between " << fromDate << " and " << toDate << " is:" ;
			rset->first();
			cout << rset->getInt("numOfOrders") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 14
void Query::numberOfSoldOrdersBetween(string fromDate, string toDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT COUNT(oid) as numOfOrders FROM Orders"
			"WHERE status = 'sold' AND odate BETWEEN ? AND ? ");
		pstmt->setString(1, fromDate);
		pstmt->setString(2, toDate);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 1) {
			cout << "Number of sold orders between " << fromDate << " and " << toDate << " is:";
			rset->first();
			cout << rset->getInt("numOfOrders") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 15
void Query::totalDiscountToCustomerSince(int customerID, string fromDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT SUM(discount) as totaldiscount FROM Purchases WHERE cusid = ? AND pdate > ? ");
		pstmt->setInt(1, customerID);
		pstmt->setString(2, fromDate);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 1) {
			cout << "The total discount to customer " << customerID << " since " << fromDate << " is: ";
			rset->first();
			cout << rset->getInt("totaldiscount") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 16
void Query::totalIncomeForYearByQuarters(int year) {

}
//qeury 17
void Query::numOfNewCustomersSince(string fromDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT COUNT(cusid) as totalcustomers FROM Purchases WHERE pdate > ? ");
		pstmt->setString(1, fromDate);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 1) {
			cout << "The number of new customers since " << fromDate << " is: ";
			rset->first();
			cout << rset->getInt("totalcustomers") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 18
void Query::totalOrdersBySupplierBetween(int supplierID, string fromDate, string toDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT SUM(price) as totaloutcome FROM Orders WHERE suppid = ? AND odate BETWEEN ? AND ? ");
		pstmt->setInt(1, supplierID);
		pstmt->setString(2, fromDate);
		pstmt->setString(3, toDate);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 1) {
			cout << "The total orders fee by supplier no. " << supplierID << " between " << fromDate << " to " << toDate << " is: ";
			rset->first();
			cout << rset->getInt("totaloutcome") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 19
void Query::totalSalesForSellerBetween(int sellerID, string fromDate, string toDate) {
	CON;
	if (con) {
		PreparedStatement *pstmt = con->prepareStatement("SELECT SUM(price) as totalsales FROM Purchases WHERE sellid = ? AND pdate BETWEEN ? AND ? ");
		pstmt->setInt(1, sellerID);
		pstmt->setString(2, fromDate);
		pstmt->setString(3, toDate);
		ResultSet * rset = pstmt->executeQuery();
		if (rset->rowsCount() == 1) {
			cout << "The total purchases fee by seller no. " << sellerID << " between " << fromDate << " to " << toDate << " is: ";
			rset->first();
			cout << rset->getInt("totalsales") << endl;
		}
		delete rset;
		delete pstmt;
		delete con;
	}
}
//qeury 20
void Query::tenMostSoldBooksBetween(string fromDate, string toDate) {

}
