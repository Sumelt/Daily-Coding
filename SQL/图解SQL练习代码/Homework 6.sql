-- 6.1 
SELECT product_name, purchase_price
	FROM Product
WHERE purchase_price NOT IN (500, 2800, 5000);

SELECT product_name, purchase_price
	FROM Product
WHERE purchase_price NOT IN (500, 2800, 5000, NULL); -- NO NULL

-- 6.2
SELECT 
	SUM(CASE WHEN sale_price <= 1000 THEN 1 ELSE 0 END) AS low_price,
	SUM(CASE WHEN sale_price BETWEEN 1001 AND 3000 THEN 1 ELSE 0 END) AS mid_price,
	SUM(CASE WHEN sale_price >= 3001 THEN 1 ELSE 0 END) AS high_price
FROM Product;