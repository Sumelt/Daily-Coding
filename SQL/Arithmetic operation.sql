select product_name, sale_price, sale_price * 2 
	AS "sale_price_X2"
    from product;
    
SELECT product_name, purchase_price
	FROM Product
WHERE purchase_price = NULL;

select product_name, product_type, regist_date
	from product
    where purchase_price IS NULL;
    
SELECT product_name, purchase_price
	FROM Product
WHERE purchase_price IS NOT NULL;

SELECT product_name, product_type, sale_price
	FROM Product
WHERE NOT sale_price >= 1000;

SELECT product_name, purchase_price
	FROM Product
WHERE product_type = '厨房用具'
	AND sale_price >= 3000;
    
SELECT product_name, purchase_price
	FROM Product
WHERE product_type = '厨房用具'
	OR sale_price >= 3000;
    
SELECT product_name, product_type, regist_date
	FROM Product
WHERE product_type = '办公用品'
	AND ( regist_date = '2009-09-11'
	OR regist_date = '2009-09-20');