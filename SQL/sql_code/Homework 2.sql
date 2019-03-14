-- 2.1
select product_name, regist_date
	from product
	where regist_date >'2009-4-28';
    
-- 2.2 ALL NULL
SELECT *
	FROM Product
	WHERE purchase_price IS NULL;

SELECT *
	FROM Product
	WHERE purchase_price <> NULL;

SELECT *
	FROM Product
	WHERE product_name > NULL;
    
-- 2.3
select product_name, sale_price, purchase_price
	from product
    where sale_price - purchase_price >= 500;
    
-- 2.4
select product_name, product_type, sale_price * 0.9 - purchase_price as profit
	from product
    where (product_type = '办公用品' or product_type = '厨房用具')
    and (sale_price * 0.9 - purchase_price) >= 100;
    
