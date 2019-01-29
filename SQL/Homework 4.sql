CREATE TABLE hw4product
(	product_id CHAR(4) NOT NULL,
	product_name VARCHAR(100) NOT NULL,
	product_type VARCHAR(32) NOT NULL,
	sale_price INTEGER ,
	purchase_price INTEGER ,
	regist_date DATE ,
	PRIMARY KEY (product_id)
);

INSERT INTO hw4product VALUES ('0001', 'T恤衫', '衣服', 1000, 500, '2008-09-20');
INSERT INTO hw4product VALUES ('0002', '打孔器', '办公用品', 500, 320, '2008-09-11');
INSERT INTO hw4product VALUES ('0003', '运动T恤', '衣服', 4000, 2800, NULL);

-- 4.2 error
-- INSERT INTO hw4product SELECT * FROM hw4product;

-- 4.3
CREATE TABLE ProductMargin  -- 商品利润表
(	product_id CHAR(4) NOT NULL,
	product_name VARCHAR(100) NOT NULL,
	sale_price INTEGER,
	purchase_price INTEGER,
	margin INTEGER,
	PRIMARY KEY(product_id)
);


INSERT INTO ProductMargin ( product_id, product_name, sale_price, purchase_price, margin )
	select product_id, product_name, sale_price, purchase_price, sale_price - purchase_price
	from hw4product
    where product_id = '0001';

INSERT INTO ProductMargin ( product_id, product_name, sale_price, purchase_price, margin )
	select product_id, product_name, sale_price, purchase_price, sale_price - purchase_price
	from hw4product
    where product_id = '0002';
    
INSERT INTO ProductMargin ( product_id, product_name, sale_price, purchase_price, margin )
	select product_id, product_name, sale_price, purchase_price, sale_price - purchase_price
	from hw4product
    where product_id = '0003';

-- 4.4
update productmargin set sale_price = 3000, margin = sale_price - purchase_price;


-- drop table hw4product, ProductMargin;