CREATE TABLE ShopProduct
(shop_id CHAR(4) NOT NULL,
shop_name VARCHAR(200) NOT NULL,
product_id CHAR(4) NOT NULL,
quantity INTEGER NOT NULL,
PRIMARY KEY (shop_id, product_id));

INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000A', '东京', '0001', 30);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000A', '东京', '0002', 50);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000A', '东京', '0003', 15);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '名古屋', '0002', 30);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '名古屋', '0003', 120);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '名古屋', '0004', 20);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '名古屋', '0006', 10);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '名古屋', '0007', 40);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000C', '大阪', '0003', 20);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000C', '大阪', '0004', 50);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000C', '大阪', '0006', 90);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000C', '大阪', '0007', 70);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000D', '福冈', '0001', 100);

-- 取得“在大阪店销售的商品的销售单价”
SELECT product_name, sale_price
	FROM Product
WHERE product_id IN (SELECT product_id FROM ShopProduct WHERE shop_id = '000C');

SELECT product_name, sale_price
	FROM Product 
WHERE product_id NOT IN (SELECT product_id FROM ShopProduct WHERE shop_id = '000A');

SELECT product_name, sale_price
	FROM Product AS P
	WHERE EXISTS (
		SELECT * FROM ShopProduct AS SP 
		WHERE SP.shop_id = '000C' AND SP.product_id = P.product_id
);

-- 对按照商品种类计算出的销售单价合计值进行行列转换
SELECT SUM(CASE WHEN product_type = '衣服'
	THEN sale_price ELSE 0 END) AS sum_price_clothes,
SUM(CASE WHEN product_type = '厨房用具'
	THEN sale_price ELSE 0 END) AS sum_price_kitchen,
SUM(CASE WHEN product_type = '办公用品'
	THEN sale_price ELSE 0 END) AS sum_price_office
FROM Product;

SELECT product_name,
	CASE WHEN product_type = '衣服'
		THEN concat('A ：', product_type)
	WHEN product_type = '办公用品'
		THEN concat('B ：', product_type)
	WHEN product_type = '厨房用具'
		THEN concat('C ：', product_type)
	ELSE NULL
END AS abc_product_type
FROM Product;

-- 使用简单CASE表达式的情况
SELECT product_name,
	CASE product_type
		WHEN '衣服' THEN concat('A ：', product_type)
		WHEN '办公用品' THEN concat('B ：', product_type)
		WHEN '厨房用具' THEN concat('C ：', product_type)
		ELSE NULL
END AS abc_product_type
FROM Product;
    
    