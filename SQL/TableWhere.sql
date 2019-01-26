-- 本SELECT语句会从结果中删除重复行。
SELECT product_name, purchase_price
	FROM Product
WHERE purchase_price >= 2000;