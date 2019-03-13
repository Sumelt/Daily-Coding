-- 7.1 交集
select un_product.regist_date, p.*
	from (SELECT * FROM Product UNION SELECT * FROM Product) as un_product
	inner join Product as p
	on un_product.product_name = p.product_name;

-- 差集
select product.product_id, product.product_name
	from product
    left outer join product2
    on product.product_name = product2.product_name
where product2.product_id is null;

-- 7.2
SELECT COALESCE(SP.shop_id, '不确定') AS shop_id, COALESCE(SP.shop_name, '不确定') AS shop_name,
P.product_id, P.product_name, P.sale_price
	FROM (ShopProduct as SP RIGHT OUTER JOIN Product as P
	ON SP.product_id = P.product_id)
ORDER BY shop_id;