#include "Database.h"

Database *Database::instance = 0;

Database::Database() : driver(get_driver_instance()) {
	connection_properties["hostName"] = DB_HOST;
	connection_properties["port"] = DB_PORT;
	connection_properties["userName"] = DB_USER;
	connection_properties["password"] = DB_PASS;
	connection_properties["OPT_RECONNECT"] = true;

	// use database
	try {
		Connection *con = driver->connect(connection_properties);
		try {
			con->setSchema("bookstore");
		}
		catch (SQLException &e) {
			Statement *stmt = con->createStatement();
			stmt->execute(
				"CREATE DATABASE IF NOT EXISTS bookstore");
			con->setSchema("bookstore"); // switch database
			stmt->execute("CREATE TABLE IF NOT EXISTS  Books  ("
				"sernum  int(9) unsigned NOT NULL,"
				"title  varchar(255) NOT NULL,"
				"author  varchar(255) NOT NULL,"
				"genre  varchar(255) NOT NULL,"
				"price  int(3) unsigned NOT NULL,"
				"discount  int(3) unsigned NOT NULL,"
				"onstock  int(1) NOT NULL,"
				"PRIMARY KEY(sernum)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS  Customers  ("
				"id int(9) unsigned NOT NULL,"
				"fname  varchar(100) NOT NULL,"
				"lname  varchar(100) NOT NULL,"
				"bdate  date DEFAULT NULL,"
				"phonenum  int(10) unsigned NOT NULL,"
				"address  varchar(255) NOT NULL,"
				"PRIMARY KEY(id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS  Suppliers  ("
				"suppid  int(9) unsigned NOT NULL,"
				"suppname  varchar(100) NOT NULL,"
				"address  varchar(255) NOT NULL,"
				"phonenum  int(10) unsigned NOT NULL,"
				"PRIMARY KEY(suppid)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS  Sellers  ("
				"id int(9) unsigned NOT NULL,"
				"fname  varchar(100) NOT NULL,"
				"lname  varchar(100) NOT NULL,"
				"bdate  date DEFAULT NULL,"
				"phonenum  int(10) unsigned NOT NULL,"
				"address  varchar(255) NOT NULL,"
				"PRIMARY KEY(id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS  Orders  ("
				"oid int(9) unsigned NOT NULL,"
				"suppid  int(9) unsigned NOT NULL,"
				"sernum  int(9) unsigned NOT NULL,"
				"price  int(3) unsigned NOT NULL,"
				"ostatus  enum('ordered', 'arrived', 'sold') NOT NULL,"
				"odate  date NOT NULL,"
				"PRIMARY KEY(suppid, sernum)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS  Purchases  ("
				"pid int(9) unsigned NOT NULL,"
				"cusid  int(9) unsigned NOT NULL,"
				"sernum  int(9) unsigned NOT NULL,"
				"sellid  int(9) unsigned NOT NULL,"
				"price  int(3) unsigned NOT NULL,"
				"pstatus  enum('ordered', 'arrived', 'sold') NOT NULL,"
				"pdate  date NOT NULL,"
				"discount  int(9) unsigned NOT NULL,"
				"PRIMARY KEY(pid)"
				")");
			delete stmt;
		}
		delete con;
	}
	catch (SQLException &e) {
		cout << e.getErrorCode() << " " << e.what() << " " << e.getSQLState();
	}
}

Database & Database::getInstance() {
	if (Database::instance == 0) {
		instance = new Database();
	}
	return *instance;
}

Connection * Database::getConnection() {
	try {
		Connection *con = driver->connect(connection_properties);
		con->setSchema(DB_NAME);
		return con;
	}
	catch (SQLException &e) {
		cout << e.what();
	}
	return 0;
}
