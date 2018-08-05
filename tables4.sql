SELECT * FROM sellers;

INSERT into sellers
values(111111111,'gur','na','2000-01-01',0521111111,'sderot'),
	(111111112,'ron','da','2000-01-02',0521111112,'sderot'),
    (111111113,'saar','ha','2000-01-03',0521111113,'afula'),
    (111111114,'joy','ka','2000-01-04',0521111114,'binyamina'),
    (111111115,'tami','ya','2000-01-05',0521111115,'givatayim'),
    (111111116,'haya','ju','2000-01-06',0521111116,'ramon'),
    (111111117,'lea','wa','2000-01-07',0521111117,'yavne'),
    (111111118,'tea','la','2000-01-08',0521111118,'rosh haayin'),
    (111111119,'dana','tas','2000-01-09',0521111119,'kfar saba'),
    (555555555,'danit','fad','2000-02-03',0521111100,'hod hasharon');
    
SELECT * FROM customers;

INSERT into customers
values(123456781, "ben", "baruch", '1990-01-02', 0521342234, "raanana"),
	(123456782, "dan", "ba", '1990-11-02', 0521342235, "natanya"),
    (123456783, "din", "golan", '1990-10-10', 0521342236, "nahariya"),
    (123456784, "or", "dor", '1990-09-08', 0521342237, "ashdod"),
    (123456785, "omer", "marmareli", '1990-08-08', 0521342238, "rehovot"),
    (123456786, "roi", "navon", '1990-07-07', 0521342239, "haifa"),
    (123456787, "tomer", "frishman", '1990-06-06', 0521342232, "eilat"),
    (123456788, "ravid", "gezer", '1991-06-03', 0541342232, "rosh pina"),
    (323456787, "rotem", "saidon", '1992-06-06', 0501342232, "tveria"),
    (423456787, "kobi", "kaduri", '1999-06-06', 0521552232, "metula");

SELECT * FROM suppliers;

INSERT into suppliers
values(1,"Vince Lombardi","Tel Aviv",0546234431),
	(2,"John Wooden","Acre",0546234432),
    (3,"Dean Smith","Nazareth",0546234433),
    (4,"Bear Bryant","Haifa",0546234434),
    (5,"Scotty Bowman","Jerusalem",0546234435),
    (6,"Don Shula","Eilat",0546234436),
    (7,"Pete Newell","Netanya",0546234437),
    (8,"Peter Pen","yarkona",0546234438),
    (9,"Reuven Atar","hod hasharon",0546234439),
    (10,"Moshe Meshulam","berlin",0546234447);

SELECT * FROM books;

INSERT into books
values(2345,"The Hilltop","Assaf Gavron","2015",99,3,1),
	(1122,"A Tale of Love and Darkness","Amos Oz","2005",91,17,0),
    (2424,"Suddenly, a Knock on the Door","Etgar Keret","2012",92,13,1),
    (6262,"A Brief History of Humankind","Yuval Noah Harari ","2014",94,30,0),
    (1423,"The Triumph and Tragedy of Israel","Ari Shavit","2013",99,43,1),
    (7400,"Let It Be Morning","Sayed Kashua","2006",87,14,1),
    (2000,"A Horse Walks into a Bar","David Grossman","2017",97,24,1),
    (9001,"The Boat","Arik Moshe","1017",79,42,0),
    (2798,"Robots","Nathan Granot","2000",47,44,1);

SELECT * FROM purchases;

INSERT into purchases (cusid, sernum, sellid ,price ,pstatus, pdate, discount)
values(123456781,2345,111111118,99,'ordered','2018-02-02',3),
	(123456782,2345,111111115,99,'ordered','2018-02-02',3),
    (123456783,1122,111111118,91,'ordered','2018-02-03',17),
    (123456784,1122,111111115,91,'ordered','2018-02-04',17),
    (123456785,6262,111111119,94,'ordered','2018-02-05',30),
    (123456786,9001,111111119,79,'ordered','2018-02-06',42),
    (123456787,9001,111111112,79,'ordered','2018-02-07',42),
    (123456788,7400,111111118,87,'ordered','2018-02-08',14),
    (323456787,1423,111111111,99,'ordered','2018-03-08',43),
    (423456787,1423,111111111,99,'ordered','2018-04-08',43);

SELECT * FROM orders;

INSERT into orders (suppid, sernum, price ,ostatus, odate)
values(1,7400,50,'ordered','2018-01-01'),
	(1,1423,60,'arrived','2018-01-02'),
    (2,9001,70,'arrived','2018-01-03'),
    (2,1122,50,'arrived','2018-01-04'),
    (3,7400,40,'ordered','2018-01-05'),
    (4,1423,55,'ordered','2018-01-06'),
    (5,9001,53,'ordered','2018-01-07'),
    (6,2345,35,'ordered','2018-01-08'),
    (7,2345,45,'ordered','2018-01-09'),
    (8,6262,44,'ordered','2018-02-09'),
    (1,1122,50,'ordered','2018-01-01');
