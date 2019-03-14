-- 用来插入数据的商品复制表
CREATE TABLE ProductCopy
	(product_id CHAR(4) NOT NULL,
	product_name VARCHAR(100) NOT NULL,
	product_type VARCHAR(32) NOT NULL,
	sale_price INTEGER ,
	purchase_price INTEGER ,
	regist_date DATE ,
	PRIMARY KEY (product_id)
);

-- 将商品表中的数据复制到商品复制表中
INSERT INTO ProductCopy (product_id, product_name, product_type, sale_price, purchase_price, regist_date)
	SELECT product_id, product_name, product_type, sale_price, purchase_price, regist_date
FROM Product;

insert into productcopy select * from product;

DELETE FROM ProductCopy;

DELETE FROM Product
	WHERE sale_price >= 4000;
    
TRUNCATE producttype;

UPDATE Product
	SET regist_date = '2009-10-10';
    
UPDATE Product
	SET sale_price = sale_price * 10
WHERE product_type = '厨房用具';

UPDATE Product
	SET regist_date = NULL
WHERE product_id = '0008';

-- 使用逗号对列进行分隔排列
UPDATE Product
	SET sale_price = sale_price * 10,
		purchase_price = purchase_price / 2
WHERE product_type = '厨房用具';

drop table ProductCopy;
