select count(*)
	from product;
    
SELECT COUNT(purchase_price)
	FROM Product;
    
SELECT SUM(sale_price)
	FROM Product;
    
SELECT SUM(sale_price), SUM(purchase_price)
	FROM Product;
    
SELECT AVG(sale_price)
	FROM Product;
    
SELECT AVG(sale_price), AVG(purchase_price)
	FROM Product;
    
SELECT MAX(sale_price), MIN(purchase_price)
	FROM Product;
    
SELECT COUNT(DISTINCT product_type)
	FROM Product;
    
select product_type, count(*)
	from product
	group by product_type;
    
SELECT purchase_price, COUNT(*)
	FROM Product
	GROUP BY purchase_price;
    
select purchase_price, count(*)
	from product
    where product_type = '衣服'
    group by purchase_price;
    
SELECT product_type, COUNT(*)
	FROM Product
	GROUP BY product_type
HAVING COUNT(*) = 2;

SELECT product_type, COUNT(*)
	FROM Product
	GROUP BY product_type
HAVING product_type = '衣服';

SELECT product_id, product_name, sale_price, purchase_price
	FROM Product
ORDER BY sale_price ASC;

SELECT product_id, product_name, sale_price, purchase_price
	FROM Product
ORDER BY sale_price, product_id DESC;

SELECT product_id, product_name, sale_price, purchase_price
	FROM Product
ORDER BY purchase_price;

SELECT product_id AS id, product_name, sale_price AS sp, purchase_price
	FROM Product
ORDER BY sp, id;

-- 通过列编号指定
SELECT product_id, product_name, sale_price, purchase_price
	FROM Product
ORDER BY 3 DESC, 1;