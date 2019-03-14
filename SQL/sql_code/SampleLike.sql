-- DDL ：创建表
CREATE TABLE SampleLike
( strcol VARCHAR(6) NOT NULL,
	PRIMARY KEY (strcol));
    
INSERT INTO SampleLike (strcol) VALUES ('abcddd');
INSERT INTO SampleLike (strcol) VALUES ('dddabc');
INSERT INTO SampleLike (strcol) VALUES ('abdddc');
INSERT INTO SampleLike (strcol) VALUES ('abcdd');
INSERT INTO SampleLike (strcol) VALUES ('ddabc');
INSERT INTO SampleLike (strcol) VALUES ('abddc');

SELECT *
	FROM SampleLike
	WHERE strcol LIKE 'ddd%';
    
SELECT *
	FROM SampleLike
	WHERE strcol LIKE '%ddd%';
    
SELECT *
	FROM SampleLike
	WHERE strcol LIKE '%ddd';
    
SELECT *
	FROM SampleLike
	WHERE strcol LIKE 'abc__';
    
SELECT product_name, sale_price
FROM Product
WHERE sale_price BETWEEN 100 AND 1000;

SELECT product_name, sale_price
	FROM Product
WHERE sale_price > 100 AND sale_price < 1000;

SELECT product_name, purchase_price
FROM Product
WHERE purchase_price IN (320, 500, 5000);

SELECT product_name, purchase_price
FROM Product
WHERE purchase_price NOT IN (320, 500, 5000);