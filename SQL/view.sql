CREATE VIEW ProductSum (product_type, cnt_product) AS
	SELECT product_type, COUNT(*)
	FROM Product
	GROUP BY product_type;
    
SELECT product_type, cnt_product
	FROM ProductSum;
    
CREATE VIEW ProductSumJim (product_type, cnt_product) AS
	SELECT product_type, cnt_product
	FROM ProductSum
WHERE product_type = '办公用品';

CREATE VIEW ProductJim (product_id, product_name, product_type, sale_price, purchase_price, regist_date) AS
	SELECT *
	FROM Product
WHERE product_type = '办公用品';

INSERT INTO ProductJim VALUES ('0009', '印章', '办公用品', 95, 10, '2009-11-30');

SELECT * FROM ProductJim;
SELECT * FROM Product;

-- 在FROM子句中直接书写定义视图的SELECT语句
SELECT product_type, cnt_product
	FROM ( 
			SELECT product_type, COUNT(*) AS cnt_product 
			FROM Product GROUP BY product_type
		  ) 
    AS ProductSum;
    
SELECT product_id, product_name, sale_price
	FROM Product
	WHERE sale_price > (SELECT AVG(sale_price) FROM Product);
    
SELECT product_id, product_name, sale_price, (SELECT AVG(sale_price) FROM Product) AS avg_price
	FROM Product;
    
SELECT product_type, AVG(sale_price) 
	FROM Product 
    GROUP BY product_type
	HAVING AVG(sale_price) > (SELECT AVG(sale_price) FROM Product);
    
SELECT product_type, product_name, sale_price
	FROM Product AS P1
	WHERE sale_price > (SELECT AVG(sale_price)
	FROM Product AS P2
	WHERE P1.product_type = P2.product_type
GROUP BY product_type);