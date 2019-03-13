SELECT product_name, product_type, sale_price,
	RANK () OVER (PARTITION BY product_type
	ORDER BY sale_price) AS ranking
FROM Product;

SELECT product_name, product_type, sale_price,
	RANK () OVER (ORDER BY sale_price) AS ranking
FROM Product;

SELECT product_name, product_type, sale_price,
	RANK () OVER (ORDER BY sale_price) AS ranking,
	DENSE_RANK () OVER (ORDER BY sale_price) AS dense_ranking,
	ROW_NUMBER () OVER (ORDER BY sale_price) AS row_num
FROM Product;

SELECT product_id, product_name, sale_price,
	sum(sale_price) OVER (ORDER BY product_id) AS current_sum
FROM Product;

SELECT product_id, product_name, sale_price,
	AVG (sale_price) OVER (ORDER BY product_id) AS current_avg
FROM Product;

SELECT product_id, product_name, sale_price,
	AVG (sale_price) OVER (ORDER BY product_id
		ROWS 2 PRECEDING) AS moving_avg
FROM Product;

SELECT product_id, product_name, sale_price,
	AVG (sale_price) OVER (ORDER BY product_id
		ROWS 2 FOLLOWING) AS moving_avg
FROM Product;


SELECT product_id, product_name, sale_price,
	AVG (sale_price) OVER (ORDER BY product_id
	ROWS BETWEEN 1 PRECEDING AND
		1 FOLLOWING) AS moving_avg
FROM Product;

SELECT product_name, product_type, sale_price,
RANK () OVER (ORDER BY sale_price) AS ranking
FROM Product;

SELECT product_name, product_type, sale_price,
RANK () OVER (ORDER BY sale_price) AS ranking
FROM Product
ORDER BY ranking;

/* MySQL无法使用
SELECT product_type, SUM(sale_price) AS sum_price
FROM Product
GROUP BY ROLLUP(product_type);

SELECT product_type, regist_date, SUM(sale_price) AS sum_price
FROM Product
GROUP BY ROLLUP(product_type, regist_date);
*/

SELECT product_type, SUM(sale_price) AS sum_price
FROM Product
GROUP BY product_type WITH ROLLUP;

SELECT product_type, regist_date, SUM(sale_price) AS sum_price
	FROM Product
GROUP BY product_type, regist_date WITH ROLLUP;

SELECT GROUPING(product_type) AS product_type,
	GROUPING(regist_date) AS regist_date, SUM(sale_price) AS sum_price
	FROM Product
GROUP BY product_type, regist_date with ROLLUP;

/*MySQL无法使用
SELECT CASE WHEN GROUPING(product_type) = 1
	THEN '商品种类 合计'
		ELSE product_type END AS product_type, 
	CASE WHEN GROUPING(regist_date) = 1
		THEN '登记日期 合计'
			ELSE CAST(regist_date AS VARCHAR(16)) END AS regist_date,
	SUM(sale_price) AS sum_price
	FROM Product
GROUP BY product_type, regist_date with ROLLUP;
*/


SELECT CASE WHEN GROUPING(product_type) = 1
THEN '商品种类 合计'
ELSE product_type END AS product_type,
CASE WHEN GROUPING(regist_date) = 1
THEN '登记日期 合计'
ELSE CAST(regist_date AS VARCHAR(16)) END AS regist_date,
SUM(sale_price) AS sum_price
FROM Product
GROUP BY product_type, regist_date with CUBE
