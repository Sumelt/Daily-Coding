CREATE TABLE Product2
(product_id CHAR(4) NOT NULL,
product_name VARCHAR(100) NOT NULL,
product_type VARCHAR(32) NOT NULL,
sale_price INTEGER ,
purchase_price INTEGER ,
regist_date DATE ,
PRIMARY KEY (product_id));

INSERT INTO Product2 VALUES ('0001', 'T恤衫' ,'衣服', 1000, 500, '2008-09-20');
INSERT INTO Product2 VALUES ('0002', '打孔器', '办公用品', 500, 320, '2009-09-11');
INSERT INTO Product2 VALUES ('0003', '运动T恤', '衣服', 4000, 2800, NULL);
INSERT INTO Product2 VALUES ('0009', '手套', '衣服', 800, 500, NULL);
INSERT INTO Product2 VALUES ('0010', '水壶', '厨房用具', 2000, 1700, '2009-09-20');

SELECT product_id, product_name
	FROM Product
UNION
SELECT product_id, product_name
	FROM Product2;
    
SELECT product_id, product_name
	FROM Product
 WHERE product_type = '厨房用具'
UNION
SELECT product_id, product_name
	FROM Product2
 WHERE product_type = '厨房用具'
ORDER BY product_id;

SELECT SP.shop_id, SP.shop_name, SP.product_id, P.product_name, P.sale_price
	FROM ShopProduct AS SP 
	INNER JOIN Product AS P 
    ON SP.product_id = P.product_id;
    
SELECT SP.shop_id, SP.shop_name, SP.product_id, P.product_name, P.sale_price
	FROM ShopProduct AS SP 
	INNER JOIN Product AS P 
	ON SP.product_id = P.product_id
WHERE SP.shop_id = '000A';

SELECT SP.shop_id, SP.shop_name, SP.product_id, P.product_name, P.sale_price
	FROM Product AS P 
	left OUTER JOIN ShopProduct AS SP
	ON SP.product_id = P.product_id;
    
SELECT SP.shop_id, SP.shop_name, SP.product_id, P.product_name, P.sale_price, IP.inventory_quantity
	FROM ShopProduct AS SP INNER JOIN Product AS P
		ON SP.product_id = P.product_id
	INNER JOIN InventoryProduct AS IP
		ON SP.product_id = IP.product_id
WHERE IP.inventory_id = 'P001';