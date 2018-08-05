CREATE DATABASE IF NOT EXISTS bookstore;
USE bookstore;

CREATE TABLE IF NOT EXISTS  Books  (
   sernum  int(9) unsigned NOT NULL,
   title  varchar(255) NOT NULL,
   author  varchar(255) NOT NULL,
   genre  varchar(255) NOT NULL,
   price  int(3) unsigned NOT NULL,
   discount  int(3) unsigned NOT NULL,
   onstock  int(1) NOT NULL,
  PRIMARY KEY ( sernum )
);

CREATE TABLE IF NOT EXISTS  Customers  (
   id int(9) unsigned NOT NULL,
   fname  varchar(100) NOT NULL,
   lname  varchar(100) NOT NULL,
   bdate  date DEFAULT NULL,
   phonenum  int(10) unsigned NOT NULL,
   address  varchar(255) NOT NULL,
  PRIMARY KEY ( id )
);

CREATE TABLE IF NOT EXISTS  Suppliers  (
   suppid  int(9) unsigned NOT NULL,
   suppname  varchar(100) NOT NULL,
   address  varchar(255) NOT NULL,
   phonenum  int(10) unsigned NOT NULL,
  PRIMARY KEY ( suppid )
);

CREATE TABLE IF NOT EXISTS  Sellers  (
   id int(9) unsigned NOT NULL,
   fname  varchar(100) NOT NULL,
   lname  varchar(100) NOT NULL,
   bdate  date DEFAULT NULL,
   phonenum  int(10) unsigned NOT NULL,
   address  varchar(255) NOT NULL,
  PRIMARY KEY ( id )
);

CREATE TABLE IF NOT EXISTS  Orders  (
   oid int (9) unsigned NOT NULL auto_increment,
   suppid  int(9) unsigned NOT NULL,
   sernum  int(9) unsigned NOT NULL,
   price  int(3) unsigned NOT NULL,
   ostatus  enum('ordered','arrived','sold') NOT NULL,
   odate  date NOT NULL,
  PRIMARY KEY (oid)
);

CREATE TABLE IF NOT EXISTS  Purchases  (
   pid int (9) unsigned NOT NULL auto_increment,
   cusid  int(9) unsigned ,
   sernum  int(9) unsigned ,
   sellid  int(9) unsigned ,
   price  int(3) unsigned NOT NULL,
   pstatus  enum('ordered','arrived','sold') NOT NULL,
   pdate  date NOT NULL,
   discount  int(9) unsigned NOT NULL,
  PRIMARY KEY ( pid )
);

drop table Orders;

SELECT MAX(y.totalp) as mostBooks FROM
(SELECT COUNT(cusid) as totalp FROM Purchases p WHERE pdate > '1992-10-30') y
INNER JOIN Customers c ON c.id = Purchases.cusid;


SELECT suppid, COUNT(suppid) as most FROM Orders
WHERE odate > '1992-10-30' GROUP BY suppid ORDER BY most DESC LIMIT 1;

SELECT * FROM suppliers s INNER JOIN
( SELECT suppid, COUNT(suppid) as most FROM Orders
WHERE odate > '1992-10-30' ) y
ON s.suppid = y.suppid
GROUP BY y.suppid
ORDER BY most DESC LIMIT 1;

SELECT * FROM Customers c INNER JOIN
( SELECT cusid, COUNT(cusid) as most FROM Purchases
WHERE pdate > ? GROUP BY cusid 
ORDER BY most DESC LIMIT 1) y
ON c.id = y.cusid;
/*13*/
SELECT COUNT(oid) as numOfOrders FROM Orders WHERE odate BETWEEN ? AND ?;
/*14*/
SELECT COUNT(oid) as numOfOrders FROM Orders WHERE status = 'sold' AND odate BETWEEN ? AND ?;
/*15*/
SELECT SUM(discount) as totaldiscount FROM Purchases WHERE cusid = ? AND pdate > ?;
/*16*/
SELECT SUM(price) as totalincome, SUM(discount) as totaldiscount FROM Purchases WHERE pdate BETWEEN ? AND ?;
/*17*/
SELECT COUNT(cusid) as totalcustomers FROM Purchases WHERE pdate > ?;
/*18*/
SELECT SUM(price) as totaloutcome FROM Orders WHERE suppid = ? AND odate BETWEEN ? AND ?;
/*19*/
SELECT SUM(price) as totalsales FROM Purchases WHERE sellid = ? AND pdate BETWEEN ? AND ?;
/*20*/
SELECT title, author FROM Books b INNER JOIN
(SELECT COUNT(sernum) as totalsales FROM Purchases
WHERE pdate BETWEEN '1992-10-30' AND '1992-10-30') y
ON b.sernum = y.sernum;