-- 3.1
SELECT product_type, SUM(purchase_price)
	FROM Product
WHERE regist_date > '2009-09-01'    
GROUP BY product_type;

-- 3.2
select  product_type, sum(sale_price), sum(purchase_price)
	from product
GROUP BY product_type
having (sum(purchase_price) * 1.5) <= sum(sale_price);

-- 3.3
select *
	from product
order by regist_date desc, sale_price asc;